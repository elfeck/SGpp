// Copyright (C) 2008-today The SG++ project
// This file is part of the SG++ project. For conditions of distribution and
// use, please see the copyright notice provided with SG++ or at
// sgpp.sparsegrids.org

#ifndef OPERATIONSECONDMOMENTLINEAR_HPP
#define OPERATIONSECONDMOMENTLINEAR_HPP

#include <sgpp/base/operation/hash/OperationSecondMoment.hpp>
#include <sgpp/base/grid/Grid.hpp>
#include <sgpp/base/datatypes/DataMatrix.hpp>
#include <sgpp/base/datatypes/DataVector.hpp>

#include <sgpp/globaldef.hpp>

namespace sgpp {
namespace base {

/**
 * SecondMomemnt of sparse grid function, linear grid without boundaries
 */
class OperationSecondMomentLinear : public OperationSecondMoment {
 public:
  /**
   * Constructor of OperationSecondMomentLinear
   *
   * @param storage Pointer to the grid's GridStorage object
   */
  explicit OperationSecondMomentLinear(GridStorage& storage) : storage(storage) {}

  ~OperationSecondMomentLinear() override {}

  /**
   * Compute second moment of the function
   * @f[ \int_{\Omega} x^2\cdot f(x) dx. @f]
   *
   * @param alpha Coefficient vector for current grid
   * @param bounds describes the boundaries of the hypercube of the original function
   */
  double doQuadrature(DataVector& alpha, DataMatrix* bounds = nullptr) override;

 protected:
  // Pointer to the grid's GridStorage object
  GridStorage& storage;
};

}  // namespace base
}  // namespace sgpp

#endif /* OPERATIONSECONDMOMENTLINEAR_HPP */
