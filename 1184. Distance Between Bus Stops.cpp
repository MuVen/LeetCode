class Solution {
public:
    int distanceBetweenBusStops(vector<int>& distance, int start, int destination) {
        if(destination < start) swap(start, destination);

        int dist1 = 0, dist2 = 0;
        for(int i = 0; i < distance.size(); i++){
            if(i >= start && i < destination)
                dist1 += distance[i];
            else
                dist2 += distance[i];
        }
        
        return min(dist1, dist2);
    }
};