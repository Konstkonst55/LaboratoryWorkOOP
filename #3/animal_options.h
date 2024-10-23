#pragma once

#ifndef ANIMAL_OPTIONS_H
#define ANIMAL_OPTIONS_H

#include "pair_uint.h"
#include "direction.h"
#include "animal_type.h"

namespace data {
	class AnimalOptions {
	private:
		PairUint _position;
		Direction _direction;
		unsigned int _stability;
		AnimalType _type;
	
	public:
		AnimalOptions(PairUint pos = { 0u, 0u }, Direction dir = Direction::Right, unsigned int stab = 0u, AnimalType type = AnimalType::Rabbit);

		PairUint GetPosition() const;
		Direction GetDirection() const;
		unsigned int GetStability() const;
		AnimalType GetType() const;
	};
}

#endif // ANIMAL_OPTIONS_H
