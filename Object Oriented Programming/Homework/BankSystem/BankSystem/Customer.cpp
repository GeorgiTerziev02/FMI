#include "Customer.h"

Customer::Customer(size_t id, const String& name, const String& address) {
	this->id = id;
	this->name = name;
	this->address = address;
}

size_t Customer::getId() const {
	return id;
}

const String& Customer::getName() const {
	return name;
}

const String& Customer::getAddress() const {
	return address;
}