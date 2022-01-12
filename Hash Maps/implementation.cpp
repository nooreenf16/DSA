template <class T>
class mapNode{
  public:
  string key;
  T value;
  mapNode* next;
  
  mapNode(string key, T value){
    this->key = key;
    this->value = value;
  }
  ~mapNode(){
    delete next;
  }
}

template <typename T>
class ourmap{
  mapNode<T>** buckets;
  int count;
  int numBuckets;
  public:
  ourmap(){
    count = 0;
    numBuckets = 5
    buckets = new mapNode<T>*[numBuckets];
    // to change the garbage addresses of the array to NULL
    for(int i=0; i < numBuckets; i++)
      buckets[i] = NULL;
   }
  ~ourmap(){
    // delete the linked lists
    for(int i=0; i < numBuckets; i++)
      delete buckets[i];
    // delete the array
    delete []buckets;
  }
  
  int size(){
    return count;
  }
  
  int getIndex(string key){
    int hashCode = 0;
    int currentCoeff = 1;
    
    for(int i = key.length()-1; i >= 0; i--){
      hashCode += key[i] * currentCoeff;
      hashCode = hashCode % numBuckets; // to make sure index isn't out of bounds
      currentCoeff *= 37;
      currentCoeff = currentCoeff % numBuckets;
    }
    return hashCode % numBuckets;
  }
  
  void insert(string key, T value){
    int bucketIndex = getIndex(string key);
    mapNode<T>* head = new bucket[bucketIndex];
    while(head != NULL){
      if(head->key == key){
        head->value = value;
        return;
      }
      head = head->next;
    }
    if(head == NULL){
      head = bucket[bucketIndex];
      mapNode<T>* node = new mapNode<T>(key, value);
      node->next = head;
      bucket[bucketIndex] = node;
      count++;
    }
}
        
        
