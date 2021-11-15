#include"header.h"
int main() {
	srand(time(NULL));
	//variaveis arquivo
	int numero_linhas = 0;
	int rodar_arquivo = 0;
	//ler arquivo.txt com as palavras
	std::string palavra;
	std::fstream file_forca;
	int b = 0;
	int rand_line = 0;
	file_forca.open("palavra.txt", std::ios::in);
	if (!file_forca) {
		std::cout << "Erro ao ler arquivo de palavras!";
		return 0;
	}
	else {
		while (file_forca.good()) {
			rodar_arquivo = file_forca.get();
			if (rodar_arquivo == '\n') {
				b++;
			}
		}
		//std::cout << b;
		rand_line = rand() % b;
		std::string line;
		file_forca.close();
		file_forca.open("palavra.txt", std::ios::in);
		while (getline(file_forca, line)) {
			rodar_arquivo++;
			if (rodar_arquivo == rand_line) {
				file_forca >> palavra;
				file_forca.close();
				break;
			}
		}
	}
	//ler dica
	std::string dica;
	std::fstream file_dica;
	file_dica.open("dica.txt", std::ios::in);
	b = 0;
	rodar_arquivo = 0;
	if (!file_dica) {
		std::cout << "Erro ao ler arquivo de palavras!";
		return 0;
	}
	else {
		while (file_dica.good()) {
			rodar_arquivo = file_dica.get();
			if (rodar_arquivo == '\n') {
				b++;
			}
		}
		std::string line;
		std::string line_dica;
		file_dica.close();
		file_dica.open("dica.txt", std::ios::in);
		while (getline(file_dica, line)) {
			rodar_arquivo++;
			if (rodar_arquivo == rand_line) {
				file_dica >> dica;
				file_dica.close();
			}
		}
	}
	//std::cout << rand_line;
	//variaveis.
	int contador = palavra.size();
	char matriz_forca[contador];
	int vida = 6;
	int comparador_vida = 1;
	int vitoria = 0;
	std::string nova_dica;
	std::string nova_palavra;
	// inicializa as posições das letras com ' '
	// aqui não estava permitindo o array posicionar corretamente as letras nas posições
	for (int i = 0; i < contador; i++) {
		matriz_forca[i] = ' ';
	}
	std::cout << "BEM VINDO AO JOGO DA FORCA!\n";
	//laço principal
	for (vida; vida > 0; vida--) {
		int comparador_letra = 0;
		comparador_vida = 0;
		//func forca
		forca(contador, matriz_forca, vida, dica);
		//digite a letra
		char letra;
		std::cout << "\n Escolha uma letra: ";
		std::cin >> letra;
		//corre a letra pela matriz
		for (int i = 0; i < contador; i++) {
			if (matriz_forca[i] == letra) {
				comparador_letra = 1;
			}
		}
		//adiciona a letra na matriz comparativa
		if (comparador_letra == 0) {
			for (int i = 0; i < contador; i++) {
				if (palavra[i] == letra) {
					matriz_forca[i] = letra;
					comparador_vida = 1;
					system("cls");
					vitoria++;
				}
			}
		}
		//adiciona uma vida
		if (comparador_vida == 1) {
			vida++;
		}
		else {
			if (comparador_letra == 1) {
				system("cls");
				std::cout << "Letra utilizada anteriormente!\n";
				vida++;
			}
			else {
				system("cls");
				std::cout << "Errou!\n";
			}
		}
		//verificar vitoria
		if (vitoria == contador) {
			system("cls");
			std::cout << "VITORIA!!\n";
			std::cout << "A palavra era: " << palavra << std::endl;
			//digitar nova palavra
			file_forca.open("palavra.txt", std::ios::app);
			if (!file_forca) {
				std::cout << "Erro ao ler arquivo!";
				return 0;
			}
			else {
				std::cout << "Adicione uma nova palavra ao jogo da forca!!!\nOBS: No lugar de espaco use -: ";
				std::cin >> nova_palavra;
				system("cls");
			}
			//digitar dica para a palavra adicionada
			file_dica.open("dica.txt", std::ios::app);
			if (!file_dica) {
				std::cout << "Erro ao ler arquivo!";
				return 0;
			}
			else {
				std::cout << "Adicione uma dica para a palavra adicionada ao jogo da forca: ";
				std::cin >> nova_dica;
				//salva palavra e dica juntos
				file_forca << std::endl << nova_palavra;
				file_forca.close();
				file_dica << std::endl << nova_dica;
				file_dica.close();
				system("cls");
				std::cout << "Obrigado por jogar o Jogo Da Forca!";
				return 0;
			}
		}
	}
	//game over
	if (vida == 0) {
		std::cout << "GAME OVER!";
	}
}
