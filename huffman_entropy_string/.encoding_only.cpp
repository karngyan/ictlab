#include <bits/stdc++.h> 
using namespace std; 

struct MinHeapNode { 

	string data; 

	unsigned long long freq; 

	MinHeapNode *left, *right; 

	MinHeapNode(string data, unsigned freq) { 
		left = right = NULL; 
		this->data = data; 
		this->freq = freq; 
	} 
}; 

struct cmp { 
	bool operator()(MinHeapNode* l, MinHeapNode* r) { 
		return (l->freq > r->freq); 
	} 
}; 

void printCodes(struct MinHeapNode* root, string str) { 
	if (!root) 
		return; 

	if (root->data != "$") 
		cout << root->data << ": " << str << "\n"; 

	printCodes(root->left, str + "0"); 
	printCodes(root->right, str + "1"); 
} 

void HuffmanCodes(vector<string> &data, vector<int> &freq, int size) { 
	struct MinHeapNode *left, *right, *top; 

	priority_queue<MinHeapNode*, vector<MinHeapNode*>, cmp> minHeap; 

	for (int i = 0; i < size; ++i) 
		minHeap.push(new MinHeapNode(data[i], freq[i])); 

	while (minHeap.size() != 1) { 

		left = minHeap.top(); 
		minHeap.pop(); 

		right = minHeap.top(); 
		minHeap.pop(); 

		top = new MinHeapNode("$", left->freq + right->freq); 

		top->left = left; 
		top->right = right; 

		minHeap.push(top); 
	} 

	printCodes(minHeap.top(), ""); 
} 

int main() { 

    
    freopen("in", "r", stdin);
    
    vector<string> data;
    vector<int> freq;
    
    string x; int f;
    int size = 0;

    while(cin >> x >> f) {
        data.push_back(x);
        freq.push_back(f);
        size++;
    }
    
	HuffmanCodes(data, freq, size); 

	return 0; 
}

