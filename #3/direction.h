#pragma once

#ifndef DIRECTION_H
#define DIRECTION_H

#include <map>

namespace data {
	enum Direction {
		Up, Right, Down, Left
	};

	static const std::map<Direction, Direction> RotationMap = {
		{Direction::Up, Direction::Right},
		{Direction::Right, Direction::Down},
		{Direction::Down, Direction::Left},
		{Direction::Left, Direction::Up}
	};

	static const std::map<Direction, std::pair<unsigned int, unsigned int>> DirectionDeltas = {
		{Direction::Up, {0, -1}},
		{Direction::Right, {1, 0}},
		{Direction::Down, {0, 1}},
		{Direction::Left, {-1, 0}}
	};
}

#endif // DIRECTION_H