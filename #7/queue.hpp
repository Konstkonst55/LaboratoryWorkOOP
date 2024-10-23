#ifndef QUEUE_H
#define QUEUE_H

#include "node.hpp"
#include "list.hpp"

namespace ds {
    template <typename T = int>
    class Queue : public List<T> {
    private:
        Node<T>* _tail;

    public:
        Queue() : List<T>(), _tail(nullptr) { }

        ~Queue() {
            this->Clear();
            _tail = nullptr;
        }

        void Push(T value) override {
            Node<T>* newNode = new Node<T>(value);

            if (this->IsEmpty()) {
                this->_head = newNode;
                _tail = newNode;
            }
            else {
                _tail->next = newNode;
                _tail = newNode;
            }

            this->_size++;
        }

        T Pop() {
            if (this->IsEmpty()) {
                throw std::out_of_range("Queue is empty");
            }

            Node<T>* frontNode = this->_head;
            T value = frontNode->data;
            this->_head = this->_head->next;
            delete frontNode;
            this->_size--;

            if (this->IsEmpty()) {
                _tail = nullptr;
            }

            return value;
        }
    };
}

#endif // QUEUE_H