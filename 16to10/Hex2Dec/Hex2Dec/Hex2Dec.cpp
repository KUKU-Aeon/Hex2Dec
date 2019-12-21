

#include "pch.h"
#include <iostream>
#include <string>
#include <fstream>
#include <stdlib.h>

using namespace std; // используем пространство имен std (где объявлены функции стандартной библ. C++ (string или vector)) 

//Напишите программу для ввода шестнадцатеричного числа и вывода его в
//десятичной системе.
//Петряев Дмитрий 9гр. 2к.

	// Возведения целого числа в степень с целым положительным показателем
int pow(int num, int exp)
{
	// Если показатель степени является нулем
	if (exp == 0) {
		// Любое число в нулевой степени является единицей
		return 1;
	}
	// Если показатель степени положителен
	if (exp > 0) {
		int result = 1;
		// Умножаем число само на себя exp раз
		for (int i = 0; i < exp; ++i) {
			result *= num;
		}
		// Возвращаем результат
		return result;
	}
	// Нам не нужно считать отрицательные степени
	return -1;
}

// Преобразование шестнадцатеричного символа в десятичное число
unsigned int char2int(char chr)
{
	if (chr >= '0' && chr <= '9')
		return chr - '0';
	else if (chr >= 'A' && chr <= 'F')
		return chr - 'A' + 10;
	else if (chr >= 'a' && chr <= 'f')
		return chr - 'a' + 10;
	return -1;
}

// Приведение строкового значения шестнадцатеричного
// числа к десятичному виду
int hex2dec(const char *hex, int size)
{
	// Изначальное десятичное значение
	int dec = 0;
	// Непосредственно преобразование шестнадцатеричного числа
	// в десятичное.
	for (int j = 0, i = size - 1; j < size; ++j, --i) {
		dec += char2int(hex[j]) * pow(16, i);
	}
	// Возвращаем десятичное число
	return dec;
}

// Проверка строки на соответствию формата десятичного числа
int is_valid_hex(const char *hex, unsigned int size)
{
	for (int i = 0; i < size; ++i)
		if (!((hex[i] >= '0' && hex[i] <= '9')
			|| (hex[i] >= 'a' && hex[i] <= 'z')
			|| (hex[i] >= 'A' && hex[i] <= 'z'))
			)
			return 0;
	return 1;
}

void ReadStr() {
	string hex;
	int dec;

	do {
		cout << "Введите число в 16-й системе: ";
		cin >> hex;
		if (!is_valid_hex(hex.c_str(), hex.length()))
		{
			cout << "Число введено некорректно: " << hex << endl;
		}
	} while (!is_valid_hex(hex.c_str(), hex.length()));

	cout << endl;
	dec = hex2dec(hex.c_str(), hex.length());
	cout << "Число " << hex << " в 10-й системе = " << dec << endl;
}

void ReadStr_FFile(ifstream *file) {
	string hex;
	int dec = 0;

	if ((*file).is_open())
	{
		while(!(*file).eof())
		{	
			
			getline(*file, hex);
			dec = hex2dec(hex.c_str(), hex.length());
			cout << endl;
			cout << "Число " << hex << " в 10-й системе = " << dec << endl;
		}
	}
	else {
		cout << "Не удалось считать данные, файл не открыт! " << endl;
	}
	(*file).seekg(0); // если пользователь захочет снова прочитать файл, ставим указатель на начало файла.
}

void printmenu()
{
	cout << endl;
	cout << "0. Выход" << endl;
	cout << "1. Считать данные с клавиатуры" << endl;
	cout << "2. Считать данные из файла" << endl;
}

int main()
{
	setlocale(0, "");//Подрубаем рашн ленгуаге

	string path = "C:\\Users\\Дмитрий\\Desktop\\C++\\16to10\\Hex2Dec\\Hex2Dec\\input.txt";
	ifstream file; 
	file.open(path);


	int el;
	do {
		printmenu();
		cout << endl;
		cout << "-->";
		cin >> el;

		switch (el)
		{
		case 1: ReadStr();	
			break;
		case 2: ReadStr_FFile(&file);	
			break;
		}

	} while (el != 0);

	file.close();
	system("pause");
	return 0;

}


