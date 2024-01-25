class Solution {
public:
    
    int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
        int ans = 0;
        vector<int> time;
        for (int i = 0; i<dist.size(); ++i){
            time.push_back(ceil((float)dist[i]/speed[i]));
        }
        sort(time.begin(),time.end());
        for (int i = 0; i<time.size(); ++i){
            if (time[i] <= i){
                break;
            }
            ans++;
        }
        return ans;
    }
};