class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        unordered_map<string,int> um1;
        unordered_map<string,int> um2;
        int mini = 1e9;
        for(int i = 0; i<list1.size(); ++i){
            um1[list1[i]] = i;
        }
        for(int i = 0; i<list2.size(); ++i){
            um2[list2[i]] = i;
        }
        vector<string> rm;
        for(auto ele : um1){
            if(um2.count(ele.first)){
                um1[ele.first] += um2[ele.first];
                mini = min(mini,um1[ele.first]);
            }else{
                rm.push_back(ele.first);
            }
        }
        for (string str : rm){
            um1.erase(str);
        }
        vector<string> v;
        for(auto ele : um1){
            if(um1[ele.first] == mini){
                v.push_back(ele.first);
            }
        }
        return v;
    }
};