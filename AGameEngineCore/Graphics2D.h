#pragma once
#include <string>

using namespace std;

class Graphics2D
{
public:
	Graphics2D(void);
	~Graphics2D(void);
	void LoadTexture(string textureName);
	void Draw();
};

