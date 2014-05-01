#include "Sprite.h"


Sprite::Sprite(void)
{
	name = "Sprite";	
}

Sprite::Sprite(string spriteName)
{
	name = spriteName;
}


Sprite::~Sprite(void)
{
}

void Sprite::SetTexture(string textureFile)
{
	this->texture = textureFile;
}


