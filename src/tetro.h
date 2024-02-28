#pragma once
#include <vector>
#include <map>
#include "position.h"
#include "colors.h"
using namespace std;
class Tetro
{
	int cellSize;
    int rotated;
    vector<Color> colors;
public:
    Tetro();
	int rowMoved;
    int columnMoved;
	int tetroid;
    void DrawTetroColor(int movedX, int movedY);
	void DrawHoldTetroColor(int movedX, int movedY);
	void DrawTetroFlag(int movedX, int movedY);
	void DrawHoldTetroFlag(int movedX, int movedY);
    void MoveTetro(int rows, int columns);
    vector<Position> GetCellPositions();
	vector<Position> GetCellPositionsHold();
    void Rotate();
    void UndoRotation();
    std::map<int,vector<Position>> cells;
};