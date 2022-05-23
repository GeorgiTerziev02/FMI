#pragma once
#include "String.h"

class Customer
{
	size_t id;
	String name;
	String address;

public:
	Customer(size_t id, const String& name, const String& address);

	size_t getId() const;
	const String& getName() const;
	const String& getAddress() const;
};

