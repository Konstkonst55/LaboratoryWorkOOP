#include "rabbit.h"

#pragma region Constructors

model::animal::Rabbit::Rabbit(const data::PairUint& pos, data::Direction dir, unsigned int stab, unsigned int order)
    : Animal(pos, dir, stab, 10, 1, 'R', order), _reproducedAt5(false), _reproducedAt10(false) { }

#pragma endregion

#pragma region Logic

void model::animal::Rabbit::Move(const data::PairUint& fieldSize) {
    MoveInDirection(fieldSize, _step);
    HandleDirectionChange();
}

bool model::animal::Rabbit::CanReproduce() {
    return (_age == 5 && !_reproducedAt5) || (_age == 10 && !_reproducedAt10);
}

void model::animal::Rabbit::ResetReproduce() {
    if (_age == 5) {
        _reproducedAt5 = true;
    }

    if (_age == 10) {
        _reproducedAt10 = true;
    }
}

#pragma endregion