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

	const int top_static = y_static - 5;
	const int bottom_static = y_static + 5;
	const int left_static = x_static - 5;
	const int right_static = x_static + 5;

	const int top_mobile = y_mobile - 5;
	const int bottom_mobile = y_mobile + 5;
	const int left_mobile = x_mobile - 5;
	const int right_mobile = x_mobile + 5;

	colliding = 
		top_mobile <= bottom_static &&
		bottom_mobile >= top_static && 
		right_mobile >= left_static && 
		left_mobile <= right_static;


	if (colliding)
	{
		gb = 0;
	}
	else
	{
		gb = 255;
	}
}

void Game::ComposeFrame()
{
	// Mobile box
	gfx.PutPixel(x_mobile - 4, y_mobile - 5, 255, gb, gb);
	gfx.PutPixel(x_mobile - 3, y_mobile - 5, 255, gb, gb);
	gfx.PutPixel(x_mobile - 5, y_mobile - 5, 255, gb, gb);
	gfx.PutPixel(x_mobile - 5, y_mobile - 4, 255, gb, gb);
	gfx.PutPixel(x_mobile - 5, y_mobile - 3, 255, gb, gb);

	gfx.PutPixel(x_mobile + 4, y_mobile - 5, 255, gb, gb);
	gfx.PutPixel(x_mobile + 3, y_mobile - 5, 255, gb, gb);
	gfx.PutPixel(x_mobile + 5, y_mobile - 5, 255, gb, gb);
	gfx.PutPixel(x_mobile + 5, y_mobile - 4, 255, gb, gb);
	gfx.PutPixel(x_mobile + 5, y_mobile - 3, 255, gb, gb);

	gfx.PutPixel(x_mobile - 4, y_mobile + 5, 255, gb, gb);
	gfx.PutPixel(x_mobile - 3, y_mobile + 5, 255, gb, gb);
	gfx.PutPixel(x_mobile - 5, y_mobile + 5, 255, gb, gb);
	gfx.PutPixel(x_mobile - 5, y_mobile + 4, 255, gb, gb);
	gfx.PutPixel(x_mobile - 5, y_mobile + 3, 255, gb, gb);

	gfx.PutPixel(x_mobile + 4, y_mobile + 5, 255, gb, gb);
	gfx.PutPixel(x_mobile + 3, y_mobile + 5, 255, gb, gb);
	gfx.PutPixel(x_mobile + 5, y_mobile + 5, 255, gb, gb);
	gfx.PutPixel(x_mobile + 5, y_mobile + 4, 255, gb, gb);
	gfx.PutPixel(x_mobile + 5, y_mobile + 3, 255, gb, gb);

	// Static box
	gfx.PutPixel(x_static - 4, y_static - 5, 0, 255, 0);
	gfx.PutPixel(x_static - 3, y_static - 5, 0, 255, 0);
	gfx.PutPixel(x_static - 5, y_static - 5, 0, 255, 0);
	gfx.PutPixel(x_static - 5, y_static - 4, 0, 255, 0);
	gfx.PutPixel(x_static - 5, y_static - 3, 0, 255, 0);
				   				 			
	gfx.PutPixel(x_static + 4, y_static - 5, 0, 255, 0);
	gfx.PutPixel(x_static + 3, y_static - 5, 0, 255, 0);
	gfx.PutPixel(x_static + 5, y_static - 5, 0, 255, 0);
	gfx.PutPixel(x_static + 5, y_static - 4, 0, 255, 0);
	gfx.PutPixel(x_static + 5, y_static - 3, 0, 255, 0);
				   				 			
	gfx.PutPixel(x_static - 4, y_static + 5, 0, 255, 0);
	gfx.PutPixel(x_static - 3, y_static + 5, 0, 255, 0);
	gfx.PutPixel(x_static - 5, y_static + 5, 0, 255, 0);
	gfx.PutPixel(x_static - 5, y_static + 4, 0, 255, 0);
	gfx.PutPixel(x_static - 5, y_static + 3, 0, 255, 0);
				   				 			
	gfx.PutPixel(x_static + 4, y_static + 5, 0, 255, 0);
	gfx.PutPixel(x_static + 3, y_static + 5, 0, 255, 0);
	gfx.PutPixel(x_static + 5, y_static + 5, 0, 255, 0);
	gfx.PutPixel(x_static + 5, y_static + 4, 0, 255, 0);
	gfx.PutPixel(x_static + 5, y_static + 3, 0, 255, 0);
}
