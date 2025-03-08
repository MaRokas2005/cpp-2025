# Pasirinkau daryti klasę gyvūnas pirmai užduočiai

## Paleidimas
```
make main
```
arba
```
g++ -o gyvunas.exe gyvunas.cpp
gyvunas.exe
```

## Klasės struktūra
### Kintamieji
```cpp
protected:
const int ID
int x, y
double direction
double speedMultiplier
std::string name
private:
static int quantity
static int nextID
static constexpr int speed = 100
```
### Metodai
```cpp
Animal(const std::string& name, int x = 0, int y = 0, double direction = 0.0d, double speedMultiplier = 1.0d)
~Animal()
void print() const
int getID() const
int getX() const
int getY() const
int getSpeed() const
double getDirection() const
std::string getName() const
static int getQuantity()
void setX(int value, bool print = true)
void setY(int value, bool print = true)
void setName(const std::string& value, bool print = true)
void move(int dx, int dy)
```
### Statinių kintamųjų inicializavimas
```cpp
int Animal::quantity = 0;
int Animal::nextID = 1;
```