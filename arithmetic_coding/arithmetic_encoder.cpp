#include <bits/stdc++.h>

#define endl "\n"
using namespace std;
using ld = long double;

void show_number_line(ld base, vector<pair<char, ld>> &upper_limit) {
  cout << base << " ";
  ld prev = base;
  for (auto it : upper_limit)
  {
    cout << " -- " << it.first << " -- " << it.second;
    prev = it.second;
  }
  cout << endl;
}

signed main()
{
  freopen("in.encoder", "r", stdin);

  string message;
  cin >> message;
  cout << "Message:\n" << message << endl << endl;
  int message_size = message.size();

  vector<pair<char, ld>> upper_limit;
  map<char, ld> prob;
  char c; ld p;
  while (cin >> c >> p) {
    upper_limit.emplace_back(c, p);
    prob[c] = p;
  }

  for (int i = 1 ; i < upper_limit.size() ; ++i) {
    upper_limit[i].second += upper_limit[i-1].second;
  }
  
  cout << "Probabilities:\n";
  for (auto it: upper_limit) {
    cout << it.first << " " << it.second << endl;
  }
  
  cout << "\nEncoding: \n\n";
  int step_counter = 1;
  cout << "Step "<< step_counter << ": \n";

  ld base = 0.0;
  show_number_line(base, upper_limit);

  for (auto c: message) {
    ld new_base;
    ld d;
    for (int i = 0 ; i < upper_limit.size() ; ++i) {
      auto it = upper_limit[i];
      if (it.first == c) {
        new_base = i == 0 ? base : upper_limit[i - 1].second;
        d = it.second - new_base;
      }
    }


    for (int i = 0 ; i < upper_limit.size() ; ++i) {
      ld lower_limit = i == 0 ? new_base : upper_limit[i-1].second;
      upper_limit[i].second = lower_limit + (d * (prob[upper_limit[i].first]));
    } 
    cout << "\nStep: " << ++step_counter << ": \n";
    show_number_line(new_base, upper_limit);
    base = new_base;
  }
  ld ul_code_word = upper_limit.back().second;
  ld ll_code_word = base;

  cout << "\nHence, the arithmetic code word is: \n";
  cout << ll_code_word << " < codeword < " << ul_code_word << endl;

  ld tag = (ul_code_word + ll_code_word) / 2.0;
  cout << "\ntTag = " << tag << endl;


  return 0;
}