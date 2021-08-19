#include<iostream>
#include<string>

int main() {
	std::string palavra = "paralelepipedo";
	int contador = palavra.size();
	char matriz_forca [contador];
	int vida = 6;
	int comparador_vida = 1;
	int vitoria = 0;
	char matriz_comparador[contador];
	std::cout << "BEM VINDO AO JOGO DA FORCA!\n";
	for(vida; vida>0; vida--){	
		int comparador_letra = 0;
		comparador_vida = 0;
		std::cout << "Numero de vidas: " << vida << "\n";
		std::cout << "-------\n";
		std::cout << "|      |\n";
		std::cout << "|      |\n";
		std::cout << "|\n";
		std::cout << "|\n";
		std::cout << "|\n";
		std::cout << "|\n";
		std::cout << "|\n";
		std::cout << "|";
		for(int j = 0; j < contador; j++){
			std::cout << matriz_forca[j];
			std::cout << "-";
		}
		char letra;
		std::cout << "\n Escolha uma letra: ";
		std::cin >> letra;
		for(int i = 0; i < contador; i++){
			if(matriz_comparador[i] == letra){
				comparador_letra = 1;
			}
		}
		if(comparador_letra == 0){
			for(int i = 0; i < contador; i++){
				if(palavra[i] == letra){
					matriz_comparador[i] = letra;
					matriz_forca[i] = letra;
					comparador_vida = 1;
					system("cls");
					vitoria++;
				}	
			}
		}	
		if(comparador_vida == 1){
			vida++;
		}
		else{
			if(comparador_letra == 1){
				system("cls");
				std::cout << "Letra utilizada anteriormente!\n";
				vida++;
			}
			else{
				system("cls");
				std::cout << "Letra inexistente!\n";
			}
		}
		if(vitoria == contador){
			system("cls");
			std::cout << "VITORIA";
			vida = 0;
		}
	}
	if(vida == 0){
		std::cout << "GAME OVER!";
	}
}