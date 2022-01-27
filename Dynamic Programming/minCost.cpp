// brute force O(n)=>exponential
int minCostPathHelper(int **input, int m, int n, int i, int j){
    if(i == m-1 && j == n-1)
        return input[i][j];
    
    if(i>=m || j>=n)
        return INT_MAX;
    
    int rig = minCostPathHelper(input, m, n, i+1, j);
    int diag = minCostPathHelper(input, m, n, i+1, j+1);
    int down = minCostPathHelper(input, m, n, i, j+1);
    
    int ans = input[i][j] + min(rig, min(diag, down));
    return ans;
}

int minCostPath(int **input, int m, int n)
{
    return minCostPathHelper(input, m, n, 0, 0);
}

// memoization (top-down)
int minCostPathHelper(int **input, int m, int n, int i, int j, int **output){
  if(i == m-1 && j == n-1)
        return input[i][j];
  if(i>=m || j>=n)
        return INT_MAX;
  
  if(output[i][j] != -1){
    return output[i][j];
  }
  int rig = minCostPathHelper(input, m, n, i+1, j, output);
  int diag = minCostPathHelper(input, m, n, i+1, j+1, output);
  int down = minCostPathHelper(input, m, n, i, j+1, output);
  
  int ans = input[i][j] + min(rig, min(diag, down)); 
  output[i][j] = ans; // save for future use
  
  return output[0][0];
}
int minCostHelper(int **input, int m, int n){
  int output[m][n];
  for(int i=0; i<m; i++){
    for(int j=0; j<n; j++)
      output[i][j] = -1;
  }
  return minCostPathHelper(input, m, n, i, j, output);
}

// dynamic programming (bottom-up) O(n)=> mxn
int minCostPath(int **input, int m ,int n){
  int **output = new int*[m];
  for(int i=0; i<m; i++)
    output[m] = new int[n];
  // fill last cell .i.e. destination
  output[m-1][n-1] = input[m-1][n-1];
  // fill last row (right to left)
  for(int i = n-2; i>=0; i--)
    output[m-1][i] = output[m-1][i+1] + input[m-1][i];
  // fill last column (bottom to top)
  for(int i = m-2; i>=0; i--)
    output[i][n-1] = output[i+1][n-1] + input[i][n-1];
  // fill remaining
  for(int i = m-1; i>=0; i--){
    for(int j = n-2; j>=0; j--)
      output[i][j] = min(output[i][j+1], min(output[i+1][j], output[i+1][j+1])) + input[i][j];
  }
  return output[0][0];
}






