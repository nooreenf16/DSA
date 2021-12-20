// method 1
int height(btNode <int>* root){
  if(root == NULL)
    return 0;
  return 1+ max(height(root->left, root->right));
}

int diameter(btNode<int>* root){
  if(root == NULL)
    return 0;
  int option1 = height(root->left) + height(root->right);
  int option2 = diameter(root->left);
  int option3 = diameter(root->right);
  
  return max(option1, max(option2, option3));
}
