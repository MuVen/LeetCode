class Solution {
	vector<int> cache;
public:
	vector<int> countBits(int num) {
		cache.resize(num + 1, 0);
        if (num == 0)
			return cache;
		cache[1] = 1;
		for (int i = 2; i <= num; i++){
			int parent = i / 2;	
			int pones = cache[parent];
			cache[i] = (i % 2 == 0) ? pones : pones + 1;
		}
		return cache;
	}
};