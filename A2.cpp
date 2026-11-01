#include <iostream>
#include <queue>
using namespace std;

struct Node {
    char ch;
    int freq;
    Node *left, *right;

    Node(char c, int f) {
        ch = c;
        freq = f;
        left = right = NULL;
    }
};

struct Compare {
    bool operator()(Node* a, Node* b) {
        return a->freq > b->freq;
    }
};

void print(Node* root, string code) {
    if (!root) return;

    if (root->ch != '$')
        cout << root->ch << " : " << code << endl;

    print(root->left, code + "0");
    print(root->right, code + "1");
}

int main() {
    priority_queue<Node*, vector<Node*>, Compare> pq;

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        char ch;
        int freq;
        cin >> ch >> freq;
        pq.push(new Node(ch, freq));
    }

    while (pq.size() > 1) {
        Node* left = pq.top();
        pq.pop();

        Node* right = pq.top();
        pq.pop();

        Node* parent = new Node('$', left->freq + right->freq);
        parent->left = left;
        parent->right = right;

        pq.push(parent);
    }

    print(pq.top(), "");
    return 0;
}