#include "game_field.h"

#include <map>

#pragma region Constructors

view::GameField::GameField(const data::PairUint& size) : _size(size) { }

#pragma endregion

#pragma region Logic

void view::GameField::MoveAnimals() {
	for (auto& rabbit : _rabbits) {
		rabbit.get().Move(_size);
	}

	for (auto& fox : _foxes) {
		fox.get().Move(_size);
	}
}

void view::GameField::HandleFeeding() {
	std::map<data::PairUint, std::vector<std::reference_wrapper<model::animal::Rabbit>>> rabbitPositions;
	std::map<data::PairUint, std::vector<std::reference_wrapper<model::animal::Fox>>> foxPositions;

	for (auto& rabbit : _rabbits) {
		if (rabbit.get().IsAlive()) {
			rabbitPositions[rabbit.get().GetPosition()].push_back(rabbit);
		}
	}

	for (auto& fox : _foxes) {
		if (fox.get().IsAlive()) {
			foxPositions[fox.get().GetPosition()].push_back(fox);
		}
	}

	for (const auto& [pos, foxes] : foxPositions) {
		auto it = rabbitPositions.find(pos);

		if (it != rabbitPositions.end()) {
			auto& rabbits = it->second;

			if (!rabbits.empty()) {
				std::reference_wrapper<model::animal::Fox> seniorFox = foxes.front();

				for (auto& fox : foxes) {
					if (fox.get().IsOlderThan(seniorFox.get())) {
						seniorFox = fox;
					}
				}

				for (auto& rabbit : rabbits) {
					rabbit.get().Die();
				}

				seniorFox.get().EatRabbits(static_cast<unsigned int>(rabbits.size()));
			}
		}
	}
}

void view::GameField::HandleReproduction() {
	std::vector<model::animal::Rabbit> newRabbits;
	std::vector<model::animal::Fox> newFoxes;

	for (auto& rabbit : _rabbits) {
		if (rabbit.get().IsAlive() && rabbit.get().CanReproduce()) {
			newRabbits.emplace_back(rabbit.get().GetPosition(), rabbit.get().GetDirection(), rabbit.get().GetStability(), _rabbits.size() + newRabbits.size());
			rabbit.get().ResetReproduce();
		}
	}

	for (auto& fox : _foxes) {
		if (fox.get().IsAlive() && fox.get().CanReproduce()) {
			newFoxes.emplace_back(fox.get().GetPosition(), fox.get().GetDirection(), fox.get().GetStability(), _foxes.size() + newFoxes.size());
			fox.get().ResetReproduce();
		}
	}

	for (auto& newRabbit : newRabbits) {
		_rabbits.emplace_back(newRabbit);
	}

	for (auto& newFox : newFoxes) {
		_foxes.emplace_back(newFox);
	}
}

void view::GameField::HandleAging() {
	for (auto& rabbit : _rabbits) {
		if (rabbit.get().IsAlive()) {
			rabbit.get().UpdateAge();
		}
	}

	for (auto& fox : _foxes) {
		if (fox.get().IsAlive()) {
			fox.get().UpdateAge();
		}
	}
}

void view::GameField::AddRabbit(model::animal::Rabbit& rabbit) {
	_rabbits.emplace_back(rabbit);
}

void view::GameField::AddFox(model::animal::Fox& fox) {
	_foxes.emplace_back(fox);
}

void view::GameField::Step() {
	MoveAnimals();
	HandleFeeding();
	HandleReproduction();
	HandleAging();
}

void view::GameField::Print(std::ostream& os) {
	std::vector<std::vector<int>> field(static_cast<int>(_size.y), std::vector<int>(static_cast<int>(_size.x), 0u));

	for (const auto& rabbit : _rabbits) {
		if (rabbit.get().IsAlive()) {
			auto [x, y] = rabbit.get().GetPosition();
			field[y][x]++;
		}
	}

	for (const auto& fox : _foxes) {
		if (fox.get().IsAlive()) {
			auto [x, y] = fox.get().GetPosition();
			field[y][x]--;
		}
	}

	for (unsigned int y = 0; y < _size.y; ++y) {
		for (unsigned int x = 0; x < _size.x; ++x) {
			if (field[y][x] == 0) {
				os << _emptySymbol;
			}
			else {
				os << field[y][x];
			}

			os << "\t";
		}

		os << std::endl << std::endl;
	}
}

#pragma endregion