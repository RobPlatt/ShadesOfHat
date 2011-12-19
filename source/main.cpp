/*
 * main.cpp
 *
 *  Created on: 19 Dec 2011
 *      Author: rob
 */


#include "Piece.h"
#include "Board.h"

#include <iostream>

int main()
{
	for ( unsigned i = 0; i < 100; i++ )
	{
		Piece piece1;
		Piece piece2;

		piece1.randomize ();
		piece2.randomize ();

		std::cout << piece1.toString () << " <- " << piece2.toString ();

		if ( piece1.canMerge ( (piece2) ) )
		{
			piece1.merge ( piece2 );
			std::cout << " : " << piece1.toString () << std::endl;
		}
		else
		{
			std::cout << " cannot be merged" << std::endl;
		}

	}


	Board board(5);

	std::cout << std::endl;
	std::cout << board.toString();

	return 0;
}



