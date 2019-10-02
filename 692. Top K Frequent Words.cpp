class Solution {
	vector<string> wor;
	vector<int> freq;
	unordered_map<string, int> map;
public:
	inline void myswap(int a, int b){
		int temp = freq[a];
		freq[a] = freq[b];
		freq[b] = temp;

		string temps = wor[a];
		wor[a] = wor[b];
		wor[b] = temps;
	}

	int partition(int left, int right){
		int pivot = freq[right];
		int sIndex = left;
		for (int i = left; i < right; i++){
			if (freq[i] > pivot){
				myswap(i, sIndex);
				sIndex++;
			}
			else if (freq[i] == pivot){
				if (wor[i].compare(wor[right]) < 0){
					myswap(i, sIndex);
					sIndex++;
				}
			}
		}

		myswap(sIndex, right);
		return sIndex;
	}

	void qsort(int left, int right){
		if (left < right){
			int wall = partition(left, right);
			qsort(left, wall - 1);
			qsort(wall + 1, right);
		}
	}

	vector<string> topKFrequent(vector<string>& words, int k) {
		for (int i = 0; i < words.size(); i++)
			map[words[i]]++;
		for (auto it = map.begin(); it != map.end(); ++it){
			wor.push_back(it->first);
			freq.push_back(it->second);
		}
		qsort(0, freq.size() - 1);
		vector<string> result;
		result.resize(k);
		for (int i = 0; i < k; i++) {
			result[i] = move(wor[i]);
		}
		return move(result);
	}
};