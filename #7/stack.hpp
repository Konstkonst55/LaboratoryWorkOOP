#pragma once

#ifndef STACK_H
#define STACK_H

#include "node.hpp"
#include "list.hpp"

namespace ds {
	template <typename T = int>
	class Stack : public List<T> {
    public:
        Stack() : List<T>() { }

        ~Stack() {
            this->Clear();
        }

        void Push(T value) override {
            Node<T>* newNode = new Node<T>(value);
            newNode->next = this->_head;
            this->_head = newNode;
            this->_size++;
        }

        T Pop() {
            if (this->IsEmpty()) {
                throw std::out_of_range("Stack is empty");
            }

            Node<T>* topNode = this->_head;
            T value = topNode->data;
            this->_head = this->_head->next;
            delete topNode;
            this->_size--;

            return value;
        }
	};
}

#endif // STACK_H