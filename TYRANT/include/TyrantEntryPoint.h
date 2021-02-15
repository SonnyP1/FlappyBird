#pragma once
#include <Application.h>
extern ty::Application* CreateApplication();


int main()
{
	ty::Application* App = CreateApplication();
	if (App)
	{
		App->Run();
	}
	delete App;
	return 0;
}