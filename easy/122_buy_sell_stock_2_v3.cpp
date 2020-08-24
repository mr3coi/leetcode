class Solution {
public:
	int maxProfit(vector<int>& prices) {
		int totalProfit = 0;
		for (int i=1;i<prices.size();++i) {
			if (prices.at(i)>prices.at(i-1)) totalProfit += prices.at(i)-prices.at(i-1);
		}
		return totalProfit;
	}
};
