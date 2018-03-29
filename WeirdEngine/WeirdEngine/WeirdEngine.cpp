// WeirdEngine.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Engine.h"
#include<iostream>

using namespace WEIRD;

int main()
{

	Engine* engine = Engine::startEngine();

	engine->init();
	engine->Run();

    return 0;
}

