#include "grid.h"
#include <iostream>
#include "colors.h"

extern int chosentheme;


Grid::Grid()
{
    nRows = 20;
    nCols = 10;
	cellSize =  30;
    InitZero();
    colors = GetCellColors(chosentheme);
	flags = GetCellflags();
}

void Grid::InitZero() 
{
    for (int row = 0; row < nRows; row++)
    {
        for (int column = 0; column < nCols; column++)
            grid[row][column] = 0;
    }
}

void Grid::DrawGridFlag() 
{

    for (int row = 0; row < nRows; row++)
    {
        for (int column = 0; column < nCols; column++)
        {
            int cellValue = grid[row][column]; 
			DrawTexture(flags[cellValue],column * cellSize + 11, row * cellSize + 11,WHITE);
		}
    }
}

void Grid::DrawGridColor() 
{

    for (int row = 0; row < nRows; row++)
    {
        for (int column = 0; column < nCols; column++)
        {
            int cellValue = grid[row][column]; 
            DrawRectangle(column * cellSize + 11, row * cellSize + 11, cellSize - 1, cellSize - 1, colors[cellValue]);
		}
    }
	DrawRectangle(8 * cellSize + 11, 4 * cellSize + 11, cellSize - 2, cellSize - 2, RED);
}

bool Grid::IsCellOut(int row, int column)
{
    if (row >= 0 && row < nRows && column >= 0 && column < nCols)
        return false;

    return true;
}

bool Grid::IsCellPortal(int row, int column)
{
    if (row == 4 && column == 8)
        return true;

    return false;
}

bool Grid::IsCellEmpty(int row, int column)
{
    if (grid[row][column] == 0)
        return true;

    return false;
}

int Grid::ClearFullRows()
{
    int completed = 0;
    for (int row = nRows - 1; row >= 0; row--)
    {
        if (IsFull(row))
        {
            ClearRow(row);
            completed++;
        }
        else if (completed > 0)
            MoveRowDown(row, completed);

    }
    return completed;
}

bool Grid::IsFull(int row)
{
    for (int column = 0; column < nCols; column++)
    {
        if (grid[row][column] == 0)
            return false;
    }
    return true;
}

void Grid::ClearRow(int row)
{
    for (int column = 0; column < nCols; column++)
        grid[row][column] = 0;
}

void Grid::MoveRowDown(int row, int numRows)
{
    for (int column = 0; column < nCols; column++)
    {
        grid[row + numRows][column] = grid[row][column];
        grid[row][column] = 0;
    }
}
