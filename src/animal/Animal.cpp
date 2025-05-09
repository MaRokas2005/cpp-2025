/**
 * @file Animal.cpp
 * @author Rokas Braidokas (rokasbraidokas@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2025-05-06
 * 
 * @copyright Copyright (c) 2025
 * 
 */
#include "Animal.h"
#include "../movement/NormalMovement.h"
#include "../movement/DiagonalMovement.h"
#include <sstream>
#include <fstream>
#include <stdexcept>

int Animal::nextID_ = 1;

Animal::Animal(const std::string& name,
               std::unique_ptr<MovementStrategy> strat)
  : ID_(nextID_++), x_(0), y_(0), name_(name), mover_(std::move(strat))
{}

Animal::Animal(const Animal& o)
  : ID_(nextID_++), x_(o.x_), y_(o.y_), name_(o.name_)
{
    std::stringstream ss;
    char tag = o.mover_->typeTag();
    o.mover_->serialize(ss);
    if (tag == 'N') mover_ = std::make_unique<NormalMovement>();
    else if (tag == 'D') mover_ = std::make_unique<DiagonalMovement>();
    else throw AnimalException("Nežinoma judėjimo strategija!!!");
    mover_->deserialize(ss);
}

Animal& Animal::operator=(const Animal& o) {
    if (this == &o) return *this;
    x_ = o.x_; y_ = o.y_; name_ = o.name_;
    std::stringstream ss;
    char tag = o.mover_->typeTag();
    o.mover_->serialize(ss);
    if (tag == 'N') mover_ = std::make_unique<NormalMovement>();
    else if (tag == 'D') mover_ = std::make_unique<DiagonalMovement>();
    else throw AnimalException("Nežinoma judėjimo strategija!!!");
    mover_->deserialize(ss);
    return *this;
}

void Animal::move(int dx, int dy) {
    mover_->move(x_, y_, dx, dy);
}

void Animal::setMovementStrategy(std::unique_ptr<MovementStrategy> strat) {
    mover_ = std::move(strat);
}

int Animal::getID() const { return ID_; }
int Animal::getX()  const { return x_; }
int Animal::getY()  const { return y_; }
std::string Animal::getName() const { return name_; }

std::ostream& operator<<(std::ostream& os, const Animal& a) {
    os.write(reinterpret_cast<const char*>(&a.x_),  sizeof(a.x_));
    os.write(reinterpret_cast<const char*>(&a.y_),  sizeof(a.y_));
    size_t len = a.name_.size();
    os.write(reinterpret_cast<const char*>(&len), sizeof(len));
    os.write(a.name_.data(), len);
    char tag = a.mover_->typeTag();
    os.write(&tag, 1);
    a.mover_->serialize(os);
    return os;
}

std::istream& operator>>(std::istream& is, Animal& a) {
    is.read(reinterpret_cast<char*>(&a.x_), sizeof(a.x_));
    is.read(reinterpret_cast<char*>(&a.y_), sizeof(a.y_));
    size_t len;
    is.read(reinterpret_cast<char*>(&len), sizeof(len));
    a.name_.resize(len);
    is.read(&a.name_[0], len);
    char tag;
    is.read(&tag, 1);
    std::unique_ptr<MovementStrategy> strat;
    if (tag == 'N') strat = std::make_unique<NormalMovement>();
    else if (tag == 'D') strat = std::make_unique<DiagonalMovement>();
    else throw AnimalException("Load: unknown strategy tag");
    strat->deserialize(is);
    a.mover_ = std::move(strat);
    return is;
}