# 前缀和（Prefix Sum）

## 🎯 算法简介

**前缀和**是一种通过预处理数组，将区间和查询时间复杂度从`O(n)`优化到`O(1)`的技术。适用于**频繁查询子数组和**的场景。

## 📜 核心公式

- **前缀和数组构建**：
  
  ```cpp
  prefix[i] = prefix[i-1] + nums[i-1];  // 注意索引偏移
  ```

- **前缀和数组构建**

  ```C++
  sum(L, R) = prefix[R] - prefix[L-1];  // 闭区间[L, R]
  ```

## 🧩 代码模板

```C++
#include <vector>
#include <unordered_map>
using namespace std;

// 求子数组和为k的个数（LeetCode 560）
int subarraySum(vector<int>& nums, int k) {
    unordered_map<int, int> prefix{{0, 1}}; // 初始化：前缀和为0出现1次
    int current = 0, count = 0;
    for (int num : nums) {
        current += num;
        if (prefix.find(current - k) != prefix.end()) {
            count += prefix[current - k];
        }
        prefix[current]++;
    }
    return count;
}
```

## 🌰 使用示例

### 例题：LeetCode 560. 和为K的子数组

**输入**：`nums = [1,1,1], k = 2`
**输出**：`2`
**解释**：

- 前缀和数组为 `[0,1,2,3]`
- 查询`current - k`存在时累加计数

## ⚠️ 注意事项

1. **索引偏移**：通常将`prefix[0]`设为0，`prefix[1]`对应`nums[0]`
2. **哈希表初始化**：必须预先插入`{0:1}`以处理从第一个元素开始的子数组
3. **数据范围**：若元素值较大，需考虑使用`long long`

## 🔗 相关题目

- [洛谷 P1114 - 前缀和经典问题](https://www.luogu.com.cn/problem/P1114)
- [蓝桥杯《区间求和》真题](https://www.lanqiao.cn/problems/1234/learning/)