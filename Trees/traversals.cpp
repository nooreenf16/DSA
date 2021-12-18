// pre order traversal
void preorder(TreeNode <int>* root){
  if(root == NULL)
    return;
  cout<<root->data<<" ";
  for(int i=0; i < root->children.size(); i++)
    preorder(root->children[i]);
}

// post order traversal
void postorder(TreeNode <int>* root){
  if(root == NULL)
    return;
  for(int i=0; i < root->children.size(); i++)
        printPostOrder(root->children[i]);
  cout<<root->data<<" ";
}

//inorder traversal
void inorder(TreeNode <int>* root){
  if(root == NULL)
    return;
}
