#pragma once
#include <string>
#include "Vector2D.h"
#include "EngineGlobal.h"
#include "Transform.h"

using namespace std;


class Texture
{
public:
	Vector2D size;
	string texturePath;

	Texture(void);
	~Texture(void);

	void LoadTexture(SDL_Texture* texture, SDL_Renderer* renderer);
	void LoadTexture(SDL_Texture* texture);
	void LoadTexture(SDL_Renderer* renderer);
	void LoadTexture(string texturePath, SDL_Renderer* renderer);
	void Draw(Transform* transform);	

	SDL_RendererFlip CheckImageScale(Transform* transform);

	void Clip (int x, int y, int w, int h);
	void Destroy();
	void Copy(Texture* lastTexture);
private:
	SDL_Texture* texture;
	SDL_Renderer* renderer;
	SDL_Rect* clip;
};

