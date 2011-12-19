/*
 * rng.h
 *
 *  Created on: 19 Dec 2011
 *      Author: rob
 */

#ifndef RNG_H_
#define RNG_H_

#include <string>

struct Rng
{
	struct Impl;

	Rng();
	~Rng();

  void seedWithTime();
	std::string getRngState();
	void setRngState(std::string& source);

  unsigned getRandom(unsigned lower, unsigned upper);

private:
  Impl* pImpl_;

  Rng(const Rng&);
  Rng& operator=(const Rng&);
};

Rng& boardRng();

#endif /* RNG_H_ */
