#pragma once

#ifndef LIST_H
#define LIST_H

#include "node.hpp"

namespace ds {
	template <typename T = int>
	class List {
	protected:
		Node<T>* _head;
		size_t _size;

	public:
		List() : _head(nullptr), _size(0) { }

		virtual ~List() {
			Clear();
		}

		size_t GetSize() const {
			return _size;
		}

		bool IsEmpty() const {
			return _size == 0;
		}

		void Clear() {
			Node<T>* current = _head;

			while (current) {
				Node<T>* next = current->next;
				delete current;
				current = next;
			}

			_head = nullptr;
			_size = 0;
		}

		virtual void Push(T value) = 0;
	};
}

#endif // LIST_H