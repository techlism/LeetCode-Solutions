class Solution { 
public:
    string findDifferentBinaryString(vector<string>& nums) {
        int maxBits = nums[0].length();
        int totalBits = pow(2, maxBits);
        vector<bool> vis(totalBits, false);

        for (auto bstr : nums) {
            // Convert binary string to decimal
            int num = stoi(bstr, nullptr, 2); 
            vis[num] = true;
        }

        int ans = 0;

        // Find the first unvisited position
        while (ans < totalBits && vis[ans]) {
            ans++;
        }

        // Convert the decimal answer to binary string
        string result = bitset<32>(ans).to_string();
        // Trim leading zeros
        return result.substr(result.length() - maxBits); 
    }
};