// recursive input function
TrreNode<int>* takeInput(){
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

// level wise printing


