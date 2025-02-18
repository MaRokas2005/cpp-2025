#include <bits/stdc++.h>

using namespace std;

class Animal
{
protected:
    int ID;
    int x, y;
    int speedMultiplier;
    double direction;
    string name;
private:
    static int quantity;
    static int nextID;
    static constexpr int speed = 10;
public:
    Animal(int x, int y)
    {
        this->ID = nextID++;
        this->x = x;
        this->y = y;
        this->quantity++;
    }
    ~Animal() {
        this->quantity--;
        cout << "Animal object with ID: " << this->ID << " has been destroyed" << '\n';
    }
    void print()
    {
        cout << "{\n\tCLASS={Animal}, \n\tID: " << ID << ", \n\tx: " << x << ", \n\ty: " << y << ", \n\tquantity = " << quantity << "\n}\n";
    }
    int getX() {return this->x;}
    void setX(int value) {this->x = value;}
};

int Animal::quantity = 0;
int Animal::nextID = 1;

int main()
{
    Animal animal1(0, 9);
    animal1.print();
    Animal an2(9, 1551);
    an2.print();
    animal1.print();
    an2.setX(908);
    an2.print();

    Animal* anis = new Animal(9, 8);
    anis->print();
    delete anis;
    return 0;
}
