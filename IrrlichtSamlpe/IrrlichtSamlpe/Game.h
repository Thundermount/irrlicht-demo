#pragma once
#include <irrlicht.h>
#include <vector>

using namespace irr;           //
using namespace core;          //  Здесь указываем пространства имен движка, для того, чтобы
using namespace scene;         //     не указывать их каждый раз, когда обращаемся
using namespace video;         //        к объекту движка.
using namespace io;            //
using namespace gui;


class Game {
public:
	IrrlichtDevice* device;
	IVideoDriver* driver;
	ISceneManager* Scene;
	std::vector < class Camera* > Cameras;

public: Game() {

}
		const int bits = 64;
		void Init(E_DRIVER_TYPE render, int width, int height, bool fullscreen, bool vsync) {
			device = createDevice(render, dimension2du(width, height), bits, fullscreen, false, vsync, 0);
			driver = device->getVideoDriver();
			Scene = device->getSceneManager();
		}
		void Init(E_DRIVER_TYPE render, int width, int height, bool fullscreen) {
			device = createDevice(render, dimension2du(width, height), bits, fullscreen, false, false, 0);
			driver = device->getVideoDriver();
			Scene = device->getSceneManager();
		}
		void Init(E_DRIVER_TYPE render, int width, int height) {
			device = createDevice(render, dimension2du(width, height), bits, false, false, false, 0);
			driver = device->getVideoDriver();
			Scene = device->getSceneManager();
		}
	void Start();
	void Update(float delta_time);

	
};

class Camera {

ICameraSceneNode* camera;
public:
	vector3df rotation;
public: Camera(Game* game) {
	camera = game->Scene->addCameraSceneNode();
	camera->bindTargetAndRotation(true);
	rotation = camera->getRotation();
	game->Cameras.push_back(this);
}
void Move(float x, float y, float z) {
	camera->setPosition(camera->getPosition() + vector3df(x, y, z));

}
void Move(vector3df vec) {
	camera->setPosition(camera->getPosition() + vec);

}
void Move(float x, float y, float z, float delta_time) {
	camera->setPosition(camera->getPosition() + vector3df(x, y, z) * delta_time);
	camera->setTarget(vector3df(camera->getPosition().X, camera->getPosition().Y, 1.0f));
}
void Move(vector3df vec, float delta_time) {
	camera->setPosition(camera->getPosition() + vec * delta_time);

}
void Rotate(vector3df vec) {
	rotation = vec;
	camera->setRotation(rotation);
}
void Rotate(float x, float y, float z) {
	rotation = vector3df(x, y, z);
	camera->setRotation(rotation);
}
};
