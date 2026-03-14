class Solution {
public:
	void helper(string temp,vector<string> &ans,int i,int n,char pre)  {
		if(i==n)
		{
			ans.push_back(temp);
			return;
		}
		for(char j='a';j<='c';j++)
		{
			if(j==pre)
				continue;
			temp[i]=j;
			helper(temp,ans,i+1,n,j);
		}
		return;
	}
    string getHappyString(int n, int k) {
    	string temp;
    	temp.resize(n);
    	vector<string> ans;
    	helper(temp,ans,0,n,'*');
    	if(ans.size()<k)
    		return "";
    	else
    	return ans[k-1];
    }
};