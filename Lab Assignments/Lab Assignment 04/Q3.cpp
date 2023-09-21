#include<iostream>
#include<queue>
#include<stack>
using namespace std;

void interleave(queue<int> *q){
    
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