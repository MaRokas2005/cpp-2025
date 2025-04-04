#include "Animal.h"
#include "AnimalImpl.h"
#include <iostream>

Animal::Animal(const std::string& name, int x, int y, double direction, double speedMultiplier)
    : pImpl(new AnimalImpl{name, x, y, direction, speedMultiplier}) {}

Animal::Animal(const Animal& other) : pImpl(new AnimalImpl(*other.pImpl)) {}

Animal& Animal::operator=(const Animal& other) {
    if (this != &other) {
        delete pImpl;
        pImpl = new AnimalImpl(*other.pImpl);
    }
    return *this;
}

Animal::~Animal(){
    delete pImpl;
}

void Animal::print() const { pImpl->print(); }
void Animal::move(int dx, int dy) { pImpl->move(dx, dy); }
int Animal::getID() const { return pImpl->getID(); }
int Animal::getX() const { return pImpl->getX(); }
int Animal::getY() const { return pImpl->getY(); }
double Animal::getDirection() const { return pImpl->getDirection(); }
std::string Animal::getName() const { return pImpl->getName(); }
int Animal::getQuantity() { return AnimalImpl::getQuantity(); }
