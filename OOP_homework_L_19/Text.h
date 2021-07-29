#pragma once
using namespace std;

class Text {
	vector<char> page;
	vector<char> mask_lat;
	vector<char> mask_kir;
	vector<char> mask_punct;
	vector<char> mask_num;
public:
	Text() {}
	Text(vector<char> page);
	void Filtration(int choice);
	void Print();
};
