/******************************************************************************
* Copyright (C) 2009 Technische Universitaet Muenchen                         *
* This file is part of the SG++ project. For conditions of distribution and   *
* use, please see the copyright notice at http://www5.in.tum.de/SGpp          *
******************************************************************************/
// @author Jörg Blank (blankj@in.tum.de), Alexander Heinecke (Alexander.Heinecke@mytum.de)

#ifndef MODLINEARGRID_HPP
#define MODLINEARGRID_HPP

#include "grid/Grid.hpp"

#include <iostream>
using namespace sg::datadriven;

namespace sg
{
namespace base
{

/**
 * grid with modified linear base functions
 */
class ModLinearGrid : public Grid
{
protected:
	ModLinearGrid(std::istream& istr);

public:
	/**
	 * Constructor modified linear grid
	 *
	 * @param dim the dimension of the grid
	 */
	ModLinearGrid(size_t dim);

	/**
	 * Destructor
	 */
	virtual ~ModLinearGrid();

	virtual const char* getType();

	virtual OperationMultipleEval* createOperationMultipleEval(DataMatrix* dataset);
	virtual OperationMultipleEvalVectorized* createOperationMultipleEvalVectorized(const std::string& VecType, DataMatrix* dataset);
	virtual OperationMultipleEvalVectorizedSP* createOperationMultipleEvalVectorizedSP(const std::string& VecType, DataMatrixSP* dataset);
	virtual GridGenerator* createGridGenerator();
	virtual OperationMatrix* createOperationLaplace();
	virtual OperationEval* createOperationEval();
	virtual OperationTest* createOperationTest();
	virtual OperationHierarchisation* createOperationHierarchisation();
	virtual OperationMatrix* createOperationLTwoDotProduct();
	virtual OperationConvert* createOperationConvert();

	// @todo (heinecke) remove this when done
	virtual OperationMatrix* createOperationUpDownTest();

	// finance operations
	virtual OperationMatrix* createOperationDelta(DataVector& coef);
	virtual OperationMatrix* createOperationGamma(DataMatrix& coef);
	virtual OperationMatrix* createOperationDeltaLog(DataVector& coef);
	virtual OperationMatrix* createOperationGammaLog(DataMatrix& coef);
	// finance operations for hull-white 1D
	virtual OperationMatrix* createOperationLB();
	virtual OperationMatrix* createOperationLD();
	virtual OperationMatrix* createOperationLE();
	virtual OperationMatrix* createOperationLF();

	static Grid* unserialize(std::istream& istr);

};

}
}

#endif /* MODLINEARGRID_HPP */
