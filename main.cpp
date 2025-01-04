#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

class Solution {
public:
    int romanToInt(string s) {
        int ans = 0;
        unordered_map<char, int> mp{
            {'I', 1}, {'V', 5}, {'X', 10}, {'L', 50},
            {'C', 100}, {'D', 500}, {'M', 1000}
        };

        for (int i = 0; i < s.size() - 1; i++) {  // Loop until the second-to-last character
            if (mp[s[i]] < mp[s[i + 1]]) {
                ans -= mp[s[i]];  // Subtract if current value is smaller than the next
            } else {
                ans += mp[s[i]];  // Add if current value is greater than or equal to the next
            }
        }

        ans += mp[s[s.size() - 1]];  // Add the value of the last character
        return ans;
    }
};

int main() {
    Solution solution;
    string s = "IX";  // Example input
    cout << "Roman to Integer: " << solution.romanToInt(s) << endl;
    
    // Dừng lại để xem kết quả
    cin.get();  // Đợi người dùng nhấn Enter
    return 0;
}
