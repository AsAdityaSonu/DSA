#include<iostream>
#include<queue>
#include<stack>
using namespace std;

void interleave(queue<int> *q){
    if (q->size() % 2 != 0)
        cout << "Input even number of integers." << endl;
 
    
    stack<int> s;
    int halfSize = q->size() / 2;
 
    // into the stack
    for (int i = 0; i < halfSize; i++) {
        s.push(q->front());
        q->pop();
    }
 
    // enqueue back the stack elements
    while (!s.empty()) {
        q->push(s.top());
        s.pop();
    }
 
    // dequeue the first half elements of queue
    for (int i = 0; i < halfSize; i++) {
        q->push(q->front());
        q->pop();
    }
 

    for (int i = 0; i < halfSize; i++) {
        s.push(q->front());
        q->pop();
    }
 
    while (!s.empty()) {
        q->push(s.top());
        s.pop();
        q->push(q->front());
        q->pop();
    }
}

int main()
{
    int half;
    queue<int> q;
  
    q.push(4);
    q.push(7);
    q.push(11);
    q.push(20);
    q.push(5);
    q.push(9);

    interleave(&q);

    int length = q.size();
	for (int i = 0; i < length; i++) {
		cout << q.front() << " ";
		q.pop();
	}

    return 0;
}