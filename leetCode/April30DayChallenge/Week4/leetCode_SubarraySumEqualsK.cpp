#include<bits/stdc++.h>
#include<stdio.h>

using namespace std;

#define DEBUG 1

class Solution {
public:
    int subarraySum(vector<int>& v, int K) {
        // map of prefix sum
        map<int,int>mp;
        int count = 0,sum=0;
        int n = (int)v.size();

        // go through array
        for(int i=0;i<n;i++){
            // add number to sum var
            sum+=v[i];

            if(sum == K){
            // if sum == K increase count
                count++;
            }

            if(mp.find(sum-K)!=mp.end()){
                // find (sum-K) from mp and add it to count
                count+=mp[sum-K];
            }

            // add sum to map and increase its by one
            mp[sum]++;
        }
        return count;
    }
};

int mysubArraySumEqualK(vector<int> v, int k)
{
    int count = 0, sum = 0;
    map<int, int> m;
    int n = v.size();

#if DEBUG
    printf("%3d:",k);
#endif

    for (int i = 0; i < n; i++)
    {
        // prefix sum
        sum = sum + v[i];

        // check prefix sum
        if(sum == k){
            count++;
        }

        // add sum-k in map
        if(m.find(sum-k) != m.end()){
            count = count + m[sum-k];
        }

        // increment count of prefix sum in map
        m[sum]++;
#if DEBUG
        printf("%3d ",count);
#endif
    }
#if DEBUG
    //printf("\n");
#endif
    return count;
}

int main(){
    int k = 3;
    vector<int> v;
    //v={1,1,1,1,1,1,1};
    v={1,2,3,1,2,-5,2,5,2,2,1,1,1,10,34,2,1,3};

    Solution s;
    for (int i = 0; i < 25; i++)
    {
        //cout << mysubArraySumEqualK(v,i) << " ";
        if(s.subarraySum(v, i) == mysubArraySumEqualK(v,i)) cout << i << " PASS\n"; else cout << i <<" FAIL\n";
    }

    cout << s.subarraySum(v, k) << "\n";

    for(auto i:v){
        printf("%3d ",i);
    }
    cout << "\n";
    int sum = 0;
    for(auto i:v){
        sum = sum + i;
        printf("%3d ",sum);
    }
    cout << "\n";

    return 0;
}