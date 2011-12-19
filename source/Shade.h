/*
 * Shade.h
 *
 *  Created on: 19 Dec 2011
 *      Author: rob
 */

#ifndef SHADE_H_
#define SHADE_H_

typedef enum
{
	WHITE,
	GREY,
	BLACK
} Shade;

Shade randomShade();

inline char shadeToChar(Shade shade)
{
	switch (shade)
	{
	case WHITE:
		return 'W';

	case GREY:
		return 'G';

	case BLACK:
		return 'B';

	default:
		return '?';
	}
}

#endif /* SHADE_H_ */
