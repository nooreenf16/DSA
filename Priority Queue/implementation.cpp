// Priority Queues are implemented using heaps (using complete binary trees-> vector/array implementation)
// children of ith node = 2i+1 and 2i+2
class PriorityQueue{
   vector<int> pq;
  public:
  PriorityQueue(){
  }
  bool isEmpty(){
    return pq.size() == 0;
  }
  int getSize(){
    return pq.size();
  }
  int getMin(){
    if(isEmpty())
      return 0;
    return pq[0];
  }
  
  void insert(int ele){
    pq.push_back(ele);
    
    int childIndex = pq.size() - 1;
    while(childIndex > 0){
      int parentIndex = (childIndex - 1)/2;
      if(pq[childIndex] < pq[parentIndex]){
        int temp = pq[childIndex];
        pq[childIndex] = pq[parentIndex];
        pq[parentIndex] = temp;
      }
      childIndex = parentIndex;
    }
  }
                  
