#include "../dec/Motor.h"

// PRIVATE

void Motor::invertDirection() {
  digitalWrite(getLeftPin(), getDirection());
  digitalWrite(getRightPin(), !getDirection());
}

// PUBLIC

Motor::Motor(uint_8 leftPin, uint_8 rightPin, uint_8 enable, bool direction,
             uint_8 velocity) {
  this->leftPin = leftPin;
  this->rightPin = rightPin;
  this->enable = enable;
  this->direction = direction;
  this->velocity = velocity;
}

// ESPECIAL
void Motor::start() {
  pinMode(getLeftPin(), OUTPUT);
  pinMode(getRightPin(), OUTPUT);
  pinMode(getEnablePin(), OUTPUT);
}

// SETS

void Motor::setLeftPin(uint_8 leftPin) { this->leftPin = leftPin; }

void Motor::setRightPin(uint_8 rightPin) { this->rightPin = rightPin; }

void Motor::setEnablePin(uint_8 enable) { this->enable = enable; }

void Motor::setDirection(bool direction) { this->direction = direction; }

void Motor::setVelocity(uint_8 velocity) {
  this->velocity = velocity;

  analogWrite(this->getEnablePin(), this->velocity);
}

// GETS

uint_8 Motor::getLeftPin() { return this->leftPin; }

uint_8 Motor::getRightPin() { return this->rightPin; }

uint_8 Motor::getEnablePin() { return this->enablePin; }

bool Motor::getDirection() { return this->direction; }

uint_8 Motor::getVelocity() { return this->velocity; }

void Motor::toggleDirection() {
  this->setDirection(!this->getDirection());
  this->invertDirection();
}

void Motor::run() {
  analogWrite(this->getEnablePin(), this->getVelocity());
  digitalWrite(this->getLeftPin(), !this->getDirection());
  digitalWrite(this->getRightPin(), this->getDirection());
}

void Motor::stop() {
  digitalWrite(this->getLeftPin(), false);
  digitalWrite(this->getRightPin(), false);
}
