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

class Text : public GameObject
{
public:
    string content;
    Text(string fontPath);
    ~Text();
	void ChangeColor(int r, int g, int b);
	void Draw(Transform* cameraTransform) override;
    void Init(SDL_Renderer* renderer);
private:
    TTF_Font* font;
    SDL_Surface* textSurface;
    SDL_Renderer* renderer;
    SDL_Color* color;
    SDL_Texture* textTexture;
    string fontPath;
    void OpenFont();
    void MakeTexture();
};