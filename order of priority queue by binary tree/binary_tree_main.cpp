#include "binary_tree.h"

int main() {
	priortyqueue p;
	p.add("C", 9);
	p.add("Javascript", 4);
	p.add("Python", 10);
	p.add("Swift", 1);
	p.add("Java", 8);
	p.add("C#", 6);
	p.add("C++", 7);
	p.add("Assembly", 3);
	p.add("Visual Basic", 5);
	p.add("SQL", 2);
	p.opposite_inorder();
	p.pop_tree();
	p.pop_tree();
	p.opposite_inorder();
	return 0;
}