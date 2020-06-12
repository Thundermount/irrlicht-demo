// IrrlichtSamlpe.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <irrlicht.h>
#include <time.h>
#include "Game.h"

using namespace irr;           //
using namespace core;          //  Здесь указываем пространства имен движка, для того, чтобы
using namespace scene;         //     не указывать их каждый раз, когда обращаемся
using namespace video;         //        к объекту движка.
using namespace io;            //
using namespace gui;

int main()
{
	Game* game = new Game();
	game->Init(EDT_OPENGL, 800, 600);
	game->Start();
	IMeshSceneNode* cube = game->Scene->addCubeSceneNode(4.0f);
	cube->setPosition(vector3df(0.0f, 0.0f, 10.0f));
	cube->setMaterialFlag(EMF_LIGHTING, false);

	ITimer* timer = game->device->getTimer();
	u32 old_time = 0;
	timer->start();


	while (game->device->run()) {
		game->driver->beginScene(true,true,SColor(0,100,0,0));
		u32 new_time = timer->getTime();
		f32 delta_time = (f32) new_time - old_time;
		old_time = new_time;
		
		for (int i = 0; i < game->Cameras.size(); i++) {
			Camera* camera = game->Cameras.at(i);
			
		}

		game->Update(delta_time);
		game->Scene->drawAll();                                            // Менеджер сцены рисует свои объекты.

		game->driver->endScene();
	}
	game->device->drop();
    return 0;
}

