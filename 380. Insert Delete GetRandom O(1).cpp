class RandomizedSet {
	unordered_map<int, int> map;
public:
	/** Initialize your data structure here. */
	RandomizedSet() {
		map.clear();
	}

	/** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
	bool insert(int val) {
		if (map.find(val) != map.end())
			return false;
		map[val] = val;
		return true;
	}

	/** Removes a value from the set. Returns true if the set contained the specified element. */
	bool remove(int val) {
		if (map.find(val) == map.end())
			return false;
		map.erase(val);
		return true;
	}

	/** Get a random element from the set. */
	int getRandom() {
		int bucket = 0, bucket_size = 0;
		do{
			bucket = rand() % map.bucket_count();
		} while ((bucket_size = map.bucket_size(bucket)) == 0);
		return next(map.begin(bucket), rand() % bucket_size)->first;
	}
};