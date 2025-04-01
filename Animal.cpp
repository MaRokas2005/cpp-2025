#include "Animal.h"
#include <iostream>

class AnimalImpl
{
public:
    AnimalImpl(const std::string& name, int x, int y, double direction, double speedMultiplier)
        : ID(nextID++), x(x), y(y), direction(direction), speedMultiplier(speedMultiplier), name(name)
    {
        quantity++;
        std::cout << "Gyvūnas sukurtas. ID: " << ID << ", vardas: " << name << "\n";
    }
    AnimalImpl(const AnimalImpl& other)
        : ID(nextID++), x(other.x), y(other.y), direction(other.direction), speedMultiplier(other.speedMultiplier), name(other.name)
    {
        quantity++;
    }
    ~AnimalImpl()
    {
        quantity--;
        std::cout << "Gyvūnas su ID: " << ID << " sunaikintas. Liko " << quantity << " objektų.\n";
    }
    AnimalImpl& operator=(const AnimalImpl& other)
    {
        if (this != &other) {
            x = other.x;
            y = other.y;
            direction = other.direction;
            speedMultiplier = other.speedMultiplier;
            name = other.name;
        }
        return *this;
    }

    void print() const
    {
        std::cout << "{\n\tCLASS={Animal}, \n\tID: " << ID
                  << ", \n\tvardas: " << name
                  << ", \n\tx: " << x
                  << ", \n\ty: " << y
                  << ", \n\tkryptis: " << direction
                  << ", \n\tkiekis: " << quantity
                  << ", \n\tgreitis: " << speed * speedMultiplier << "\n}\n";
    }
    void move(int dx, int dy)
    {
        x += dx;
        y += dy;
        std::cout << "Gyvūnas, vardu " << name << ", juda į (x: " << x << ", y: " << y << ").\n";
    }

    int getID() const { return ID; }
    int getX() const { return x; }
    int getY() const { return y; }
    double getDirection() const { return direction; }
    std::string getName() const { return name; }
    static int getQuantity() { return quantity; }

private:
    const int ID;
    int x, y;
    double direction;
    double speedMultiplier;
    std::string name;
    static int quantity;
    static int nextID;
    static constexpr int speed = 100;
};

int AnimalImpl::quantity = 0;
int AnimalImpl::nextID = 1;

Animal::Animal(const std::string& name, int x, int y, double direction, double speedMultiplier)
    : pImpl(std::make_unique<AnimalImpl>(name, x, y, direction, speedMultiplier)) {}

Animal::Animal(const Animal& other) : pImpl(std::make_unique<AnimalImpl>(*other.pImpl)) {}

Animal& Animal::operator=(const Animal& other) {
    if (this != &other) {
        *pImpl = *other.pImpl;
    }
    return *this;
}

Animal::~Animal() = default;

void Animal::print() const { pImpl->print(); }
void Animal::move(int dx, int dy) { pImpl->move(dx, dy); }
int Animal::getID() const { return pImpl->getID(); }
int Animal::getX() const { return pImpl->getX(); }
int Animal::getY() const { return pImpl->getY(); }
double Animal::getDirection() const { return pImpl->getDirection(); }
std::string Animal::getName() const { return pImpl->getName(); }
int Animal::getQuantity() { return AnimalImpl::getQuantity(); }


AnimalException::AnimalException(const std::string& msg) : message(msg) {}

const char* AnimalException::what() const noexcept {
    return message.c_str();
}