class MyQueue {
    stack<int> input, output;

public:
    MyQueue() {
        // Constructor
    }
    void push(int x) {
        input.push(x);
    }

    int pop() {
        if (output.empty()) {
            while (!input.empty()) {
                output.push(input.top());
                input.pop();
            }
        }

        if (output.empty()) {
            cout << "Queue is empty" << endl;
            exit(0);
        }

        int val = output.top();
        output.pop();
        return val;
    }

    int peek() {
        if (output.empty()) {
            while (!input.empty()) {
                output.push(input.top());
                input.pop();
            }
        }

        if (output.empty()) {
            cout << "Queue is empty" << endl;
            exit(0);
        }

        return output.top();
    }
    bool empty() {
        return input.empty() && output.empty();
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