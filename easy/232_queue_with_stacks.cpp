class MyQueue {
	std::stack<int> storage;
	int top;
public:
	/** Initialize your data structure here. */
	MyQueue() {
		
	}
	
	/** Push element x to the back of queue. */
	void push(int x) {
		if (storage.empty()) top = x;
		storage.push(x);
	}
	
	/** Removes the element from in front of queue and returns that element. */
	int pop() {
		std::stack<int> backup;
		int out = top;
		size_t nbItems = storage.size();
		for (int i=0; i<nbItems-1; ++i) {
			backup.push(storage.top());
			storage.pop();
		}
		storage.pop();
		if (backup.size()) {
			top = backup.top();
			nbItems = backup.size();
			for (int i=0; i<nbItems; ++i) {
				storage.push(backup.top());
				backup.pop();
			}
		}
		return out;
	}
	
	/** Get the front element. */
	int peek() {
		return top;
	}
	
	/** Returns whether the queue is empty. */
	bool empty() {
		return storage.empty();
	}
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
