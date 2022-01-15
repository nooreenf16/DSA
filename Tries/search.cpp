bool search(TrieNode* root, string word) {
  if(word.size() == 0)
       return root->isTerminal;

  int index = word[0] - 'a';
  if(root->children[index] != NULL)
      return search(root->children[index], word.substr(1));
  else
      return false;
    }
bool search(string word) { 
  return search(root, word); 
}
