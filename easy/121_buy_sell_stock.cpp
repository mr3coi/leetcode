class Solution {
public:
	int maxProfit(vector<int>& prices) {
		int bestMargin = 0;
		int bestBuyPriceSoFar = std::numeric_limits<int>::max();
		for (int i=0;i<prices.size();++i) {
			bestBuyPriceSoFar = std::min(bestBuyPriceSoFar, prices.at(i));
			bestMargin = std::max(bestMargin, prices.at(i) - bestBuyPriceSoFar);
		}
		return bestMargin;
	}
};
