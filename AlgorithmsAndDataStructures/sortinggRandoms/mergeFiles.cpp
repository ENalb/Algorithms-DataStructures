#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <climits>

void merge(std::vector<std::ifstream>& files, std::ofstream& outfile) {
    std::vector<int> nums(files.size());
    for (int i = 0; i < files.size(); ++i) {
        if (files[i] >> nums[i]) {
            continue;
        }
        else {
            files[i].close();
        }
    }

    while (true) {
        int min_index = -1;
        int min_value = INT_MAX;
        for (int i = 0; i < nums.size(); ++i) {
            if (files[i].is_open() && nums[i] < min_value) {
                min_index = i;
                min_value = nums[i];
            }
        }

        if (min_index == -1) {
            break;
        }

        outfile << min_value << std::endl;

        if (files[min_index] >> nums[min_index]) {
            continue;
        }
        else {
            files[min_index].close();
        }
    }
}

int main() {
    const int num_files = 35;
    std::vector<std::ifstream> files(num_files);
    std::ofstream outfile("merged.txt");
    for (int i = 1; i <= num_files; ++i) {
        std::string filename = "sorted_" + std::to_string(i) + ".txt";
        files[i-1].open(filename);
        if (!files[i-1]) {
            std::cerr << "Error: could not open file " << filename << std::endl;
            return 1;
        }
    }
    merge(files, outfile);
    for (int i = 0; i < num_files; ++i) {
        files[i].close();
    }
    outfile.close();

    return 0;
}