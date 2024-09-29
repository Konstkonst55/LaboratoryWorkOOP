#pragma once

#ifndef GAME_FIELD_H
#define GAME_FIELD_H

#include "pair_uint.h"
#include "rabbit.h"
#include "fox.h"
#include <vector>
#include <ostream>
#include <functional>

namespace view {
	class GameField {
	private:
		const char _emptySymbol = '.';
		const data::PairUint& _size;

		std::vector<std::reference_wrapper<model::animal::Rabbit>> _rabbits;
		std::vector<std::reference_wrapper<model::animal::Fox>> _foxes;

		void MoveAnimals();
		void HandleFeeding();
		void HandleReproduction();
		void HandleAging();

	public:
		GameField(const data::PairUint& size);

		void AddRabbit(model::animal::Rabbit& rabbit);
		void AddFox(model::animal::Fox& fox);

		void Step();
		void Print(std::ostream& os);
	};
}

#endif // GAME_FIELD_H
