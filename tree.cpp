#include <iostream>
#include <stdlib.h>
using namespace std;
struct node
{
  int val;
  struct node* left;
  struct node* right;
};
void traverse(struct node* n)
{
  if( n == NULL)
  {
    return;
  }
  traverse(n->left);
  cout<<n->val;
  traverse(n->right);
}
struct node* newNode(int n)
{
  struct node* element = (struct node*)malloc(sizeof(struct node));
  element->val = n;
  element->left = NULL;
  element->right = NULL;
  return(element);
}
int main()
{
  struct node* root = (struct node*)malloc(sizeof(struct node));
  root->val = 5;
  root->left = newNode(2);
  root->right = newNode(8);
  root->left->left = newNode(1);
  root->left->right = newNode(3);

  traverse(root);
  return 0;
}
