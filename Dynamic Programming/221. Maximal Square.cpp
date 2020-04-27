/*
We use a dp matrix to solve.
the ith,jth location tells us the length of the square formed.So finally I can return ans*ans to the caller function.
Let the input be:
		
		1 0 1 0 0
        1 0 1 1 1     <----------- INPUT MATRIX
        1 1 1 1 1
        1 0 0 1 0
How to construct a dp matrix?
First try to figure out what you want. Here i want to find the maximum area(this can be found using max side as square are is side*side).
So we buid the matrix by calculating the side length. 
Posiible squares

1

11
11

111
111
111

And so on.We can build this bottom up using the formula if we encountered a 1 dp[i][j] =1+min(dp[i-1][j],min(dp[i-1][j-1],dp[i][j-1])).
So what does the formula signify? Thig this visually->If i encounter a 1 i must know if there is a possibility for a bigger square length.
 example

 11
 11  here after encountering first 1 this is the maximal possible square however when encountering the last 1 use the formula and u get the side length.
  We have to create dp of size n+1 and m+1 cuz for the first row using the formula it will throw an error.You can solve this issue evn by usin if else statement.     
       0 0 0 0 0 0
       0 1 0 1 0 0
       0 1 0 1 1 1     <----------- DP MATRIX
       0 1 1 1 2 2
       0 1 0 0 1 0

       We can see the maximum value is 2 thus the answer is 2*2 =4.
*/

    int maximalSquare(vector<vector<char>>& matrix) {
     int m = matrix.size();
    if(m==0) return 0;
    int n = matrix[0].size();
    
    vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
    
    int ret = 0;
    for(int i = 1; i <= m; i ++){
        for(int j = 1; j <= n; j ++){
            if(matrix[i-1][j-1] == '0'){
                dp[i][j] = 0;
            }else{
                dp[i][j] = 1 + min(dp[i-1][j], min(dp[i][j-1], dp[i-1][j-1]));
            }
            ret = max(ret, dp[i][j]);
        }
    }
    return ret*ret;
    }