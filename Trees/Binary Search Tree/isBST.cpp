// method 1 : O(n*h)
int minimum(btNode <int>* root){
  if(root == NULL)
    return INT_MAX;
  return min(root->data, min(minimum(root->left), minimum(root->right)));
}
             
int maximum(btNode <int>* root){
  if(root == NULL)
    return INT_MIN;
  return max(root->data, max(maximum(root->left), maximum(root->right)));
}

bool isBST(btNode <int>* root){
  if(root == NULL)
    return true;
  int leftMax = maximum(root->left);
  int rightMin = minimum(root->right);
  
  int output = (root->data > leftMax) && (root->data < rightMin) && isBST(root->left) && isBST(root->right);
  return output;
}

// method 2 : O(n)
// instead of return min, max and bool of isBST seperately, it's done altogether with a class object
class isBSTreturn{
  public:
  int minimum;
  int maximum;
  bool isBST;
}
isBSTreturn isBST2(btNode <int>* root){
  if(root == NULL){
    isBSTreturn output;
    output.minimum = INT_MIN;
    output.maximum = INT_MAX;
    output.isBST = true;
  }
  isBSTreturn leftOutput = isBST2(root->left);
  isBSTreturn rightOutput = isBST2(root->right);
  
  int minimum = min(root->data, min(leftOutput.minimum, rightOutput.minimum)); //getting the overall min from left subtree
  int maximum = max(root->data, max(leftOutput.maximum, rightOutput.maximum)); 
  bool isBSTfinal = (root->data > leftOutput.maximum) && (root->data < rightOutput.minimum) && leftOutput.isBST && rightOutput.isBST;
  
  isBSTreturn output;
  output.minimum = minimum;
  output.maximum = maximum;
  output.isBST = isBSTfinal;
  
  return output;
}

// method 3 : O(n)
// pushing constraints on each level
bool isBST3(btNode <int>* root, int min=INT_MIN, int max=INT_MAX){
  if(root == NULL)
    return true;
  if(root->data < min || root->data >max)
    return false;
  bool left = isBST3(root->left, min, root->data);
  bool right = isBST3(root->right, root->data, max);
  return left && right;
}
    
