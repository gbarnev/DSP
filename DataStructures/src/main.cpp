#include "TreeExamples.h"
#include <iostream>
using namespace DSP;
using namespace std;

int main(int argc, char** argv)
{
	BinTree<int> tree;
	tree.insert(3);
	tree.insert(5);
	tree.insert(4);
	tree.insert(15);
	tree.insert(1);
	tree.insert(0);
	tree.insert(2);
	tree.insert(8);
	tree.insert(7);
	tree.insert(6);

	tree.remove(5);
	tree.remove(7);
	tree.remove(0);
	tree.remove(1);
	tree.remove(3);

	return 0;
}