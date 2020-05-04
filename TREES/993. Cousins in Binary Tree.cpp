/*
The question asks for x and y who have different parents and same depth.
My answer would be a bfs.
We use two maps to solve the problem; One for storing the prent of x and y
The pther for stroing the depth of x and y
Finally if the first map values are unequal and the second map values are equal we return true.
*/

    bool isCousins(TreeNode* root, int x, int y) {
        unordered_map<int,TreeNode*> map;
        map[x]=root;
        map[y]=root;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty())
        {
            TreeNode* t=q.front();
            q.pop();
            if(t->left)
            {
                if(t->left->val==x)map[x]=t;
                else if(t->left->val==y)map[y]=t;
                q.push(t->left);
            }
            if(t->right)
            {
                if(t->right->val==x)map[x]=t;
                else if(t->right->val==y)map[y]=t;
                q.push(t->right);
            }
        }
        unordered_map<int,int> map1;
        int level=0;
        q.push(root);
        while(!q.empty())
        {
            int n=q.size();
            level++;
            for(int i=0;i<n;i++)
            {
                TreeNode* t=q.front();
                q.pop();
                if(t->val==x)map1[x]=level;
                else if(t->val==y)map1[y]=level;
                if(t->left)q.push(t->left);
                if(t->right)q.push(t->right);
            }
        }
        return map[x]!=map[y]&&map1[x]==map1[y];
    }