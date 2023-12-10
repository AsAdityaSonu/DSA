#include <iostream>
#include <queue>
#include <stack>
#include <stdlib.h>
using namespace std;

queue<int> Q;
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


int inDegree(struct node** p, int vertex) {
    int degree = 0;

    for (int i = 0; i < 10; i++) {
        struct node* q = *(p + i);
        while (q != NULL) {
            if (q->data == vertex) {
                degree++;
            }
            q = q->next;
        }
    }

    return degree;
}

int outDegree(struct node** p, int vertex) {
    int degree = 0;

    struct node* q = *(p + vertex - 1);
    while (q != NULL) {
        degree++;
        q = q->next;
    }

    return degree;
}

void adjacentVertices(struct node** p, int vertex) {
    struct node* q = *(p + vertex - 1);

    cout << "Adjacent vertices of vertex " << vertex << ": ";
    while (q != NULL) {
        cout << q->data << " ";
        q = q->next;
    }

    cout << endl;
}

int countEdges(struct node** p) {
    int count = 0;

    for (int i = 0; i < 10; i++) {
        struct node* q = *(p + i);
        while (q != NULL) {
            count++;
            q = q->next;
        }
    }

    return count / 2; // Each edge is counted twice (for both vertices)
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

    cout << "\nIn-degree of vertex 3: " << inDegree(graph, 3) << endl;
    cout << "Out-degree of vertex 3: " << outDegree(graph, 3) << endl;

    adjacentVertices(graph, 3);

    cout << "Number of edges: " << countEdges(graph) << endl;

    return 0;
}
