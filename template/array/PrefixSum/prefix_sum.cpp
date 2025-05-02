#include <iostream>
#include <fstream>
#include <unordered_map>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int>prefix;
        prefix[0] = 1;
        int current_sum = 0, count = 0;

        for (int num : nums) {
            current_sum += num;
            if (prefix.find(current_sum - k) != prefix.end()) {
                count += prefix[current_sum - k];
            }

            prefix[current_sum]++;
        }
        return count;
    }
};


int main() {
    ifstream fin("test_case.txt");
    string line;
    Solution solution;
    while (getline(fin, line)) {
        if (line.find("#") == 0) {
            cout << "\n=== testing: " << line.substr(2) << endl;
            continue;
        }

        // 读取输入数据
        if (line == "Input:") {
            int n, k;
            fin >> n;
            vector<int> nums(n);
            for (int i = 0; i < n; ++i) fin >> nums[i];
            for (int i = 0; i < n; ++i) cout << nums[i] << " ";
            fin >> k;
            cout << k;
            cout << endl;
            fin.ignore(numeric_limits<streamsize>::max(), '\n');  // 忽略剩余行

            // 执行被测函数
            int res = solution.subarraySum(nums, k);

            // 读取预期输出
            getline(fin, line);
            int expected = stoi(line.substr(line.find(":") + 2));

            // 验证结果
            cout << "result: " << res << " | expected: " << expected
                << " → " << (res == expected ? "Right" : "Wrong") << endl;
        }
    }
    fin.close();
    return 0;
}