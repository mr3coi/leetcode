class MinStack {
	std::stack<int> minHistory;
	std::vector<int> mainStack;
	int minVal{std::numeric_limits<int>::max()};
	int topIdx{-1};
public:
	/** initialize your data structure here. */
	MinStack() : mainStack(10,0) { }
	
	void push(int x) {
		if (topIdx == mainStack.size()) mainStack.resize(mainStack.size() * 2);
		mainStack.at(++topIdx) = x;
		if (x < minVal) {
			minHistory.push(topIdx);
			minVal = x;
		}
	}
	
	void pop() {
		if (topIdx == minHistory.top()) {
			minHistory.pop();
			minVal = minHistory.empty() ? std::numeric_limits<int>::max() : mainStack.at(minHistory.top());
		}
		--topIdx;
	}
	
	int top() {
		return mainStack.at(topIdx);
	}
	
	int getMin() {
		return minVal;
	}
};
