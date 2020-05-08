/*
Code copied from voturbac

      0
      |
      1
     / \
    2   4
   /     \
  3       5


  |          |
  |          |
  |          |
  |          |
  |____0_____|

  0 s neighbors are 1

  |          |
  |          |
  |          |
  |    1     |
  |____0_____|


 1's neighbors are 2 and 3

  |          |
  |          |
  |    2     |
  |    1     |
  |____0_____|


  2's neighbors are 3

  |          |
  |    3     |
  |    2     |
  |    1     |
  |____0_____|

  Then 3 has no neghbors so we go to this part of the Code

 code fragment:   diameter=max(diameter,depth+max_depth);
    	 		  max_depth=max(depth,max_depth);

depth = 1
diameter = 1
max_depth = 1

  |          |
  |          |
  |    2     |
  |    1     |
  |____0_____|

  As 2s neighbors have been explored
  we enter the code fragment
depth = 2
diameter = 2
max_depth = 2

  |          |
  |          |
  |    4     |
  |    1     |
  |____0_____|


  |          |
  |    5     |
  |    4     |
  |    1     |
  |____0_____|


  As 5 has no unvisited neighbors we enter the code fragment

depth = 1
diameter = 2 (cuz max_depth+depth is equal to 1 but doest beat the maximum diameter)
max_depth = 1 

  |          |
  |          |
  |    4     |
  |    1     |
  |____0_____|

depth = 2
diameter = 2 
max_depth = 2

  |          |
  |          |
  |          |
  |    1     |
  |____0_____|

  As 1 has no unvisited neighbors

depth = 3
diameter = 4 
max_depth = 3  

  |          |
  |          |
  |          |
  |          |
  |____0_____|

depth = 3
diameter = 4 
max_depth = 3

So my diameter code wuld have cached in my maximum by then which i will return to my caller function
*/

    int dfs(vector<vector<int>>& graph,vector<bool> &vis,int i,int &diameter)
    {
        vis[i]=true;
        int max_depth=0;
        for(int j:graph[i])
        {
            if(vis[j])continue;
            int depth=dfs(graph,vis,j,diameter);
            diameter=max(diameter,depth+max_depth);
            max_depth=max(depth,max_depth);
        }
        cout<<i<<" "<<diameter<<" "<<max_depth<<endl;
        return i==0?diameter:max_depth+1;
    }
    int treeDiameter(vector<vector<int>>& edges) {
        int diameter=0;
        vector<vector<int>> graph(edges.size()+1);
        vector<bool> vis(edges.size()+1,false);
        for(auto &x:edges)
        {
            graph[x[0]].push_back(x[1]);
            graph[x[1]].push_back(x[0]);
        }
        dfs(graph,vis,0,diameter);
        return diameter;
    }  
