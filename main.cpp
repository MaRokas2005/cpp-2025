#include<bits/stdc++.h>
#include "Animal.h"

using namespace std;

int main()
{
    std::ofstream logFile("test_results.txt");
    if (!logFile) {
        throw AnimalException("Nepavyko atidaryti failo test_results.txt");
    }

    try {
        Animal kiskis("Kiškis", 0, 9, 0, 0.75);
        kiskis.print();
        logFile << "Sukurta: Kiškis" << std::endl;

        Animal meska("Meška", 9, 1551, 50, 0.5);
        meska.print();
        meska.move(10, -20);
        logFile << "Meška pajudėjo." << std::endl;

        auto vilkas = std::make_unique<Animal>("Vilkas", 9, 8, 270, 0.7);
        vilkas->print();

        throw AnimalException("Testuojama AnimalException išimtis");
    } catch (const AnimalException& e) {
        std::cerr << "AnimalException: " << e.what() << std::endl;
        logFile << "AnimalException: " << e.what() << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Klaida: " << e.what() << std::endl;
        logFile << "Klaida: " << e.what() << std::endl;
    }

    logFile.close();
    return 0;
}