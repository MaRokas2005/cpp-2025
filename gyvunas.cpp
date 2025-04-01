#include <bits/stdc++.h>

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
        Animal::quantity++;
        std::cout << "Gyvūnas sukurtas. ID: " << getID();
        std::cout << ", vardas: " << getName() << ". " << '\n';
    }
    ~Animal() {
        Animal::quantity--;
        std::cout << "Gyvūno objektas su ID: " << getID();
        cout << " buvo sunaikintas. Liko " << getQuantity() << " objektų." << '\n';
    }
    void print() const
    {
        std::cout << "{\n\tCLASS={Animal}, \n\tID: " << ID;
        std::cout << ", \n\tvardas: " << name;
        std::cout << ", \n\tx: " << x;
        std::cout << ", \n\ty: " << y;
        std::cout << ", \n\tkryptis: " << direction;
        std::cout << ", \n\tkiekis: " << quantity;
        std::cout << ", \n\tgreitis: " << getSpeed() << "\n}\n";
    }
    int getID() const { return ID; }
    int getX() const { return x; }
    int getY() const { return y; }
    int getSpeed() const { return speed * speedMultiplier; }
    double getDirection() const { return direction; }
    std::string getName() const { return name; }
    static int getQuantity() { return quantity; }

    void setX(int value, bool print = true)
    {
        if(print) std::cout << "Gyvūno, vardu " << getName() << ", x reikšmė pakeista iš " << getX() << " į " << value << '\n';
        x = value;
    }
    void setY(int value, bool print = true)
    {
        if(print) std::cout << "Gyvūno, vardu " << getName() << ", y reikšmė pakeista iš " << getY() << " į " << value << '\n';
        y = value;
    }
    void setName(const std::string& value, bool print = true)
    {
        if(print) std::cout << "Gyvūno vardas pakeistas iš " << getName() << " į " << value << '\n';
        name = value;
    }

    void move(int dx, int dy)
    {
        std::cout << "Gyvūnas, vardu " << name << ", juda iš (x: " << getX() << ", y: " << getY() << ") į ";
        setX(getX() + dx, false);
        setY(getY() + dy, false);
        std::cout << "(x: " << getX() + dx << ", y: " << getY() << ").\n";
    }
};

int Animal::quantity = 0;
int Animal::nextID = 1;

int main()
{
    Animal kiskis{"Kiškis", 0, 9, 0, 0.75d};
    kiskis.print();

    Animal meska{"Meška", 9, 1551, 50, 0.5d};
    meska.print();
    meska.setX(908);
    meska.setY(-17);
    meska.setName("Meškinas");
    meska.print();


    Animal* vilkas = new Animal{"Vilkas", 9, 8, 270, 0.7d};
    vilkas->print();
    delete vilkas; //Butinas


    //statinis masyvas
    cout << "\n\nStatinis masyvas." << '\n';
    Animal* s_masyvas[10];
    for(int i = 0; i < 10; ++i)
    {
        s_masyvas[i] = new Animal{"s_animal_" + to_string(i), 8, 9, 5, .5d*i};
    }

    Animal* p_d_masyvas[2]; // = new Animal[2]{Animal("animal1"), Animal("animal2")};


    //dinaminis masyvas
    cout << "\n\nDinaminis masyvas" << '\n';
    Animal* d_masyvas[10];
    for(int i = 0; i < 10; ++i){
        d_masyvas[i] = new Animal{"d_animal_" + to_string(i), 1};
    }

    cout << "\nYra " << Animal::getQuantity() << " Animal tipo objektų.\n";

    cout << "\nIštrinamas statinio masyvo objektai:\n";
    for(int i = 0; i < sizeof(s_masyvas) / sizeof(s_masyvas[0]); ++i)
    {
        delete s_masyvas[i];
    }
    cout << "\nYra " << Animal::getQuantity() << " Animal tipo objektų.\n";

    cout << "\nIštrinamas dinaminio masyvo objektai:\n";
    for(int i = 0; i < 10; ++i)
    {
        delete d_masyvas[i];
    }
    delete[] d_masyvas;

    cout << "\nYra " << Animal::getQuantity() << " Animal tipo objektų.\n";

    Animal ozka{"Ožka", 9, -8, 4, .9};
    ozka.move(-8, 9);


    return 0;
}
