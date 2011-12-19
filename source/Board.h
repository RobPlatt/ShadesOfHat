/*
 * Board.h
 *
 *  Created on: 19 Dec 2011
 *      Author: rob
 */

#ifndef BOARD_H_
#define BOARD_H_

#include "Piece.h"

#include <vector>
#include <string>

class Board
{
public:
	Board(unsigned size);

	Piece& at(unsigned row, unsigned column) { return grid_.at(row).at(column); }
	const Piece& at(unsigned row, unsigned column) const { return grid_.at(row).at(column); }

	void randomize();

	std::string toString();

private:
	unsigned size_;
	std::vector< std::vector<Piece> > grid_;
};


#endif /* BOARD_H_ */
