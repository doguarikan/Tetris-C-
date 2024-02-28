#include <raylib.h>
#include "game.h"
#include "colors.h"
#include <iostream>

double lastUpdateTime = 0;
int chosentheme = 0;
int exitcode = 0;
int gamediff = 1;

bool IsRunned(double interval)
{
    double currentTime = GetTime();
    if (currentTime - lastUpdateTime >= interval)
    {
        lastUpdateTime = currentTime;
        return true;
    }
    return false;
}


int main()
{
    InitWindow(550, 700, "raylib Tetris");
    SetTargetFPS(60);

    Font font = LoadFontEx("Font/monogram.ttf", 64, 0, 0);
	Texture2D mainimage = LoadTexture("Visual/pngegg.png");
	Texture2D earth = LoadTexture("Visual/earth.png");
	
	menu:
	while(!IsKeyPressed(KEY_ENTER))
	{
		BeginDrawing();
		ClearBackground(darkGrey);
		DrawTextEx(font,"TETRIS",{190,15},55,2,WHITE);
		DrawTexture(mainimage,120,120,WHITE);
		DrawTextEx(font,"Press Enter To Play The Game",{60,380},27,2,WHITE);
		DrawTextEx(font,"Press 'T' to change theme",{60,420},27,2,WHITE);
		DrawTextEx(font,"Press 'D' to change difficulty",{60,460},27,2,WHITE);
		DrawTextEx(font,"Press 'C' see controls",{60,500},27,2,WHITE);
		DrawTextEx(font,"Press 'ESC' to quit",{60,540},27,2,WHITE);
		DrawTextEx(font,"Dogu Baha Arikan",{300,650},25,2,BEIGE);

		EndDrawing();
		if(IsKeyPressed(KEY_T))
			goto themes;
		else if(IsKeyPressed(KEY_D))
			goto diff;
		else if(IsKeyPressed(KEY_C))
			goto control;
		else if(IsKeyPressed(KEY_ESCAPE))
		{
			EndDrawing();
			CloseWindow();
			exitcode = 1;
			goto exit;
		}
		else if(IsKeyPressed(KEY_ENTER))
			goto game;
	}

	themes:
	while(!IsKeyPressed(KEY_ENTER))
	{
		BeginDrawing();
		ClearBackground(darkGrey);
		DrawTextEx(font,"THEMES",{190,15},53,2,WHITE);
		DrawTextEx(font,"A - GREEN",{60,220},26,2,WHITE);
		DrawRectangle(80,120,80,80,green);
		DrawTextEx(font,"B - FLAGS",{360,220},26,2,WHITE);
		DrawTexture(earth,380,120,WHITE);
		DrawTextEx(font,"C - GRAY",{60,420},26,2,WHITE);
		DrawRectangle(80,320,80,80,GRAY);
		DrawTextEx(font,"press the letter to choose theme",{20,540},25,2,green);
		DrawTextEx(font,"press esc to return menu",{210,600},25,2,RED);
		int keypressed = GetKeyPressed();
		if(keypressed == KEY_A)
			chosentheme = 1;

		if(keypressed == KEY_B)
			chosentheme = 2;

		if(keypressed == KEY_C)
			chosentheme = 0;

		if(keypressed == KEY_ESCAPE)
			goto menu;
		EndDrawing();
	}

	diff:
	while(!IsKeyPressed(KEY_ENTER))
	{
		BeginDrawing();
		ClearBackground(darkGrey);
		DrawTextEx(font,"DIFFICULTY",{135,15},55,2,WHITE);
		DrawTextEx(font,"Press 'E' to chose easy mode",{35,140},30,1,GREEN);
		DrawTextEx(font,"Press 'N' to chose normal mode",{35,240},30,1,ORANGE);
		DrawTextEx(font,"Press 'H' to chose hard mode",{35,340},30,1,RED);

		DrawTextEx(font,"press esc to return menu",{210,600},25,2,RED);
		if(IsKeyPressed(KEY_E))
		{
			gamediff = 0;
		}
		if(IsKeyPressed(KEY_N))
		{
			gamediff = 1;	
		}
		if(IsKeyPressed(KEY_H))
		{
			gamediff = 2;
		}
		if(IsKeyPressed(KEY_ESCAPE))
			goto menu;
		EndDrawing();
	}

	control:
	while(!IsKeyPressed(KEY_ENTER))
	{
		BeginDrawing();
		ClearBackground(darkGrey);
		DrawTextEx(font,"CONTROLS",{155,15},55,2,WHITE);
		DrawTextEx(font,"-Left Right Arrows To Move Tetromino Left Right",{13,160},22,1,WHITE);
		DrawTextEx(font,"-Esc To Close Game",{13,200},22,1,WHITE);
		DrawTextEx(font,"-Up Arrow To Rotate Tetromino",{13,240},22,1,WHITE);
		DrawTextEx(font,"-Down Arrow To Move Tetromino Down",{13,280},22,1,WHITE);
		DrawTextEx(font,"-L Shift To Hold Tetromino",{13,320},22,1,WHITE);
		DrawTextEx(font,"-Space To Release Tetromino",{13,360},22,1,WHITE);
		DrawTextEx(font,"-Red Grid Is Portal And Pushes ",{13,400},22,1,WHITE);
		DrawTextEx(font,"Tetromino 5 Grid Left And 2 Grid Down",{13,420},22,1,WHITE);
		DrawTextEx(font,"press esc to return menu",{210,600},25,2,RED);
		if(IsKeyPressed(KEY_ESCAPE))
			goto menu;
		EndDrawing();
	}
	exit: //expectation segment yediği için buraya atladık, en sona atlarsak game oluşmadığı için hata veriyo
	game:
    Game game = Game();
	if(exitcode == 1)
	{
		goto end;
	}
    while (WindowShouldClose() == false) 
    {

        game.HandleInput();

        if (gamediff==0 && IsRunned(0.6))
            game.TetroDown();
		
		if (gamediff==1 && IsRunned(0.4))
            game.TetroDown();
		
		if (gamediff==2 && IsRunned(0.2))
            game.TetroDown();

        BeginDrawing();
		if(chosentheme == 0)
        {
			ClearBackground(GRAY); 
			DrawRectangleRounded({340, 55, 170, 60}, 0.3, 6, darkerblue);
			DrawRectangleRounded({340, 175, 170, 180}, 0.3, 6, darkerblue);
			DrawRectangleRounded({340, 400, 170, 180}, 0.3, 6, darkerblue);
			UpdateMusicStream(game.music);
		}
		else if(chosentheme == 1)
		{
			ClearBackground(green);
			DrawRectangleRounded({340, 55, 170, 60}, 0.3, 6, yellow);
			DrawRectangleRounded({340, 175, 170, 180}, 0.3, 6, yellow);
			DrawRectangleRounded({340, 400, 170, 180}, 0.3, 6, yellow);
			UpdateMusicStream(game.music2);
		}
		else if(chosentheme == 2)
		{
			ClearBackground(darkBluecountry);
			DrawRectangleRounded({340, 55, 170, 60}, 0.3, 6, orangecountry);
			DrawRectangleRounded({340, 175, 170, 180}, 0.3, 6, orangecountry);
			DrawRectangleRounded({340, 400, 170, 180}, 0.3, 6, orangecountry);
			UpdateMusicStream(game.music3);
		}
		DrawTextEx(font, "Score", {380, 15}, 38, 2, WHITE);
        DrawTextEx(font, "Next", {390, 140}, 38, 2, WHITE);
		DrawTextEx(font, "Hold Piece", {335, 365}, 36, 2, WHITE);

        
		if (game.gameOver)
		{
			if(game.score>game.GetHighScore())
			{
				game.SaveHighScore();
			}
			DrawTextEx(font, "GAME OVER", {340, 600}, 40, 2, RED);
		}
				
		DrawTextEx(font,"HIGH SCORE",{20,650},35,1,BLACK);
		char highscore[15];
		sprintf(highscore,"%d", game.GetHighScore());
		DrawText(highscore, 200, 650,35,BLACK);
            

        char scoreText[15];
        sprintf(scoreText, "%d", game.score);
        DrawTextEx(font, scoreText, {385, 65}, 38, 2, WHITE);
        
        game.Draw(chosentheme);
        EndDrawing(); 
    }
	
    CloseWindow(); 
	end: 
	return 0;
}