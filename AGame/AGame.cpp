// AGame.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "MainGame.h"

int main(int argc, char* argv[])
{
	MainGame mainGame;
 
	mainGame.Init();

	return mainGame.Run();
}
