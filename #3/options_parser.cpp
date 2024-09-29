#include "options_parser.h"

#include <stdexcept>
#include <fstream>
#include <sstream>

#pragma region Constructors

data::OptionsParser::OptionsParser(const std::string& path) : _filePath(path) { }

#pragma endregion

#pragma region Logic

void data::OptionsParser::Parse(std::vector<AnimalOptions>& animals, PairUint& size, unsigned int& turns) {
    std::ifstream file(_filePath);

    if (!file.is_open()) {
        throw std::runtime_error("Unable to open file: " + _filePath);
    }

    if (!(file >> size.x >> size.y >> turns)) {
        throw std::runtime_error("Error reading width, height or turns from file");
    }

    size_t numRabbits, numFoxes;

    if (!(file >> numRabbits >> numFoxes)) {
        throw std::runtime_error("Error reading number of rabbits or foxes from file");
    }

    for (size_t i = 0; i < numRabbits; i++) {
        unsigned int x, y, direction, stability;

        if (!(file >> x >> y >> direction >> stability)) {
            throw std::runtime_error("Error reading rabbit data from file");
        }

        animals.emplace_back(data::PairUint(x, y), static_cast<Direction>(direction), stability, data::AnimalType::Rabbit);
    }

    for (size_t i = 0; i < numFoxes; i++) {
        unsigned int x, y, direction, stability;

        if (!(file >> x >> y >> direction >> stability)) {
            throw std::runtime_error("Error reading fox data from file");
        }

        animals.emplace_back(data::PairUint(x, y), static_cast<Direction>(direction), stability, data::AnimalType::Fox);
    }
}

#pragma endregion