// Copyright (C) 2008-today The SG++ project
// This file is part of the SG++ project. For conditions of distribution and
// use, please see the copyright notice provided with SG++ or at
// sgpp.sparsegrids.org

#include <sgpp/base/operation/hash/OperationQuadraturePoly.hpp>


#include <sgpp/globaldef.hpp>


namespace SGPP {
  namespace base {

    float_t OperationQuadraturePoly::doQuadrature(DataVector& alpha) {
      float_t res = 0;
      GridStorage::index_type index;
      GridStorage::grid_map_iterator end_iter = storage->end();

      for (GridStorage::grid_map_iterator iter = storage->begin(); iter != end_iter; iter++) {
        if (base.getDegree() <= 3) {
          res += pow(2.0, (2.0 - log(3.0) / log(2.0)) * static_cast<float_t>(iter->first->dim()) - static_cast<float_t>(iter->first->getLevelSum())) * alpha.get(iter->second);
        } else {
          res += 0; // if this case occurs, something has gone very wrong...
        }
      }

      return res;
    }

  }
}