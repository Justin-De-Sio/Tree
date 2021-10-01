#include <iostream>
#include "randomTree.hpp"
using namespace std;
int main() {
    cout << "Hello World!" << endl;
    RandomTree<string> myTree ("R");

    myTree.show();

    myTree.add("A");
    myTree.add("B");
    myTree.add("C");
    myTree.add("D");
    myTree.add("E");
    myTree.show();
}
