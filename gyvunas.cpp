#include <bits/stdc++.h>

using namespace std;

class Animal
{
protected:
    int ID;
    int x, y;
    double direction;
    double speedMultiplier;
    std::string name;
private:
    static int quantity;
    static int nextID;
    static constexpr int speed = 100;
public:
    Animal() : name("FORGOT"), x(0), y(0), direction(0), speedMultiplier(1.0)
    {
        this->nextID = nextID++;
        this->quantity++;
    }
    Animal(std::string name, int x, int y, double direction = 0.0d, double speedMultiplier = 1.0d)
     : name(name), x(x), y(y), direction(direction), speedMultiplier(speedMultiplier)
    {
        this->ID = nextID++;
        this->quantity++;
    }
    ~Animal() {
        this->quantity--;
        cout << "Animal object with ID: " << this->ID << " has been destroyed" << '\n';
    }
    void print()
    {
        cout << "{\n\tCLASS={Animal}, \n\tID: " << ID;
        cout << ", \n\tname: " << name;
        cout << ", \n\tx: " << x;
        cout << ", \n\ty: " << y;
        cout << ", \n\tdirection = " << direction;
        cout << ", \n\tquantity = " << quantity;
        cout << ", \n\tspeed = " << getSpeed() << "\n}\n";
    }
    int getID() const { return ID; }
    int getX() const { return x; }
    int getY() const { return y; }
    int getSpeed() const { return speed * speedMultiplier; }
    double getDirection() const { return direction; }
    std::string getName() const { return name; }
    static int getQuantity() { return quantity; }

    void setX(int value) { x = value; }
    void setY(int value) { y = value; }
    void setName(std::string value) { name = value; }
};

int Animal::quantity = 0;
int Animal::nextID = 1;

int main()
{
    Animal animal1("eitis", 0, 9, 0, 0.75);
    animal1.print();
    Animal an2("Kostas", 9, 1551, 50, 0.5);
    an2.print();
    animal1.print();
    an2.setX(908);
    an2.print();

    Animal* anis = new Animal("Milda", 9, 8, 270, 0.7);
    anis->print();
    delete anis; //Butinas
    return 0;
}
