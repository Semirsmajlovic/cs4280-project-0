// Define our includes
#include <iostream>

#include <fstream>

#include "tree.h"

using namespace std;

int main(int argc, char * argv[]) {
  // Define our variables
  string file;
  string outPre;
  string outIn;
  string outPost;
  ofstream printPre;
  ofstream printIn;
  ofstream printPost;

  // Read our arguments count
  if (argc == 1) {
    try {

      // Set our variables
      string userInput;
      ofstream temp;
      file = "temp.sp2022";
      outPre = "output.preorder";
      outIn = "output.inorder";
      outPost = "output.postorder";

      // Open our temp file.
      temp.open(file.c_str());
      while (cin >> userInput) {
        temp << userInput << " ";
      }
      temp.close();
    } catch (const ifstream::failure & e) {
      cout << "\n***************************************************************\n";
      cout << "There has been an error, file either doesn't exist or is empty.\n";
      cout << "***************************************************************\n\n";
      return 1;
    }
  } else if (argc == 2) {
    file = argv[1];
    outPre = file;
    outPre.append(".preorder");
    outIn = file;
    outIn.append(".inorder");
    outPost = file;
    outPost.append(".postorder");
    file.append(".sp2022");
  } else if (argc > 2) {
    cout << "\n*********************************************************************************\n";
    cout << "You have provided more than 2 arguments, please read the README for instructions.\n";
    cout << "*********************************************************************************\n\n";
    return 1;
  }

  // Build our tree with failsafe.
  treeNode * root = buildTree(file);

  // Failsafe for empty or non-existant files.
  if (root == NULL) {
    cout << "\n***************************************************************\n";
    cout << "There has been an error, file either doesn't exist or is empty.\n";
    cout << "***************************************************************\n\n";
    return 1;
  }
  cout << "\n*****************************************************";

  // Build our preorder file.
  cout << "\nStep 1: The preorder file is being built...\n";
  printPre.open(
    outPre.c_str()
  );
  printPreorder(
    root,
    printPre
  );
  printPre.close();

  // Build our print in order file.
  cout << "Step 2: The inorder file is being built...\n";
  printIn.open(
    outIn.c_str()
  );
  printInorder(
    root,
    printIn
  );
  printIn.close();

  // Build our post order file.
  cout << "Step 3: The postorder file is being built...\n";
  printPost.open(
    outPost.c_str()
  );
  printPostorder(
    root,
    printPost
  );

  cout << "\nThe traversals have been completed.\n";
  cout << "*****************************************************\n\n";

  printPost.close();

  return 0;
}