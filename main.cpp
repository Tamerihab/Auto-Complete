#include<iostream>

#include<string>

#include<fstream>

#include"trie.h"

void split_string(trie &trie,std::string& str, std::vector<std::string>& res) {

	std::string word = "";

	for (auto x : str) {

		if (x == ' ') {
			std::cout << endl;
			word = "";
		}
		else {
			word = word + x;
		}
	}
	std::cout << "Your Search Options are: " << endl;
	trie.autoComplete(word,res);
}
/*--------------------------------------------------------------------
	 Split the string into words and return the words in a vector
	 Precondition: String is a valid string & vector is a valid vector  .
	 Postcondition: String is split successfully and stored in a vector..
	 --------------------------------------------------------------------*/

bool is_space(std::string& str) { //checks if there is a space in the entered string

	for (auto x : str) {

		if (x == ' ')
			return true;
		else
			continue;
	}
	return false;
}
/*--------------------------------------------------------------------
	 Checks if there is a space in the entered string
	 Precondition:  string is a valid string.
	 Postcondition: Returns true if there is a space, false if not..
	 --------------------------------------------------------------------*/

int main() {

	std::string data;
	std::fstream dictionary;
	trie t;
	dictionary.open("Text.txt", std::fstream::in); //read dictionary file into trie tree structure
	if (dictionary.is_open())
	{
		while (dictionary)
		{
			dictionary >> data;
			t.insert(data);
		}
	}
	else
	{
		std::cout << "error:  file not open." << std::endl;
		return -1;
	}
	dictionary.close();
	data.clear();

	vector<string> res;

	string word;
	cout << "Enter word to complete: \n";
	getline(cin, word);
	cout << "-------------------------------- \n";
	if (is_space(word) == true) {
		split_string(t, word,res);
	}
	else
		t.autoComplete(word,res);

	return 0;

}