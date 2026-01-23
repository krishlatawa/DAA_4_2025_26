#include <iostream>
#include<bits/stdc++.h>
using namespace std;
struct Node {
    char ch;
    int freq;
    Node *left, *right;
    Node(char c, int f) {
    ch = c;
    freq = f;
    left = right = nullptr;
    }
};

struct Compare {
    bool operator()(Node* a, Node* b) {
    return a->freq > b->freq;
    }
    
};

void generateCodes(Node* root, string code, unordered_map<char, string> &huffmanCode) {
    if (!root) return;

    if (!root->left && !root->right) {
    huffmanCode[root->ch] = code;
    }
    generateCodes(root->left, code + "0", huffmanCode);
    generateCodes(root->right, code + "1", huffmanCode);
}

string decodeString(Node* root, const string &encoded) {
    string decoded = "";
    Node* curr = root;
    for (char bit : encoded) {
    if (bit == '0') curr = curr->left;
    else curr = curr->right;
    if (!curr->left && !curr->right) {
    decoded += curr->ch;
    curr = root;
        }
    }
    return decoded;
}
int main() {
    string input;
    cout << "Enter input string: ";
    getline(cin, input);
    unordered_map<char, int> freq;
    for (char c : input) {
        freq[c]++;
    }
    
    priority_queue<Node*, vector<Node*>, Compare> pq;
    for (auto &p : freq) {
        pq.push(new Node(p.first, p.second));
    }

    while (pq.size() > 1) {
    Node* left = pq.top(); pq.pop();
    Node* right = pq.top(); pq.pop();
    Node* parent = new Node('\0', left->freq + right->freq);
    parent->left = left;
    parent->right = right;
    pq.push(parent);
    }
    
    Node* root = pq.top();
    unordered_map<char, string> huffmanCode;
    generateCodes(root, "", huffmanCode);

    string encoded = "";
    for (char c : input) {
    encoded += huffmanCode[c];
    }
    cout<<encoded<<endl;
    
    string decoded = decodeString(root, encoded);
    cout << "\nCharacter Frequencies:\n";
    for (auto &p : freq) {
    cout << p.first << " : " << p.second << endl;
    }
    cout << "\nHuffman Codes:\n";
    for (auto &p : huffmanCode) {
    cout << p.first << " : " << p.second << endl;
    }

    cout << "\nOriginal String : " << input << endl;
    cout << "Encoded String : " << encoded << endl;
    cout << "Decoded String : " << decoded << endl;
    return 0;
}