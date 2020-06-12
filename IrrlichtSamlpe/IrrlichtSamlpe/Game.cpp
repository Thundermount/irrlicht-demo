#include "stdafx.h"
#include "Game.h"
#include <irrlicht.h>
#include <list>


Camera* camera;
void Game::Start() {
	camera = new Camera(this);
	camera->Move(-100, 0, -100);
}
void Game::Update(float delta_time) {
	camera->Move(0.05f,0.0f,0.0f,delta_time);
}