#include "trie.h"

trie::trie() : count(0)
{
	root = new Node('\0');
}

void trie::insert(std::string str)
{

	Node *cur = root;

	for (int index = 0; index < str.length(); index++)
	{
		if (!cur->child[str[index]])
		{
			Node *newNode = new Node(str[index]);
			cur->child[str[index]] = newNode;
		}

		cur = cur->child[str[index]];
	}
	cur->is_leaf = true;

	count++;
}

//-------------------------------------------------------------------

bool trie::search(std::string str)
{

	Node *cur = root;

	if (!cur)
		return false;

	for (int index = 0; index < str.length(); index++)
	{
		if (!cur->child[str[index]])
			return false;
		cur = cur->child[str[index]];
	}
	return cur->is_leaf;
}

//-------------------------------------------------------------------

bool trie::remove(std::string str)
{

	Node *cur = root;

	if (!cur)
		return false;

	for (int index = 0; index < str.length(); index++)
	{
		if (!cur->child[str[index]])
			return false;
		cur = cur->child[str[index]];
	}
	cur->is_leaf = false;
	return true;
}

//-------------------------------------------------------------------
