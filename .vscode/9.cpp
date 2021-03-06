/*
判断一个整数是否是回文数。回文数是指正序（从左向右）和倒序（从右向左）读都是一样的整数。

示例 1:

输入: 121
输出: true
示例 2:

输入: -121
输出: false
解释: 从左向右读, 为 -121 。 从右向左读, 为 121- 。因此它不是一个回文数。
*/
class Solution {
public://my answer
    bool isPalindrome(int x) {
        if(x<0)
        return false;
        int k=x;vector<int> s;
        while(k){
            s.push_back(k%10);
            k=k/10;
        }
        for(int i=0,j=s.size()-1;i<j;i++,j--)
        {
            if(s[i]!=s[j]) return false;
        }
        return true;
    }
};
class Solution {
public://题解
    bool isPalindrome(int x) {
        // 特殊情况：
        // 如上所述，当 x < 0 时，x 不是回文数。
        // 同样地，如果数字的最后一位是 0，为了使该数字为回文，
        // 则其第一位数字也应该是 0
        // 只有 0 满足这一属性
        if (x < 0 || (x % 10 == 0 && x != 0)) {
            return false;
        }

        int revertedNumber = 0;
        while (x > revertedNumber) {//不符合的64543  645>34  ---> 64<345
            revertedNumber = revertedNumber * 10 + x % 10;
            x /= 10;
        }

        // 当数字长度为奇数时，我们可以通过 revertedNumber/10 去除处于中位的数字。
        // 例如，当输入为 12321 时，在 while 循环的末尾我们可以得到 x = 12，revertedNumber = 123，
        // 由于处于中位的数字不影响回文（它总是与自己相等），所以我们可以简单地将其去除。
        return x == revertedNumber || x == revertedNumber / 10;
    }
};
class Solution {
public://https://www.cnblogs.com/hujunzheng/p/5042068.html stringstream   <sstream>
    bool isPalindrome(int x) {
        if (x < 0 || (x % 10 == 0 && x != 0))
			return false;
        stringstream  stream;		
		string temp;
		stream << x;
		stream >> temp;
		int length = temp.size();
		for (int i = 0; i < length / 2; i++)
		{
			if (temp[i] != temp[length - 1-i])
			{
				return false;
			}
		}
		return 1;
    }
};
