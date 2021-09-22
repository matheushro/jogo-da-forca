#include<iostream>
#include<string>
#include<fstream>
//funcao principal da forca
void forca (int contador, std::string matriz_forca, int vida, std::string dica){
	std::cout << "Numero de vidas: " << vida << std::endl;
	std::cout << "Dica: " << dica << std::endl;
	if(vida == 6){
		std::cout << "-------\n";
		std::cout << "|       |\n";
		std::cout << "|       |\n";
		std::cout << "|\n";
		std::cout << "|\n";
		std::cout << "|\n";
		std::cout << "|\n";
		std::cout << "|\n";
		std::cout << "|\n";
	} else if(vida == 5){
		std::cout << "-------\n";
		std::cout << "|       |\n";
		std::cout << "|       |\n";
		std::cout << "|     (>_<)\n";
		std::cout << "|\n";
		std::cout << "|\n";
		std::cout << "|\n";
		std::cout << "|\n";
		std::cout << "|\n";
	} else if(vida == 4){
		std::cout << "-------\n";
		std::cout << "|       |\n";
		std::cout << "|       |\n";
		std::cout << "|     (>_<)\n";
		std::cout << "|      /| \n";
		std::cout << "|\n";
		std::cout << "|\n";
		std::cout << "|\n";
		std::cout << "|\n";
	} else if(vida == 3){
		std::cout << "-------\n";
		std::cout << "|       |\n";
		std::cout << "|       |\n";
		std::cout << "|     (>_<)\n";
		std::cout << "|      /|\\\ \n";
		std::cout << "|\n";
		std::cout << "|\n";
		std::cout << "|\n";
		std::cout << "|\n";
	} else if(vida == 2){
		std::cout << "-------\n";
		std::cout << "|       |\n";
		std::cout << "|       |\n";
		std::cout << "|     (>_<)\n";
		std::cout << "|      /|\\\ \n";
		std::cout << "|      /     \n";
		std::cout << "|\n";
		std::cout << "|\n";
		std::cout << "|\n";
	} else if(vida == 1){
		std::cout << "-------\n";
		std::cout << "|       |\n";
		std::cout << "|       |\n";
		std::cout << "|     (>_<)\n";
		std::cout << "|      /|\\\ \n";
		std::cout << "|      / \\\  \n";
		std::cout << "|\n";
		std::cout << "|\n";
		std::cout << "|\n";
	}
	for(int j = 0; j < contador; j++){
		std::cout << matriz_forca[j] << " ";
	}
	std::cout << "\n";
	for(int j = 0; j < contador; j++){
		std::cout << "- ";
	}
}

int main() {
	//ler arquivo.txt com as palavras
	std::string palavra;
	std::fstream file_forca;
	file_forca.open("palavra.txt", std::ios::in);
	if(!file_forca){
		std::cout << "Erro ao ler arquivo de palavras!";
		return 0;
	}else{
		file_forca >> palavra;
		file_forca.close();
	}
	//ler dica
	std::string dica;
	std::fstream file_dica;
	file_dica.open("dica.txt", std::ios::in);
	if(!file_dica){
		std::cout << "Erro ao ler arquivo de dicas!";
		return 0;
	}else{
		file_dica >> dica;
		file_dica.close();
	}
	//variaveis
	int contador = palavra.size();
	char matriz_forca [contador];
	char matriz_comparador[contador];
	int vida = 6;
	int comparador_vida = 1;
	int vitoria = 0;
	
	std::cout << "BEM VINDO AO JOGO DA FORCA!\n";
	//laço principal
	for(vida; vida > 0; vida--){	
		int comparador_letra = 0;
		comparador_vida = 0;
		
		//func forca
		forca(contador, matriz_forca, vida, dica);
		
		//digite a letra
		char letra;
		std::cout << "\n Escolha uma letra: ";
		std::cin >> letra;
		
		//corre a letra pela matriz
		for(int i = 0; i < contador; i++){
			if(matriz_comparador[i] == letra){
				comparador_letra = 1;
			}
		}
		
		//adiciona a letra na matriz comparativa
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
		
		//adiciona uma vida
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
				std::cout << "Errou!\n";
			}
		}
		
		//verificar vitoria
		if(vitoria == contador){
			system("cls");
			std::cout << "VITORIA!!\n";
			std::cout << "A palavra era: " << palavra << std::endl;
			//digitar nova palavra
			file_forca.open("palavra.txt", std::ios::app);
			if(!file_forca){
				std::cout << "Erro ao ler arquivo!";
				return 0;
			}else{
				std::string nova_palavra;
				std::cout << "Adicione uma nova palavra ao jogo da forca!!!\nOBS: No lugar de espaco use -: ";
				std::cin >> nova_palavra;
				system("cls");
			}
			//digitar dica para a palavra adicionada
			file_dica.open("dica.txt", std::ios::app);
			if(!file_dica){
				std::cout << "Erro ao ler arquivo!";
				return 0;
			}else{
				std::string nova_dica;
				std::cout << "Adicione uma dica para a palavra adicionada ao jogo da forca: ";
				std::cin >> nova_dica;
				//salva palavra e dica juntos
				file_forca << nova_palavra << std::endl;
				file_forca.close();
				file_dica << nova_dica << std::endl;
				file_dica.close();
				system("cls");
				std::cout << "Obrigado por jogar o Jogo Da Forca!";
				return 0;
			}
		}
	}
	
	//game over
	if(vida == 0){
		std::cout << "GAME OVER!";
	}
}