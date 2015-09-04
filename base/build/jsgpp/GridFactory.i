// Copyright (C) 2008-today The SG++ project
// This file is part of the SG++ project. For conditions of distribution and
// use, please see the copyright notice provided with SG++ or at
// sgpp.sparsegrids.org

%include "std_string.i"

%newobject SGPP::base::Grid::createLinearGrid(size_t dim);
%newobject SGPP::base::Grid::createLinearStretchedGrid(size_t dim);
%newobject SGPP::base::Grid::createLinearBoundaryGrid(size_t dim, size_t boundaryLevel);
%newobject SGPP::base::Grid::createLinearClenshawCurtisGrid(size_t dim);
%newobject SGPP::base::Grid::createLinearBoundaryGrid(size_t dim);
%newobject SGPP::base::Grid::createLinearBoundaryGrid(SGPP::base::BoudingBox& BB);
%newobject SGPP::base::Grid::createLinearStretchedBoundaryGrid(size_t dim);
%newobject SGPP::base::Grid::createLinearStretchedBoundaryGrid(SGPP::base::Stretching& BB);
%newobject SGPP::base::Grid::createModLinearGrid(size_t dim);
%newobject SGPP::base::Grid::createPolyGrid(size_t dim, size_t degree);
%newobject SGPP::base::Grid::createModPolyGrid(size_t dim, size_t degree);
%newobject SGPP::base::Grid::createWaveletGrid(size_t dim);
%newobject SGPP::base::Grid::createWaveletBoundaryGrid(size_t dim);
%newobject SGPP::base::Grid::createModWaveletGrid(size_t dim);
%newobject SGPP::base::Grid::createBsplineGrid(size_t dim, size_t degree);
%newobject SGPP::base::Grid::createBsplineBoundaryGrid(size_t dim, size_t degree);
%newobject SGPP::base::Grid::createBsplineClenshawCurtisGrid(size_t dim, size_t degree);
%newobject SGPP::base::Grid::createModBsplineGrid(size_t dim, size_t degree);
%newobject SGPP::base::Grid::createModBsplineClenshawCurtisGrid(size_t dim, size_t degree);
%newobject SGPP::base::Grid::createFundamentalSplineGrid(size_t dim, size_t degree);
%newobject SGPP::base::Grid::createModFundamentalSlineGrid(size_t dim, size_t degree);
%newobject SGPP::base::Grid::createLinearTruncatedBoundaryGrid(size_t dim);
%newobject SGPP::base::Grid::createSquareRootGrid(size_t dim);
%newobject SGPP::base::Grid::createPrewaveletGrid(size_t dim);
%newobject SGPP::base::Grid::createPeriodicGrid(size_t dim);

%newobject SGPP::base::Grid::unserialize(std::string& istr);

%newobject SGPP::base::Grid::createGridGenerator();

%include "stl.i"
%include "typemaps.i"

//%apply std::string *OUTPUT { std::string& ostr };
//%apply std::string *INPUT { std::string& istr };


using namespace SGPP;
namespace SGPP
{
namespace base
{

class Grid
{
public:
  static Grid* createLinearGrid(size_t dim);
  static Grid* createLinearStretchedGrid(size_t dim);
  static Grid* createLinearBoundaryGrid(size_t dim, size_t boundaryLevel);
  static Grid* createLinearClenshawCurtisGrid(size_t dim);
  static Grid* createLinearBoundaryGrid(size_t dim);
  static Grid* createLinearStretchedBoundaryGrid(size_t dim);
  static Grid* createModLinearGrid(size_t dim);
  static Grid* createPolyGrid(size_t dim, size_t degree);
  static Grid* createModPolyGrid(size_t dim, size_t degree);
  static Grid* createWaveletGrid(size_t dim);
  static Grid* createWaveletBoundaryGrid(size_t dim);
  static Grid* createModWaveletGrid(size_t dim);
  static Grid* createBsplineGrid(size_t dim, size_t degree);
  static Grid* createBsplineBoundaryGrid(size_t dim, size_t degree);
  static Grid* createBsplineClenshawCurtisGrid(size_t dim, size_t degree);
  static Grid* createModBsplineGrid(size_t dim, size_t degree);
  static Grid* createModBsplineClenshawCurtisGrid(size_t dim, size_t degree);
  static Grid* createFundamentalSplineGrid(size_t dim, size_t degree);
  static Grid* createModFundamentalSplineGrid(size_t dim, size_t degree);
  static Grid* createSquareRootGrid(size_t dim);
  static Grid* createLinearTruncatedBoundaryGrid(size_t dim);
  static Grid* createPrewaveletGrid(size_t dim);
  static Grid* createLinearGridStencil(size_t dim);
  static Grid* createModLinearGridStencil(size_t dim);
  static Grid* createPeriodicGrid(size_t dim);
	
  static Grid* unserialize(std::string& istr);
	
protected:
  Grid();
  Grid(Grid& o);

public:
  virtual ~Grid();

public:	
  virtual SGPP::base::GridGenerator* createGridGenerator() = 0;
  virtual SGPP::base::GridStorage* getStorage();
  virtual SGPP::base::BoundingBox* getBoundingBox();
  virtual SGPP::base::Stretching* getStretching();

  virtual const char* getType() = 0;
  virtual const SBasis& getBasis() = 0;
  virtual void serialize(std::string& ostr);
  void refine(SGPP::base::DataVector* vector, int num);
  float_t eval(SGPP::base::DataVector& alpha, SGPP::base::DataVector& point);
  void insertPoint(size_t dim, unsigned int levels[], unsigned int indeces[], bool isLeaf);
  int getSize();
};
}
}

//these are just two new interfaces for consistency with Memento design pattern
%extend SGPP::base::Grid{
	SGPP::base::Grid* createMemento(){
		return $self;
	}
	
	static SGPP::base::Grid* setMemento(std::string& istr){
		return SGPP::base::Grid::unserialize(istr);
	}
};

	
