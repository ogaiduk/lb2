#pragma once
#include <exception>
#include <string>
class OutOfRange : public std::exception {

public:
	OutOfRange(std::string);
	const  char* what() const noexcept;
private:
	std::string description;
};
