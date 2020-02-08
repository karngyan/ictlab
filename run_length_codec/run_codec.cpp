#include<bits/stdc++.h>
using namespace std;
map< string, char > all_char;

string decode(string &s) {
    string ans = "";
    int n = s.size();
    if (n == 0)
        return ans;
    string cur(s.begin(), s.begin() + 1);
    for (int i = 1 ; i < n ; ++i) {
        if (all_char.find(cur) != all_char.end()) {
            ans += all_char[cur];
            cur = s[i];
        } else {
            cur += s[i];
        }
    }
    if (all_char.find(cur) != all_char.end())
            ans += all_char[cur];
    return ans;
}

string compress(string &s) {
    string ans = "";
    int n = s.size();
    if (n == 0) return ans;
    int cnt = 1;
    char cur_char = s[0];
    int i = 1;
    while(i < n) {
        if (s[i] == cur_char) {
            cnt++;
        } else {
            ans += cur_char;
            ans += char(cnt + '0');
            cnt = 1;
            cur_char = s[i];
        }
        i++;
    }
    ans += cur_char;
    ans += char(cnt + '0');
    return ans;
}

string encode(string &s) {
    string ans = "";
    int n = s.size();

    map<char, string> reverse_all_char;
    for (auto it : all_char) {
        reverse_all_char.insert(make_pair(it.second, it.first));
    }

    for (int i = 0 ; i < n-1 ; ++i) {
        char c = s[i];
        int cnt = s[i+1] - '0';
        while(cnt--) {
            ans += reverse_all_char[c];
        }
    }
    return ans;
}

signed main() {

    freopen("in", "r", stdin);

    int n;
    cin >> n;
    for (int i = 0 ; i < n ; ++i) {
        string bin; char val;
        cin >> val >> bin;
        cout << val << " " << bin << endl;
        all_char.insert(make_pair(bin, val));
    }

    string input_string;
    cin >> input_string;
    cout << "Encoded String: " << input_string << endl;

    string char_string = decode(input_string);
    cout << "Full String: " << char_string << endl;

    string compressed_char_string = compress(char_string);
    cout << "Compressed String: " << compressed_char_string << endl;

    string encoded_string = encode(compressed_char_string);
    cout << "Encoded String(from compressed string): " << encoded_string << endl;


    return 0;
}
