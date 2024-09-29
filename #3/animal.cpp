#include "animal.h"

#include <map>

#pragma region Constructors

model::animal::Animal::Animal(const data::PairUint& pos, data::Direction dir, unsigned int stab,unsigned int maxAge, unsigned int step, char symbol, unsigned int order)
    : _position(pos), _direction(dir), _stability(stab), _maxAge(maxAge), _step(step), _symbol(symbol), _birthOrder(order), _age(0), _stepsSinceLastChange(0), _isAlive(true) {}

#pragma endregion

#pragma region GetsSets

const data::PairUint& model::animal::Animal::GetPosition() const {
    return _position;
}

unsigned int model::animal::Animal::GetAge() const {
    return _age;
}

char model::animal::Animal::GetSymbol() const {
    return _symbol;
}

unsigned int model::animal::Animal::GetMaxAge() const{
    return _maxAge;
}

data::Direction model::animal::Animal::GetDirection() { 
    return _direction;
}

unsigned int model::animal::Animal::GetStability() {
    return _stability;
}

bool model::animal::Animal::IsAlive() const {
    return _isAlive;
}

#pragma endregion

#pragma region Logic

void model::animal::Animal::Die() {
    _isAlive = false;
}

void model::animal::Animal::UpdateAge() {
    if (++_age >= _maxAge) {
        Die();
    }
}

void model::animal::Animal::RotateDirection() {
    _direction = data::RotationMap.at(_direction);
}

void model::animal::Animal::MoveInDirection(const data::PairUint& fieldSize, unsigned int step) {
    auto delta = data::DirectionDeltas.at(_direction);

    _position.x = (_position.x + delta.first * step + fieldSize.x) % fieldSize.x;
    _position.y = (_position.y + delta.second * step + fieldSize.y) % fieldSize.y;
}

void model::animal::Animal::HandleDirectionChange() {
    _stepsSinceLastChange++;

    if (_stepsSinceLastChange >= _stability) {
        RotateDirection();

        _stepsSinceLastChange = 0;
    }
}

bool model::animal::Animal::IsOlderThan(const Animal& other) const {
    return std::tie(_age, _birthOrder) < std::tie(other._age, other._birthOrder);
}

#pragma endregion