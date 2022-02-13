class Solution {
public:
    vector<int> constructRectangle(int area) {
        int sqrt{1};
        while (sqrt * sqrt < area)
        {
            ++sqrt;
        }
        if (sqrt * sqrt == area)
        {
            return {sqrt, sqrt};
        }
        int val=sqrt-1;
        for (; val >= 1; --val)
        {
            if (area % val == 0)
            {
                break;
            }
        }
        return {area / val, val};
    }
};
