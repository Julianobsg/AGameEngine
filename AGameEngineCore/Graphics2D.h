#pragma once
#include <string>

using namespace std;

class Graphics2D
{
public:
	Graphics2D(void);
	~Graphics2D(void);
	virtual void LoadTexture(string textureName);
	virtual void Draw();
};

