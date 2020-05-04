#include<bits/stdc++.h>
using namespace std;

//class FirstUnique {
//    map<int,int> m;
//    vector<int> v;
//public:
//    FirstUnique(vector<int>& nums) {
//        for(auto i : nums){
//            if(m.find(i) == m.end()){
//                v.push_back(i);
//            }
//            m[i]++;
//        }
//    }
//    
//    int showFirstUnique() {
//        for (auto i : v){
//            if(m[i] != 1) continue;
//            return i;
//        }
//        return -1;
//    }
//    
//    void add(int value) {
//            if(m.find(value) == m.end()){
//                v.push_back(value);
//            }
//            m[value]++;
//    }
//};

/**
 * Your FirstUnique object will be instantiated and called as such:
 * FirstUnique* obj = new FirstUnique(nums);
 * int param_1 = obj->showFirstUnique();
 * obj->add(value);
 */
class FirstUnique {
private:
    queue<int> q;
    unordered_map<int, int> count;
public:
    FirstUnique(vector<int>& nums) {
        for(int num: nums){
            count[num]++;
            q.push(num);
        }
    }
    
    int showFirstUnique() {
        while(!q.empty() && count[q.front()] > 1){
            q.pop();
        }
        if(q.empty()){
            return -1;
        }
        else{
            return q.front();
        }
    }
    
    void add(int value) {
        if(++count[value] == 1){
            q.push(value);
        }
    }
};

#define PRINT cout << "PASS\n"; else cout << "FAIL\n";
int main(){
    vector<int> v;
v = { 2,3,5 };
FirstUnique firstUnique(v);
//if(2 == firstUnique.showFirstUnique()) cout << "PASS\n"; else cout << "FAIL\n"; // return 2
if(2 == firstUnique.showFirstUnique()) PRINT // return 2
firstUnique.add(5);            // the queue is now [2,3,5,5]
if(2 == firstUnique.showFirstUnique())  PRINT // return 2
firstUnique.add(2);            // the queue is now [2,3,5,5,2]
if(3 == firstUnique.showFirstUnique()) PRINT // return 3
firstUnique.add(3);            // the queue is now [2,3,5,5,2,3]
if(-1 == firstUnique.showFirstUnique()) PRINT // return -1



    return 0;
}