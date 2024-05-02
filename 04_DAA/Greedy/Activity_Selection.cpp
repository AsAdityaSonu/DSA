#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Activity {
    int start;
    int finish;
    
    Activity(int s, int f) : start(s), finish(f) {}
};

bool cmp(const Activity& a, const Activity& b) {
    return a.finish < b.finish;
}

vector<Activity> select(vector<Activity>& acc) {
    vector<Activity> ans;
    
    sort(acc.begin(), acc.end(), cmp);
    
    ans.push_back(acc[0]);
    
    for (int i = 1; i < acc.size(); ++i) {
        if (acc[i].start >= ans.back().finish) {
            ans.push_back(acc[i]);
        }
    }
    
    return ans;
}

int main() {
    // Example acc
    vector<Activity> acc;
    acc.push_back(Activity(1, 4));
    acc.push_back(Activity(3, 5));
    acc.push_back(Activity(0, 6));
    acc.push_back(Activity(5, 7));
    acc.push_back(Activity(8, 9));
    acc.push_back(Activity(5, 9));
    
    // Select maximum non-overlapping acc
    vector<Activity> selected = select(acc);
    
    // Display selected acc
    cout << "Selected acc:\n";
    for (int i = 0; i < selected.size(); ++i) {
        cout << "Start: " << selected[i].start << ", Finish: " << selected[i].finish << "\n";
    }
    
    return 0;
}
