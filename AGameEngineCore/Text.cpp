//
//  Text.cpp
//  AGameEngine
//
//  Created by Juliano-Mac on 21/09/14.
//  Copyright (c) 2014 AGameEngine. All rights reserved.
//

#include "Text.h"
#include "Debug.h"

Text::Text(string fontPath) : GameObject()
{
#ifdef _WIN32
	fontPath = "Media/" + fontPath;
#endif
    this->fontPath = fontPath;

    color = new SDL_Color {255,255,255,255};
    
    content = "";
    pixelsPerMeter = 48;
    fontSize = 20;
    font = NULL;
}

Text::~Text()
{
    TTF_CloseFont(font);
    font = NULL;
}

void Text::Load(SDL_Renderer *renderer)
{
    this->renderer = renderer;
    texture = new Texture;
	texture->renderer = renderer;
    OpenFont();
    
	if (!font) {
		Debug::Log("Could not open file given the error: " + string(TTF_GetError()) + "\n");
		return;
	}

    MakeTexture();
}

void Text::Draw(Transform* cameraTransform)
{
//    SDL_RenderCopy(renderer, textTexture, NULL, NULL);
    cameraTransform->scale.x = cameraTransform->scale.x / pixelsPerMeter;
    cameraTransform->scale.y = cameraTransform->scale.y / pixelsPerMeter;
    texture->Draw(cameraTransform);
}

void Text::OpenFont()
{
    font = TTF_OpenFont(fontPath.c_str(), fontSize);
}

void Text::MakeTexture()
{
    if (font) {
        if(!(textSurface = TTF_RenderUTF8_Solid(font, content.c_str(), *color))) {
            //handle error here, perhaps print TTF_GetError at least
            Debug::Log("Could not make texture given the error: " + string(TTF_GetError()) + "\n");
        } else {
            textTexture = SDL_CreateTextureFromSurface(this->renderer, this->textSurface);
            SDL_FreeSurface(textSurface);
            texture->LoadTexture(textTexture);
        }
    }
}

void Text::ChangeColor(int r, int g, int b)
{
    if (this->color->r != r ||
        this->color->g != g ||
        this->color->b != b) {
        this->color->r = r;
        this->color->g = g;
        this->color->b = b;
        MakeTexture();
    }
}

void Text::FontSize(int fontSize)
{
    this->fontSize = fontSize;
    OpenFont();
    MakeTexture();
}

void Text::SetContent(string content)
{
	this->content = content;
	MakeTexture();
}

std::string Text::GetContent()
{
	return this->content;
}

