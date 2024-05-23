
#ifndef UNTITLED_PILA_H
#define UNTITLED_PILA_H

#endif //UNTITLED_PILA_H

#include "pila.cpp"


template<typename T>
class pila:private DLList<T>
        {
        public:
    struct N {
        T data;
        N* next;
        N* prev;

        explicit N(const T& data, N* next = nullptr, N* prev = nullptr)
                : data(data), next(next), prev(prev) {}
    };

    class iterator {
    public:
        explicit iterator(N* node = nullptr) : node(node) {}

        T& operator*() {
            return node->data;
        }

        iterator& operator++() {
            if (node) {
                node = node->next;
            }
            return *this;
        }

        iterator& operator--() {
            if (node) {
                node = node->prev;
            }
            return *this;
        }

        bool operator==(const iterator& other) const {
            return node == other.node;
        }

        bool operator!=(const iterator& other) const {
            return node != other.node;
        }

    private:
        N* node;
    };
    pila() : head(nullptr), tail(nullptr) {}
            iterator end() {
                return iterator();
            }

            void push_back(const T& data)

            {
                N* newNode = new N(data, nullptr, tail);
                if (tail) {
                    tail->next = newNode;
                }
                tail = newNode;
                if (head == nullptr) {
                    head = tail;
                }
            }
            void pop_back()
            {
                if (tail) {
                    N* temp = tail;
                    tail = tail->prev;
                    delete temp;
                    if (tail) {
                        tail->next = nullptr;
                    } else {
                        head = nullptr;
                    }
                }
            }
            void print()
            {
                N* temp = head;
                while (temp) {
                    std::cout << temp->data << " ";
                    temp = temp->next;
                }
                std::cout << std::endl;
            }

            void clear() {
                while (head) {
                    pop_back();
                }
            }
            ~pila() {
                clear();
            }




private:
            N* head;
            N* tail;


        };


