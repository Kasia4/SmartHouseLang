#pragma once
class Position
{
public:
	Position() : row(0), column(0), charnum(0) {};
	Position(unsigned int row, unsigned int column, unsigned int charnum) : row(row), column(column), charnum(charnum) {};
	~Position() = default;

	void updatePositionRow();
	void updatePositionColumn();

private:
	unsigned int row;
	unsigned int column;
	unsigned int charnum;
};

