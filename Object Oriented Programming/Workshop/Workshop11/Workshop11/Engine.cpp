#include "Engine.h"

Engine::Engine(size_t id, const String& manufacturer, const String& description, short hp) 
	: CarPart(id, manufacturer, description), hp(hp) {}


short Engine::getHP() const {
	return hp;
}

std::ostream& operator<<(std::ostream& out, const Engine& engine) {
	out << (CarPart&)engine << " - " << engine.hp << " hp";

	return out;
}