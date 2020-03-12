#include<bits/stdc++.h>
using namespace std;

signed main() {
    freopen("in.encoder", "r", stdin);
    
    string message;
    cin >> message;
    cout << "Message: " << message << endl;
    int message_size = message.size();
    int m = 0;
    reverse(message.begin(), message.end());

    while(((1<<m) - 1 - m) < message_size) {
        m++;
    }
    cout << "m = " <<  m << endl;

    int block_size = message_size + m;

    vector<short> b(block_size+1, 0);

    // adding data bits to block
    for (int i = 1, j = 0; i<=block_size and j < message_size; ++i) {
        if (__builtin_popcount(i) != 1) {
            int data = message[j++] - '0';
            b[i] = data;
        }
    }

    // for (int i = 1; i <= block_size ; ++i) {
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

    // for (int i = 0 ; i < m ; ++i) {
    //     cout << "P" << i << ": ";
    //     for (auto it : p[i]) {
    //         cout << it << " ";
    //     }
    // }
    for (int i = 0 ; i < m ; ++i) {
        int par = 0;
        for (auto it : p[i]) {
            par += b[it];
            par %= 2;
        }
        b[1<<i] = par;
    }

    
    cout << "Encoded Data: \n" << endl;
    for (int i = block_size , p = m, d = block_size - m; i >= 1 ; --i) {
        if (__builtin_popcount(i) == 1) {
            ostringstream ss;
            ss << "P" << p--;
            cout << setw(m+1) << ss.str();
        } else {
            ostringstream ss; ss << "D" << d--;
            cout << setw(m+1) << ss.str();
        }
    } cout << endl;

    for (int i = block_size ; i >= 1 ; --i) {
        cout << setw(m+1) << b[i] ;
    } cout << endl;

    for (int i = block_size ; i >= 1 ; --i) {
        cout << setw(m+1) << i ;
    } cout << endl;
    
    cout << "Complete Block: ";
    for (int i = block_size ; i >= 1 ; --i) {
        cout << b[i];
    } cout << endl;
    // put one bit error block code in decoder input file
    ofstream decoder_input_file;
    srand(time(nullptr));
    int error_bit = rand()%block_size + 1;
    // cin >> error_bit; # add input as error bit
    decoder_input_file.open("in.decoder");
    b[error_bit] ^= 1;

    for (int i = block_size ; i >= 1 ; --i) {
        decoder_input_file << b[i];
    }
    cout << "Added block in in.decoder file with error bit at : " << error_bit << endl; 
    decoder_input_file.close();
    
    
    return 0;
}