#include "AnimalException.h"
#include <string>
#include <exception>

AnimalException::AnimalException(const std::string& msg) : message(msg) {}

const char* AnimalException::what() const noexcept {
    return message.c_str();
}