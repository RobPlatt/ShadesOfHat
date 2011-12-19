/*
 * rng.cpp
 *
 *  Created on: 19 Dec 2011
 *      Author: rob
 */

#include "rng.h"

#include <tr1/random>

namespace
{

std::tr1::mt19937 generator;

}

unsigned getRandom(unsigned lower, unsigned upper)
{
	std::tr1::uniform_int<unsigned> dist(lower, upper);
  return dist(generator);
}
