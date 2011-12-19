/*
 * Shade.cpp
 *
 *  Created on: 19 Dec 2011
 *      Author: rob
 */

#include "Shade.h"
#include "rng.h"

Shade randomShade()
{
	unsigned n = boardRng().getRandom(0, 2);

	switch (n)
	{
	case 0:
		return WHITE;
	case 1:
		return GREY;
	case 2:
		return BLACK;
	default:
		throw "Expected 0,1,2 from rng";
	}
}
