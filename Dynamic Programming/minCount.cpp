// minimum number of steps to reach 1 from n by -1 or /2 or /3

// brute force
int minCount(int n){
  if(n<=1)
    return 0;
  
  int x = minCount(n-1);
  
  if(n%2 == 0)
    int y = minCount(n/2);
  if(n%3 == 0)
    int z = minCount(n/3);
  
  return 1 + min(x, min(y,z));
}
