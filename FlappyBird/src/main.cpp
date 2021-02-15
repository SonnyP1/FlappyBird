#include <tyrant.h>
#include <Application.h>
#include <TyrantEntryPoint.h>
#include "FlappyBirdApp.h"
#include <Level.h>
#include "MainGameLevel.h"

ty::Application* CreateApplication()
{
	FlappyBirdApp* app = new FlappyBirdApp(768, 1024, "FlappyBird");
	app->LoadLevel(new MainGameLevel(app));
	return app;
}