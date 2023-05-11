#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

int binary_search(std::vector<int>& nums, int start, int end, int key){
    if(start >= end){
        return -1;
    }
    int mid = start + (end - start) / 2;
    if(key == nums[mid]){
        return mid;
    }
    else if(key > nums[mid]){
        return binary_search(nums, mid + 1, end, key);
    }
    return binary_search(nums, start, mid - 1, key);
}

int main() {
    std::ifstream file_in("sorted.txt");
    if (!file_in) {
        std::cerr << "Error: could not open input file." << std::endl;
        return 1;
    }

    const int count_numbers = 4856480;
    std::vector<int> numbers(count_numbers);
    file_in.read(reinterpret_cast<char*>(&numbers[0]), count_numbers * sizeof(int));
    file_in.close();

    int min_num = numbers[0];
    int max_num = numbers[count_numbers-1];

    std::vector<int> missing_numbers;

    for (int i = 1; i < count_numbers; ++i) {
        if (numbers[i] != numbers[i-1] + 1) {
            int start = numbers[i-1] + 1;
            int end = numbers[i] - 1;
            while (start <= end) {
                int mid = (start + end) / 2;
                if (binary_search(numbers, 0, count_numbers, mid)) {
                    start = mid + 1;
                } else {
                    missing_numbers.push_back(mid);
                    end = mid - 1;
                }
            }
        }
    }

    std::ofstream file_out("missing_numbers.txt");
    if (!file_out) {
        std::cerr << "Error: could not open output file." << std::endl;
        return 1;
    }

    for (int num : missing_numbers) {
        file_out << num << "\n";
    }
    file_out.close();

    std::cout << "Missing numbers found successfully." << std::endl;
    return 0;
}
