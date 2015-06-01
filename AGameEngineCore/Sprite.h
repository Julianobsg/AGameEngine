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
	Vector2D<float> relativeScale;
    Texture* LastTexture();
	Texture* ActualTexture();

    std::vector<Animation*> animations;
    
	Sprite();
	virtual ~Sprite();
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
	Texture* actualTexture;
};

