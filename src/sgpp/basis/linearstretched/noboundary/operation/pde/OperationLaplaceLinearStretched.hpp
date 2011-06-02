/******************************************************************************
* Copyright (C) 2011 Technische Universitaet Muenchen                         *
* This file is part of the SG++ project. For conditions of distribution and   *
* use, please see the copyright notice at http://www5.in.tum.de/SGpp          *
******************************************************************************/
// @author Jörg Blank (blankj@in.tum.de), Alexander Heinecke (Alexander.Heinecke@mytum.de), Sarpkan Selcuk (Sarpkan.Selcuk@mytum.de)


#ifndef OPERATIONLAPLACELINEARSTRETCHED_HPP
#define OPERATIONLAPLACELINEARSTRETCHED_HPP

#include "algorithm/pde/UpDownOneOpDim.hpp"

using namespace sg::base;

namespace sg
{
namespace pde
{

/**
 * Implementation for linear functions of Laplace Operation, linear grids without boundaries
 *
 * @version $HEAD$
 */
class OperationLaplaceLinearStretched: public UpDownOneOpDim
{
public:
	/**
	 * Construtor of OperationLaplaceLinearStretched
	 *
	 * @param storage Pointer to the grid's gridstorage obejct
	 */
	OperationLaplaceLinearStretched(GridStorage* storage);

	/**
	 * Destructor
	 */
	virtual ~OperationLaplaceLinearStretched();

protected:
	virtual void specialOP(DataVector& alpha, DataVector& result, size_t dim, size_t gradient_dim);

	virtual void up(DataVector& alpha, DataVector& result, size_t dim);

	virtual void down(DataVector& alpha, DataVector& result, size_t dim);

	virtual void downOpDim(DataVector& alpha, DataVector& result, size_t dim);

	virtual void upOpDim(DataVector& alpha, DataVector& result, size_t dim);
};

}
}

#endif /* OPERATIONLAPLACELINEARSTRETCHED_HPP */
