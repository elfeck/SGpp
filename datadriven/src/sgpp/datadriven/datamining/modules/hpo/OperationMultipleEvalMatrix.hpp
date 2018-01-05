// Copyright (C) 2008-today The SG++ project
// This file is part of the SG++ project. For conditions of distribution and
// use, please see the copyright notice provided with SG++ or at
// sgpp.sparsebase::Grids.org

#ifndef OperationMultipleEvalMatrix_HPP
#define OperationMultipleEvalMatrix_HPP

#include <sgpp/base/Grid/GridStorage.hpp>
#include <sgpp/base/operation/hash/OperationMultipleEval.hpp>

#include <sgpp/globaldef.hpp>


namespace sgpp {
namespace datadriven {

/**
 * This class implements OperationB for a base::Grids with linear basis ansatzfunctions without boundaries
 */
class OperationMultipleEvalMatrix : public base::OperationMultipleEval {
 public:
  /**
   * Constructor of OperationBLinear
   *
   * @param base::Grid base::Grid
   * @param dataset the dataset that should be evaluated
   */
  OperationMultipleEvalMatrix(base::Grid& grid, base::DataMatrix& dataset)
      : OperationMultipleEval(grid, dataset), storage(grid.getStorage()) {}

  /**
   * Destructor
   */
  ~OperationMultipleEvalMatrix() override {}

  void mult(base::DataVector& alpha, base::DataVector& result) override;
  void multTranspose(base::DataVector& source, base::DataVector& result) override;

  double getDuration() override;

 protected:
  /// reference to the base::Grid's base::GridStorage object
  base::GridStorage& storage;
};

}  // namespace datadriven
}  // namespace sgpp

#endif /* OperationMultipleEvalMatrix_HPP */
