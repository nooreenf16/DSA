// Pre Order Traversal => root - left child - right child
void preOrder(btNode<int>* root){
  if(root == NULL)
    return;
  cout<<root->data<<" ";
  preOrder(root->left);
  preOrder(root->right);
}
  
 // In Order Traversal => left child - root - right child
void inOrder(btNode <int>* root){
  if(root == NULL)
    return;
  inOrder(root->left);
  cout<<root->data<<" ";
  inOrder(root->right);
}

// Post Order Traversal => left child - right child - root
void postOrder(btNode <int> *root) {
    if(root == NULL)
        return;
    postOrder(root->left);
    postOrder(root->right);
    cout<<root->data<<" ";
}


/********************************************************/
/****** CONSTRUCTION OF TREE USING THE ORDER GIVEN ******/

// using PreOrder and InOrder
btNode <int>* buildTree(int *preorder, int prelength, int *inorder, int inlength){
  
