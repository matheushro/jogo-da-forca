#include<iostream>
#include<string>
#include<fstream>
#include <cstdlib>
#include <ctime>

//funcao forca 
void forca(int contador, char matriz_forca[], int vida, std::string dica) {
	std::cout << "Numero de vidas: " << vida << std::endl;
	std::cout << "Dica: " << dica << std::endl;
	if (vida == 6) {
		std::cout << "-------\n";
		std::cout << "|       |\n";
		std::cout << "|       |\n";
		std::cout << "|\n";
		std::cout << "|\n";
		std::cout << "|\n";
		std::cout << "|\n";
		std::cout << "|\n";
		std::cout << "|\n";
	}
	else if (vida == 5) {
		std::cout << "-------\n";
		std::cout << "|       |\n";
		std::cout << "|       |\n";
		std::cout << "|     (>_<)\n";
		std::cout << "|\n";
		std::cout << "|\n";
		std::cout << "|\n";
		std::cout << "|\n";
		std::cout << "|\n";
	}
	else if (vida == 4) {
		std::cout << "-------\n";
		std::cout << "|       |\n";
		std::cout << "|       |\n";
		std::cout << "|     (>_<)\n";
		std::cout << "|      /| \n";
		std::cout << "|\n";
		std::cout << "|\n";
		std::cout << "|\n";
		std::cout << "|\n";
	}
	else if (vida == 3) {
		std::cout << "-------\n";
		std::cout << "|       |\n";
		std::cout << "|       |\n";
		std::cout << "|     (>_<)\n";
		std::cout << "|      /|\\\\ \n";
		std::cout << "|\n";
		std::cout << "|\n";
		std::cout << "|\n";
		std::cout << "|\n";
	}
	else if (vida == 2) {
		std::cout << "-------\n";
		std::cout << "|       |\n";
		std::cout << "|       |\n";
		std::cout << "|     (>_<)\n";
		std::cout << "|      /|\\\\ \n";
		std::cout << "|      /     \n";
		std::cout << "|\n";
		std::cout << "|\n";
		std::cout << "|\n";
	}
	else if (vida == 1) {
		std::cout << "-------\n";
		std::cout << "|       |\n";
		std::cout << "|       |\n";
		std::cout << "|     (>_<)\n";
		std::cout << "|      /|\\\\ \n";
		std::cout << "|      / \\\\  \n";
		std::cout << "|\n";
		std::cout << "|\n";
		std::cout << "|\n";
	}
	//matriz forca
	for (int i = 0; i < contador; i++) {
		std::cout << matriz_forca[i] << " ";
	}
	std::cout << "\n";
	for (int i = 0; i < contador; i++) {
		std::cout << "- ";
	}
}