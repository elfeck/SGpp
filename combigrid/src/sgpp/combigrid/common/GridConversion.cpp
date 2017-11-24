// Copyright (C) 2008-today The SG++ project
// This file is part of the SG++ project. For conditions of distribution and
// use, please see the copyright notice provided with SG++ or at
// sgpp.sparsegrids.org

#include <sgpp/base/grid/storage/hashmap/HashGridStorage.hpp>
#include <sgpp/combigrid/common/GridConversion.hpp>

namespace sgpp {
namespace combigrid {

std::shared_ptr<TreeStorage<uint8_t>> convertHierarchicalSparseGridToCombigrid(
    base::HashGridStorage& storage, GridConversionTypes conversionType) {
  switch (conversionType) {
    case GridConversionTypes::ALLSUBSPACES:
      return allStorageLevels(storage);
    case GridConversionTypes::COMPLETESUBSPACES:
    default:
      return completeStorageLevels(storage);
  }
}

void convertCombigridToHierarchicalSparseGrid(
    std::shared_ptr<TreeStorage<uint8_t>> levelStructure, base::HashGridStorage& storage,
    std::shared_ptr<AbstractCombigridStorage> const& funcStorage,
    sgpp::base::DataVector& functionValues) {
  size_t d = levelStructure->getNumDimensions();

  functionValues.clear();

  auto it = levelStructure->getStoredDataIterator();
  base::HashGridPoint::level_type sglevel;
  base::HashGridPoint::index_type sgindex;
  base::HashGridPoint point(d);

  std::vector<bool> orderingConfiguration;
  for (size_t dim = 0; dim < d; ++dim) {
    // ToDo (rehmemk) This must be generalized for arbitrary needsSorted!
    bool needsSorted = true;
    orderingConfiguration.push_back(needsSorted);
  }

  while (it->isValid()) {
    MultiIndex currentLevel = it->getMultiIndex();

    // now iterate over index
    MultiIndex multiBounds(d);
    for (size_t i = 0; i < d; ++i) {
      // there are 2^l elements in the level, subtract 1 because the bound is inclusive
      multiBounds[i] = 1 << currentLevel[i];
    }
    MultiIndexIterator indexIt(multiBounds);

    auto funcIter = funcStorage->getGuidedIterator(currentLevel, indexIt, orderingConfiguration);

    while (indexIt.isValid()) {
      MultiIndex index = indexIt.getMultiIndex();
      for (size_t i = 0; i < d; ++i) {
        sglevel = static_cast<base::HashGridPoint::level_type>(currentLevel[i] + 1);
        sgindex = static_cast<base::HashGridPoint::index_type>(2 * index[i] + 1);
        point.push(i, sglevel, sgindex);
      }
      functionValues.push_back(funcIter->value());
      storage.insert(point);
      indexIt.moveToNext();
    }

    it->moveToNext();
  }

  storage.recalcLeafProperty();
}

std::shared_ptr<TreeStorage<uint8_t>> allStorageLevels(base::HashGridStorage& storage) {
  size_t numDims = storage.getDimension();
  auto treeStorage = std::make_shared<TreeStorage<uint8_t>>(numDims);

  auto it = storage.begin();

  for (; it != storage.end(); ++it) {
    MultiIndex level(numDims);
    for (size_t i = 0; i < numDims; ++i) {
      level[i] = it->first->getLevel(i) - 1;
    }

    treeStorage->set(level, 1);
  }

  return treeStorage;
}

std::shared_ptr<TreeStorage<uint8_t>> completeStorageLevels(base::HashGridStorage& storage) {
  size_t numDims = storage.getDimension();
  auto treeStorage = std::make_shared<TreeStorage<uint8_t>>(numDims);
  auto countStorage = std::make_shared<TreeStorage<size_t>>(numDims);

  auto it = storage.begin();

  for (; it != storage.end(); ++it) {
    MultiIndex level(numDims);
    for (size_t i = 0; i < numDims; ++i) {
      level[i] = it->first->getLevel(i) - 1;
    }

    ++countStorage->get(level);
  }

  auto countIt = countStorage->getStoredDataIterator();

  while (countIt->isValid()) {
    auto level = countIt->getMultiIndex();

    // compute number of points that are in the level if it is full
    size_t prod = 1;
    for (size_t dim = 0; dim < numDims; ++dim) {
      prod *= 1 << level[dim];
    }

    if (countIt->value() == prod) {
      treeStorage->set(level, 1);
    }
    countIt->moveToNext();
  }

  return treeStorage;
}

} /* namespace combigrid */
} /* namespace sgpp */
