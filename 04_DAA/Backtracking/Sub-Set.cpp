#include <iostream>
#include <vector>

using namespace std;

void PrintSubsetSum(int i, int n, int set[], int targetSum, vector<int>& subset) {
    if (targetSum == 0) {
        cout << "[ ";
        for (int j = 0; j < subset.size(); j++) {
            cout << subset[j] << " ";
        }
        cout << "]" << endl;
        return;
    }

    if (i == n) {
        return;
    }

    PrintSubsetSum(i + 1, n, set, targetSum, subset);

    if (set[i] <= targetSum) {
        subset.push_back(set[i]);
        PrintSubsetSum(i + 1, n, set, targetSum - set[i], subset);
        subset.pop_back();
    }
}

int main() {
    int set1[] = {1, 2, 1};
    int sum1 = 3;
    int n1 = sizeof(set1) / sizeof(set1[0]);
    vector<int> subset1;
    PrintSubsetSum(0, n1, set1, sum1, subset1);
    cout << endl;

    return 0;
}
