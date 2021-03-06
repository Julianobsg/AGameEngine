 //
//  Text.h
//  AGameEngine
//
//  Created by Juliano-Mac on 21/09/14.
//  Copyright (c) 2014 AGameEngine. All rights reserved.
//
#pragma once

#include "GameObject.h"
#include "EngineGlobal.h"
#include "Vector3D.h"
#include "Texture.h"

class Text : public GameObject
{
	friend class Scene;
public:
    int pixelsPerMeter;

    Texture *texture;
    Text(string fontPath);
    ~Text();
	void SetContent(string content);
	string GetContent();

	void ChangeColor(int r, int g, int b);
    void FontSize(int fontSize);
	void Draw(Transform* cameraTransform) override;
private:
    string content;
    int fontSize;
    TTF_Font* font;
    SDL_Surface* textSurface;
    SDL_Renderer* renderer;
    SDL_Color* color;
    SDL_Texture* textTexture;
    string fontPath;
    void Load(SDL_Renderer* renderer);
    void OpenFont();
    void MakeTexture();
};