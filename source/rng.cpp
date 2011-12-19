/*
 * rng.cpp
 *
 *  Created on: 19 Dec 2011
 *      Author: rob
 */

#include "rng.h"

#include <tr1/random>
#include <ctime>
#include <sstream>

namespace
{

Rng boardRng_;

}

struct Rng::Impl
{
	std::tr1::mt19937 generator_;
};

Rng& boardRng()
{
	return boardRng_;
}

Rng::Rng()
{
	pImpl_ = new(Rng::Impl);
}

Rng::~Rng()
{
	delete(pImpl_);
}

void Rng::seedWithTime()
{
	unsigned int seed = (unsigned int)time(NULL);
	pImpl_->generator_.seed(seed);
}

std::string Rng::getRngState()
{
	std::ostringstream ss;
	ss << pImpl_->generator_;
	return ss.str();
}

void Rng::setRngState(std::string& source)
{
	std::istringstream ss(source);
	ss >> pImpl_->generator_;
}

unsigned Rng::getRandom(unsigned lower, unsigned upper)
{
	std::tr1::uniform_int<unsigned> dist(lower, upper);
  return dist(pImpl_->generator_);
}
