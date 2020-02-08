#include<bits/stdc++.h>

using namespace std;

// (symbol, decimel)
map< string, int > dictionary;

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
    for (auto it: dictionary) {
        cout << it.first << " " << it.second << endl; 
    }
}

void show_dictionary() {
    for (auto it: dictionary) {
        cout << it.first << " " << it.second << endl; 
    }
    cout << endl;
}

string encode(string &s) {
    string ans = "";
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
        ans += to_string(dictionary[cur_alphabet]);
        cur_alphabet = tmp;
        // show_dictionary();
    }

    return ans;
}

int main() {

    freopen("in", "r", stdin);

    string s;
    cin >> s;
    cout << "Input String: " << endl << s << endl;
    init_dictionary(s);

    string encoded_string = encode(s);
    cout << "Final Dictionary: " << endl; 
    show_dictionary() ;

    cout << "Encoded String: " << endl;
    cout << encoded_string << endl;



    return 0;
}