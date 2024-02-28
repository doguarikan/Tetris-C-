#include "game.h"
#include "grid.h"
#include "tetro.h"
#include <random>
#include <fstream>

using namespace std;

extern const int chosentheme;
extern const int gamediff;
int isholded = 0;
Tetro holdedTetro; 

Game::Game()
{
    grid = Grid();
    tetros = GetAllTetro();
    currentTetro = RandomTetro();
    nextTetro = RandomTetro();
    gameOver = false;
    score = 0;
    InitAudioDevice();
    music = LoadMusicStream("Sounds/music.mp3");
	music2 = LoadMusicStream("Sounds/music2.mp3");
	music3 = LoadMusicStream("Sounds/music3.mp3");
    PlayMusicStream(music);
	PlayMusicStream(music2);
	PlayMusicStream(music3);
    rotateSound = LoadSound("Sounds/rotate.mp3");
    clearSound = LoadSound("Sounds/clear.mp3");
}

Game::~Game()
{
    UnloadSound(rotateSound);
    UnloadSound(clearSound);
    UnloadMusicStream(music);
    CloseAudioDevice();
}

Tetro Game::RandomTetro()
{
    int randomIndex = rand() % tetros.size();
    Tetro tetromino = tetros[randomIndex];
    return tetromino;
}

vector<Tetro> Game::GetAllTetro() 
{
    return {CornerTetro(), TowerTetro(), SquareTetro(), DZTetro() ,PyramidTetro() ,ZigzagTetro() ,PlusTetro(), UTetro(), StepTetro(), ArrowTetro()};
}

void Game::Draw(int chosentheme)
{
	if (chosentheme == 0 || chosentheme == 1)
	{
    	grid.DrawGridColor();
		currentTetro.DrawTetroColor(11, 11);
        if(TetroPortal())
			Portal();
		nextTetro.DrawTetroColor(281, 240);
		if(isholded == 1)
			holdedTetro.DrawHoldTetroColor(387,478);
    }
	else if(chosentheme == 2)
	{
		grid.DrawGridFlag();
		currentTetro.DrawTetroFlag(11, 11);
        nextTetro.DrawTetroFlag(281, 240);
		if(isholded == 1)
			holdedTetro.DrawHoldTetroFlag(387,478);
	}
}

void Game::HandleInput()
{
    int keyPressed = GetKeyPressed();
    if (gameOver && keyPressed != 0)
    {
        gameOver = false;
        Reset();
    }
    switch (keyPressed)
    {
    case KEY_LEFT:
        MoveLeft();
        break;
    case KEY_RIGHT:
        MoveRight();
        break;
    case KEY_DOWN:
        TetroDown();
        break;
    case KEY_UP:
        TurnTetro();
        break;
	case KEY_LEFT_SHIFT:
		if(isholded==0)
			HoldTetro();
		break;
	case KEY_SPACE:
		if(isholded == 1)
			ReleaseTetro();
		break;
    }
}

void Game::MoveLeft()
{
    if (!gameOver)
    {
        currentTetro.MoveTetro(0, -1);
        if (TetroNotFit() || TetroOut())
			currentTetro.MoveTetro(0,1);
	}
}

void Game::MoveRight()
{
    if (!gameOver)
    {
        currentTetro.MoveTetro(0, 1);
        if (TetroNotFit() || TetroOut())
			currentTetro.MoveTetro(0,-1);
	}
}

void Game::TetroDown()
{
    if (!gameOver)
    {
        currentTetro.MoveTetro(1, 0);
        if (TetroOut() || TetroNotFit())
        {
            currentTetro.MoveTetro(-1, 0);
            LockTetro();
        }
    }
}

void Game::Portal()
{
	currentTetro.MoveTetro(2,-5);
	if(TetroNotFit() || TetroOut())
		currentTetro.MoveTetro(-2,5);
}

void Game::HoldTetro()
{
	holdedTetro = currentTetro;
	isholded = 1;
	currentTetro = nextTetro;
	nextTetro = RandomTetro();
}

void Game::ReleaseTetro()
{
	isholded = 2;
	currentTetro = holdedTetro;
	currentTetro.columnMoved = 3;
	currentTetro.rowMoved = 0;
}

bool Game::TetroOut()
{
    vector<Position> tiles = currentTetro.GetCellPositions();
    for (Position item : tiles)
    {
        if (grid.IsCellOut(item.row, item.column))
            return true;
    }
    return false;
}

bool Game::TetroPortal()
{
    vector<Position> tiles = currentTetro.GetCellPositions();
    for (Position item : tiles)
    {
        if (grid.IsCellPortal(item.row, item.column))
            return true;
    }
    return false;
}

void Game::TurnTetro()
{
    if (!gameOver)
    {
        currentTetro.Rotate();
        if (TetroOut() || TetroNotFit())
            currentTetro.UndoRotation();
        else
            PlaySound(rotateSound);
    }
}

void Game::LockTetro()
{
    vector<Position> tiles = currentTetro.GetCellPositions();
    for (Position item : tiles)
        grid.grid[item.row][item.column] = currentTetro.tetroid;

    currentTetro = nextTetro;
    if (TetroNotFit())
        gameOver = true;

    nextTetro = RandomTetro();
    int rowsCleared = grid.ClearFullRows();
    if (rowsCleared > 0)
    {
        PlaySound(clearSound);
        UpdateScore(rowsCleared);
    }
}

bool Game::TetroNotFit()
{
    vector<Position> tiles = currentTetro.GetCellPositions();
    for (Position item : tiles)
    {
        if (grid.IsCellEmpty(item.row, item.column) == false)
            return true;
    }
    return false;
}

void Game::Reset() // reset atar
{
    grid.InitZero(); 
    tetros = GetAllTetro(); 
    currentTetro = RandomTetro(); 
    nextTetro = RandomTetro(); 
    score = 0;
}

void Game::SaveHighScore()
{
	std::ofstream file;
    file.open("highscore.txt");
    file << score;
    file.close();
}

int Game::GetHighScore() {
    std::ifstream file;
    int highscore = 0;
    file.open("highscore.txt");
    if (file.is_open()) {
        file >> highscore;
    }
    file.close();
    return highscore;
}

void Game::UpdateScore(int clearedLines)
{
	int one = 200;
	int two = 600;
	int three = 1000;

	if(gamediff == 0)
	{
		one = 100;
		two = 300;
		three = 500;
	}
	else if(gamediff == 2)
	{
		one = 300;
		two = 900;
		three = 1500;
	}
    switch (clearedLines)
    {
    case 1:
        score += one;
        break;
    case 2:
        score += two;
        break;
    case 3:
        score += three;
        break;
    default:
        break;
    }
}

/*void Game::LeftToRight()
{
	if(TetroNotFit())
		currentTetro.MoveTetro(0,1);
	else if(TetroOut() || TetroNotFit())
	{
		currentTetro.MoveTetro(0,10);
		while(TetroOut()|| TetroNotFit())
			currentTetro.MoveTetro(0,-1);
	}

}*/

/*void Game::RightToLeft()
{
	if(TetroNotFit())
	{
		currentTetro.MoveTetro(0,-1);
	}
	else if(TetroOut() || TetroNotFit())
	{
		currentTetro.MoveTetro(0,-10);
		while(TetroOut() || TetroNotFit())
			currentTetro.MoveTetro(0,1);
	}

}*/
