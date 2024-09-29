#include "pair_uint.h"

#pragma region Constructors

data::PairUint::PairUint(unsigned int x, unsigned int y) : x(x), y(y) { }

#pragma endregion

#pragma region Operators

bool data::PairUint::operator==(const PairUint& other) const {
    return this->x == other.x && this->y == other.y;
}

bool data::PairUint::operator!=(const PairUint& other) const {
    return !(*this == other);
}

bool data::PairUint::operator>(const PairUint& other) const {
    return (this->x > other.x) || (this->x == other.x && this->y > other.y);
}

bool data::PairUint::operator<(const PairUint& other) const {
    return (this->x < other.x) || (this->x == other.x && this->y < other.y);
}

#pragma endregion