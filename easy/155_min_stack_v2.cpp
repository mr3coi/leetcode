class MinStack {
	std::stack<int> minHistory;
	std::stack<int> mainStack;
	int minVal{std::numeric_limits<int>::max()};
public:
	/** initialize your data structure here. */
	MinStack() { }
	
	void push(int x) {
		mainStack.push(x);
		if (minHistory.empty() or x <= minHistory.top()) {
			minHistory.push(x);
		}
	}
	
	void pop() {
		if (mainStack.top() == minHistory.top()) minHistory.pop();
		mainStack.pop();
	}
	
	int top() {
		return mainStack.top();
	}
	
	int getMin() {
		return minHistory.top();
	}
};
