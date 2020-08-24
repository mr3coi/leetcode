class MinStack {
	std::stack<long> stack;
	long minVal;
public:
	/** initialize your data structure here. */
	MinStack() { }
	
	void push(int x) {
		long xVal = static_cast<long>(x);
		if (stack.empty()) {
			stack.push(xVal);
			minVal = xVal;
		}
		else {
			if (x < minVal) {
				// Engrave last minVal into this position
				stack.push(xVal + (xVal - minVal));
				minVal = xVal;
			}
			else stack.push(xVal);
		}
	}
	
	void pop() {
		if (stack.top() < minVal) {
			minVal += (minVal - stack.top());
		}
		stack.pop();
	}
	
	int top() {
		long out = stack.top() < minVal ? minVal : stack.top();
		return static_cast<int>(out);
	}
	
	int getMin() {
		return static_cast<int>(minVal);
	}
};
