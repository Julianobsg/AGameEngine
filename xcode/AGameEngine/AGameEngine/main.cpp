//
//  main.cpp
//  AGameEngine
//
//  Created by Juliano-Mac on 22/05/14.
//  Copyright (c) 2014 AGameEngine. All rights reserved.
//
#include "MainGame.h"

int main(int argc, const char * argv[])
{
    MainGame mainGame;
    
    mainGame.Init();
    
    return mainGame.Run();
}
