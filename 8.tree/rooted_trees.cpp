#include<iostream>
using namespace std;

#define MAX 100005
#define NIL -1
#define rep(i, n) for (int i = 0; (i) < (n); ++(i))

struct Node { int parent, leftChild, rightSibling; };

Node Tree[MAX];
int n, Depth[MAX];

// void printChildlen(int parentNodeId) {
//   Node parentNode = Tree[parentNodeId];
//   cout << "[";
//   Node node = Tree[parentNode.leftChild];
//   // int rightSiblingId;
//   for (int i = 0; node.rightSibling != NIL; i++) {
//     if (i == 0) {
//       if (parentNode.leftChild != NIL) {
//         cout << parentNode.leftChild;
//       }
//       node = Tree[parentNode.leftChild];
//     }
//     else {
//       cout << ", " << node.rightSibling;
//       node = Tree[node.rightSibling];
//     }
//   }
//   cout << "]";
// }

void printChildlen(int parentNodeId) {
    cout << "[";
    if (Tree[parentNodeId].leftChild != NIL) {
        // Print first child
        cout << Tree[parentNodeId].leftChild;
        
        // Print remaining siblings
        int currentChild = Tree[Tree[parentNodeId].leftChild].rightSibling;
        while (currentChild != NIL) {
            cout << ", " << currentChild;
            currentChild = Tree[currentChild].rightSibling;
        }
    }
    cout << "]";
}

void printNode(int id) {
  Node node = Tree[id];
  int depth = Depth[id];
  cout << "node " << id << ": ";
  cout << "parent = " << node.parent << ", ";
  cout << "depth = " << depth << ", ";
  if (node.parent == NIL) {
    cout << "root, ";
  }
  else if (node.leftChild == NIL) {
    cout << "leaf, ";
  }
  else {
    cout << "internal node, ";
  }
  printChildlen(id);
  cout << "\n";

}

void setDepth(int nodeId, int depth) {
  Depth[nodeId] = depth;
  if (Tree[nodeId].rightSibling != NIL) setDepth(Tree[nodeId].rightSibling, depth);
  if (Tree[nodeId].leftChild != NIL) setDepth(Tree[nodeId].leftChild, depth + 1);
}

int main() {
  int id, childNum, childId;
  int leftChildId;
  cin >> n;
  rep(i, n) Tree[i].parent = Tree[i].leftChild = Tree[i].rightSibling = NIL;

  rep(i, n) {
    cin >> id >> childNum;

    rep(i, childNum) {
      if (childNum != 0) {
        cin >> childId;

        if (i == 0) {
          Tree[id].leftChild = childId;
        }
        else {
          Tree[leftChildId].rightSibling = childId;
        }

        leftChildId = childId;

        Tree[childId].parent = id;
      }
    }
  }
  

  int rootId;

  rep(i, n) {
    if (Tree[i].parent == NIL) rootId = i;
  }

  setDepth(rootId, 0);

  // rep(i, n) cout << Depth[i];

  rep(i, n) printNode(i);

  return 0;
}
