#include "cell.h"

Cell::Cell()
{
	visited = false;
	upOpen = false;
	downOpen = false;
	leftOpen = false;
	rightOpen = false;

	rect.x = 0;
	rect.y = 0;
	rect.w = CELL_WIDTH;
	rect.h = CELL_HEIGHT;
}

Cell::Cell(int x, int y)
{
	visited = false;
	upOpen = false;
	downOpen = false;
	leftOpen = false;
	rightOpen = false;
	
	rect.x = x;
	rect.y = y;
	rect.w = CELL_WIDTH;
	rect.h = CELL_HEIGHT;
}

Cell::~Cell()
{

}