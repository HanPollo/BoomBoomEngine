#include "MainLoop.h"
#include "Engine.h"

int main()
{
	MainLoop::Get()->SetRunCondition([]() {return Engine::isRunning(); });
	MainLoop::Get()->AddToOnBegin([]() {Engine::processStage(); Engine::init(); });
	MainLoop::Get()->AddToOnUpdate([](float dt) {Engine::update(dt); /*TTD::processAI(dt);*/ });
	MainLoop::Get()->AddToOnPostUpdate([]() {Engine::render(); });
	return MainLoop::Get()->Run();
}
