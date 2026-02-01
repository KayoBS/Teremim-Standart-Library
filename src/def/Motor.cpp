#include "../dec/Motor.h"

// PRIVATE

void Motor::invertDirection() {
  digitalWrite(getLeftPin(), getDirection());
  digitalWrite(getRightPin(), !getDirection());
}

// PUBLIC

Motor::Motor(byte leftPin, byte rightPin, byte enable, bool direction,
             byte velocity) {
  this->leftPin = leftPin;
  this->rightPin = rightPin;
  this->enablePin = enable;
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

void Motor::setDirection(bool direction) { this->direction = direction; }

void Motor::setVelocity(byte velocity) {
  this->velocity = velocity;

  analogWrite(this->getEnablePin(), this->velocity);
}

// GETS

byte Motor::getLeftPin() { return this->leftPin; }

byte Motor::getRightPin() { return this->rightPin; }

byte Motor::getEnablePin() { return this->enablePin; }

bool Motor::getDirection() { return this->direction; }

byte Motor::getVelocity() { return this->velocity; }

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
  analogWrite(this->getEnablePin(), 0);
}
