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
public:
    int pixelsPerMeter;

    string content;
    Text(string fontPath);
    ~Text();
	void ChangeColor(int r, int g, int b);
    void FontSize(int fontSize);
	void Draw(Transform* cameraTransform) override;
    void Init(SDL_Renderer* renderer);
private:
    int fontSize;
    TTF_Font* font;
    SDL_Surface* textSurface;
    SDL_Renderer* renderer;
    SDL_Color* color;
    Texture *texture;
    SDL_Texture* textTexture;
    string fontPath;
    void OpenFont();
    void MakeTexture();
};