#include "animal_options.h"

#pragma region Constructors

data::AnimalOptions::AnimalOptions(PairUint pos, Direction dir, unsigned int stab, AnimalType type)
	: _position(pos), _direction(dir), _stability(stab), _type(type) { }

#pragma endregion

#pragma region GetsSets

data::PairUint data::AnimalOptions::GetPosition() const {
	return _position;
}

data::Direction data::AnimalOptions::GetDirection() const {
	return _direction;
}

unsigned int data::AnimalOptions::GetStability() const {
	return _stability;
}

data::AnimalType data::AnimalOptions::GetType() const {
	return _type;
}

#pragma endregion