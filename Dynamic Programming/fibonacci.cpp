// ------------------------------ using memoization and recursion (top-down)------------------------------
int fiboHelper(int n, int *ans){
  if(n<=1)
    return 1;
  //check if o/p already exists
  if(ans[n] != 1)
    return ans[n];
  // calculation
  int a = fiboHelper(n-1, ans);
  int b = fiboHelper(n-2, ans);
  //save output
  ans[n] = a+b;
  
  return ans[n];
}

int fibo(int n){
  int* ans = new int[n+1];
  // to change thegarbage values
  for(int i=0; i<n+1; i++)
    ans[i] = -1;
  return fiboHelper(n, ans);
}

// ------------------------------ dynamic programming (botton-up) ------------------------------
int fibo(int n){
  int* ans = new int[n+1];
  // to change thegarbage values
  for(int i=0; i<n+1; i++)
    ans[i] = -1;
  
  ans[0] = 0;
  ans[1] = 1;
  
  for(int i=2; i<n; i++){
    ans[i] = ans[i-1] + ans[i-2];
  }
  
  return ans[n];
}
