#include "MainGame.h"

extern "C" int main (int argc, char *argv[])
{
	MainGame mg;
	mg.Init();
	return mg.Run();
}
