#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
  vector<int> deckRevealedIncreasing(vector<int>& deck) {
    int n = deck.size();
    sort(deck.begin(), deck.end());
    
    
    queue<int> indices;
    for (int i = 0; i < n; ++i) {
      indices.push(i);
    }

    vector<int> result(n);
    for (int card : deck) {
      int revealedIndex = indices.front();
      indices.pop();

      result[revealedIndex] = card;

      if (!indices.empty()) {
        indices.push(indices.front());
        indices.pop();
      }
    }

    return result;
  }
};


int main()
{
    
    return 0;
}