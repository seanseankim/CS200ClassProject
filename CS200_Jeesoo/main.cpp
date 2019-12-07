#include <iostream>
#include "main.hpp"
#include "Engine.hpp"

int main()
{
	std::cout << "*******************************ENGINE GUIDE*******************************" << std::endl;
	std::cout << "----------------------------------Camera----------------------------------" << std::endl;
	std::cout << "Move : Up/Down/Right/Left keyboard buttons" << std::endl;
	std::cout << "Rotate : Delete and Page Down keyboard buttons" << std::endl;
	std::cout << "Zoom : Mouse scroll\n" << std::endl;
	std::cout << "----------------------------------Player----------------------------------" << std::endl;
	std::cout << "Move : WASD keyboard buttons\n" << std::endl;
	std::cout << "---------------------------------Features----------------------------------" << std::endl;
	std::cout << "ScreenShot : Caps Lock keyboard button" << std::endl;
	std::cout << "Pause : Number 1 keyboard button\n" << std::endl;
	std::cout << "Fullscreen : F keyboard button\n" << std::endl;
	std::cout << "V sync : V keyboard button\n" << std::endl;
	std::cout << "--------------------------------INSTRUCTIONS------------------------------" << std::endl;
	std::cout << "To move to the next level, go down the pipe in each level\n" << std::endl;
	std::cout << "**************************************************************************\n" << std::endl;
	Engine engine;
	engine.Init();
	while (!engine.IsDone())
	{
		engine.Update();
	}
	engine.Delete();

	return 0;
}
