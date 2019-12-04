class Solution {
    vector<string> ans;
public:
	/*
		open - close braces.
		return condition is if the string length is 2 x n.
		if open < n add open braces
		you can add close braces only if close < open which mean there is open braces in the string
		if close < open add close braces.
	*/
    void generateParenthesisUtil(string tans, int open,int close,int n){
        if(tans.length() == n*2){
            ans.push_back(tans);
            return;
        }
        
        if(open < n)
            generateParenthesisUtil(tans+"(", open+1, close, n);
        if(close < open)
            generateParenthesisUtil(tans+")", open, close+1, n);
    }

    vector<string> generateParenthesis(int n) {
        generateParenthesisUtil("",0,0,n);
        return move(ans);
    }
};