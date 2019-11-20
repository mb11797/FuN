#include<iostream>
#include<algorithm>
using namespace std;

  bool isvalid(long long int a[], long long int n, long long int k, long long int mid, long long int s);
int main() {

  long long int n;
  cin >> n;
  long long int k;
  cin >> k;
  long long int t;
  cin >> t;
  long long int a[n];
  long long int total = 0;
  long long int i = 0;
  long long int s = 0;
  for (; i < n; i++) {
    cin >> a[i];
    a[i] = a[i] * t;
    total += a[i];
    s = max(s, a[i]);
  }

  long long int e = total;
  long long int small = s;
  sort(a, a + n);
  long long int mid;
  long long int ans;
  while (s <= e) {
    mid = (s + e) / 2;

    if ((isvalid(a, n, k, mid, small))) {
      ans = mid;
      e = mid - 1;
    } else {
      s = mid + 1;
    }
  }

  cout << ans % 10000003<<endl;

  return 0;
}

bool isvalid(long long int a[], long long int n, long long int k, long long int mid, long long int s) {
  long long int current = 0;
  long long int i = 0;

  long long int painter = 1;
  for (; i < n; i++) {
    if (current + a[i] > mid) {
      current = a[i];
      painter++;
      if (painter > k) {
        return false;
      }
    } else {
      current += a[i];
    }
  }
  return true;
}
