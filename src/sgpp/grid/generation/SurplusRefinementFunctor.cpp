/******************************************************************************
* Copyright (C) 2010 Technische Universitaet Muenchen                         *
* This file is part of the SG++ project. For conditions of distribution and   *
* use, please see the copyright notice at http://www5.in.tum.de/SGpp          *
******************************************************************************/
// @author Dirk Pflueger (pflueged@in.tum.de), Jörg Blank (blankj@in.tum.de), Alexander Heinecke (Alexander.Heinecke@mytum.de)

#include "grid/generation/SurplusRefinementFunctor.hpp"

namespace sg
{

SurplusRefinementFunctor::SurplusRefinementFunctor(DataVector* alpha, int refinements_num, double threshold) : alpha(alpha), refinements_num(refinements_num), threshold(threshold)
{
}


SurplusRefinementFunctor::~SurplusRefinementFunctor()
{
}

double SurplusRefinementFunctor::operator()(GridStorage* storage, size_t seq)
{
	return fabs(alpha->get(seq));
}

double SurplusRefinementFunctor::start()
{
	return 0.0;
}

int SurplusRefinementFunctor::getRefinementsNum()
{
	return this->refinements_num;
}

double SurplusRefinementFunctor::getRefinementThreshold()
{
	return this->threshold;
}

}
