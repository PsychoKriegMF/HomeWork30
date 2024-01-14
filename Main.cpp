#include <iostream>
#include <string>
#include <fstream>



bool overwrite(std::string str,std::string str2) {
	static std::ifstream in;
	in.open(str);
	if (in.is_open()) {
		in.close();
		std::ofstream out;
		out.open(str);
		if (out.is_open()) {
			out << str2;
			return true;
		}
	}
	else
		return false;
}

int main() {
	setlocale(LC_ALL, "ru");

	//Задача 1

	std::string path = "file.txt";

	std::ofstream out;
	out.open(path, std::ios::app);

	if (out.is_open()) {
		std::string str_out;
		do {
			std::cout << "Введите строку: ";
			std::getline(std::cin, str_out);
			out << str_out << '\n';
		} 
		while (str_out != "end");
	}
	else
		std::cout << "Ошибка открытия файла!\n";
	out.close();

	std::ifstream in;
	in.open(path);

	if (in.is_open()) {
		std::string file;
		std::string str;
		while (std::getline(in, file)) {
			file += str + '\n';
		}
			std::cout<< std::endl;
	}
	else
		std::cout << "Ошибка открытия файла!\n";
	in.close();
	
	
	if (remove(path.c_str()) == 0) {
		std::cout << "Файл удален!\n";
	}
	else
		std::cout << "Ошибка удаления файла!\n";

		
	// Задача 2.

	std::string str_remove;
	std::cout << "Введите строку дял замены: ";
	std::getline(std::cin, str_remove);
	if (overwrite(path, str_remove)) {
		std::cout << "True\n";
	}
	else
		std::cout << "False\n";
	

	return 0;
}