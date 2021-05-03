#include <iostream>
#include <cstring>
#include <stack>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N;
    cin>>N;
    cin.ignore();

    string str;
    stack<char> s;
    int len,wordlen;
    char word[20];

    while(N--){
        getline(cin,str);
        len = str.length();
        wordlen=0;
        while(len!=0){
            len--;
            if(str.at(len)==' '){
                while(wordlen!=0){
                    wordlen--;
                    s.push(word[wordlen]);
                }
                s.push(' ');
            }
            else{
                word[wordlen++]=str.at(len);
            }
        }
        while(wordlen!=0){
            wordlen--;
            s.push(word[wordlen]);
        }

        while(s.empty()==false){
            cout<<s.top();
            s.pop();
        }
        cout<<"\n";
    }
    return 0;
}