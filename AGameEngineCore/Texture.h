#pragma once
#include <string>
#include "Vector2D.h"
#include "EngineGlobal.h"
#include "Transform.h"

using namespace std;


class Texture
{
	friend class Text;
	friend class Sprite;
	friend class Animation;
public:
	Vector2D<int> size;
	Vector2D<int> imageSize;
	string texturePath;
	float pixelsPerMeter;

	Texture(void);
	~Texture(void);

	void Draw(Transform* transform);	


	void Clip (int x, int y, int w, int h);
	void Destroy();
	void Copy(Texture* lastTexture);
private:
	void LoadTexture(SDL_Texture* texture, SDL_Renderer* renderer);
	void LoadTexture(SDL_Texture* texture);
	void LoadTexture(SDL_Renderer* renderer);
	SDL_RendererFlip CheckImageScale(Transform* transform);
	SDL_Texture* texture;
	SDL_Renderer* renderer;
	SDL_Rect* clip;
};

