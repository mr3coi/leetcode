/**
 * Idea: keep most recent value separate, keep rest in queue.
 * When popping, push all elements in queue except last back into queue
 * and retrieve last element which will be the new top after popping.
 */
class MyStack {
	int topVal;
	size_t size{0};
	std::queue<int> restQ;
public:
	/** Initialize your data structure here. */
	MyStack() {
		
	}
	
	/** Push element x onto stack. */
	void push(int x) {
		if (size) {
			restQ.push(topVal);
		}
		topVal = x;
		++size;
	}
	
	/** Removes the element on top of the stack and returns that element. */
	int pop() {
		int popVal = topVal;
		if (size > 1) {
			for (int i=0; i<restQ.size()-1; ++i) {
				restQ.push(restQ.front());
				restQ.pop();
			}
			topVal = restQ.front();
			restQ.pop();
		}
		--size;
		return popVal;
	}
	
	/** Get the top element. */
	int top() {
		return topVal;
	}
	
	/** Returns whether the stack is empty. */
	bool empty() {
		return !size;
	}
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
