#pragma once

#ifndef NODE_H
#define NODE_H

namespace ds {
	template <typename T = int>
	struct Node {
		T data;
		Node* next;

		Node() = default;
		Node(T value) : data(value), next(nullptr) { }
		~Node() = default;
	};
}

#endif // NODE_H