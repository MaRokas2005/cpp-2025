/**
 * @file DiagonalMovement.h
 * @author Rokas Braidokas (rokasbraidokas@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2025-05-06
 * 
 * @copyright Copyright (c) 2025
 * 
 */
#ifndef DIAGONALMOVEMENT_H
#define DIAGONALMOVEMENT_H

#include "SpeedBasedMovement.h"
#include <cmath>

/**
 * @brief Allows diagonal moves at constant cost.
 * 
 */
class DiagonalMovement : public SpeedBasedMovement {
public:
    /**
     * @brief Construct a new Diagonal Movement object
     * 
     * @param mult initial speed multiplier, default = 1.0
     */
    explicit DiagonalMovement(double mult = 1.0)
      : SpeedBasedMovement(mult)
    {}
    /**
     * @brief Move the animal by (dx,dy), updating x,y in place.
     * 
     * @param x int& x coordinate of the animal
     * @param y int& y coordinate of the animal
     * @param dx int x displacement
     * @param dy int y displacement
     */
    void move(int& x, int& y, int dx, int dy) override {
        double dist = std::hypot(dx, dy);
        if (dist > 0) {
            x += static_cast<int>((dx / dist) * speedMultiplier_);
            y += static_cast<int>((dy / dist) * speedMultiplier_);
        }
    }

    /**
     * @brief Return a tag to identify concrete type in the stream.
     * 
     * @return char 
     */
    char typeTag() const override { return 'D'; }
};

#endif // DIAGONALMOVEMENT_H