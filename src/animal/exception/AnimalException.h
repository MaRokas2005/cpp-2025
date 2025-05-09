/**
 * @file AnimalException.h
 * @author Rokas Braidokas (rokasbraidokas@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2025-05-09
 * 
 * @copyright Copyright (c) 2025
 * 
 */
#ifndef ANIMALEXCEPTION_H
#define ANIMALEXCEPTION_H

#include <exception>
#include <string>

class AnimalException : public std::exception {
private:
    std::string message;
public:
    /**
     * @brief Construct a new Animal Exception object
     * 
     * @param msg message to be displayed
     */
    explicit AnimalException(const std::string& msg);
    /**
     * @brief just a wrapper for std::exception::what()
     * 
     * @return const char* 
     */
    const char* what() const noexcept override;
};

#endif