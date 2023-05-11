#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

void merge(std::vector<int>& arr, int start, int mid, int end) {
    int n1 = mid - start + 1;
    int n2 = end - mid;

    std::vector<int> left(n1);
    std::vector<int> right(n2);

    for (int i = 0; i < n1; i++)
        left[i] = arr[start + i];
    for (int j = 0; j < n2; j++)
        right[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = start;

    while (i < n1 && j < n2) {
        if (left[i] <= right[j]) {
            arr[k++] = left[i++];
        }
        else {
            arr[k++] = right[j++];
        }
    }

    while (i < n1) {
        arr[k++] = left[i++];
    }

    while (j < n2) {
        arr[k++] = right[j++];
    }
}

void mergeSort(std::vector<int>& arr, int start, int end) {
    if (start < end) {
        int mid = start + (end - start) / 2;
        mergeSort(arr, start, mid);
        mergeSort(arr, mid + 1, end);
        merge(arr, start, mid, end);
    }
}

int main(){
    std::ifstream infile("randomNumbers.txt");
    if (!infile) {
        std::cerr << "Error: could not open file\n";
        return 1;
    }

    int total_bytes = 200 * 1024 * 1024; 
    int num_files = 0;
    std::vector<int> numbers;
    int num_bytes = 0;

    int num;
    while (infile >> num) {
        numbers.push_back(num);
        num_bytes += sizeof(num);

        if (num_bytes >= total_bytes) {
            num_bytes = 0;
            num_files++;
            mergeSort(numbers, 0, numbers.size() - 1);

            std::ofstream outfile("sorted_" + std::to_string(num_files) + ".txt");
            if (!outfile) {
                std::cerr << "Error: could not create file\n";
                return 1;
            }

            for (int i = 0; i < numbers.size(); ++i) {
                outfile << numbers[i] << std::endl;
            }

            numbers.clear();
            outfile.close();
        }
    }
    if (numbers.size() > 0) {
        num_files++;
        mergeSort(numbers, 0, numbers.size() - 1);

        std::ofstream outfile("sorted_" + std::to_string(num_files) + ".txt");
        if (!outfile) {
            std::cerr << "Error: could not create file\n";
            return 1;
        }

        for (int i = 0; i < numbers.size(); ++i) {
            outfile << numbers[i] << std::endl;
        }

        outfile.close();
    }

    infile.close();

    return 0;
}
