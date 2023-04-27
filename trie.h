
#include <iostream>

#include <vector>

#include <cstring>

using namespace std;

class trie
{

private:
	class Node
	{

	public:
		char data;

		bool is_leaf{};

		Node *child[128];

		Node(char data) : is_leaf(false)
		{

			this->data = data;
			memset(child, 0, sizeof(child));
		}
	};

	Node *root;

	long count{};

	bool hasChild(Node *root)
	{

		for (int i = 0; i < 128; ++i)
		{
			if (root->child[i] != NULL)
			{
				return true;
			}
		}
		return false;
	}
	/*--------------------------------------------------------------------
	 Checks if the node has children
	 Precondition: Node is a valid node in the trie.
	 Postcondition: Returns true if there is a child, false if not..
	 --------------------------------------------------------------------*/

	void displayUtil(string s, Node *root, std::vector<std::string> &res)
	{
		// if the given char is end of word print it

		if (root->is_leaf == true)
		{
			cout << s << endl;

			res.push_back(s);
		}
		// for all children in root if not NULL recursively call its children
		for (int i = 0; i < 128; i++)
		{
			if (root->child[i] != NULL)
			{
				displayUtil(s + root->child[i]->data, root->child[i], res);
			}
		}
	}

	void autoSuggestUtil(string input, Node *root, std::vector<std::string> &res)
	{
		Node *cur = root;
		// traversing the given input string
		for (int i = 0; i < input.length(); i++)
		{
			// no such prefix exist then return
			if (cur->child[input[i]] == NULL)
			{
				cout << input << endl;
				return;
			}
			cur = cur->child[input[i]];
		}

		// if it is end node and has no children print the input string
		if (cur->is_leaf and hasChild(cur) == false)
		{
			cout << input << endl;
			return;
		}

		// print the subtree
		if (hasChild(root))
		{
			displayUtil(input, cur, res);
		}
	}
	/*--------------------------------------------------------------------
	 Completes the string given with all possible words available
	 Precondition:  string is a valid string.
	 Postcondition: all words with the same prefix as the string has been returned,
	 provided string is valid..
	 --------------------------------------------------------------------*/

public:
	trie();
	/*--------------------------------------------------------------------
	 Default constructor: builds an empty trie object.
	 Precondition:  None
	 Postcondition: child is null and mySize is 0.
	 --------------------------------------------------------------------*/
	void insert(std::string str);
	/*--------------------------------------------------------------------
	 Insert a value into a list at a given index.
	 Precondition:  string is a valid string
	 Postcondition: str has been inserted into trie at nodes,
	 provided string is valid..
	 --------------------------------------------------------------------*/

	bool search(std::string str);
	/*--------------------------------------------------------------------
	Searches if word exists in trie.
	Precondition:  string is a valid string
	Postcondition:returns true if found otherwise it returns false,
	provided string is valid..
	--------------------------------------------------------------------*/

	void display(std::vector<std::string> &res)
	{
		displayUtil("", root, res);
	}

	/*--------------------------------------------------------------------
	prints the Strings in the trie
	Precondition:Vector is a valid vector.
	Postcondition: all strings in vector has been returned..
	--------------------------------------------------------------------*/

	void autoComplete(string input, std::vector<std::string> &res)
	{
		return autoSuggestUtil(input, root, res);
	}

	/*--------------------------------------------------------------------
	Completes the string given with all possible words available
	Precondition:  string is a valid string.
	Postcondition: all words with the same prefix as the string has been returned,
	provided string is valid..
	--------------------------------------------------------------------*/

	bool remove(std::string str);
	/*--------------------------------------------------------------------
	Removes the string from the trie
	Precondition:  string is a valid string.
	Postcondition: string has been removed from trie,
	provided string is valid..
	--------------------------------------------------------------------*/
};
