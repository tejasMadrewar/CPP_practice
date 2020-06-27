#include<bits/stdc++.h>

using namespace std;

#define PRINT cout << "PASS\n"; else cout << "FAIL\n";




class StockSpanner {
    int day;
    stack< array<int, 2> > s;
public:
    StockSpanner() { this->day = 0; }
    
    int next( int price ) {
        ++day;
        int count;
        if( s.empty() ) {
            s.push( { price, day } );
            count = 1;
        } else if( s.top()[0] > price ) {
            count = day - s.top()[1];
            s.push( { price, day } );
        } else {
            while( !s.empty() && price >= s.top()[0] ) 
                s.pop();
            if( s.empty() ) count = day;
            else count = day - s.top()[1];
            
            s.push( {price, day } );
        }
        return count;
    }
};
/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */

int main(){
    StockSpanner s;

    vector<int> v = {100, 80, 60, 70, 60, 75, 85};
    vector<int> ans = {1, 1, 1, 2, 1, 4, 6};

    int n  = v.size();
    for(int i = 0; i <n ; i++){
        int a = ans[i];
        if(s.next(v[i]) == a) PRINT
    }

    return 0;
}