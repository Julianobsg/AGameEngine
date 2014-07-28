#pragma once
#include "GameObject.h"
#include "Texture.h"
#include "Animation.h"
#include <vector>

class Sprite :
	public GameObject
{
public:
    std::vector<Animation*> animations;
    
	Sprite();
	void AddAnimantion(Animation* animation);
    void AddTexture(string texturePath);
	void AddClip (int x, int y, int w, int h);
	void Play (int playAnimation);
    
    void Init(SDL_Renderer* renderer);
	void Draw();
	void Destroy();

	virtual void AddBehaviour(Behaviour* behaviour);
	Texture* LastTexture();
    
private:
    int animationPlaying;
};

