#pragma once

#ifndef FOX_H
#define FOX_H

#include "animal.h"
#include "pair_uint.h"
#include "direction.h"

namespace model {
	namespace animal {
		class Fox : public Animal {
		private:
			const unsigned int _foodAmountForReproduction = 2;
			unsigned int _rabitsEaten;

		public:
			Fox(const data::PairUint& pos = { 0u, 0u }, data::Direction dir = data::Direction::Right, unsigned int stab = 0u, unsigned int order = 0u);
			
			void Move(const data::PairUint& fieldSize) override;
			bool CanReproduce() override;
			void ResetReproduce() override;

			void EatRabbit();
			void EatRabbits(unsigned int rabbitsCount);
		};
	}
}

#endif // FOX_H