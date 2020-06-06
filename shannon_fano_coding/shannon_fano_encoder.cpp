#include <bits/stdc++.h>
using namespace std;
using ld = long double;

struct node {
  string symbol;
  ld pro;
  int arr[20];
  int top;
} p[20];


void shannon(int l, int h, node p[]) {

  ld pack1 = 0, pack2 = 0, diff1 = 0, diff2 = 0;
  int i, d, k, j;

  if ((l + 1) == h || l == h || l > h) {
    
    if (l == h || l > h)
      return;

    p[h].arr[++(p[h].top)] = 0;
    p[l].arr[++(p[l].top)] = 1;
    
    return;
  
  } else {
  
    for (i = l; i <= h - 1; i++)
      pack1 = pack1 + p[i].pro;
  
    pack2 = pack2 + p[h].pro;
    diff1 = pack1 - pack2;
  
    if (diff1 < 0)
      diff1 = diff1 * -1;
    
    j = 2;

    while (j != h - l + 1) {
      k = h - j;
      pack1 = pack2 = 0;
      for (i = l; i <= k; i++)
        pack1 = pack1 + p[i].pro;
      for (i = h; i > k; i--)
        pack2 = pack2 + p[i].pro;
      diff2 = pack1 - pack2;
      if (diff2 < 0)
        diff2 = diff2 * -1;
      if (diff2 >= diff1)
        break;
      diff1 = diff2;
      j++;
    }
    
    k++;
    
    for (i = l; i <= k; i++)
      p[i].arr[++(p[i].top)] = 1;
    
    for (i = k + 1; i <= h; i++)
      p[i].arr[++(p[i].top)] = 0;

    shannon(l, k, p);
    shannon(k + 1, h, p);
  }
}

void sort_by_prob(int n, node p[]) {
  int i, j;
  node temp;
  for (j = 1; j <= n - 1; j++) {
    for (i = 0; i < n - 1; i++) {
      if ((p[i].pro) > (p[i + 1].pro)) {
        temp.pro = p[i].pro;
        temp.symbol = p[i].symbol;

        p[i].pro = p[i + 1].pro;
        p[i].symbol = p[i + 1].symbol;

        p[i + 1].pro = temp.pro;
        p[i + 1].symbol = temp.symbol;
      }
    }
  }
}

void display(int n, node p[]) {
  int i, j;
  cout << "Symbol\tProbability\tCode";
  for (i = n - 1; i >= 0; i--) {
    cout << "\n" << p[i].symbol << "\t" << p[i].pro << "\t\t";
    for (j = 0; j <= p[i].top; j++)
      cout << p[i].arr[j];
  }
}

signed main() {
  int n, i, j;
  ld total = 0;
  string ch;
  node temp;

  freopen("in.encoder", "r", stdin);

  cin >> n;

  ld x[n];
  for (i = 0; i < n; i++) {
    char ch;
    cin >> ch >> x[i];
    p[i].symbol += ch;
  }

  for (i = 0; i < n; i++) {
    p[i].pro = x[i];
    total = total + p[i].pro;
  }

  p[i].pro = 1 - total;

  sort_by_prob(n, p);

  for (i = 0; i < n; i++)
    p[i].top = -1;

  shannon(0, n - 1, p);

  display(n, p);

  return 0;
}
