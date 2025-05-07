// File: NormalMovement.h
#ifndef NORMALMOVEMENT_H
#define NORMALMOVEMENT_H

#include "SpeedBasedMovement.h"

/// @brief Simple axis-aligned movement.
class NormalMovement : public SpeedBasedMovement {
public:
    /**
     * @brief Construct a new Normal Movement object
     * 
     * @param mult initial speed multiplier, default = 1.0
     */
    explicit NormalMovement(double mult = 1.0)
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
        x += static_cast<int>(dx * speedMultiplier_);
        y += static_cast<int>(dy * speedMultiplier_);
    }

    /**
     * @brief Return a tag to identify concrete type in the stream.
     * 
     * @return char 
     */
    char typeTag() const override { return 'N'; }
};

#endif // NORMALMOVEMENT_H