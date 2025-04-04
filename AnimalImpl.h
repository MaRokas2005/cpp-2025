#ifndef ANIMALIMPL_H
#define ANIMALIMPL_H

#include <string>

class AnimalImpl {
private:
    const int ID;
    int x, y;
    double direction;
    double speedMultiplier;
    std::string name;

    static int quantity;
    static int nextID;
    static constexpr int speed = 100;
public:
    AnimalImpl(const std::string& name, int x, int y, double direction, double speedMultiplier);
    AnimalImpl(const AnimalImpl& other);
    ~AnimalImpl();
    AnimalImpl& operator=(const AnimalImpl& other);

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
