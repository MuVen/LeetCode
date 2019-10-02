#define MAX 10000
typedef long long int lli;

class Solution {
	lli mystack[MAX];
	int top;
public:
	Solution(){ top = -1; }
	int calPoints(vector<string>& ops) {
		lli score = 0;
		for (int i = 0; i < ops.size(); i++){
			string s = ops[i];
			if (s == "C"){
				lli lastRoundScore = mystack[top--];
				score -= lastRoundScore;
			}
			else if (s == "D"){
				lli thisRoundScore = mystack[top] * 2;
				mystack[++top] = thisRoundScore;
				score += thisRoundScore;
			}
			else if (s == "+"){
				lli thisRoundScore = mystack[top] + mystack[top - 1];
				mystack[++top] = thisRoundScore;
				score += thisRoundScore;
			}
			else{
				lli thisRoundScore = atoi(s.c_str());
				score += thisRoundScore;
				mystack[++top] = thisRoundScore;
			}
		}

		return score;
	}
};