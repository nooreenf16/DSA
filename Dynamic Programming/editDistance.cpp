/*Edit Distance of two strings is minimum number of operations required to make one string equal to other. In order to do so you can perform any of the following three operations only :
1. Delete a character
2. Replace a character with another one
3. Insert a character*/


// brute force
int editDistance(string s1, string s2) {
    if(s1.size() == 0 || s2.size() == 0){
        return s1.size() == 0 ? s2.size(): s1.size();
    }
    
    if(s1[0] == s2[0])
        return editDistance(s1.substr(1), s2.substr(1));
    else{
        int insert = 1 + editDistance(s1.substr(1), s2);
        int del = 1 + editDistance(s1, s2.substr(1));
        int update = 1 + editDistance(s1.substr(1), s2.substr(1));
        return min(insert, min(del, update));
    }
}

// memoization
int editDistanceHelper(string s1, string s2, int **output)
{
	//Write your code here
    int m = s1.size(), n = s2.size();
    
    if(s1.size() == 0 || s2.size() == 0)
        return s1.size() == 0? s2.size(): s1.size();
    
    if(output[s1.size()][s2.size()] != -1)
        return output[s1.size()][s2.size()];
    
    int ans;
    if(s1[0] == s2[0])
        ans = editDistanceHelper(s1.substr(1), s2.substr(1), output);
    else{
        int insert = 1 + editDistanceHelper(s1.substr(1), s2, output);
        int del = 1 + editDistanceHelper(s1, s2.substr(1), output);
        int update = 1 + editDistanceHelper(s1.substr(1), s2.substr(1), output);
        ans = min(insert, min(del, update));
    } 
    output[m][n] = ans;
    return ans;
}

int editDistance(string s1, string s2)
{
    if(s1.size() == 0 || s2.size() == 0)
        return 0;
    
    int m = s1.size(), n = s2.size();
    
    int **output = new int*[m+1];
    for(int i=0; i<=m; i++){
        output[i] = new int[n+1];
        for(int j=0; j<=n; j++)
            output[i][j] = -1;
    }
    
    return editDistanceHelper(s1, s2, output);
}
