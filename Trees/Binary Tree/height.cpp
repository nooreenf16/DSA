// height of a binary tree
int height(btNode<int>* root){
  if(root == NULL)
    return 0;
  return 1 + max(height(root->left), height(root->right));
}
