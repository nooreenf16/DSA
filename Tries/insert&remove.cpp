 class Trie{
   TrieNode *root;
   
   public:
   Trie(){
     root = new TrieNode('\0');
   }
   
   //helper for insertion
   void insertWord(TrieNode *root, string word){
     // base case
     if(word.size() == 0){ 
       root->terminal = true;
       return;
     }
     // calculation
     int index = word[0] - 'a'; // will give indexes of array as 1, 2 ...
     TrieNode *child;
     if(root->children[index] != NULL)
       child = root->children[index];
     else{
       child = new TrieNode(word[0]);
       root->children[index] = child;
     }
     // recursive call
     insertWord(child, word.substr(1));
   }
   void insertWord(string word){
     insertWord(root, word);
   }
   
   // helper for remove
  void removeWord(TrieNode *root, string word){
   if(word.size() == 0){
    root->isTerminal = false;
    return;
   }
   
   int index = word[0] - 'a';
   TrieNode *child;
   if(root->children[index] != NULL)
    child = root->children[index];
   else
    return;
   
   removeWord(child, word.substr(1));
   
   // removing
   if(child->isTerminal == false){
    for(int i=0; i<26; i++){
     if(child->children[i] != NULL)
      return;
    }
    delete child;
    root->children[index] = NULL;
   }
  }
  void removeWord(string word){
   removeWord(root, word);
  }
 }
