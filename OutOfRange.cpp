#include "OutOfRange.h"

OutOfRange::OutOfRange(std::string str) : description(str) {};

const  char* OutOfRange::what() const noexcept {
	return description.c_str();
}