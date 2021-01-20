#include <iostream>
#include <string>
#include "TreeVisitor.h"
#include "NTree.h"

using namespace std;

int main()
{
	string A("A");
	string AA("AA");
	string AB("AB");
	string AC("AC");
	string AAA("AAA");
	string ABA("ABA");
	string ABB("ABB");

	typedef NTree<string, 3> NS3Tree;

	NS3Tree root(A);

	NS3Tree nodeAA(AA);
	NS3Tree nodeAB(AB);
	NS3Tree nodeAC(AC);
	NS3Tree nodeAAA(AAA);
	NS3Tree nodeABA(ABA);
	NS3Tree nodeABB(ABB);

	root.attachNtree(0, &nodeAA);
	root.attachNtree(1, &nodeAB);
	root.attachNtree(2, &nodeAC);
	root[0].attachNtree(0, &nodeAAA);
	root[1].attachNtree(0, &nodeABA);
	root[1].attachNtree(1, &nodeABB);

	cout << "root: " << root.key() << endl;
	cout << "root[0]: " << root[0].key() << endl;
	cout << "root[1]: " << root[1].key() << endl;
	cout << "root[2]: " << root[2].key() << endl;
	cout << "root[0][0]: " << root[0][0].key() << endl;
	cout << "root[1][0]: " << root[1][0].key() << endl;
	cout << "root[1][1]: " << root[1][1].key() << endl;

	// test traversal
	PreOrderVisitor<string> v1;
	PostOrderVisitor<string> v2;
	cout << "Pre-Order Traversal" << endl;
	root.travereseDepthFirst(v1);
	cout << endl;
	cout << "Post-Order Traversal" << endl;
	root.travereseDepthFirst(v2);
	cout << endl;

	// test detachNTree
	root[0].detachNTree(0);
	root[1].detachNTree(0);
	root[1].detachNTree(1);
	root.detachNTree(0);
	root.detachNTree(1);
	root.detachNTree(2);
	if (&root[0] == &NS3Tree::NIL)
		cout << "Detach succeeded." << endl;
	else
		cout << "Detach failed." << endl;

	system("pause");
	return 0;
}