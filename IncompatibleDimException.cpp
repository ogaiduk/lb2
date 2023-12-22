#include "IncompatibleDimException.h"

IncompatibleDimException::IncompatibleDimException(std::string str) : description(str) {};

const  char* IncompatibleDimException::what() const noexcept {
	return description.c_str();
}
