#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <iterator>
#include <algorithm>
#include <conio.h>
#include "Text.h"
using namespace std;

int main() {
	setlocale(LC_ALL, "Russian");
	//cout << "Input file_path : ";
	string file_path("1.txt");
	ifstream fin(file_path);
	try {
		if (!fin.is_open())
			throw "Error!";
	}
	catch (const char*) {
		cout << "Error with file openning !" << endl;
		return 0;
	}
	vector<char> page;
	fin.seekg(0, fin.end);
	int length = fin.tellg();
	fin.seekg(0, fin.beg);
	while (length) {
		page.push_back(fin.get());
		length--;
	}
	fin.close();
	Text text(page);
	int choice = 0;
	while (choice != 5) {
		system("cls");
		text.Print();
		cout << "\n\nChoose the operation to filtration the file : ";
		cout << "\n1.Symbols of the Latin alphabet";
		cout << "\n2.Cyrillic symbols";
		cout << "\n3.Punctuation symbols";
		cout << "\n4.Numbers";
		cout << "\n5.Exit";
		choice = _getch() - 48;
		text.Filtration(choice);
	}
	cout << "\nDone";
	system("pause>>NUL");
	return 0;
}
