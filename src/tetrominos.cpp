#include "tetro.h"
#include "position.h"

class CornerTetro : public Tetro
{
public:
    CornerTetro()
    {
        tetroid = 1;
        cells[0] = {Position(0, 0), Position(1, 0), Position(1, 1)};
        cells[1] = {Position(0, 0), Position(0, 1), Position(1, 0)};
        cells[2] = {Position(0, 0), Position(0, 1), Position(1, 1)};
        cells[3] = {Position(0, 1), Position(1, 0), Position(1, 1)};
        MoveTetro(0, 4);//baslama noktalarını gosterir(sol ust kosesi 0,0 dan baslar )
    }
};

class TowerTetro : public Tetro
{
public:
    TowerTetro()
    {
        tetroid = 2;
        cells[0] = {Position(0, 0), Position(1, 0), Position(2, 0)};
        cells[1] = {Position(1, 0), Position(1, 1), Position(1, 2)};
        MoveTetro(0, 4);
    }
};

class SquareTetro : public Tetro
{
public:
    SquareTetro()
    {
        tetroid = 3;
        cells[0] = {Position(0, 0), Position(0, 1), Position(1, 0), Position(1, 1)};
        MoveTetro(0, 4);
    }
};

class DZTetro : public Tetro
{
public:
    DZTetro()
    {
        tetroid = 4;
        cells[0] = {Position(0, 0), Position(1, 0), Position(1, 1), Position(1, 2), Position(2, 2)};
        cells[1] = {Position(0, 1), Position(0, 2), Position(1, 1), Position(2, 0), Position(2, 1)};
        MoveTetro(0, 3);
    }
};

class PyramidTetro : public Tetro
{
public:
    PyramidTetro()
    {
        tetroid = 5;
        cells[0] = {Position(0, 1), Position(1, 0), Position(1, 1), Position(1, 2)};
        cells[1] = {Position(0, 1), Position(1, 1), Position(1, 2), Position(2, 1)};
        cells[2] = {Position(1, 0), Position(1, 1), Position(1, 2), Position(2, 1)};
        cells[3] = {Position(0, 1), Position(1, 0), Position(1, 1), Position(2, 1)};
        MoveTetro(0, 3);
    }
};

class ZigzagTetro : public Tetro
{
public:
    ZigzagTetro()
    {
        tetroid = 6;
        cells[0] = {Position(0, 1), Position(0, 2), Position(1, 0), Position(1, 1)};
        cells[1] = {Position(0, 1), Position(1, 1), Position(1, 2), Position(2, 2)};
        cells[2] = {Position(1, 0), Position(1, 1), Position(2, 1), Position(2, 2)};
        cells[3] = {Position(0, 1), Position(1, 0), Position(1, 1), Position(2, 0)};
        MoveTetro(0, 3);
    }
};

class PlusTetro : public Tetro
{
public:
    PlusTetro()
    {
        tetroid = 7;
        cells[0] = {Position(0, 1), Position(1, 0), Position(1, 1), Position(1, 2), Position(2,1)};
        MoveTetro(0, 3);
    }
};

class UTetro : public Tetro
{
public:
    UTetro()
    {
        tetroid = 8;
        cells[0] = {Position(0, 0), Position(0, 2), Position(1, 0), Position(1, 1), Position(1,2)};
		cells[1] = {Position(0, 1), Position(0, 2), Position(1, 1), Position(2, 1), Position(2,2)};
		cells[2] = {Position(1, 0), Position(1, 1), Position(1, 2), Position(2, 0), Position(2,2)};
		cells[3] = {Position(0, 0), Position(0, 1), Position(1, 1), Position(2, 0), Position(2,1)};
        MoveTetro(0, 3);
    }
};

class StepTetro : public Tetro
{
public:
    StepTetro()
    {
        tetroid = 9;
        cells[0] = {Position(0, 1), Position(1, 0), Position(1, 1), Position(2, 0)};
        cells[1] = {Position(0, 0), Position(0, 1), Position(1, 1), Position(1, 2)};
        cells[2] = {Position(0, 2), Position(1, 1), Position(1, 2), Position(2, 1)};
        cells[3] = {Position(1, 0), Position(1, 1), Position(2, 1), Position(2, 2)};
        MoveTetro(0, 3);
    }
};

class ArrowTetro : public Tetro
{
public:
    ArrowTetro()
    {
        tetroid = 10;
        cells[0] = {Position(0, 1), Position(1, 0), Position(1, 1), Position(1, 2), Position(2,0), Position(2,2)};
		cells[1] = {Position(0, 0), Position(0, 1), Position(1, 1), Position(1, 2), Position(2,0), Position(2,1)};
		cells[2] = {Position(0, 0), Position(0, 2), Position(1, 0), Position(1, 1), Position(1,2), Position(2,1)};
		cells[3] = {Position(0, 1), Position(0, 2), Position(1, 0), Position(1, 1), Position(2,1), Position(2,2)};
        MoveTetro(0, 3);
    }
};