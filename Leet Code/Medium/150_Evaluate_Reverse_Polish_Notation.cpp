#include<iostream>
#include<vector>
#include<stack>
using namespace std;

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> s;

        for(int i=0;i<tokens.size();i++){
            if(tokens[i] != "+" && tokens[i] != "-" && tokens[i] != "/" && tokens[i] != "*"){
                s.push(stoi(tokens[i]));
            }else{
                int temp1 = s.top();
                s.pop();
                int temp2 = s.top();
                s.pop();

                if(tokens[i]=="+"){
                    s.push(temp1+temp2);
                }else if(tokens[i]=="-"){
                    s.push(temp2-temp1);
                }else if(tokens[i]=="*"){
                    s.push(temp2*temp1);
                }else if(tokens[i]=="/"){
                    if (temp1 == 0) {
                        continue;
                    }
                    s.push(temp2/temp1);
                }
            }
        }

        return s.top();
    }
};

int main()
{
    
    return 0;
}