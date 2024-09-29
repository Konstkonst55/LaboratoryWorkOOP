#pragma once

#ifndef OPTIONS_PARSER_H
#define OPTIONS_PARSER_H

#include "animal_options.h"
#include <string>
#include <vector>

namespace data {
	class OptionsParser {
	private:
		std::string _filePath;

	public:
		OptionsParser(const std::string& path);

		void Parse(std::vector<AnimalOptions>& animals, PairUint& size, unsigned int& turns);
	};
}

#endif // OPTIONS_PARSER_H
