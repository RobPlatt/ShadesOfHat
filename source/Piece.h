/*
 * Piece.h
 *
 *  Created on: 19 Dec 2011
 *      Author: rob
 */

#ifndef PIECE_H_
#define PIECE_H_

#include "Shade.h"

#include <string>

class Piece
{
	unsigned int number_;
	Shade shade_;
	bool isHat_;

public:
	Piece();

	unsigned int number() const { return number_; }
	Shade shade() const { return shade_; }
	bool isHat() const { return isHat_; }

	bool canMerge(const Piece& piece) const;
	void merge(const Piece& piece);

	void randomize();

	std::string toString() const;

};

#endif /* PIECE_H_ */
