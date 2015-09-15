#include "Header.h"

//Collision Function for Paddle and Ball
bool paddleCollisionLeft(float xBall, float yBall, float rBall, float xPaddle, float yPaddle, float hPaddle)
{
	//Helped by Terry Nguyen: Exits function if the ball is already behind the paddle
	if (xBall < xPaddle - 10)
	{
		return false;
	}

	//Checks if the ball collides with the Paddle
	if (xBall - (rBall / 2) - 3 <= xPaddle && yBall - (rBall / 2) - 3 >= yPaddle && yBall <= (yPaddle + hPaddle))
		return true;

}

bool paddleCollisionRight(float xBall, float yBall, float rBall, float xPaddle, float yPaddle, float hPaddle)
{
	//Helped by Terry Nguyen: Exits function if the ball is already behind the paddle
	if (xBall > xPaddle + 10)
	{
		return false;
	}

	//Checks if the ball collides with the Paddle
	if (xBall + (rBall / 2) + 3 >= xPaddle && yBall + (rBall / 2) + 3 >= yPaddle && yBall <= (yPaddle + hPaddle))
		return true;

}

bool wallCollisionTop(float x1Wall, float yWall, float x2Wall, float xBall, float yBall, float rBall)
{
	if (xBall >= x1Wall && xBall <= x2Wall)
	{
		if (yBall - (rBall / 2) - 3 <= yWall)
			return true;
	}
}

bool wallCollisionBot(float x1Wall, float yWall, float x2Wall, float xBall, float yBall, float rBall)
{
	if (xBall >= x1Wall && xBall <= x2Wall)
	{
		if (yBall + (rBall / 2) + 3 >= yWall)
			return true;
	}
}