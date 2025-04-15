#include <iostream>
#include <cmath>  //pour sin, cos
#include <string>
#include "stack.h"
using namespace m1;

void CalcRPN(void) {
	try {
		Stack<double> stack(100);
		std::string input;
		double num,a,b;
		int n = 0;
		while (true) {
			std::cout << "0 pour sortir, 1 pour un numéro, 2 pour une opération :" << std::endl;
			std::cin >> n;

			if (n == 0) 
				break;

			else if (n == 1) {
				std::cout <<" "<< std::endl;
				std::cin >> num;
				stack.push(num);
			}

			else if (n == 2) {
				std::cout << " " << std::endl;
				std::cin >> input;
				if (input == "+") {
					if (stack.get_top() < 2)
						throw std::invalid_argument("Pas assez de numéros dans la pile.");
					a = stack.pop();
					b = stack.pop();
					stack.push(a + b);
				}
				else if (input == "-") {
					if (stack.get_top() < 2)
						throw std::invalid_argument("Pas assez de numéros dans la pile.");
					a = stack.pop();
					b = stack.pop();
					stack.push(a - b);
				}
				else if (input == "*") {
					if (stack.get_top() < 2)
						throw std::invalid_argument("Pas assez de numéros dans la pile.");
					a = stack.pop();
					b = stack.pop();
					stack.push(a * b);
				}
				else if (input == "/") {
					if (stack.get_top() < 2)
						throw std::invalid_argument("Pas assez de numéros dans la pile.");
					a = stack.pop();
					b = stack.pop();
					if (b==0)
						throw std::invalid_argument("Division par 0.");
					stack.push(a / b);
				}
				else if (input == "sin") {
					if (stack.is_empty())
						throw std::invalid_argument("Pas assez de numéros dans la pile.");
					a = stack.pop();
					stack.push(std::sin(a));
				}
				else if (input == "cos") {
					if (stack.is_empty())
						throw std::invalid_argument("Pas assez de numéros dans la pile.");
					a = stack.pop();
					stack.push(std::cos(a));
				}
				else
					throw std::invalid_argument("Opération non reconnu.");
			}

			else
				throw std::invalid_argument("n non acceptable.");

			std::cout << " " << std::endl;
			std::cout << "État de la pile : " << std::endl << stack << std::endl;
			std::cout << " " << std::endl;
		}//while
	}
	catch (const std::exception& e) {
		std::cerr << "Erreur : " << e.what() << std::endl;
	}
}

int main() {
	CalcRPN();
	return 0;
}