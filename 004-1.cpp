#include <iostream>
#include <vector>
# include<algorithm>
# include<array>
using namespace std;

bool canMake(vector<int>& cuts, int l, int k, int minLen) {
    int last = 0, cnt = 0;
    for (int cut : cuts) {
        if (cut - last >= minLen) {
            cnt++;
            last = cut;
        }
    }
    if (l - last >= minLen) cnt++;
    return cnt >= k + 1;
}

int solve(vector<int>& cuts, int l, int k) {
    sort(cuts.begin(), cuts.end());
    int left = 1, right = l+1;
    while (left < right) {
        int mid = (left + right) / 2;
        if (canMake(cuts, l, k, mid)) {
            left = mid + 1;
        } else {
            right = mid;
        }
    }
    return left - 1;
}

int main() {
    int n, l, k;
    cin >> n >> l >> k;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a.at(i);
    }

    auto score = solve(a, l, k);

     cout << score << endl;

    return 0;
}

