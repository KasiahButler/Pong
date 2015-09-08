#include <iostream>
#include <cstring>
#include "sfwdraw.h"
#include "Header.h"

int main()
{
	sfw::initContext(SCREEN_WIDTH, SCREEN_HEIGHT, "TESTING!");
	float xPos = 300, yPos = 30;
	int xWidth = 60, yWidth = 5;

	while (sfw::stepContext())
	{
		sfw::drawLine(xPos, yPos, xPos + xWidth, yPos);
		sfw::drawLine(xPos , yPos - yWidth, xPos + xWidth, yPos - yWidth);
		sfw::drawLine(xPos, yPos, xPos, yPos - yWidth);
		sfw::drawLine(xPos + xWidth, yPos, xPos + xWidth, yPos - yWidth);

		if (sfw::getKey('A')) xPos -= 10;
		if (sfw::getKey('D')) xPos += 10;

		sfw::drawCircle(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2, 10);
		
	}
	sfw::termContext;
}
