/**
 * @file MovementStrategy.h
 * @author Rokas Braidokas (rokasbraidokas@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2025-05-06
 * 
 * @copyright Copyright (c) 2025
 * 
 */
#ifndef MOVEMENTSTRATEGY_H
#define MOVEMENTSTRATEGY_H

#include <istream>
#include <ostream>

/// @brief Abstract interface for animal movement behavior.
class MovementStrategy {
public:
    /**
     * @brief Destroy the Movement Strategy object
     * 
     */
    virtual ~MovementStrategy() = default;

    /**
     * @brief Move the animal by (dx,dy), updating x,y in place.
     * 
     * @param x int& x coordinate of the animal
     * @param y int& y coordinate of the animal
     * @param dx int x displacement
     * @param dy int y displacement
     */
    virtual void move(int& x, int& y, int dx, int dy) = 0;

    /**
     * @brief Serialize strategy-specific data to a binary stream.
     * 
     * @param os output stream to write to
     */
    virtual void serialize(std::ostream& os) const = 0;

    /**
     * @brief Deserialize strategy-specific data from a binary stream.
     * 
     * @param is input stream to read from
     */
    virtual void deserialize(std::istream& is) = 0;

    /**
     * @brief Return a tag to identify concrete type in the stream.
     * 
     * @return char 
     */
    virtual char typeTag() const = 0;
};

#endif // MOVEMENTSTRATEGY_H