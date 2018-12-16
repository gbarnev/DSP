#pragma once
#include "BinTree.h"
#include <iostream>

using namespace std;
using namespace DSP;

typedef BinTree<char> CharTree;

CharTree inputTree()
{
	char x;
	cout << "Enter root: ";
	cin >> x;

	if (x == '\0')
		return CharTree();

	CharTree left, right;
	char code = '\0';

	while (code != 'y' && code != 'n')
	{
		cout << "Enter left element of " << x << " y/n?" << endl;
		cin >> code;
	}

	if (code == 'y')
		left = inputTree();

	code = '\0';

	while (code != 'y' && code != 'n')
	{
		cout << "Enter right element of " << x << " y/n?" << endl;
		cin >> code;
	}

	if (code == 'y')
		right = inputTree();

	return CharTree(x, left, right);
}