#pragma once
#include <exception>
#include <string>
class IncompatibleDimException : public std::exception {

public:
	IncompatibleDimException(std::string);
	const  char* what() const noexcept;
private:
	std::string description;
};