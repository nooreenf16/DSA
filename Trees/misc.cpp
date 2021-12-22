// contains x
bool isPresent(btNode <int>* root, int x){
  if(root == NULL)
    return false;
  if(root->data == x)
    return true;
  for(int i=0; i < root->children.size(); i++){
    if(isPresent(root->children[i], x))
       return true;
  }
  return false;
}
     
// get nodes larger than x
int getLargeNodeCount(TreeNode<int>* root, int x) {
    // Write your code here
    if(root == NULL)
        return 0;
    int n=0;
    if(root->data > x)
        n++;
    for(int i=0; i < root->children.size(); i++)   
        n += getLargeNodeCount(root->children[i], x);
    return n;
}

// to check if 2 trees are identical
