#include<bits/stdc++.h>
using namespace std;

signed main() {
    freopen("in.decoder", "r", stdin);
    
    string block_string;
    cin >> block_string;
    cout << "Recieved Block: " << block_string << endl;
    reverse(block_string.begin(), block_string.end());
    int block_size = block_string.size();
    int m = 0;

    while((1<<m - 1) <  block_size) {
        m++;
    }
    m--;
    cout << m << endl;

    int message_size = block_size - m;
    string correct_message = "";

    vector<short> b(block_size+1, 0);

    // adding data and received parity bits to block
    for (int i = 1; i<=block_size; ++i) {
        b[i] = block_string[i-1] - '0';
    }
    // for  (int i = 1; i <= block_size ; ++i) {
    //     cout << b[i] << " ";
    // }


    // generate parity bits
    vector< vector<int> > p(m, vector<int>());

    for (int i = 1 ; i <= block_size; ++i) {
        for (int j = 0; j < m ; ++j) {
            if ((i>>j) & 1) {
                p[j].push_back(i);
            }
        }
    }

    int error_bit = 0;
    for (int i = 0 ; i < m ; ++i) {
        int par = 0;
        for (auto it : p[i]) {
            par += b[it];
            par %= 2;
        }
        // check correctness
        if (par != 0) {
            // cout << "error " << i << endl;
            error_bit = error_bit | (1<<i);
        }
    }

    if (error_bit > 0) {
        b[error_bit] ^= 1;
    }

    cout << "Error Bit: " << error_bit << endl;
    for (int i = block_size; i > 0 ; --i) {
        if (__builtin_popcount(i) != 1) {
            correct_message += (char) b[i] + '0';
        }
    } 

    cout << "Corrected Message: " << correct_message;


    return 0;
}