#pragma once
#include <raylib.h>
#include <vector>
using namespace std;

extern const Color darkGrey;
extern const Color green;
extern const Color darkgreen;
extern const Color darkred;
extern const Color orangecountry;
extern const Color yellow;
extern const Color purple;
extern const Color cyan;
extern const Color blue;
extern const Color darkerblue;
extern const Color lightBlue;
extern const Color darkBluecountry;
extern const Color pink;
extern const Color darkpink;
extern const Color white;

vector<Color> GetCellColors(int chosentheme);
vector<Texture2D> GetCellflags();