#include <iostream>
#include <queue>
#include <map>
using namespace std;

struct Node {
    char data;
    unsigned freq;
    Node *left, *right;

    Node(char data, unsigned freq, Node* l = NULL, Node* r = NULL)
        : data(data), freq(freq), left(l), right(r) {}
};

struct compare {
    bool operator()(Node* l, Node* r) {
        return (l->freq > r->freq);
    }
};

void printCodes(struct Node* root, string str) {
    if (!root)
        return;

    if (root->data != '$')
        cout << root->data << ": " << str << "\n";

    printCodes(root->left, str + "0");
    printCodes(root->right, str + "1");
}

void HuffmanCodes(char data[], int freq[], int size) {
    struct Node *left, *right, *top;

    priority_queue<Node*, vector<Node*>, compare> minHeap;

    for (int i = 0; i < size; ++i)
        minHeap.push(new Node(data[i], freq[i]));

    while (minHeap.size() != 1) {
        left = minHeap.top();
        minHeap.pop();

        right = minHeap.top();
        minHeap.pop();

        top = new Node('$', left->freq + right->freq, left, right);
        minHeap.push(top);
    }

    printCodes(minHeap.top(), "");
}

int main() {
    char arr[] = { '-', 'E', 'V', 'M', 'P', 'R', 'S', 'I' };
    int freq[] = { 1, 1, 1, 1, 2, 2, 4 ,5 };
    int size = sizeof(arr) / sizeof(arr[0]);
    HuffmanCodes(arr, freq, size);
    return 0;
}