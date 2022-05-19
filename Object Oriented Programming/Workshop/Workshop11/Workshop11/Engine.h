#pragma once
#include "CarPart.h"

class Engine : public CarPart {
	short hp;
public:
	Engine(size_t, const String&, const String&, short hp);

	short getHP() const;

	friend std::ostream& operator<<(std::ostream&, const Engine&);
};