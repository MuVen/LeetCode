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