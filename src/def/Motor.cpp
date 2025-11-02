#include "../dec/Motor.h"

// PRIVATE

void Motor::invertDirection() {
  digitalWrite(getLeftPin(), getDirection());
  digitalWrite(getRightPin(), !getDirection());
}

// PUBLIC

Motor::Motor(uint8_t leftPin, uint8_t rightPin, uint8_t enable, bool direction,
             uint8_t velocity) {
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

void Motor::setLeftPin(uint8_t leftPin) { this->leftPin = leftPin; }

void Motor::setRightPin(uint8_t rightPin) { this->rightPin = rightPin; }

void Motor::setEnablePin(uint8_t enable) { this->enable = enable; }

void Motor::setDirection(bool direction) { this->direction = direction; }

void Motor::setVelocity(uint8_t velocity) {
  this->velocity = velocity;

  analogWrite(this->getEnablePin(), this->velocity);
}

// GETS

uint8_t Motor::getLeftPin() { return this->leftPin; }

uint8_t Motor::getRightPin() { return this->rightPin; }

uint8_t Motor::getEnablePin() { return this->enablePin; }

bool Motor::getDirection() { return this->direction; }

uint8_t Motor::getVelocity() { return this->velocity; }

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
