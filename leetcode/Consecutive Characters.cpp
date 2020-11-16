#include<iostream>
#include<string>

using namespace std;

int maxPower(string s){
    int len = s.length();
        
    int max = 0, count = 0;
    char ch = ' ';
        
    for(int i = 0; i < len; i++) {
        if(s[i] == ch) {
            count++;
        } else {
            if(count > max) {
                max = count;
            }
            count = 1;
            ch = s[i];
        }
    }
    return max > count ? max : count;
}

int main()
{
    string str = "j";
    
    printf("%d ", maxPower(str));

    return 0;
}
