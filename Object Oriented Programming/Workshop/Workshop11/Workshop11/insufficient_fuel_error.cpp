#include "insufficient_fuel_error.h"

insufficient_fuel_error::insufficient_fuel_error(const char* message) 
	:std::logic_error(message) {}