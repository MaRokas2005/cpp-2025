/**
 * @file SpeedBasedMovement.h
 * @author Rokas Braidokas (rokasbraidokas@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2025-05-06
 * 
 * @copyright Copyright (c) 2025
 * 
 */
#ifndef SPEEDBASEDMOVEMENT_H
#define SPEEDBASEDMOVEMENT_H

#include "MovementStrategy.h"

/**
 * @brief Base class for strategies that share a speedMultiplier.
 * 
 */
class SpeedBasedMovement : public MovementStrategy {
protected:
    double speedMultiplier_;

public:
    /**
     * @brief Construct a new Speed Based Movement object
     * 
     * @param mult speed multiplier, default = 1.0
     */
    explicit SpeedBasedMovement(double mult = 1.0)
      : speedMultiplier_(mult)
    {}

    /**
     * @brief Serialize strategy-specific data to a binary stream.
     * 
     * @param os output stream to write to
     */
    void serialize(std::ostream& os) const override {
        os.write(reinterpret_cast<const char*>(&speedMultiplier_), sizeof(speedMultiplier_));
    }

    /**
     * @brief Deserialize strategy-specific data from a binary stream.
     * 
     * @param is input stream to read from
     */
    void deserialize(std::istream& is) override {
        is.read(reinterpret_cast<char*>(&speedMultiplier_), sizeof(speedMultiplier_));
    }

    /**
     * @brief Get the speed multiplier
     * 
     * @return double 
     */
    double getSpeedMultiplier() const { return speedMultiplier_; }

    /**
     * @brief Set the speed multiplier
     * 
     * @param m 
     */
    void setSpeedMultiplier(double m) { speedMultiplier_ = m; }
};

#endif // SPEEDBASEDMOVEMENT_H