#include <iostream>
#include <vector>
#include <string>

class Solution {
public:
    std::string longestCommonPrefix(const std::vector<std::string>& strs) {
        if (strs.empty()) return "";  
        if (strs.size() == 1) return strs[0];  

        std::string prefix = strs[0];  
        for (const std::string& s : strs) {  
            while (s.find(prefix) != 0) { 
                prefix = prefix.substr(0, prefix.length() - 1);  
                if (prefix.empty()) return "";  
            }
        }
        return prefix;  
    }
};

int main() {
    Solution solution;
    std::vector<std::string> strs = {"flower", "flow", "flight"};
    std::cout << "Longest Common Prefix: " << solution.longestCommonPrefix(strs) << std::endl;

    
    std::cout << "Press Enter to exit..." << std::endl;
    std::cin.get();  
    return 0;
}
