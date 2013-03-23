/******************************************************************************
* Copyright (C) 2011 Technische Universitaet Muenchen                         *
* This file is part of the SG++ project. For conditions of distribution and   *
* use, please see the copyright notice at http://www5.in.tum.de/SGpp          *
******************************************************************************/
// @author Alexander Heinecke (Alexander.Heinecke@mytum.de)
// @author Roman Karlstetter (karlstetter@mytum.de)

#include "parallel/datadriven/basis/modlinear/operation/OperationMultipleEvalIterativeSPX86SimdModLinear.hpp"
#include "parallel/datadriven/basis/modlinear/operation/impl/SPX86SimdModLinear.hpp"
#include "parallel/tools/PartitioningTool.hpp"

namespace sg
{
namespace parallel
{

OperationMultipleEvalIterativeSPX86SimdModLinear::OperationMultipleEvalIterativeSPX86SimdModLinear(
		sg::base::GridStorage* storage, sg::base::DataMatrixSP* dataset,
		int gridFrom, int gridTo, int datasetFrom, int datasetTo) :
	sg::parallel::OperationMultipleEvalVectorizedSP(storage, dataset)
{
	m_gridFrom = gridFrom;
	m_gridTo = gridTo;
	m_datasetFrom = datasetFrom;
	m_datasetTo = datasetTo;
	rebuildLevelAndIndex();
}

void OperationMultipleEvalIterativeSPX86SimdModLinear::rebuildLevelAndIndex()
{
	LevelIndexMaskOffsetHelperSP::rebuild<SPX86SimdModLinear::kernelType, OperationMultipleEvalVectorizedSP>(this);
}

void OperationMultipleEvalIterativeSPX86SimdModLinear::updateGridComputeBoundaries(int gridFrom, int gridTo)
{
	m_gridFrom = gridFrom;
	m_gridTo = gridTo;
}

double OperationMultipleEvalIterativeSPX86SimdModLinear::multTransposeVectorized(sg::base::DataVectorSP& source, sg::base::DataVectorSP& result)
{
	myTimer_->start();
    result.setAll(0.0);

	#pragma omp parallel
	{
		size_t start;
		size_t end;
		PartitioningTool::getOpenMPPartitionSegment(m_gridFrom, m_gridTo, &start, &end, 1);

		SPX86SimdModLinear::multTranspose(level_, index_, NULL, NULL, dataset_, source, result, start, end, 0, this->dataset_->getNcols());
	}

	return myTimer_->stop();
}

double OperationMultipleEvalIterativeSPX86SimdModLinear::multVectorized(sg::base::DataVectorSP& alpha, sg::base::DataVectorSP& result)
{
	myTimer_->start();
	result.setAll(0.0);

	#pragma omp parallel
	{
		size_t start;
		size_t end;
		PartitioningTool::getOpenMPPartitionSegment(m_datasetFrom, m_datasetTo, &start, &end, SPX86SimdModLinear::getChunkDataPoints());

		SPX86SimdModLinear::mult(level_, index_, NULL, NULL, dataset_, alpha, result, 0, alpha.getSize(), start, end);
	}

	return myTimer_->stop();
}

}
}
