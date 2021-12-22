// method 1
int minimum(bstNode <int>* root){
  if(root == NULL)
    return INT_MAX;
  return min(root->data, min(minimum(root->left), minimum(root->right)));
}
             
int maximum(bstNode <int>* root){
  if(root == NULL)
    return INT_MIN;
  return max(root->data, max(maximum(root->left), maximum(root->right)));
}

bool isBST(bstNode <int>* root){
  if(root == NULL)
    return true;
  int leftMax = maximum(root->left);
  int rightMin = minimum(root->right);
  
  int output = (root->data > leftMax) && (root->data < rightMin) && isBST(root->left) && isBST(root->right);
  return output;
}
