struct Log{
	int id;
	string status;
	int timestamp;
};

class Solution {
public:
	vector<int> exclusiveTime(int n, vector<string>& logs) {
		vector<int> times(n, 0);
		stack<Log> st;
		for (string log : logs){
			stringstream ss(log);
			string temp1, temp2, temp3;
			getline(ss, temp1, ':');
			getline(ss, temp2, ':');
			getline(ss, temp3, ':');
			Log item = { stoi(temp1), temp2, stoi(temp3) };
			if (item.status == "start"){
				st.push(item);
			}
			else{
				int time_added = item.timestamp - st.top().timestamp + 1;
				times[item.id] += time_added;
				st.pop();
				if (!st.empty()){
					times[st.top().id] -= time_added;
				}
			}
		}

		return times;
	}
};