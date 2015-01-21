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
    this->fontPath = fontPath;

    color = new SDL_Color {255,255,255,255};
    
    content = "";
}

Text::~Text()
{
    TTF_CloseFont(font);
}

void Text::Init(SDL_Renderer *renderer)
{
    this->renderer = renderer;
    
    OpenFont();
    
    MakeTexture();
}

void Text::Draw()
{
    SDL_RenderCopy(renderer, textTexture, NULL, NULL);

}

void Text::OpenFont()
{
    font = TTF_OpenFont(fontPath.c_str(), 20);
    
    if(!font) {
        Debug::Log("Could not open file given the error: " + string(TTF_GetError()));
        // handle error
    }
}

void Text::MakeTexture()
{
    if(!(textSurface = TTF_RenderUTF8_Solid(font, content.c_str(), *color))) {
        //handle error here, perhaps print TTF_GetError at least
    } else {
        textTexture = SDL_CreateTextureFromSurface(this->renderer, textSurface);
        SDL_FreeSurface(textSurface);
    }
}