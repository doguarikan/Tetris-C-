#include "colors.h"

const Color darkGrey = {26, 31, 40, 255};
const Color green = {47, 170, 23, 255};
const Color darkgreen = {47, 100, 23, 255};
const Color darkred = {150, 33, 75, 255};
const Color orangecountry = {226, 116, 17, 255};
const Color yellow = {237, 200, 4, 255};
const Color purple = {166, 0, 247, 255};
const Color cyan = {21, 204, 209, 255};
const Color blue = {102, 191, 255, 255};
const Color lightBlue = {59, 85, 162, 255};
const Color darkBluecountry = {44, 44, 127, 255};
const Color darkerblue = {0, 0, 128, 255};
const Color pink = {255, 102, 178, 255};
const Color darkpink = {170, 51, 88, 255};
const Color white = {220, 220, 220, 255};

vector<Color>colors;
vector<Texture2D>flags;

vector<Color> GetCellColors(int chosentheme){
	if(chosentheme == 1)
	{
		colors.push_back(darkGrey);
		colors.push_back(darkpink);
		colors.push_back(ORANGE);
		colors.push_back(VIOLET);
		colors.push_back(cyan);
		colors.push_back(white);
		colors.push_back(pink);
		colors.push_back(RED);
		colors.push_back(DARKGREEN);
		colors.push_back(purple);
		colors.push_back(MAGENTA);
		return colors;
	}	
		colors.push_back(darkGrey);
		colors.push_back(green);
		colors.push_back(darkred);
		colors.push_back(orangecountry);
		colors.push_back(yellow);
		colors.push_back(DARKBROWN);
		colors.push_back(darkpink);
		colors.push_back(darkBluecountry);
		colors.push_back(BEIGE);
		colors.push_back(darkgreen);
		colors.push_back(pink);
		return colors;
}
vector<Texture2D> GetCellflags(){
	Texture2D italy = LoadTexture("Visual/italy.png");
	Texture2D canada = LoadTexture("Visual/canada.png");
	Texture2D france = LoadTexture("Visual/france.png");
	Texture2D india = LoadTexture("Visual/india.png");
	Texture2D serbia = LoadTexture("Visual/serbia.png");
	Texture2D spain = LoadTexture("Visual/spain.png");
	Texture2D sweden = LoadTexture("Visual/sweden.png");
	Texture2D turkey = LoadTexture("Visual/turkey.png");
	Texture2D uk = LoadTexture("Visual/uk.png");
	Texture2D germany = LoadTexture("Visual/germany.png");
	Texture2D black = LoadTexture("Visual/black.png");
	flags.push_back(black);
	flags.push_back(italy);
	flags.push_back(canada);
	flags.push_back(france);
	flags.push_back(india);
	flags.push_back(serbia);
	flags.push_back(spain);	
	flags.push_back(sweden);
	flags.push_back(turkey);
	flags.push_back(uk);
	flags.push_back(germany);
	return flags;
}