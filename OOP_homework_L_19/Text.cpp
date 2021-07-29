#include <iostream>
#include <vector>
#include <fstream>
#include <iterator>
#include <cctype>
#include "Text.h"
using namespace std;

Text::Text(vector<char> page) {
	this->page = page;
	vector<char>::iterator iter(page.begin());
	while (iter != page.end()) {
		if (isalpha(*iter)) {
			mask_lat.push_back(*iter);
			mask_kir.push_back(' ');
			mask_punct.push_back(' ');
			mask_num.push_back(' ');
		}
		else if (ispunct(*iter)) {
			mask_lat.push_back(' ');
			mask_kir.push_back(' ');
			mask_punct.push_back(*iter);
			mask_num.push_back(' ');
		}
		else if (isdigit(*iter)) {
			mask_lat.push_back(' ');
			mask_kir.push_back(' ');
			mask_punct.push_back(' ');
			mask_num.push_back(*iter);
		}
		else if (!ispunct(*iter) && !isalpha(*iter) && !isdigit(*iter) && !isspace(*iter)) {
			mask_lat.push_back(' ');
			mask_kir.push_back(*iter);
			mask_punct.push_back(' ');
			mask_num.push_back(' ');
		}
		else if (!isgraph(*iter)) {
			mask_lat.push_back(' ');
			mask_kir.push_back(' ');
			mask_punct.push_back(' ');
			mask_num.push_back(' ');
		}
		iter++;
	}
}

void Text::Filtration(int choice) {
	vector<char> temp;
	if (choice == 1) temp = mask_lat;
	else if (choice == 3) temp = mask_punct;
	else if (choice == 4) temp = mask_num;
	else if (choice != 1 && choice != 3 && choice != 4) temp = mask_kir;
	for (int i = 0; i < page.size(); i++) {
		if (page[i] != ' ' && temp[i] != ' ')
			page[i] = ' ';
		else if (page[i] != ' ' && temp[i] == ' ')
			page[i] = page[i];
		else if (page[i] == ' ' && temp[i] != ' ')
			page[i] = temp[i];
		else if (page[i] == ' ' && temp[i] == ' ')
			page[i] = ' ';
	}
}

void Text::Print() {
	ostream_iterator<char> fout(cout);
	copy(page.begin(), page.end(), fout);
}