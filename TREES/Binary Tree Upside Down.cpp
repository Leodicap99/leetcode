/*
Input: [1,2,3,4,5]
    1
   / \
  2   3
 / \
4   5



Output: [4,5,2,#,#,3,1]

   4
  / \
 5   2
    / \
   3   1 



Follow the reversing of linked list code
*/
    TreeNode* upsideDownBinaryTree(TreeNode* root) {
        TreeNode* curr=root,*next,*prev=NULL,*temp=NULL;
        while(curr)
        {
            next=curr->left;
            
            curr->left=temp;
            temp=curr->right;
            curr->right=prev;
            
            prev=curr;
            curr=next;
        }
        return prev;
    }


/*

public ListNode reverseList(ListNode head) {
        ListNode pre = null;
        ListNode cur = head;
        while (cur != null) {                              <---------Reversing ll
            ListNode next = cur.next;
            cur.next = pre;
            pre = cur;
            cur = next;
        }
        
        return pre;
}
*/