#include <iostream>
#include <vector>

using namespace std;

void combinations(vector<int>& nums, int start, int k, vector<int>& current, vector<vector<int>>& result) {
    if (current.size() == k) {
        result.push_back(current);
        return;
    }
    
    for (int i = start; i <= nums.size() - (k - current.size()); i++) {
        current.push_back(nums[i]);
        combinations(nums, i + 1, k, current, result);
        current.pop_back();
    }
}

vector<vector<int>> getCombinations(vector<int>& nums, int k) {
    vector<vector<int>> result;
    vector<int> current;
    combinations(nums, 0, k, current, result);
    return result;
}

int main() {
    int n, l, k;
    cin >> n >> l >> k;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a.at(i);
    }

    auto result = getCombinations(a, k);
    
    int score = 0;
    for (auto combo : result) {
        combo.insert(combo.begin(), 0);
        combo.push_back(l);
        
        int minLength = l;
        for (int i = 1; i < combo.size(); i++) {
            minLength = min(minLength, combo[i] - combo[i-1]);
        }
        score = max(score, minLength);
    }

     cout << score << endl;

    return 0;
}

