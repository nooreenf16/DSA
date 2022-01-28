// ------------------------------------- recursive {time comp = exponential} -------------------------------------
int lcs(string s, string t){
  // base case
  if(s.size() == 0 || t.size() == 0)
    return 0;
  // recursive calls
  if(s[0] == t[0])
    return lcs(s.substr(1), t.substr(1));
  else{
    int a = lcs(s.substr(1), t); // when match of s[0] is not present
    int b = lcs(s, t.substr(1)); // when match of t[0] is not present
    int c = lcs(s.substr(1), t.substr(1)); // when match of both s[0] and t[0] are not present //can be omitted
    return max(a, max(b,c));
  }
}

// ------------------------------------- memoization -------------------------------------
int lcsHelper(string s, string t, int **output){
  int m = s.size(), n = t.size();
  // base case
  if(s.size() == 0 || t.size() == 0)
    return 0;
  // check if o/p already exists at i,j
  if(output[m][n] != -1)
     return output[m][n];
  
  int ans;
  // recursive calls
  if(s[0] == t[0])
    ans = 1 + lcsHelper(s.substr(1), t.substr(1), output);
  else{
    int a = lcsHelper(s.substr(1), t, output); // when match of s[0] is not present
    int b = lcsHelper(s, t.substr(1), output); // when match of t[0] is not present
    int c = lcsHelper(s.substr(1), t.substr(1), output); // when match of both s[0] and t[0] are not present //can be omitted
    ans = max(a, max(b,c));
  }
  //saving final answer in output array
  output[m][n] = ans;
  return ans;
}

int lcs(string s, string t){
  int m = s.size();
  int n = t.size();
  
  int **output = new int*[m];
  for(int i=0; i<=m; i++){
    output[i] = new int[n+1];
    for(int j=0; j<=n; j++)
      output[i][j] = -1;
  }
  return lcsHelper(s, t, output);
}

// ------------------------------------- dynamic programming -------------------------------------
int lcs(string s, string t){
  int m = s.size(), n = t.size();
  int **output = new int*[m+1];
  for(int i=0; i<=m; i++){
    output[i] = new int[n+1];
    for(int j=0; j<=n; j++)
      output[i][j] = -1;
  }
  // filling the cells which has no dependencies
  output[0][0] = 0;
  for(int i=0; i<=n; i++) // row
    output[0][i] = 0;
  for(int i=0; i<=m; i++) // col
    output[i][0] = 0;
  // filling rest of the cells
  for(int i=1; i<=m; i++){
    for(int j=1; j<=n; j++){
      // check if first char matches
      if(s[m-i] == t[n-j])
        output[i][j] = 1 + output[i-1][j-1];
      else{
        output[i][j] = max(output[i-1][j], max(output[i][j-1], output[i-1][j-1])); // min of laft, top, diag cells
      }
    }
  }
  return output[m][n];
}
