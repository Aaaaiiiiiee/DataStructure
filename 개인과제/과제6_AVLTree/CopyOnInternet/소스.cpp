#include "avl.h"

int main(void)
{
	AVL avl;
	int sel, data;
	while (1)
	{
		cout << "AVL Tree" << endl;
		cout << "1. Search" << endl;
		cout << "2. Add" << endl;
		cout << "3. Delete" << endl;
		cout << "선택: ";
		cin >> sel;
		if (sel == 4)
			break;
		switch (sel)
		{
		case 1:
			cout << "Search: ";
			cin >> data;
			cout << "[Result]" << endl;
			avl.Search(data);
			break;
		case 2:
			cout << "Add: ";
			cin >> data;
			cout << "[Result]" << endl;
			avl.Insert(data);
			cout << avl;
			break;
		case 3:
			cout << "Delete: ";
			cin >> data;
			cout << "[Result]" << endl;
			avl.Delete(data);
			cout << avl;
			break;
		default:
			cout << "다시 입력하세요(1~3)" << endl;
			break;
		}
	}
	return 0;
}

