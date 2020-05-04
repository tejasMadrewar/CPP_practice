#include<string>
#include<iostream>

using namespace std;

// # means back space
class Solution {
public:
    string newString(string s){
        string temp(s);
        for (int i = 0; i < temp.size(); i++)
        {
            if (temp[i] == '#')
            {
                if (i != 0)
                    temp.erase(i - 1, 2);
                else
                    temp.erase(i, 1);
                i = -1;
                //cout << temp << "\n";
            }
        }
        return temp;
    }
    bool backspaceCompare(string S, string T) {
        bool result;
        string one = newString(S);
        string two = newString(T);
        cout << one << " == " << two << "\n";

        return (one == two);
        
    }
};

int main(){
    Solution s;
    if(s.backspaceCompare("ab#c","ad#c") != true) cout << "FAIL\n";
    if(s.backspaceCompare( "ab##", "c#d#") != true) cout << "FAIL\n";
    if(s.backspaceCompare( "a##c", "#a#c"  ) == true) cout << "FAIL\n";

    return 0;
}