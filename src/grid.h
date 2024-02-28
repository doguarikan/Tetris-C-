#pragma once
#include <vector>
#include <raylib.h>
using namespace std;
class Grid
{
	bool IsFull(int row);
    void ClearRow(int row);
    void MoveRowDown(int row, int numRows);
    int nRows;
    int nCols;
    vector<Color> colors;
	vector<Texture2D> flags;
public:
    Grid();
	int cellSize;
    void InitZero();
    void DrawGridColor();
	void DrawGridFlag();
    bool IsCellOut(int row, int column);
	bool IsCellPortal(int row, int column);
    bool IsCellEmpty(int row, int column);
    int ClearFullRows();
    int grid[20][10];
};