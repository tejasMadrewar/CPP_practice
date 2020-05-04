#include<iostream>
#include<vector>
#include<map>

using namespace std;

class Solution {
public:
    map<int,int> data;
    
    int sumOfDigit(int num){
        int result = 0;
        int temp = num;

        while(temp > 0){
            result = result + ((temp % 10) * (temp % 10)) ;
            temp = temp / 10;
        }
        cout << result << "\n";
        return result;
    }

    bool isHappy(int n) {
        int temp = n;
        int v = 0;

        for(int i = 0; i < 30; i++){

            auto el = data.find(temp);

            if(el == data.end()){
                v = sumOfDigit(temp);
                data.insert({temp,v});
            }else{
                v = el->second;
            }

            if(v == 1) return true;
            temp = v;
        }
        return false;
    }
};

int main(){
    Solution s;
    cout << "helloworld\n";

    cout << s.isHappy(19);
    
    return 0;
}