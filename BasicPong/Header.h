#pragma once
#include "sfwdraw.h"

//Screen constant, Allows the Window to always be drawn at the same size
const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 600;

//Struct for creating the Ball, made to allow for multiple balls to be drawn at
//the same size
struct Ball
{
	float xPos;
	float yPos;
	float radius;
};

//Player paddle struct to allow for multiple paddles to be created easily
struct Player
{
	float xPos;
	float yPos;
	float yWidth;
	int pScore;
};

struct Velocity
{
	float xPos;
	float yPos;
};

bool paddleCollisionLeft(float xBall, float yBall, float rBall, float xPaddle, float yPaddle, float hPaddle);

bool paddleCollisionRight(float xBall, float yBall, float rBall, float xPaddle, float yPaddle, float hPaddle);

bool wallCollisionTop(float x1Wall, float yWall, float x2Wall, float xBall, float yBall, float rBall);

bool wallCollisionBot(float x1Wall, float yWall, float x2Wall, float xBall, float yBall, float rBall);