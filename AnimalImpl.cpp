#include "AnimalImpl.h"
#include <iostream>

int AnimalImpl::quantity = 0;
int AnimalImpl::nextID = 1;

AnimalImpl::AnimalImpl(const std::string& name, int x, int y, double direction, double speedMultiplier)
    : ID(nextID++), x(x), y(y), direction(direction), speedMultiplier(speedMultiplier), name(name) {
    quantity++;
    std::cout << "Gyvūnas sukurtas. ID: " << ID << ", vardas: " << name << "\n";
}

AnimalImpl::AnimalImpl(const AnimalImpl& other)
    : ID(nextID++), x(other.x), y(other.y), direction(other.direction), speedMultiplier(other.speedMultiplier), name(other.name) {
    quantity++;
}

AnimalImpl::~AnimalImpl() {
    quantity--;
    std::cout << "Gyvūnas su ID: " << ID << " sunaikintas. Liko " << quantity << " objektų.\n";
}

AnimalImpl& AnimalImpl::operator=(const AnimalImpl& other) {
    if (this != &other) {
        x = other.x;
        y = other.y;
        direction = other.direction;
        speedMultiplier = other.speedMultiplier;
        name = other.name;
    }
    return *this;
}

void AnimalImpl::print() const {
    std::cout << "{\n\tCLASS={Animal}, \n\tID: " << ID
              << ", \n\tvardas: " << name
              << ", \n\tx: " << x
              << ", \n\ty: " << y
              << ", \n\tkryptis: " << direction
              << ", \n\tkiekis: " << quantity
              << ", \n\tgreitis: " << speed * speedMultiplier << "\n}\n";
}

void AnimalImpl::move(int dx, int dy) {
    x += dx;
    y += dy;
    std::cout << "Gyvūnas, vardu " << name << ", juda į (x: " << x << ", y: " << y << ").\n";
}

int AnimalImpl::getID() const { return ID; }
int AnimalImpl::getX() const { return x; }
int AnimalImpl::getY() const { return y; }
double AnimalImpl::getDirection() const { return direction; }
std::string AnimalImpl::getName() const { return name; }
int AnimalImpl::getQuantity() { return quantity; }
