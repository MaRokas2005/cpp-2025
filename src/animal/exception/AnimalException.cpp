/**
 * @file AnimalException.cpp
 * @author Rokas Braidokas (rokasbraidokas@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2025-05-09
 * 
 * @copyright Copyright (c) 2025
 * 
 */
#include "AnimalException.h"
#include <string>
#include <exception>

AnimalException::AnimalException(const std::string& msg) : message(msg) {}

const char* AnimalException::what() const noexcept {
    return message.c_str();
}