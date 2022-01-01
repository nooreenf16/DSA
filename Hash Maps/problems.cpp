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

/*******************************************************************************************************/
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

/*******************************************************************************************************/
void printIntersection(int arr1[], int arr2[], int n, int m) {
   unordered_map<int, int> mp;
    // Hashing the elements of the first array
    for (int i = 0; i < n; i++)
        mp[arr1[i]]++;

    for (int j = 0; j < m; j++)
    {
        // Checking if the elements are present in the second array or not.
        if (mp.count(arr2[j]) != 0)
        {
            cout<<arr2[j]<<endl;
            mp[arr2[j]]--;
            // Deleting the element if it's frequency is 0.
            if (mp[arr2[j]] == 0) 
                mp.erase(arr2[j]);
        }
    }
}
