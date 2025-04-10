#ifndef ANIMAL_H
#define ANIMAL_H

#include <memory>
#include <string>
class AnimalImpl;
class Animal
{
private:
    AnimalImpl *pImpl;
public:
    Animal(const std::string& name, int x = 0, int y = 0, double direction = 0.0, double speedMultiplier = 1.0);
    Animal(const Animal& other);
    Animal& operator=(const Animal& other);
    Animal(Animal&&) noexcept = default;
    Animal& operator=(Animal&&) noexcept = default;
    ~Animal();

    void print() const;
    void move(int dx, int dy);

    int getID() const;
    int getX() const;
    int getY() const;
    double getDirection() const;
    std::string getName() const;
    static int getQuantity();

};

#endif