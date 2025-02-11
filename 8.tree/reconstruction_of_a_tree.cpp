#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

#define rep(i, n) for(int i = 0; i < n; i++)

int pos;
vector<int> Preorder, Inorder, Postorder, Post;

void reconstruction(int start, int end) {

  if (start >= end) return;
  int root = Preorder[pos];
  pos++;

  int index = distance(Inorder.begin(), find(Inorder.begin(), Inorder.end(), root));

  reconstruction(start, index);
  reconstruction(index + 1, end);
 
  Post.push_back(root);
}

int main() {
  int n;
  scanf("%d", &n);
  int k;
  rep(i, n) {
    scanf("%d", &k);
    Preorder.push_back(k);
  }
  rep(i, n) {
    scanf("%d", &k);
    Inorder.push_back(k);
  }

  pos = 0;
  reconstruction(0, Inorder.size());

  rep(i, n) {
    if (i != 0) printf(" ");
    printf("%d", Post[i]);
  }
  printf("\n");

  return 0;
}
