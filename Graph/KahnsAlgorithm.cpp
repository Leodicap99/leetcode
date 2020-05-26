void toposort()
{
	vector<int> indegree(n,0);
	for(int i=0;i<n;i++)
	{
		for(auto &x:adj[i])
			indegree[x]++;
	}
	queue<int> q;
	for(int i=0;i<n;i++)
	{
		if(indegree[i]==0)q.push(i);
	}
	int count=0;
	vector<int> top_order;
	while(!q.empty())
	{
		int t=q.front();
		q.pop();
		top_order.push_back(t);
		for(auto &x:adj[t])
		{
			if(--indegree[x]==0)q.push(x);
		}
	}
	if(count==n)cout<<"NO SORT POSSIBLE"<<endl;
	else 
	{
		for(int i=0;i<top_order.size();i++)
		{
			cout<<top_order[i]<<" ";
		}
	}
}