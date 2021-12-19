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

// takeInput level wise
btNode <int>* takeInputLevel(){
  int rootData;
  cout<<"Enter node data: ";
  cin>>rootData;
  if(rootData == -1)
    return;
  btNode <int>* root = new btNode(rootData);
  queue<btNode<int>*> pendingNodes;
  pendingNodes.push(root);
  while(pendingNodes.size() != 0){
    btNode <int>* front = pendingNodes.front();
    pendingNodes.pop();
    cout<<"Enter left child of "<<front->data;
    int lcData;
    cin>>lcData;
    if(lcData != -1){
      btNode <int>* leftChild = takeInputLevel();
      pendingNodes.push(leftChild);
      front->left = leftChild;
    }
    cout<<"Enter right child of"<<front->data;
    int rcData;
    cin>>rcData;
    if(rcData != -1){
      btNode <int>* rightChild = takeInputLevel();
      pendingNodes.push(rightChild);
      front->right = rightChild;
    }
  }
  return root;
}

// printInput level wise
void printInputLevel(btNode <int>* root){
  if(root == NULL)
    return;
  queue<BinaryTreeNode<int>*> pending;
  pending.push(root);
  while(pending.size() != 0){
      btNode<int>* front = pending.front();
      pending.pop();
      cout<<front->data<<":";
      if(front->left == NULL)
          cout<<"L:-1,";
      else{
          cout<<"L:"<<front->left->data<<",";
          pending.push(front->left);
      }
      if(front->right == NULL)
          cout<<"R:-1"<<endl;
      else{
          cout<<"R:"<<front->right->data<<endl;
          pending.push(front->right);
      }
  }
}
