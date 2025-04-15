#ifndef PILE_H
#define PILE_H

#include <iostream>
#include <stdexcept>

namespace m1 {

    template <typename T>
    class Stack {
    private:
        T* elements;
        size_t max_size;
        size_t top;

    public:
        Stack(size_t max_size) : max_size(max_size), top(0) {
            elements = new T[max_size];
        }

        ~Stack() {
            delete[] elements;
        }

        size_t get_max_size() const { //tout ici (dans .h) pour éviter de devoir ajouter chaque fois template <typename T>
            return max_size;
        }

        size_t get_top() const {
            return top;
        }

        bool is_empty() const {
            return top == 0;
        }

        void empty() {
            top = 0;
        }

        void push(T item) {
            if (top >= max_size) {
                throw std::overflow_error("Stack overflow: maximum size reached.");
            }
            elements[top++] = item; //il donne à elements[top] la valeur de item et après il incrémente top
        }

        T pop() {
            if (is_empty()) {
                throw std::underflow_error("Stack underflow: no elements to pop.");
            }
            return elements[--top]; //il decrémente top et il donne la valeur de elements[top-1]
        }

        T* get_elements() const {
            return elements;
        }
    };

    // Opérateur externe
    template <typename T>
    std::ostream& operator<<(std::ostream& os, const Stack<T>& stack) {
        os << "[ ";
        for (size_t i = 0; i < stack.get_top(); ++i) { //get_top pour que get_pop marche
            os << stack.get_elements()[stack.get_top() - 1 - i];  //ou contateur decrémentale
            if (i < stack.get_top() - 1) os << std::endl;
        }
        os << " ]";
        return os;
    }

} // namespace m1

#endif // PILE_H

