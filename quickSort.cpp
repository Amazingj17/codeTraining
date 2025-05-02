#include <vector>
#include <iostream>
#include <algorithm>


void quickSort(std::vector<int>& arr, int low, int high);

int main() {

    int size;
    std::cin >> size;
    std::vector<int> arr(size);
    for (int i = 0; i < size; ++i) {
        std::cin >> arr[i];
    }

    quickSort(arr, 0, size - 1);

    for (int i = 0; i < size; ++i) {
        std::cout << arr[i] << " \n"[i == size - 1];
    }
    return 0;
}


void quickSort(std::vector<int>& arr, int low, int high) {
    if (low >= high) {                        //分区中只剩一个元素时，直接返回
        return;
    }
    int position = low + (high - low) / 2;    //用中间的值作为基准
    int pivot = arr[position];
    std::swap(arr[low], arr[position]);       //将基准值交换到最前面
    int i = low + 1;
    int j = high;
    while (true) {
        while (i <= high && arr[i] < pivot) { //找到大于pivot的数
            ++i;
        }
        while (j >= low && arr[j] > pivot) {  //找到小于pivot的数
            --j;
        }
        if (i > j) {
            break;                            //找到基准的正确位置
        }
        std::swap(arr[i], arr[j]);            //大于pivot交换到右边，小于pivot交换到左边
        ++i;
        --j;
    }
    std::swap(arr[low], arr[j]);              //正确放置pivot
    quickSort(arr, low, j - 1);               //处理左边区域
    quickSort(arr, j + 1, high);              // 处理右边区域
}
