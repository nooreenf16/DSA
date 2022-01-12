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
  
  int getValue(string key){
    int bucketIndex = getIndex(string key);
    mapNode<T>* head = buckt[bucketIndex];
    while(head != NULL){
      if(head->key == key)
        return head->value;
      head = head->next;
    }
    return 0;
  }
  
  int size(){
    return count;
  }
  
  private:
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
  
  public:
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
/*  
  T remove(string key){
    int bucketIndex = getIndex(string key);
    mapNode<T>* head = new bucket[bucketIndex];
    while(head != NULL){
      if(head->next->key == key){
        mapNode<T>* temp = head->next;
        head->next = temp->next;
      }
      head = head->next;
    }
    return temp->value;
  }
  */
  T remove(string key){
    int bucketIndex = getIndex(string key);
    mapNode<T>* head = buckt[bucketIndex];
    mapNode<T>* prev = NULL;
    
    while(head != NULL){
      if(head->key == key){
        if(prev->key == NULL)
          bucket[bucketIndex] = head->next;
        else
          prev->next = head->next;
        T value = head->value;
        head->next = NULL;
        delete head;
        count--;
        return value;
        
      }
      prev = head;
      head = head->next;
    }
    return 0;
  }
  
        
        
