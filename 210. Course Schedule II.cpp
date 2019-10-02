class Solution {
	vector<vector<int>> grid;
	vector<bool> fvisited;
	vector<bool> recstack;
	stack<int> s;
	int nvertices;
	bool hascycle;
public:
	void dfs(int src){
		if (fvisited[src])
			return;
		if (hascycle)
			return;

		fvisited[src] = true;
		recstack[src] = true;
		for (int i = 0; i < nvertices; i++){
			if (fvisited[i] == true && grid[src][i] == 1 && recstack[i] == true){
				hascycle = true;
				return;
			}
			if (fvisited[i] == false && grid[src][i] == 1){
				dfs(i);
				if (hascycle)
					return;
			}
		}

		recstack[src] = false;
		s.push(src);
	}

	vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
		nvertices = numCourses;
		grid.resize(numCourses, vector<int>(numCourses, 0));
		for (int i = 0; i < prerequisites.size(); i++){
			int a = prerequisites[i][0];
			int b = prerequisites[i][1];
			grid[a][b] = 1;
		}

		fvisited.resize(numCourses, false);
		recstack.resize(numCourses, false);

		for (int i = 0; i < numCourses; i++){
			if (fvisited[i] == false){
				hascycle = false;
				dfs(i);
				if (hascycle)
					return vector<int>{};
			}
		}

		vector<int> result;
		int rindex = numCourses-1;
		result.resize(numCourses, 0);
		while (s.empty() == false){
			result[rindex--] = s.top();
			s.pop();
		}

		return result;
	}
};