class RandomizedCollection {
public:
    /** Initialize your data structure here. */
    RandomizedCollection() {
        m.clear();
        nums.clear();
    }
    
    /** Inserts a value to the collection. Returns true if the collection did not already contain the specified element. */
    bool insert(int val) {
        m[val].push(nums.size());
        nums.push_back(val);
        return m[val].size()==1;
    }
    
    /** Removes a value from the collection. Returns true if the collection contained the specified element. */
    bool remove(int val) {
        if(m[val].empty())return false;
        int t=m[val].top();
        if(t!=nums.size()-1){
            int b=nums.back();
            swap(nums[t],nums[nums.size()-1]);
            m[b].pop();
            m[b].push(t);
        }
        m[val].pop();
        nums.pop_back();
        return true;
    }
    
    /** Get a random element from the collection. */
    int getRandom() {
        return nums[rand()%(int)nums.size()];
    }
    
private:
unordered_map<int,priority_queue<int>>m;
vector<int>nums;
};

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection obj = new RandomizedCollection();
 * bool param_1 = obj.insert(val);
 * bool param_2 = obj.remove(val);
 * int param_3 = obj.getRandom();
 */
