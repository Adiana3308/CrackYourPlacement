class Solution {
public:
    bool canCross(vector<int>& stones) {
        map<int,set<int>> mp;
        mp[0].insert(1);
        for(int i = 0;i<stones.size();i++){
            for(int jump : mp[stones[i]]){
                int pos = jump + stones[i];
                if(pos==stones[stones.size()-1]) return true;
               if(jump-1>0) mp[pos].insert(jump - 1);
               mp[pos].insert(jump);
               mp[pos].insert(jump + 1);
            }
        }
        return false;
    }
};
