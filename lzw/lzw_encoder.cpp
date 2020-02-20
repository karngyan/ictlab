#include<bits/stdc++.h>

using namespace std;

// (symbol, decimel)
map< string, int > dictionary;

void show_dictionary() {
    map<int, string> invert_map;
    for (auto it: dictionary)
        invert_map.insert(make_pair(it.second, it.first));

    cout << setw(6) << "Indices" << " " << setw(6) << "Symbol" << endl;
    for (auto it: invert_map) {
        cout << setw(6) << it.first << " " << setw(6) << it.second << endl; 
    }
    cout << endl;
}

void init_dictionary(string &sss) {
    char null = '#';
    char symbol = 'a';
    int decimel = 0;
    string s(1, null);
    set<char> all;
    for (auto it: sss) {
        all.insert(it);
    }
    all.erase(all.find(null));
    int size = all.size();

    dictionary.insert(make_pair(s, decimel));
    for (int i = 0 ; i < size ; ++i) {
        decimel++;
        string ss(1, symbol);
        dictionary.insert(make_pair(ss, decimel));
        symbol++;
    }

    cout << "Initial Dictionary: \n";
    show_dictionary();
}


vector<int> encode(string &s) {
    vector<int> ans;
    int n = s.size();
    if (n == 0) return ans;

    string cur_alphabet(1, s[0]);
    for(int i = 1 ; i < n ; ++i) {
        cur_alphabet += s[i];
        if (dictionary.find(cur_alphabet) != dictionary.end())
            continue;
        int dict_size = dictionary.size();
        dictionary.insert(make_pair(cur_alphabet, dict_size));
        string tmp(1, s[i]);
        cur_alphabet.pop_back();
        ans.push_back(dictionary[cur_alphabet]);
        cur_alphabet = tmp; 
        // show_dictionary();
    }

    return ans;
}

int main() {

    freopen("in.encoder", "r", stdin);

    string s;
    cin >> s;
    
    cout << "Input String: " << endl << s << "\n\n";
    init_dictionary(s);

    vector<int> index_seq = encode(s);
    cout << "Final Dictionary: " << endl; 
    show_dictionary() ;

    cout << "Index Sequence: " << endl;
    cout << "Length: " << index_seq.size() << endl;
    for (auto it: index_seq) {
        cout << it << " ";
    }



    return 0;
}