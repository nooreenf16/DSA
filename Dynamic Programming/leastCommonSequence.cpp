// recursive {time comp = exponential}
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

// memoization
