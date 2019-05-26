#include "BinarySearchTree.h"
#include <cstdlib>
#include <ctime>

BinarySearchTree bst;

void Menu();
void Search();
void Insert();
void Delete();
void DownTree();
void PrintTree();
void RandomInsert();

int main(void)
{
	srand((unsigned int)time(NULL));
	Menu();

	return 0;
}

void Menu()
{
	char ch;
	do
	{
		/*1.Search, 2.Insert 3.Delete 4.DownTree 5.Exit*/
		cout << "1.Search / 2.Insert / 3.Delete / 4.DownTree / 5.PrintTree / 6.RandomInsert / 7.Exit : ";
		cin >> ch;
		switch (ch)
		{
		case '1':
			Search();
			break;
		case '2':
			Insert();
			break;
		case '3':
			Delete();
			break;
		case '4':
			DownTree();
			break;
		case '5':
			PrintTree();
			break;
		case '6' : 
			RandomInsert();
			break;
		case '7' : 
			cout << "Exit Program" << endl;
			break;
		default:
			cout << "Wrong Input" << endl;
			cout << "Make Sure Your Select" << endl;
			break;
		}
		cout << endl;
	} while (ch != '7');
}
void Search()
{
	cout << "-------------1.Search-------------" << endl;
	cout << "Input key value to search in binary search tree. ";
	int key;	cin >> key;
	
	Node* search_result = bst.Search(key);
	if (search_result != nullptr)
	{
		bst.PrintTree(search_result);
		cout << "Search Success" << endl;
	}
	else
		cout << "Search Fail" << endl;
}
void Insert()
{
	cout << "-------------2.Insert-------------" << endl;
	cout << "Input key value to insert in binary search tree. ";
	int key;	cin >> key;
	
	if (bst.Insert(key))
		cout << "Insert Success" << endl;
	else
		cout << "Insert Fail" << endl;
}
void Delete()
{
	cout << "-------------3.Delete-------------" << endl;
	cout << "Input key value to delete in binary search tree. ";
	int key;	cin >> key;

	if (bst.Delete(key))
		cout << "Delete Success" << endl;
	else
		cout << "Delete Fail" << endl;
}
void DownTree()
{
	cout << "-------------4.DownTree-------------" << endl;
	cout << "Input string sequence that conduct downtree in binary search tree." << endl;
	string sequence;	cin >> sequence;
	
	if (bst.DownTree(sequence))
		cout << "DownTree Success" << endl;
	else
		cout << "DownTree Fail" << endl;
}
void PrintTree()
{
	cout << "-------------5.PrintTree-------------" << endl;
	bst.PrintTree();
}
void RandomInsert()
{
	cout << "-------------6.RandomInsert-------------" << endl;
	int num_rand = rand();
	cout << "Random number " << num_rand << " will insert" << endl;

	if (bst.Insert(num_rand))
		cout << "Insert Success" << endl;
	else
		cout << "Insert Fail" << endl;
}