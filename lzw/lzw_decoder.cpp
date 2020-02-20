#include<bits/stdc++.h>

using namespace std;

// (decimel, symbol)
map< int, string > dictionary;

void replace(string &s, char a, char b) {
    for (auto &it : s) {
        if (it == a) {
            it = b;
        }
    }
}

void show_dictionary() {

    cout << setw(6) << "Indices" << " " << setw(6) << "Symbol" << endl;
    for (auto it: dictionary) {
        cout << setw(6) << it.second << " " << setw(6) << it.first << endl; 
    }
    cout << endl;
}


string decode(vector<int> &index_seq) {
    string ans = "";
    int n = index_seq.size();
    if (n == 0) 
        return ans;

    string cur_alphabet = "";
    ans = dictionary[index_seq[0]];
    dictionary.insert(make_pair(dictionary.size(), ans + '?'));
    for (int i = 1 ; i < n ; ++i) {
        int index = index_seq[i];
        int dict_size = dictionary.size();

        // index in dictionary
        char first_symbol = dictionary[index][0];

        //update previous entry
        string s = dictionary[dict_size - 1];
        replace(s, '?', first_symbol);
        dictionary[dict_size - 1] = s;

        //add to answer
        ans += dictionary[index];

        //new
        dictionary.insert(make_pair(dict_size, dictionary[index] + "?"));
    }

    return ans;
}

int main() {

    freopen("in.decoder", "r", stdin);

    // vector<int> index_seq = {
    //     3, 1, 2, 5, 4, 7, 1, 5, 5
    // };
    // dictionary = {
    //     {0, "#"},
    //     {1, "a"},
    //     {2, "b"},
    //     {3, "c"}
    // };

    int index_size;
    cin >> index_size;

    vector<int> index_seq(index_size);
    for (int i = 0 ; i < index_size ; ++i) {
        cin >> index_seq[i];
    }

    int dict_size;
    cin >> dict_size;
    for (int i = 0 ;i < dict_size ; ++i) {
        int a;
        string b;
        cin >> a >> b;
        dictionary.insert(make_pair(a, b));
    }

    cout << "Index Sequence: \n";
    for (auto it : index_seq) {
        cout << it << " ";
    } cout << "\n\n";
    cout << "Initial Dictionary: \n";
    show_dictionary();

    string alphabet_string = decode(index_seq);
    cout << "Alphabet String: \n" << alphabet_string << endl; 


// cababcaabcaabab

    return 0;
}