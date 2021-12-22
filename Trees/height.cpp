int height(btNode <int>* root){
  if(root == NULL)
    return 0;
  int h=0;
  for(int i=0; i < root->children.size(); i++)
    h = max(h, height(root->children[i]));
  return 1 + h;
            
