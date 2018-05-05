#include "Position.h"


void Position::updatePositionRow()
{
	++row;
	column = 0;
	++charnum;
}

void Position::updatePositionColumn()
{
	++column;
	++charnum;
}

unsigned int Position::getCharNum()
{
	return charnum;
}
