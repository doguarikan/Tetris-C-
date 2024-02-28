#include "tetro.h"

extern int chosentheme;
extern int isholded;
using namespace std;

Tetro::Tetro()
{
    cellSize = 30;
    rotated = 0;
    colors = GetCellColors(chosentheme);
    rowMoved = 0;
    columnMoved = 0;
}

void Tetro::DrawTetroFlag(int movedX, int movedY)
{
	vector<Texture2D> miniflag = GetCellflags();
    vector<Position> tiles = GetCellPositions();
    for (Position item : tiles)
    	DrawTexture(miniflag[tetroid], item.column * cellSize + movedX, item.row * cellSize + movedY, WHITE);
}
void Tetro::DrawTetroColor(int movedX, int movedY)
{
    vector<Position> tiles = GetCellPositions();
    for (Position item : tiles)
		DrawRectangle(item.column * cellSize + movedX, item.row * cellSize + movedY, cellSize - 3, cellSize - 3, colors[tetroid]);
}

void Tetro::DrawHoldTetroColor(int movedX, int movedY)
{
    vector<Position> tiles = GetCellPositionsHold();
    for (Position item : tiles)
		DrawRectangle(item.column * cellSize + movedX, item.row * cellSize + movedY, cellSize - 3, cellSize - 3, colors[tetroid]);
}
void Tetro::DrawHoldTetroFlag(int movedX, int movedY)
{
	vector<Texture2D> miniflag = GetCellflags();
    vector<Position> tiles = GetCellPositionsHold();
    for (Position item : tiles)
    	DrawTexture(miniflag[tetroid], item.column * cellSize + movedX, item.row * cellSize + movedY, WHITE);
}

void Tetro::MoveTetro(int rows, int columns) 
{
    rowMoved += rows;
    columnMoved += columns;
}

vector<Position> Tetro::GetCellPositions()
{
    vector<Position> tiles = cells[rotated];
    vector<Position> movedTiles;
    for (Position item : tiles)
    {
        Position newPos = Position(item.row + rowMoved, item.column + columnMoved);
        movedTiles.push_back(newPos);
    }
    return movedTiles;
}
vector<Position> Tetro::GetCellPositionsHold()
{
    vector<Position> tiles = cells[0];
    vector<Position> movedTiles;
    for (Position item : tiles)
    {
        Position newPos = Position(item.row, item.column);
        movedTiles.push_back(newPos);
    }
    return movedTiles;
}

void Tetro::Rotate()
{
    rotated++;
    if (rotated == (int)cells.size())
        rotated = 0;
}

void Tetro::UndoRotation() 
{
    rotated--;
    if (rotated == -1)
        rotated = cells.size() - 1;
}
