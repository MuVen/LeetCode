struct idlink{
	int id;
	int counter;
	idlink* next;
	idlink* prev;
};
idlink idlinknodes[1000];

struct idlinkfl{
	idlink* first;
	idlink* last;
};

class Twitter {
	unordered_map<int, vector<pair<int, int>>> map;
	unordered_map<int, vector<int>> ufollow;
	vector<int> result;
	idlinkfl mpfl;
	int pindex;
	int twitterCounter;
public:
	/** Initialize your data structure here. */
	Twitter() {
		map.clear();
		twitterCounter = 1;
	}

	/** Compose a new tweet. */
	void postTweet(int userId, int tweetId) {
		map[userId].push_back({ tweetId, twitterCounter++ });
	}

	idlink* getIDNode(int id, int counter){
		idlink* temp = &idlinknodes[pindex++];
		temp->id = id;
		temp->counter = counter;
		temp->next = temp->prev = nullptr;
		return temp;
	}

	void initNewsFeed(){
		result.clear();
		pindex = 0;
		mpfl.first = mpfl.last = nullptr;
	}
	
	void insertionSort(int id, int tcounter){
		if (mpfl.first == nullptr && mpfl.last == nullptr){
			mpfl.first = mpfl.last = getIDNode(id, tcounter);
			return;
		}

		idlink* temp = mpfl.first;
		idlink* mptemp = getIDNode(id, tcounter);
		int count = 0;
		while (temp){
			if (mptemp->counter > temp->counter){
				if (temp == mpfl.first){
					temp->prev = mptemp;
					mptemp->next = temp;
					mpfl.first = mptemp;
				}
				else {
					temp->prev->next = mptemp;
					mptemp->prev = temp->prev;
					mptemp->next = temp;
					temp->prev = mptemp;
				}
				return;
			}
			temp = temp->next;
			count++;
			if (count == 10)
				break;
		}

		if (count < 10 && temp == nullptr){
			mpfl.last->next = mptemp;
			mptemp->prev = mpfl.last;
			mpfl.last = mptemp;
		}
	}

	/** Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent. */
	vector<int> getNewsFeed(int userId) {
		initNewsFeed();
		{
			auto tweets = map[userId];
			for (int i = 0; i < tweets.size(); i++){
				//cout << userId << " " << tweets[i]<<endl;
				insertionSort(tweets[i].first, tweets[i].second);
			}
		}

		if (map.find(userId) != map.end()){
			auto vec = ufollow[userId];
			for (int i = 0; i < vec.size(); i++){
				int follwingUId = vec[i];
				if (map.find(follwingUId) != map.end()){
					auto tweets = map[follwingUId];
					for (int i = 0; i < tweets.size(); i++){
						//cout << follwingUId << " " << tweets[i] << endl;
						insertionSort(tweets[i].first, tweets[i].second);
					}
				}
			}
		}

		idlink* temp = mpfl.first;
		while (temp){
			result.push_back(temp->id);
			if (result.size() == 10)
				break;
			temp = temp->next;
		}
		return move(result);
	}

	/** Follower follows a followee. If the operation is invalid, it should be a no-op. */
	void follow(int followerId, int followeeId) {
		if (followerId == followeeId)
			return;

		auto &vec = ufollow[followerId];
		auto it = find(vec.begin(), vec.end(), followeeId);
		if (it == vec.end())
			ufollow[followerId].push_back(followeeId);
	}

	/** Follower unfollows a followee. If the operation is invalid, it should be a no-op. */
	void unfollow(int followerId, int followeeId) {
		if (followerId == followeeId)
			return;

		auto& vec = ufollow[followerId];
		auto it = find(vec.begin(), vec.end(), followeeId);
		if (it != vec.end())
			vec.erase(it);
	}
};