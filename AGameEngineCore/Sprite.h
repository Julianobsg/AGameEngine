#pragma once
#include "GameObject.h"

class Sprite :
	public GameObject
{
public:
	string texture;

	Sprite(void);
	Sprite(string spriteName);
	
	~Sprite(void);
	
	void SetTexture(string textureFile);


};

