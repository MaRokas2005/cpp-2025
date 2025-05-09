/**
 * @file Animal.h
 * @author Rokas Braidokas (rokasbraidokas@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2025-05-06
 * 
 * @copyright Copyright (c) 2025
 * 
 */
#ifndef ANIMAL_H
#define ANIMAL_H

#include "../movement/MovementStrategy.h"
#include "exception/AnimalException.h"
#include <memory>
#include <string>
#include <iosfwd>

/**
 * @brief Represents an Animal with replaceable movement.
 * 
 */
class Animal {
    const int ID_;
    int x_, y_;
    std::string name_;
    std::unique_ptr<MovementStrategy> mover_;

    static int nextID_;
public:
    /**
     * @brief Construct a new Animal object
     * 
     * @param name animal name
     * @param strat initial movement strategy (default = NormalMovement)
     */
    Animal(const std::string& name,
           std::unique_ptr<MovementStrategy> strat);

    /**
     * @brief Copy preserves runtime strategy.
     * 
     * @param o Animal to copy from
     */
    Animal(const Animal& o);
    /**
     * @brief Copy assignment operator for the Animal class
     * 
     * @param o 
     * @return Animal& 
     */
    Animal& operator=(const Animal& o);

    /**
     * @brief Move by (dx,dy) via current strategy.
     * 
     * @param dx delta x
     * @param dy delta y
     */
    void move(int dx, int dy);

    /**
     * @brief Set the Movement Strategy object
     * 
     * @param strat strategy to set
     */
    void setMovementStrategy(std::unique_ptr<MovementStrategy> strat);

    /**
     * @brief get Identifier of the animal
     * 
     * @return int 
     */
    int getID()        const;
    /**
     * @brief get X coordinate of the animal
     * 
     * @return int 
     */
    int getX()         const;
    /**
     * @brief get Y coordinate of the animal
     * 
     * @return int 
     */
    int getY()         const;
    /**
     * @brief Get the Name object
     * 
     * @return std::string 
     */
    std::string getName() const;

    /**
     * @brief Binary serialization (writes x, y, name, then strategy tag + data).
     * 
     * @param os output stream
     * @param a animal to write
     * @return std::ostream& 
     */
    friend std::ostream& operator<<(std::ostream& os, const Animal& a);
    /**
     * @brief Binary deserialization (reads x, y, name, then strategy tag + data).
     * 
     * @param is input stream
     * @param a animal to read into
     * @return std::istream& 
     */
    friend std::istream& operator>>(std::istream& is, Animal& a);
};

#endif // ANIMAL_H