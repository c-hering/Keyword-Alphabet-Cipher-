#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
	string key;
	string input;
	string alph = "abcdefghijklmnopqrstuvwxyz";
	string new_alph;
	string final;
	string encrypted;
	string decrypted;
	int input_ln;
	int key_ln;
	bool isInKey;
	int test;

	while (true) {
		input = "";
		key = "";
		new_alph = "";
		final = "";
		encrypted = "";
		decrypted = "";

		cout << "Phrase: ";
		getline(cin, input);
		cout << "Key: ";
		cin >> key;
		cin.ignore();
		key_ln = key.length();
		input_ln = input.length();
		transform(input.begin(), input.end(), input.begin(), ::tolower);
		input.erase(remove(input.begin(), input.end(), ' '), input.end());
		for (int i = 0; i < 26; i++) {
			isInKey = false;
			for (int x = 0; x < key_ln; x++) {
				if (key[x] == alph[i]) {
					isInKey = true;
				}
			}
			if (isInKey == false) {
				new_alph += alph[i];
			}
		}
		final = key + new_alph;
		cout << "New Alphabet: " << final << endl;

		for (int y = 0; y < input_ln; y++) {
			test = input[y] % 97;
			encrypted += final[test];
		}
		cout << encrypted << endl;

		for (int i = 0; i < input_ln; i++) {
			for (int y = 0; y < 26; y++) {
				if (input[i] == final[y]) {
					decrypted += alph[y];
				}
			}
		}
		cout << decrypted << endl;
	}
}
/*

	




*/