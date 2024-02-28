#pragma once
#include "grid.h"
#include "tetrominos.cpp"
#include <vector>
using namespace std;
class Game
{
	void MoveLeft();
    void MoveRight();
	//void LeftToRight();
	//void RightToLeft();
	void Portal();
	void HoldTetro();
	void ReleaseTetro();
    Tetro RandomTetro();
    vector<Tetro> GetAllTetro(); 
    bool TetroOut();
	bool TetroPortal();
    void TurnTetro();
    void LockTetro();
    bool TetroNotFit();
    void Reset();
    void UpdateScore(int clearedLines);
    Grid grid;
    vector<Tetro> tetros;
    Tetro currentTetro;
    Tetro nextTetro;
    Sound rotateSound;
    Sound clearSound;
public:
    Game();
    ~Game();
    void Draw(int chosentheme);
    void HandleInput();
    void TetroDown();
	void SaveHighScore();
	int GetHighScore();
    bool gameOver;
    int score;
    Music music;
	Music music2;
	Music music3;
};