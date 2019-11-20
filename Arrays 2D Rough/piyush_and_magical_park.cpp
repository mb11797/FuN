#include<iostream>
using namespace std;

int main() {
  int r, c, s, k;
  cin >> r >> c >> k >> s;
  char a[100][100];
  for (int i = 0; i < r; i++) {
    for (int j = 0; j < c; j++) {
      cin >> a[i][j];
    }
  }
  for (int i = 0; i < r; i++) {
    for (int j = 0; j < c; j++) {
      if (s >= 0) {
        if (a[i][j] == '.') {
          s = s - 2;
        } if (a[i][j] == '*') {
          s = s + 5;
        } if (a[i][j] == '#') {
          break;
        } if (j<c-1) {
          s--;
        }
      }
    }
  }

  if (s >= k) {
    cout << "Yes" << endl << s;
  } else {
    cout << "No";
  }

  return 0;
}
