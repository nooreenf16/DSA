// finding the min and max data of the tree and returning it as a pair
int findMin(btNode<int> *root){
    if(root == NULL)
        return INT_MAX;
    int left = findMin(root->left);
    int right = findMin(root->right);
    int res = min(left, right);
    return min(root->data, res);
}
int findMax(btNode<int> *root){
    if(root == NULL)
        return INT_MIN;
    int left = findMax(root->left);
    int right = findMax(root->right);
    int res = max(left, right);
    return max(root->data, res);
}

pair<int, int> getMinAndMax(btNode<int> *root) {
    pair<int, int>p;
    p.first = findMin(root);
    p.second = findMax(root);
    return p;
}
