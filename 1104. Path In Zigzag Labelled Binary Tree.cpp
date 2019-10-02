class Solution {
public:
    vector<int> pathInZigZagTree(int label) {
        vector<int> res;
        int height = log2(label);
        res.push_back(label);
        while(height > 0){
            int left = pow(2, height - 1);
            int right = pow(2,height) - 1;
            label = left + (right - label/2);
            res.push_back(label);
            height--;
        }
        reverse(res.begin(), res.end());
        return res;
    }
};