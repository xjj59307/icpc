/*
ID: xjj_hdl1
PROG: humble
LANG: C++
*/

#include <fstream>
#include <iostream>
#include <queue>
#include <vector>
#include <set>
#include <functional>
#include <limits>
using namespace std;

int main() {
  ofstream fout("humble.out");
  ifstream fin("humble.in");

  int k;
  int n;
  int primes[105];
  priority_queue<int, vector<int>, greater<int> > queue;
  set<int> product_set;

  fin >> k >> n;
  for (int i = 0; i < k; ++i) {
    fin >> primes[i];
    queue.push(primes[i]);
  }

  int max = -1;
  int count = 1;

  while (true) {
    // get the minimum element
    int base = queue.top();
    queue.pop();
    // cout << "the current base is " << base << endl;

    if (count++ == n) {
      fout << base << endl; 
      break;
    }

    for (int i = 0; i < k; ++i) {
      if ((long long)base * primes[i] > numeric_limits<int>::max()) continue;

      int product = base * primes[i];

      if (queue.size() < n && product > max)
        max = product;

      if (product_set.find(product) == product_set.end() &&
          (product < max || queue.size() < n)) {
        queue.push(product);
        product_set.insert(product);
        // cout << product << " being pushed" << endl;
      }
    }
  }

  return 0;
}
