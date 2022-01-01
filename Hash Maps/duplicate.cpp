#include <unordered_map>
#include <vector>

// time complexity: O(n)
vector<int> removeDuplicates(int *a, int size){
  vector<int> output;
  unordered_map<int, bool> seen;
  
  for(int i=0; i<size; i++){
    if(seen.count(a[i]) > 0)
      continue;
    seen[a[i]] = true;
    output.push_back(a[i]);
  }
  return output;
}

int highestFrequency(int arr[], int n){
  unordered_map<int,int> output;
  vector<int> iterate;
  int maxx = 0, ans;
  for(int i=0; i<n; i++){
      if(output.count(arr[i]) > 0)
          output[arr[i]]++;

      else{
          output[arr[i]] = 1;
          iterate.push_back(arr[i]);
      }
  }
  for(int i=0; i<iterate.size(); i++){
      if(output[iterate[i]] > maxx){
              maxx = output[iterate[i]];
          ans = iterate[i];
      }
  }
  return ans;
}


