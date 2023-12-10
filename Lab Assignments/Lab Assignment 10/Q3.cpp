// DFS
#include <iostream>
#include <stack>
#include <stdlib.h>
using namespace std;

stack<int> S;


struct node {
    int data;
    struct node* next;
};

void addEdge(struct node** root, int i, int j) {
    // Avoid adding self-loop edges
    if (i == j) {
        cout << "Self-loop edges are not allowed!" << endl;
        return;
    }

    // edge i->j
    struct node*& q = *(root + i - 1);
    struct node* r = new node;
    r->data = j;
    r->next = NULL;

    if (q == NULL) {
        q = r;
    } else {
        r->next = q->next;
        q->next = r;
    }

    // edge j->i
    struct node*& q1 = *(root + j - 1);
    struct node* r1 = new node;
    r1->data = i;
    r1->next = NULL;
    if (q1 == NULL) {
        q1 = r1;
    } else {
        r1->next = q1->next;
        q1->next = r1;
    }
}

void BFS(struct node** p, int visited[], int num) {
    S.push(num);
    visited[num - 1] = 1;

    while (!S.empty()) {
        int d = S.top();
        S.pop();
        cout << d << " ";

        struct node* q = *(p + d - 1);
        while (q != NULL) {
            if (!visited[q->data - 1]) {
                S.push(q->data);
                visited[q->data - 1] = 1;
            }
            q = q->next;
        }
    }
}



int main() {
    struct node* graph[10];
    int visited[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    for (int i = 0; i < 10; i++) {
        graph[i] = NULL;
    }

    addEdge(graph, 1, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 1, 4);
    addEdge(graph, 2, 3);
    addEdge(graph, 2, 5);
    addEdge(graph, 3, 6);
    addEdge(graph, 4, 7);
    addEdge(graph, 5, 8);
    addEdge(graph, 6, 9);
    addEdge(graph, 7, 8);
    addEdge(graph, 8, 9);

    BFS(graph, visited, 1);

    return 0;
}
