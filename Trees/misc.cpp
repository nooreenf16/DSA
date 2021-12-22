// contains x
bool isPresent(btNode <int>* root){
  if(root == NULL)
    return false;
  if(root->data == x)
    return true;
  for(int i=0; i < root->children.size(); i++){
    if(isPresent(root->children[i]))
       return true;
  }
  return false;
}
     
