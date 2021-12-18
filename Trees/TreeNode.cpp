#include <vector>
template <class T>;
class TreeNode{
  public:
  T data;
  vector<TreeNode <T>*> children;
  
  TreeNode(T data){
    this->data = data;
  }
  // delete tree using destructor
  // in main-> delete root;
  ~TreeNode(){ 
    for(int i=0; i<children.size(); i++)
      delete children[i];
  }
}


// delete tree using function
void deleteTree(TreeNode <int>* root){
  for(int i=0; i < root->children.size(); i++)
    deleteTree(root->children[i]);
  delete root;
}
