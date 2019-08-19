# include<iostream>//c++ library access
# include "iGraphics.h"      //igraphics framework
using namespace std; //used to solve problems regarding same name of function
#define windowWidth 1200  
#define windowHeight 650
#define yMargin 50
#define totalBlocks 50



struct blockStruc
{
	int x, y;
	int dx = 100;
	int dy = 20;
	bool show = true;
};
blockStruc blocks[totalBlocks];

int red = 255, green = 255, blue = 255;
int rx = 0, ry = 0, dx = 1200, dy = 650;
int xBall = (int)windowWidth / 2, yBall = yMargin, dxBall = 7, dyBall = 5, rediusBall = 10;


int xBar = xBall - 50;
int yBar = yBall - 20;
int dxBar = 100, dyBar = 10;

bool isStarted = false;

void restarGame();
void ballMoving();
void creatBlocks();

void ballMoving()
{
	if (isStarted)
	{
		xBall += dxBall;
		yBall += dyBall;
		if (xBall >= windowWidth || xBall <= 0)
			dxBall *= (-1);
		if (yBall >= windowHeight || yBall <= 0)
			dyBall *= (-1);
		
		//////////////////////////////////////////
		for (int i = 0; i < totalBlocks; i++)
		{
			if (blocks[i].show)
			{
				if (xBall >= blocks[i].x && xBall <= blocks[i].x + blocks[i].dx)
				{
					if (yBall >= blocks[i].y && yBall <= blocks[i].y + blocks[i].dy)
					{
						dyBall *= (-1);
						blocks[i].show = false;
					}
				}
				else if (yBall >= blocks[i].y && yBall <= blocks[i].y + blocks[i].dy)
				{
					if (xBall >= blocks[i].x && xBall <= blocks[i].x + blocks[i].dx)
					{
						dxBall *= (-1);
						blocks[i].show = false;
					}
				}
			}
		}

		//
		if (xBall >= xBar && xBall <= xBar + dxBar && yBall >= yBar && yBall <= yBar + dyBar)
		{
			dyBall *= (-1);
		}
		else
		{
			if (yBall < yBar)
			{
				restarGame();
			}
		}
		//

	}
}

void restarGame()
{
	//creatBlocks();
	xBall = (int)windowWidth / 2;
	yBall = yMargin;
	dxBall = 7;
	dyBall = 5;
	xBar = xBall - 50;
	yBar = yBall - 20;

	for (int i = 0; i < totalBlocks; i++)
	{
		blocks[i].show = true;
	}

	isStarted = false;

}

void creatBlocks()
{
	int x = 100;
	int y = 450;
	for (int i = 0; i < totalBlocks; i++)
	{
		blocks[i].x = x;
		blocks[i].y = y;
		x += 100;
		if (x > 1000)
		{
			x = 100;
			y += 20;
		}
	}
}
void iDraw()
{
	//place your drawing codes here
	iClear();
	//iRectangle(rx,ry,dx,dy);
	iSetColor(red, green, blue);
	iFilledRectangle(rx, ry, dx, dy);
	iSetColor(0, 0, 0);
	iFilledCircle(xBall, yBall, rediusBall, 1000);
	iSetColor(0, 0, 0);
	iFilledRectangle(xBar, yBar, dxBar, dyBar);

	iText(10, windowHeight - 20, "Press Space Bar to Start",GLUT_BITMAP_HELVETICA_18);

	for (int i = 0; i < totalBlocks; i++)
	{
		if (blocks[i].show)
		{
			iSetColor(0, 0, 0);
			iRectangle(blocks[i].x, blocks[i].y, blocks[i].dx, blocks[i].dy);
			iSetColor(255, 165, 0);
			iFilledRectangle(blocks[i].x + 1, blocks[i].y + 1, blocks[i].dx, blocks[i].dy);
		}
	}

}

/*
function iMouseMove() is called when the user presses and drags the mouse.
(mx, my) is the position where the mouse pointer is.
*/
void iMouseMove(int mx, int my)
{
	//place your codes here
}

/*
function iMouse() is called when the user presses/releases the mouse.
(mx, my) is the position where the mouse pointer is.
*/
void iMouse(int button, int state, int mx, int my)
{
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		//place your codes here
	}
	if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
	{
		//place your codes here
	}
}
/*iPassiveMouseMove is called to detect and use
the mouse point without pressing any button */

void iPassiveMouseMove(int mx, int my)
{
	//place your code here

	//mposx = mx;
	//mposy = my;
	if (mx == 2){}        /*Something to do with mx*/
	else if (my == 2){}   /*Something to do with my*/

}

/*
function iKeyboard() is called whenever the user hits a key in keyboard.
key- holds the ASCII value of the key pressed.
*/
void iKeyboard(unsigned char key)
{
	if (key == ' ')
	{
		if (!isStarted)
		{
			isStarted = true;
		}

	}
	//place your codes for other keys here
}


void iSpecialKeyboard(unsigned char key)
{

	if (key == GLUT_KEY_END)
	{
		exit(0);
	}
	else if (key == GLUT_KEY_LEFT)
	{
		if (xBar > 0)
		{
			xBar -= 10;
			if (!isStarted)
			{
				xBall -= 10;
			}
		}


	}
	else if (key == GLUT_KEY_RIGHT)
	{
		if (xBar < windowWidth - dxBar)
		{
			xBar += 10;
			if (!isStarted)
			{
				xBall += 10;
			}
		}

	}
	//place your codes for other keys here
}

//
int main()
{
	//place your own initialization codes here.
	creatBlocks();
	iSetTimer(20, ballMoving);
	PlaySound("music\\dxball.wav",NULL,SND_LOOP|SND_ASYNC);
	iInitialize(windowWidth, windowHeight, "DX BALL");
	return 0;
}
