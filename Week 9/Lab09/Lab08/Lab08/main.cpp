#include "BTree.h"
#include "TreeVisitor.h"
#include <string>

using namespace std;

int main() {
	string s1("Hello World!");
	string s2("A");
	string s3("B");
	string s4("C");

	BTree<string> A2Tree(s1);

	BTree<string> STree1(s2);
	BTree<string> STree2(s3);
	BTree<string> STree3(s4);

	A2Tree.attachLeft(&STree1);
	A2Tree.attachRight(&STree2);
	A2Tree.left().attachLeft(&STree3);

	cout << "Key: " << A2Tree.key() << endl;
	cout << "Key: " << A2Tree.left().left().key() << endl;

	cout << endl << "Preorder Visitor:" << endl;
	A2Tree.transverseDepthFirst(PreOrderVisitor<string>());

	cout << endl << endl << "Inorder Visitor:" << endl;
	A2Tree.transverseDepthFirst(InOrderVisitor<string>());

	cout << endl << endl << "Postorder Visitor:" << endl;
	A2Tree.transverseDepthFirst(PostOrderVisitor<string>());
	cout << endl;

	A2Tree.left().detachLeft();
	A2Tree.detachLeft();
	A2Tree.detachRight();

	system("pause");
	return 0;
}