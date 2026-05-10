#include <iostream>
using namespace std;
class Solution {
public:
    int sum = 0;
    string s;
    int getvalue(char c, int i){
        if(c == 'I' || c == 'i') return 1;
        else if(c == 'V' || c == 'v') return 5;
        else if(c == 'X' || c == 'x') return 10;
        else if(c == 'L' || c == 'l') return 50;  
        else if(c == 'C' || c == 'c') return 100;
        else if(c == 'D' || c == 'd') return 500;
        else if(c == 'M' || c == 'm') return 1000;
        else return 0;
    }
    int romanToInt(string s) {
        for(int i = 0; i < s.size(); i++){
            getvalue(s[i], i);
            if(getvalue(s[i], i) < getvalue(s[i + 1], i + 1)){
                sum -= getvalue(s[i], i);
            }
            else{
                sum += getvalue(s[i], i);
            }
        }
        return sum;
    }
};

int main(void){
    Solution s;
    cout << "Enter the roman number:";
    cin >> s.s;
    cout << s.romanToInt(s.s) << endl;
    return 0;
}