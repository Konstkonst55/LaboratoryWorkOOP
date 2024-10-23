#pragma once

#ifndef RABBIT_H
#define RABBIT_H

#include "animal.h"
#include "pair_uint.h"
#include "direction.h"

namespace model {
	namespace animal {
		class Rabbit : public Animal {
		private:
			bool _reproducedAt5, _reproducedAt10;

		public:
			Rabbit() = default;
			Rabbit(const data::PairUint& pos = { 0u, 0u }, data::Direction dir = data::Direction::Right, unsigned int stab = 0u, unsigned int order = 0u);

			void Move(const data::PairUint& fieldSize) override;
			bool CanReproduce() override;
			void ResetReproduce() override;
		};
	}
}

#endif // RABBIT_H
