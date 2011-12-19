/*
 * Board.cpp
 *
 *  Created on: 19 Dec 2011
 *      Author: rob
 */

#include "Board.h"

#include <sstream>
#include <iomanip>

Board::Board(unsigned size) : size_(size)
{
	grid_.resize(size);
	for (unsigned i = 0; i < size; i++)
	{
		grid_[i].resize(size);
	}

	randomize();
}

void Board::randomize()
{
	for (unsigned i = 0; i < size_; i++)
	{
		for (unsigned j = 0; j < size_; j++)
		{
			at(i, j).randomize();
		}
	}
}

std::string Board::toString()
{
	std::ostringstream ss;

	ss << "  ";
	for (unsigned i = 0; i < size_; i++)
	{
		ss << std::setfill(' ') << std::setw(4) << std::right << char('a'+i);
	}

	ss << std::endl;

	for (unsigned i = 0; i < size_; i++)
	{
		ss << std::setfill(' ') << std::setw(2) << std::right << i;
		for (unsigned j = 0; j < size_; j++)
		{
			ss << '|' << std::setfill(' ') << std::setw(3) << std::right << at(i, j).toString();
		}
		ss << '|' << std::endl;
	}

	return ss.str();
}
