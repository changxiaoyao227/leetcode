/*给定一个整数数组 A，如果它是有效的山脉数组就返回 true，否则返回 false。

让我们回顾一下，如果 A 满足下述条件，那么它是一个山脉数组：

A.length >= 3
在 0 < i < A.length - 1 条件下，存在 i 使得：
A[0] < A[1] < ... A[i-1] < A[i]
A[i] > A[i+1] > ... > A[A.length - 1]
提示：

0 <= A.length <= 10000
0 <= A[i] <= 10000 
来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/valid-mountain-array
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。*/
#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    bool validMountainArray(vector<int>& A) {
        int l=A.size();
        if(l<3)
        return false;
        int i=1;
        while(i<l&&A[i-1]<A[i]){
            i++;
        }
        if(i==1||i==l){
            return false;
        }
        while(i<l&&A[i]<A[i-1]){
            i++;
        }
        if(i==l)
        return true;
        else 
        return false;
    }
};
int main(){
    vector<int> a;
    a.push_back(1);a.push_back(3);a.push_back(2);
    Solution s;
    cout<<s.validMountainArray(a)<<endl;
    return 0;
}