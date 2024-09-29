#pragma once

#ifndef ANIMAL_H
#define ANIMAL_H

#include "pair_uint.h"
#include "direction.h"

namespace model {
	namespace animal {
		class Animal {
		protected:
			data::PairUint _position;
			data::Direction _direction;
			unsigned int _stability;
			unsigned int _maxAge;
			unsigned int _step;
			char _symbol;
			unsigned int _birthOrder;

			unsigned int _age;
			unsigned int _stepsSinceLastChange;
			bool _isAlive;

		public:
			Animal(const data::PairUint& pos, data::Direction dir, unsigned int stab, unsigned int maxAge, unsigned int step, char symbol, unsigned int order);
			virtual ~Animal() = default;

			const data::PairUint& GetPosition() const;
			unsigned int GetAge() const;
			char GetSymbol() const;
			unsigned int GetMaxAge() const;
			data::Direction GetDirection();
			unsigned int GetStability();
			bool IsAlive() const;
			void Die();

			virtual void Move(const data::PairUint& fieldSize) = 0;
			virtual bool CanReproduce() = 0;
			virtual void ResetReproduce() = 0;

			void UpdateAge();
			void RotateDirection();
			void MoveInDirection(const data::PairUint& fieldSize, unsigned int step);
			void HandleDirectionChange();
			bool IsOlderThan(const Animal& other) const;
		};
	}
}

#endif // ANIMAL_H