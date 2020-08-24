class Solution {
public:
	using Cache = std::vector<int>;

	int maxProfitFixedEndDate(const vector<int>& prices, int start, int end) {
		if (start >= end) return 0;
		int bestBuyPriceSoFar = std::numeric_limits<int>::max();
		for (int i=start;i<=end;++i) {
			bestBuyPriceSoFar = std::min(bestBuyPriceSoFar, prices.at(i));
		}
		return prices.at(end) - bestBuyPriceSoFar;
	}

	int maxProfitHelper(const vector<int>& prices, Cache& cache, int start) {
		if (start >= prices.size()-1) return 0;
		if (cache.at(start) != -1) return cache.at(start);
		int& maxProfit = cache.at(start);
		for (int end=start+1;end<prices.size();++end) {
			maxProfit = std::max(maxProfit, maxProfitFixedEndDate(prices,start,end) + maxProfitHelper(prices, cache, end+1));
		}
		return maxProfit;
	}

	int maxProfit(vector<int>& prices) {
		Cache cache(prices.size(), -1);
		return maxProfitHelper(prices, cache, 0);
	}
};
