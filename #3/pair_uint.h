#pragma once

#ifndef PAIR_UINT_H
#define PAIR_UINT_H

namespace data {
	class PairUint {
	public:
		unsigned int x, y;

		PairUint(unsigned int x = 0u, unsigned int y = 0u);

		bool operator==(const PairUint& other) const;
		bool operator!=(const PairUint& other) const;
		bool operator>(const PairUint& other) const;
		bool operator<(const PairUint& other) const;
	};
}

#endif // PAIR_UINT_H