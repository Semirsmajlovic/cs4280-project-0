#ifndef NODE_H
#define NODE_H

// Define our includes
#include <vector>
#include <string>

// Namespace declaration
using namespace std;

// treeNode data structure
struct treeNode {
	string key;
	string cKey;
	int level;
	vector<string> strings;
	treeNode *head;
	treeNode *left;
	treeNode *right;
};

#endif