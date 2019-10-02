class Solution {
	unordered_map<int, Employee*> map;
public:
	int getImportance(vector<Employee*> employees, int id) {
		if (employees.size() == 0)
			return 0;

		for (int i = 0; i < employees.size(); i++)    {
			map[employees[i]->id] = employees[i];
		}
		int ans = 0;
		queue<Employee*> que;
		que.push(map[id]);
		while (!que.empty()){
			Employee* enode = que.front(); que.pop();
			ans += enode->importance;
			vector<int> esub = enode->subordinates;
			for (int i = 0; i < esub.size(); i++){
				que.push(map[esub[i]]);
			}
		}

		return ans;
	}
};