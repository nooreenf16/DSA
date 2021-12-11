// recursive input function
TreeNode<int>* takeInput(){
  int rootData, n;
  
  cout<<"Enter root data: ";
  cin>>rootData;
 
  cout<<"Enter number of children of "<<rootData<<": ";
  cin>>n;
  
  for(int i=0; i<n; i++){
    TreeNode<int>* child = takeInput();  // looping over all the children to take its data
    root->children.push_back(child);  // pushing the child into children vector
  }
  
  return root;
}

// recursive printing function
void printTree(TreeNode <int>* root)
{
  if(root == NULL) // edge case, not base case
    return; 
  
  cout<<root->data<<" : ";
  for(int i=0; i < root->children.size(); i++) // prints all the children of the current node
    cout<<root->children[i]->data<<" ";
  cout<<endl;
  
  for(int i=0; i < root->children.size(); i++){
    printTree(root->children[i]);  // passing the ith child of the current node in arg
  }
}

// level wise taking input using queues
TreeNode <int>* takeInputLevel(){
  int rootData;
  cout<<"Enter root data; ";
  cin>>rootData;
  TreeNode <int>* root = new TreeNode<int>(rootData);
  queue<TreeNode<int>*> pendingNodes;
  pendingNodes.push(root);
  
  while(!pendingNodes.empty()){
    int numChild;
    TreeNode <int>* front = pendingNodes.front();
    pendingNodes.pop(); // removing the node whose children are taken
    cout<<"Enter number of children of "<< front->data;
    cin>>numChild;
    for(int i=0; i<numChild; i++){
      int childData;
      cout<<"Enter the child data: ";
      cin>>childData;
      TreeNode <int>* child = new TreeNode<int>(childData);
      front->children.push_back(child);
      pendingNodes.push(child);
    }
  }
  return root;
}

// level wise printing output using queues
void printTreeLevel(TreeNode<int>* root){
  if(root == NULL)
    return;
  queue<TreeNode<int>*> pending;
  pending.push(root);
  do{
    TreeNode<int>* front = pending.front();
    pending.pop();
    cout<<front->data<<":";
    for(int i=0; i < front->children.size(); i++){
      cout<<front->children[i]->data;
      pending.push(front->children[i]);
      if(i+1 == front->children.size())
        break;
       cout<<",";
    }
    cout<<endl;
  }while(!pending.empty());
}
