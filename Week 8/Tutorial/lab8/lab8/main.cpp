#include "BTree.h"
#include "TreeVisitor.h"
#include <string>

using namespace std;

int main() {
	string s1("Hello World!");
	string s2("A");
	string s3("B");
	string s4("C");
	string s5("RRREEEEEEEE");
	string s6("Stop Time!");

	BTree<string> A2Tree(s1); // Hello World!

	BTree<string> STree1(s2); // A
	BTree<string> STree2(s3); // B
	BTree<string> STree3(s4); // C
	BTree<string> STree4(s5); // RREEEEEEE
	BTree<string> STree5(s6); // Stop Time!

	A2Tree.attachLeft(&STree1);
	A2Tree.attachRight(&STree2);
	A2Tree.left().attachLeft(&STree3);
	A2Tree.right().attachRight(&STree4);
	A2Tree.right().attachLeft(&STree5);

	cout << "Value of A2Tree.key(): " << A2Tree.key() << endl;
	cout << "Value of A2Tree.left().key(): " << A2Tree.left().key() << endl;
	cout << "Value of A2Tree.right().key(): " << A2Tree.right().key() << endl;
	cout << "Value of A2Tree.left().left().key(): " << A2Tree.left().left().key() << endl;
	cout << "Value of A2Tree.right().right().key(): " << A2Tree.right().right().key() << endl;
	cout << "Value of A2Tree.right().left().key(): " << A2Tree.right().left().key() << endl;

	//Enable below to test exception thrower
	//A2Tree.right().right().right().left();

	//Tree Traversal via Visitor
	cout << endl << "Traversing Tree via Visitor class: " << endl;
	A2Tree.transverseDepthFirst(PreOrderVisitor<string>());
	cout << endl;

	A2Tree.right().detachRight();
	A2Tree.right().detachLeft();
	A2Tree.left().detachLeft();
	A2Tree.detachLeft();
	A2Tree.detachRight();

	system("pause");
	return 0;
}