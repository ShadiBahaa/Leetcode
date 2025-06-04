class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if(hand.size()%groupSize != 0)return false;
        map<int,int> mp;
        for (int ele : hand){
            mp[ele]++;
        }
        while(true){
            if(mp.size()==0)return true;
            int key = (mp.begin())->first;
            vector<int> v;
            while(v.size() < groupSize){
                if(mp.count(key)&&mp[key]!=0){
                    mp[key]--;
                    if(mp[key]==0){
                        mp.erase(key);
                    }
                    v.push_back(key);
                }else{
                    return false;
                }
                key += 1;
            }
        }
        return true;
    }
};