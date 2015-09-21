//Include required libraries for draw Library, Header files, and iostream for output just in case
#include <iostream>
#include <cstring>
#include "sfwdraw.h"
#include "Header.h"


int main()
{
	//Create the variables for Game Borders, Player and AI Paddle, as well as the Ball
	Player playerPaddleOne{30, 300, 100, 0};
	Player playerPaddleTwo{ 770, 300, 100, 0 };
	Ball starterBall{ SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2, 10 };
	Velocity ballVelocity{};
	char playerChoice = 'o';

	std::cout << "Welcome to my basic Pong game!" << std::endl;
	system("pause");

	//Create the window (set to the const width/height of 800x600) and give the window a name
	sfw::initContext(SCREEN_WIDTH, SCREEN_HEIGHT, "Corgii Pong");

	//Initialize Game State Loop
	while (sfw::stepContext())
	{
		if (sfw::getKey(' '))
		{
			ballVelocity.xPos = 250;
			ballVelocity.yPos = rand() % 50;
		}
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

		//Prevents Paddles from going off screen by forcing their position to the borders
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

		//Calls on functions for Ball Collision with Paddles and Top/Bottom Walls
		if (paddleCollisionLeft(starterBall.xPos, starterBall.yPos, starterBall.radius, playerPaddleOne.xPos, playerPaddleOne.yPos, playerPaddleOne.yWidth) == true)
		{
			starterBall.xPos += 5;
			ballVelocity.xPos = -ballVelocity.xPos;
		}
		if (paddleCollisionRight(starterBall.xPos, starterBall.yPos, starterBall.radius, playerPaddleTwo.xPos, playerPaddleTwo.yPos, playerPaddleTwo.yWidth) == true)
		{
			starterBall.xPos -= 5;
			ballVelocity.xPos = -ballVelocity.xPos;
		}
		if (wallCollisionTop(5, 5, 795, starterBall.xPos, starterBall.yPos, starterBall.radius) == true)
		{
			starterBall.yPos += 5;
			ballVelocity.yPos = -ballVelocity.yPos;
		}

		if (wallCollisionBot(5, 595, 795, starterBall.xPos, starterBall.yPos, starterBall.radius) == true)
		{
			starterBall.yPos -= 5;
			ballVelocity.yPos = -ballVelocity.yPos;
		}

		//Checks to see if the ball scores and increases the players score by 1
		if (starterBall.xPos >= 795)
		{
			++playerPaddleOne.pScore;
			starterBall.xPos = SCREEN_WIDTH / 2;
			std::cout << "Player One Score: " << playerPaddleOne.pScore << std::endl;
			std::cout << "Player Two Score: " << playerPaddleTwo.pScore << std::endl;

			//Ends game if player one has 3 points and gives choice of playing again or quitting
			if (playerPaddleOne.pScore == 3)
			{
				std::cout << "Player One WINS!" << std::endl;
				system("pause");
				break;
			}
		}
		if (starterBall.xPos <= 5)
		{
			++playerPaddleTwo.pScore;
			starterBall.xPos = SCREEN_WIDTH / 2;
			std::cout << "Player One Score: " << playerPaddleOne.pScore << std::endl;
			std::cout << "Player Two Score: " << playerPaddleTwo.pScore << std::endl;

			//Ends game if player one has 3 points and gives choice of playing again or quitting
			if (playerPaddleTwo.pScore == 3)
			{
				std::cout << "Player Two WINS!" << std::endl;
				system("pause");
				break;
			}
		}
	}
	sfw::termContext;
}
