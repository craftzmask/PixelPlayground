/****************************************************************************************** 
 *	Chili DirectX Framework Version 16.07.20											  *	
 *	Game.cpp																			  *
 *	Copyright 2016 PlanetChili.net <http://www.planetchili.net>							  *
 *																						  *
 *	This file is part of The Chili DirectX Framework.									  *
 *																						  *
 *	The Chili DirectX Framework is free software: you can redistribute it and/or modify	  *
 *	it under the terms of the GNU General Public License as published by				  *
 *	the Free Software Foundation, either version 3 of the License, or					  *
 *	(at your option) any later version.													  *
 *																						  *
 *	The Chili DirectX Framework is distributed in the hope that it will be useful,		  *
 *	but WITHOUT ANY WARRANTY; without even the implied warranty of						  *
 *	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the						  *
 *	GNU General Public License for more details.										  *
 *																						  *
 *	You should have received a copy of the GNU General Public License					  *
 *	along with The Chili DirectX Framework.  If not, see <http://www.gnu.org/licenses/>.  *
 ******************************************************************************************/
#include "MainWindow.h"
#include "Game.h"

Game::Game( MainWindow& wnd )
	:
	wnd( wnd ),
	gfx( wnd )
{
}

void Game::Go()
{
	gfx.BeginFrame();	
	UpdateModel();
	ComposeFrame();
	gfx.EndFrame();
}

void Game::UpdateModel()
{
	if (wnd.kbd.KeyIsPressed(VK_UP))
	{
		y = y - 3;
	}

	if (wnd.kbd.KeyIsPressed(VK_DOWN))
	{
		y = y + 3;
	}

	if (wnd.kbd.KeyIsPressed(VK_LEFT))
	{
		x = x - 3;
	}

	if (wnd.kbd.KeyIsPressed(VK_RIGHT))
	{
		x = x + 3;
	}


	if (wnd.kbd.KeyIsPressed('W'))
	{
		--height;
	}

	if (wnd.kbd.KeyIsPressed('S'))
	{
		++height;
	}

	if (wnd.kbd.KeyIsPressed('A'))
	{
		--width;
	}

	if (wnd.kbd.KeyIsPressed('D'))
	{
		++width;
	}

	/*
	if (wnd.kbd.KeyIsPressed(VK_UP))
	{
		y_mobile = y_mobile - 3;
	}

	if (wnd.kbd.KeyIsPressed(VK_DOWN))
	{
		y_mobile = y_mobile + 3;
	}

	if (wnd.kbd.KeyIsPressed(VK_LEFT))
	{
		x_mobile = x_mobile - 3;
	}

	if (wnd.kbd.KeyIsPressed(VK_RIGHT))
	{
		x_mobile = x_mobile + 3;
	}

	colliding =
		OverlapTest(x_mobile, y_mobile, x_static0, y_static0) ||
		OverlapTest(x_mobile, y_mobile, x_static1, y_static1) || 
		OverlapTest(x_mobile, y_mobile, x_static2, y_static2) || 
		OverlapTest(x_mobile, y_mobile, x_static3, y_static3);

	x_mobile = ClampScreenX(x_mobile);
	y_mobile = ClampScreenY(y_mobile);
	*/
}

void Game::DrawBox(int x, int y, int r, int g, int b)
{
	gfx.PutPixel(x - 4, y - 5, r, g, b);
	gfx.PutPixel(x - 3, y - 5, r, g, b);
	gfx.PutPixel(x - 5, y - 5, r, g, b);
	gfx.PutPixel(x - 5, y - 4, r, g, b);
	gfx.PutPixel(x - 5, y - 3, r, g, b);									 
	gfx.PutPixel(x + 4, y - 5, r, g, b);
	gfx.PutPixel(x + 3, y - 5, r, g, b);
	gfx.PutPixel(x + 5, y - 5, r, g, b);
	gfx.PutPixel(x + 5, y - 4, r, g, b);
	gfx.PutPixel(x + 5, y - 3, r, g, b);										 
	gfx.PutPixel(x - 4, y + 5, r, g, b);
	gfx.PutPixel(x - 3, y + 5, r, g, b);
	gfx.PutPixel(x - 5, y + 5, r, g, b);
	gfx.PutPixel(x - 5, y + 4, r, g, b);
	gfx.PutPixel(x - 5, y + 3, r, g, b);										 
	gfx.PutPixel(x + 4, y + 5, r, g, b);
	gfx.PutPixel(x + 3, y + 5, r, g, b);
	gfx.PutPixel(x + 5, y + 5, r, g, b);
	gfx.PutPixel(x + 5, y + 4, r, g, b);
	gfx.PutPixel(x + 5, y + 3, r, g, b);
}


bool Game::OverlapTest(int box0x, int box0y, int box1x, int box1y)
{
	const int top0 = box0y - 5;
	const int bottom0 = box0y + 5;
	const int left0 = box0x - 5;
	const int right0 = box0x + 5;

	const int top1 = box1y - 5;
	const int bottom1 = box1y + 5;
	const int left1 = box1x - 5;
	const int right1 = box1x + 5;

	return
		top0 <= bottom1 &&
		bottom0 >= top1 &&
		right0 >= left1 &&
		left0 <= right1;;
}

int Game::ClampScreenX(int x)
{
	const int left = x - 5;
	if (left < 0)
	{
		x = 5;
	}

	const int right = x + 5;
	if (right >= gfx.ScreenWidth)
	{
		x = gfx.ScreenWidth - 6;
	}

	return x;
}

int Game::ClampScreenY(int y)
{
	const int top = y - 5;
	if (top < 0)
	{
		y = 5;
	}

	const int bottom = y + 5;
	if (bottom >= gfx.ScreenHeight)
	{
		y = gfx.ScreenHeight - 6;
	}

	return y;
}

void Game::ComposeFrame()
{
	Color c(255, 255, 255);
	gfx.DrawRectDim(x, y, width, height, c);

	/*
	DrawBox(x_static0, y_static0, 0, 255, 0);
	DrawBox(x_static1, y_static1, 0, 255, 0);
	DrawBox(x_static2, y_static2, 0, 255, 0);
	DrawBox(x_static3, y_static3, 0, 255, 0);

	if (colliding)
	{
		DrawBox(x_mobile, y_mobile, 255, 0, 0);
	}
	else
	{
		DrawBox(x_mobile, y_mobile, 255, 255, 255);
	}
	*/
}
