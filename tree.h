#ifndef TREE_H
#define TREE_H

// Define our includes
#include <string>

#include <fstream>

#include <iostream>

#include "node.h"

// Namespace declaration
using namespace std;

// buildTree prototype
treeNode * buildTree(
  string fileName
);

// Constructor prototype.
treeNode * constructor(
  int level,
  string key,
  string s
);

// insert prototype
void insert(
  treeNode * node,
  string key,
  string s
);

// searchTree prototype
int searchTree(
  treeNode * node,
  string s
);

// printPreorder prototype
void printPreorder(
  treeNode * root,
  ofstream & ofile
);

// printInorder prototype
void printInorder(
  treeNode * root,
  ofstream & ofile
);

// printPostorder prototype
void printPostorder(
  treeNode * root,
  ofstream & ofile
);

#endif