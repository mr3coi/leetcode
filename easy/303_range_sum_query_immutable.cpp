class NumArray {
public:
    NumArray(vector<int>& nums) : copy(nums) {
        copy.insert(copy.begin(), 0);
        for (int i=1; i<copy.size(); ++i)
        {
            copy.at(i) += copy.at(i-1);
        }
    }
    
    int sumRange(int left, int right) {
        return copy.at(right+1) - copy.at(left);
    }

private:
    vector<int> copy;
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */
