//Include required libraries for draw Library, Header files, and iostream for output just in case
#include <iostream>
#include <cstring>
#include "sfwdraw.h"
#include "Header.h"


int main()
{
	//Create the window (set to the const width/height of 800x600) and give the window a name
	sfw::initContext(SCREEN_WIDTH, SCREEN_HEIGHT, "TESTING!");

	//Create the variables for Game Borders, Player and AI Paddle, as well as the Ball
	Player playerPaddleOne{30, 300, 100};
	Player playerPaddleTwo{ 770, 300, 100 };
	Ball starterBall{ SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2, 10 };
	Velocity ballVelocity{ 100, 40 };

	//Initialize Game State Loop
	while (sfw::stepContext())
	{
		//Draw the Borders using the screen width/height const, these will be used for collision detection
		//Bottom Border
		sfw::drawLine(SCREEN_WIDTH - 795, SCREEN_HEIGHT - 5, SCREEN_WIDTH - 5, SCREEN_HEIGHT - 5);
		//Top Border
		sfw::drawLine(SCREEN_WIDTH - 795, SCREEN_HEIGHT - 595, SCREEN_WIDTH - 5, SCREEN_HEIGHT - 595);
		//Right Border
		sfw::drawLine(SCREEN_WIDTH - 5, SCREEN_HEIGHT - 595, SCREEN_WIDTH - 5, SCREEN_HEIGHT - 5);
		//Left Border
		sfw::drawLine(SCREEN_WIDTH - 795, SCREEN_HEIGHT - 595, SCREEN_WIDTH - 795, SCREEN_HEIGHT - 5);

		//Draw the Player Paddles to screen
		sfw::drawLine(playerPaddleOne.xPos, playerPaddleOne.yPos, playerPaddleOne.xPos, playerPaddleOne.yPos + playerPaddleOne.yWidth);

		sfw::drawLine(playerPaddleTwo.xPos, playerPaddleTwo.yPos, playerPaddleTwo.xPos, playerPaddleTwo.yPos + playerPaddleTwo.yWidth);

		//Allow control of Player Paddles
		if (sfw::getKey('w')) playerPaddleOne.yPos -= 300 * sfw::getDeltaTime();
		if (sfw::getKey('s')) playerPaddleOne.yPos += 300 * sfw::getDeltaTime();

		if (sfw::getKey('i')) playerPaddleTwo.yPos -= 300 * sfw::getDeltaTime();
		if (sfw::getKey('k')) playerPaddleTwo.yPos += 300 * sfw::getDeltaTime();
		
		//Draw the Ball
		sfw::drawCircle(starterBall.xPos, starterBall.yPos, starterBall.radius);
		starterBall.xPos -= ballVelocity.xPos * sfw::getDeltaTime();
		starterBall.yPos -= ballVelocity.yPos * sfw::getDeltaTime();

		//Calls on functions for Collision detection of the Ball with the Borders and Paddles
		if (playerPaddleOne.yPos + playerPaddleOne.yWidth >= 595)
		{
			playerPaddleOne.yPos = 595 - playerPaddleOne.yWidth;
		}
		if (playerPaddleOne.yPos <= 5)
		{
			playerPaddleOne.yPos = 5;
		}
		if (playerPaddleTwo.yPos + playerPaddleTwo.yWidth >= 595)
		{
			playerPaddleTwo.yPos = 595 - playerPaddleTwo.yWidth;
		}
		if (playerPaddleTwo.yPos <= 5)
		{
			playerPaddleTwo.yPos = 5;
		}
		if (paddleCollisionLeft(starterBall.xPos, starterBall.yPos, starterBall.radius, playerPaddleOne.xPos, playerPaddleOne.yPos, playerPaddleOne.yWidth) == true)
		{
			ballVelocity.xPos = -ballVelocity.xPos;
		}
		if (paddleCollisionRight(starterBall.xPos, starterBall.yPos, starterBall.radius, playerPaddleTwo.xPos, playerPaddleTwo.yPos, playerPaddleTwo.yWidth) == true)
		{
			ballVelocity.xPos = -ballVelocity.xPos;
		}
		if (wallCollisionTop(5, 5, 795, starterBall.xPos, starterBall.yPos, starterBall.radius) == true)
		{
			ballVelocity.yPos = -ballVelocity.yPos;
		}

		if (wallCollisionBot(5, 595, 795, starterBall.xPos, starterBall.yPos, starterBall.radius) == true)
		{
			ballVelocity.yPos = -ballVelocity.yPos;
		}
	}
	//Shuts down OpenGL window
	sfw::termContext;
}
