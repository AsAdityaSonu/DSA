// reverse string

#include <iostream>
#include <string>

using namespace std;

void rev(string &st){
    int first=0;
    int last = st.length()-1;

    for(int i = 0;i<(st.length()/2);i++){
        char temp=st[first];
        st[first]=st[last];
        st[last]=temp;

        first++;
        last--;
    }

    cout<<st<<endl;
}

int main(){
    string a="Aditya";
    
    rev(a);
}