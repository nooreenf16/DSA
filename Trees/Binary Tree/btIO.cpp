// takeInput recursive
btNode <int>* takeInput(){
  int rootData;
  cout<<"Enter node data: ";
  cin>>rootData;
  if(rootData == -1)
    return NULL;
  
  btNode <int>* root = new btNode(rootData);
  btNode <int>* leftChild = takeInput();
  btNode <int>* rightChild = takeInput();
  
  root->left = leftChild;
  root->right = rightChild;
  return root;
}

// printTree recursive
void printTree(btNode <int>* root){
  if(root == NULL)
    return;
  cout<<root->data<<": ";
  if(root->left != NULL)
    cout<<"L"<< root->left->data;
  if(root->right != NULL)
    cout<<" R"<<root->right->data;
  cout<<endl;
  printTree(root->left);
  printTree(root->right);
}
