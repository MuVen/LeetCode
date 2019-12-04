class Solution {
public:
	bool isValid(string s) {
		char stack[10000] = { 0 };
		int top = -1;

		char ch;
		for (int i = 0; s[i] != '\0'; i++){
			switch (s[i]){
			case '(':stack[++top] = '('; break;
			case ')':
				if (top == -1)return false;
				ch = stack[top--];
				if (ch != '(') return false;
				break;

			case '{':stack[++top] = '{'; break;
			case '}':
				if (top == -1)return false;
				ch = stack[top--];
				if (ch != '{') return false;
				break;

			case '[':stack[++top] = '['; break;
			case ']':
				if (top == -1)return false;
				ch = stack[top--];
				if (ch != '[') return false;
				break;
			}
		}

		return top == -1;
	}
};


/*
class Solution {
	unordered_map<char, char> map;
    stack<char> sta;
public:    
    bool isValid(string s) {
        map[')']='(';
        map['}']='{';
        map[']']='[';
        for(int i = 0; s[i] != '\0'; i++){
            if(map.find(s[i]) == map.end()){
                sta.push(s[i]);
            }else{
                if(sta.empty() || sta.top() != map[s[i]])
                    return false;
                sta.pop();
            }
        }
        
        return sta.empty() == true;
    }
};
*/