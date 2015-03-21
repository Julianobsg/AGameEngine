#pragma once
#include "GameObject.h"
#include "Texture.h"
#include "Animation.h"
#include <vector>

class Sprite :
	public GameObject
{
	friend class Scene;
public:
    int pixelsPerMeter;
    Texture* LastTexture();
    std::vector<Animation*> animations;
    
	Sprite();
	void AddAnimantion(Animation* animation);
    void AddTexture(string texturePath);
	void AddClip (int x, int y, int w, int h);
	void Play (int playAnimation);
    
	void Draw(Transform* cameraTransform) override;
	void Destroy();

	virtual void AddBehaviour(Behaviour* behaviour);
	
private:
	bool clipped;
    void Load(SDL_Renderer* renderer);
    int animationPlaying;
};

