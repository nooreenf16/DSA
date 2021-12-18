template <class T>
class btNode 
{
  public:
  T data;
  btNode *left;
  btNode *right;
  
  btNode(T data){
    this->data = data;
    left = NULL;
    right = NULL;
  }
  ~btNode(){
    delete left;
    delete right;
  }
};
