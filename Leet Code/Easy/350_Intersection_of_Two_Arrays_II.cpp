#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;

// Approach 1: Two pointer
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());

        int i=0, j=0;
        
        while(i<nums1.size() && j<nums2.size()){
            if(nums1[i]<nums2[j]){
                i++;
            }else if(nums1[i]>nums2[j]){
                j++;
            }else{
                ans.push_back(nums1[i]);
                i++;
                j++;
            }
        }

        return ans;
    }
};

// Approach 2: Beats 6.27%
class Solution {
public:
    vector<int> intersect(vector<int>& a, vector<int>& b) {
        vector<int> ans;
        int allowed = 10;
        int max_ele = 1001;
        for(int j=0;j<max_ele;j+=allowed){
            map<int,int> freq;
            for(int i=0;i<a.size();i++){
                if(a[i]>=j && a[i]<j+allowed){
                    freq[a[i]]++;
                }
            }

            for(int i=0;i<b.size();i++){
                if(b[i]>=j && b[i]<j+allowed){
                    if(freq[b[i]]>0){
                        ans.push_back(b[i]);
                        freq[b[i]]--;
                    }
                }
            }
        }

        return ans;
    }
};

int main()
{
    
    return 0;
}