void printLevelWise(BinaryTreeNode<int> *root) {
    if(root == NULL)
        return;
    queue<BinaryTreeNode<int>*>pending;
    pending.push(root);
    pending.push(NULL);
    while(pending.size() != 0){
        BinaryTreeNode<int>* front = pending.front();
        pending.pop();
        if(front == NULL){
            if(!pending.empty())
            	pending.push(NULL);
            cout<<endl;
        }
        else{
            cout<<front->data<<" ";
            if(front->left != NULL)
                pending.push(front->left);
            if(front->right != NULL)
                pending.push(front->right);
        }
    }
}

/************OUTPUT************/
/*
1
2 3
4 5 6 7
*/
  
