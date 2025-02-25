#include <bits/stdc++.h>
#include <windows.h>

using namespace std;

class Animal
{
protected:
    const int ID;
    int x, y;
    double direction;
    double speedMultiplier;
    std::string name;
private:
    static int quantity;
    static int nextID;
    static constexpr int speed = 100;
public:
    Animal(const std::string& name, int x = 0, int y = 0, double direction = 0.0d, double speedMultiplier = 1.0d)
     : ID(nextID++), name(name), x(x), y(y), direction(direction), speedMultiplier(speedMultiplier)
    {
        this->quantity++;
        std::cout << "Animal object created. ID: " << getID();
        std::cout << ", name: " << getName() << ". " << '\n';
    }
    ~Animal() {
        this->quantity--;
        std::cout << "Animal object with ID: " << getID();
        cout << " has been destroyed. Left " << getQuantity() << " objects." << '\n';
    }
    void print() const
    {
        std::cout << "{\n\tCLASS={Animal}, \n\tID: " << ID;
        std::cout << ", \n\tname: " << name;
        std::cout << ", \n\tx: " << x;
        std::cout << ", \n\ty: " << y;
        std::cout << ", \n\tdirection = " << direction;
        std::cout << ", \n\tquantity = " << quantity;
        std::cout << ", \n\tspeed = " << getSpeed() << "\n}\n";
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
    void setName(const std::string& value) { name = value; }

    void move(int dx, int dy)
    {
        setX(getX() + dx);
        setY(getY() + dy);
    }
};

int Animal::quantity = 0;
int Animal::nextID = 1;

int main()
{
    SetConsoleOutputCP(65001);
    Animal animal1("eitis", 0, 9, 0, 0.75d);
    animal1.print();
    Animal an2("Kostas", 9, 1551, 50, 0.5d);
    an2.print();
    animal1.print();
    an2.setX(908);
    an2.print();

    Animal* anis = new Animal("Milda", 9, 8, 270, 0.7d);
    anis->print();
    delete anis; //Butinas

    Animal* darVienas = new Animal("haha");
    darVienas->print();
    delete darVienas;


    //statinis masyvas
    cout << "Statinis masyvas." << '\n';
    Animal* s_masyvas[10];
    for(int i = 0; i < 10; ++i)
    {
        s_masyvas[i] = new Animal("s_animal " + to_string(i), 8, 9, 5, .5d*i);
    }


    //dinaminis masyvas
    cout << "Dinaminis masyvas" << '\n';
    Animal** d_masyvas = new Animal*[10];
    for(int i = 0; i < 10; ++i){
        d_masyvas[i] = new Animal("d_animal " + to_string(i), 1);
    }

    cout << "Yra Animal tipo objektų " << Animal::getQuantity()<< '\n';

    for(int i = 0; i < sizeof(s_masyvas) / sizeof(s_masyvas[0]); ++i)
    {
        delete s_masyvas[i];
    }
    cout << "Yra Animal tipo objektų " << Animal::getQuantity()<< '\n';
    for(int i = 0; i < 10; ++i)
    {
        delete d_masyvas[i];
    }
    delete[] d_masyvas;
    cout << "Yra Animal tipo objektų " << Animal::getQuantity()<< '\n';


    return 0;
}
