#pragma once
#include <string>

using namespace std;

class Debug
{
public:
	Debug(void);
	~Debug(void);
	static void Log(string message);
};

