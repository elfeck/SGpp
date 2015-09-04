// Copyright (C) 2008-today The SG++ project
// This file is part of the SG++ project. For conditions of distribution and
// use, please see the copyright notice provided with SG++ or at
// sgpp.sparsegrids.org

#include <sgpp/base/grid/Grid.hpp>
#include <sgpp/base/grid/type/WaveletBoundaryGrid.hpp>

#include <sgpp/base/grid/generation/BoundaryGridGenerator.hpp>

#include <sgpp/base/exception/factory_exception.hpp>

#include <sgpp/base/operation/hash/common/basis/WaveletBoundaryBasis.hpp>



#include <iostream>

#include <sgpp/globaldef.hpp>


namespace SGPP {
  namespace base {

    WaveletBoundaryGrid::WaveletBoundaryGrid(std::istream& istr) : Grid(istr) {
    }

    WaveletBoundaryGrid::WaveletBoundaryGrid(size_t dim) {
      this->storage = new GridStorage(dim);
    }

    WaveletBoundaryGrid::~WaveletBoundaryGrid() {
    }

    const char* WaveletBoundaryGrid::getType() {
      return "waveletBoundary";
    }

    const SBasis& WaveletBoundaryGrid::getBasis() {
      static SWaveletBoundaryBase basis;
      return basis;
    }

    Grid* WaveletBoundaryGrid::unserialize(std::istream& istr) {
      return new WaveletBoundaryGrid(istr);
    }

    /**
     * Creates new GridGenerator
     * This must be changed if we add other storage types
     */
    GridGenerator* WaveletBoundaryGrid::createGridGenerator() {
      return new BoundaryGridGenerator(this->storage);
    }



  }
}
