#include "fox.h"

#pragma region Constructors

model::animal::Fox::Fox(const data::PairUint& pos, data::Direction dir, unsigned int stab, unsigned int order)
    : Animal(pos, dir, stab, 15, 2, 'F', order), _rabitsEaten(0) {}

#pragma endregion

#pragma region Logic

void model::animal::Fox::Move(const data::PairUint& fieldSize) {
    MoveInDirection(fieldSize, _step);
    HandleDirectionChange();
}

bool model::animal::Fox::CanReproduce() {
    return _rabitsEaten >= _foodAmountForReproduction;
}

void model::animal::Fox::ResetReproduce() {
    _rabitsEaten = 0;
}

void model::animal::Fox::EatRabbit() {
    _rabitsEaten++;
}

void model::animal::Fox::EatRabbits(unsigned int rabbitsCount) {
    _rabitsEaten+=rabbitsCount;
}

#pragma endregion