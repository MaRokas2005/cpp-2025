#ifndef ANIMALEXCEPTION_H
#define ANIMALEXCEPTION_H

#include <exception>
#include <string>

class AnimalException : public std::exception {
private:
    std::string message;
public:
    explicit AnimalException(const std::string& msg);
    const char* what() const noexcept override;
};

#endif