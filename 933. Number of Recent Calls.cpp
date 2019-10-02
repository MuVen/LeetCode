class RecentCounter {
	queue<int> que;
public:
	RecentCounter() {}

	int ping(int t) {
		que.push(t);
		while (que.front() < t - 3000)
			que.pop();
		return que.size();
	}
};