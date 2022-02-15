// Define our includes
#include <iostream>
#include <fstream>
#include "tree.h"

// Namespace declaration
using namespace std;

treeNode *root = NULL;

treeNode *buildTree(string fileName)
{
	// Declare our variables
	string key;
	string input;

	ifstream file(fileName.c_str());

	// Check our file open state and search for file.
	if (file.is_open()) {
		while (file >> input) {
			key = input.substr(0, 2);
			insert(root, key, input);
		}
		file.close();
	} else {
        cout << "\n*****************************************************\n";
		cout << "The file " << fileName << " could not be found.\n";
        cout << "*****************************************************\n\n";
		return NULL;
	}
	
	return root;
}

// Constructor prototype
treeNode *constructor(int level, string key, string s)
{
	treeNode *node = new treeNode;
	node->left = NULL;
	node->right = NULL;
	node->head = NULL;
	node->key = key;
	node->cKey = key; 
	node->strings.push_back(s);
	node->level = level;
	
    return node;
}

// toLower prototype
string toLower(string key)
{
	for (int i = 0; i < key.length(); i++) {
		if (key[i] >= 'A' && key[i] <= 'Z') {
			key[i] = key[i] + 32;
		}
	}

	return key;
}

// insert prototype
void insert(treeNode *node, string key, string s)
{
	string copy = key;

	for (int i = 0; i < copy.length(); i++) {
		if (copy[i] >= 'A' && copy[i] <= 'Z') {
			copy[i] = copy[i] + 32;
		}
	}

	if (root == NULL) {
		root = constructor(0, key, s);
		root->head = root;
	} else if (copy < toLower(node->cKey)) {
		if (node->left == NULL) {
			node->left = constructor((node->level+1), key, s);
			node->left->head = node;
		} else if(copy == toLower(node->left->cKey)) {
			if (searchTree(node->left, s) != 0) {
				node->left->strings.push_back(s);
			}
		} else{
			insert(node->left, key, s);
		}
	} else if (copy == toLower(node->cKey)) {
		if (searchTree(node, s) != 0) {
			node->strings.push_back(s);
		}
	} else if (copy > toLower(node->cKey)) {
		if (node->right == NULL) {
			node->right = constructor((node->level+1), key, s);
			node->right->head = node;
		} else if (copy == toLower(node->right->cKey)) {
			if (searchTree(node->right, s) != 0) {
				node->right->strings.push_back(s);
			}
		} else {
			insert(node->right, key, s);
		}
	}
} 

// searchTree prototype
int searchTree(treeNode *node, string s)
{
	if (node->strings.size() > 0) {
		for (int i = 0; i < node->strings.size(); i++) {
			if (node->strings[i].compare(s) == 0) {
				 return 0; 
			}
		}
	}

	return 1;			
}

// printPreorder prototype
void printPreorder(treeNode *root, ofstream& ofile) 
{
	if (root != NULL) {
		for (int i = 0; i < root->level; i++) {
            ofile << "\t";
        }
		for (int i = 0; i < (int)root->strings.size(); i++) {
			ofile << root->strings[i] << " ";
		}
		ofile << "\n";
		printPreorder(
            root->left, 
            ofile
        );
		printPreorder(
            root->right, 
            ofile
        );
	}
}

// printInorder prototype
void printInorder(treeNode *root, ofstream& ofile)
{
	if (root != NULL) {
		printInorder(
            root->left, 
            ofile
        );
		for (int i = 0; i < root->level; i++) { 
            ofile << "\t";
        }
		for (int i = 0; i < (int)root->strings.size(); i++) {
			ofile << root->strings[i] << " ";
		}
		ofile << "\n";
		printInorder(
            root->right, 
            ofile
        );
	}
}

// printPostorder prototype
void printPostorder(treeNode *root, ofstream& ofile) 
{	
    if (root != NULL) {	
        printPostorder(
            root->left, 
            ofile
        );
		printPostorder(
            root->right, 
            ofile
        );
		for (int i = 0; i < root->level; i++) { 
            ofile << "\t";
        }
		for (int i = 0; i < (int)root->strings.size(); i++) {
			ofile << root->strings[i] << " ";
		}
		ofile << "\n";
	}
}