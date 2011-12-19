/*
 * Piece.cpp
 *
 *  Created on: 19 Dec 2011
 *      Author: rob
 */

#include "Piece.h"
#include "rng.h"

#include <sstream>
#include <iomanip>

Piece::Piece() : number_(0), shade_(WHITE), isHat_(false)
{

}

bool Piece::canMerge(const Piece& source) const
{
	if (isHat_ or source.isHat_)
		return false;

	if (number_ + source.number_ > 21)
		return false;

	return true;
}

void Piece::merge(const Piece& source)
{
	if (!canMerge(source))
		throw "Can't merge";

	// merge numbers
	number_ += source.number_;

	// merge shade
	unsigned numWhite = (shade_ == WHITE) + (source.shade_ == WHITE);
	unsigned numGrey = (shade_ == GREY) + (source.shade_ == GREY);
	unsigned numBlack = (shade_ == BLACK) + (source.shade_ == BLACK);

	if (numWhite == 1 && numGrey == 1)
		shade_ = WHITE;

	if (numBlack == 1 && numGrey == 1)
		shade_ = BLACK;

	if (numWhite == 1 && numBlack == 1)
		shade_ = GREY;
}

void Piece::randomize()
{
	Shade shade = randomShade();
	unsigned int n = getRandom(1, 11);

	shade_ = shade;
	number_ = n;
}

std::string Piece::toString() const
{
	std::ostringstream ss;

	if (isHat_)
		ss << 'H';
	else
		ss << number_;

	ss << shadeToChar(shade_);

	return ss.str();
}
