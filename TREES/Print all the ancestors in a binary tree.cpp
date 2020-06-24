bool printAncestors(struct node *root, int target) 
{ 
  /* base cases */
  if (root == NULL) 
     return false; 
  
  if (root->data == target) 
     return true; 
  
  /* If target is present in either left or right subtree of this node, 
     then print this node */
  if ( printAncestors(root->left, target) || 
       printAncestors(root->right, target) ) 
  { 
    cout << root->data << " "; 
    return true; 
  } 
  
  /* Else return false */
  return false; 
} 
