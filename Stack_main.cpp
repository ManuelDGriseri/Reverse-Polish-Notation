#include "pile.h"
#include <iostream>
using namespace m1;

int main() {
    try {
        Stack<int> stack(5);

        // Ajouter des éléments dans la pile
        stack.push(3);
        stack.push(20);
        stack.push(5);
        stack.push(57);
        stack.push(100);
        //stack.push(100);  stack overflow

        // Afficher la pile
        std::cout << "État de la pile : " << std::endl << stack << std::endl;

        // Dépiler les éléments
        while (!stack.is_empty()) {
            std::cout << "Élément dépilé : " << stack.pop() << std::endl;
        }

        // Afficher la pile vide
        std::cout << "Pile vidée. État : " << stack << std::endl;

    }
    catch (const std::exception& e) {
        std::cerr << "Erreur : " << e.what() << std::endl;
    }

    return 0;
}
