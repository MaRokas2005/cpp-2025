/**
 * @file main.cpp
 * @author Rokas Braidokas (rokasbraidokas@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2025-05-06
 * 
 * @copyright Copyright (c) 2025
 * 
 */
#include "animal/Animal.h"
#include "movement/NormalMovement.h"
#include "movement/DiagonalMovement.h"
#include <fstream>
#include <cassert>
#include <iostream>

int main() {
    Animal a("Wolf", std::make_unique<NormalMovement>(2.0));
    a.move(3, 0);
    std::cout << a.getName() << " at (" << a.getX() << "," << a.getY() << ")\n";

    a.setMovementStrategy(std::make_unique<DiagonalMovement>(3.0));
    a.move(1, 1);
    std::cout << "After diagonal: (" << a.getX() << "," << a.getY() << ")\n";

    // Serialize
    {
        std::ofstream ofs("animal.bin", std::ios::binary);
        ofs << a;
    }
    // Deserialize
    Animal b("Placeholder", std::make_unique<NormalMovement>());
    {
        std::ifstream ifs("animal.bin", std::ios::binary);
        ifs >> b;
    }
    auto bx = b.getX(), by = b.getY();
    b.move(2, 0);
    assert(b.getX() != bx || b.getY() != by);
    std::cout << "Deserialized and moved: (" << b.getX() << "," << b.getY() << ")\n";

    std::cout << "All tests passed.\n";
    return 0;
}