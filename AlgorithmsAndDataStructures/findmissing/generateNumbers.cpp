#include <iostream>
#include <fstream>
#include <vector>
#include <ctime>
#include <algorithm>
#include <random>

int main(){
	std::ofstream file("numbers.txt");
	if (!file) {
        std::cerr << "Error: could not open output file." << std::endl;
    }
	int count_numbers = 100000000;
	std::vector<int> numbers(count_numbers);
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dis(std::numeric_limits<int>::min(), std::numeric_limits<int>::max());

    for (int i = 0; i < count_numbers; ++i) {
        int rand_num;
        do {
            rand_num = dis(gen);
        } while (std::find(numbers.begin(), numbers.begin() + i, rand_num) != numbers.begin() + i);
        numbers[i] = rand_num;
        file << numbers[i] << std::endl;
    }
    // for (int i = 0; i < count_numbers; ++i) {
    //     int rand_num;
    //     do {
    //         rand_num = rand();
    //     } while (std::find(numbers.begin(), numbers.end(), rand_num) != numbers.end());
    //     numbers[i] = rand_num;
    // }
    // for (int i = 0; i < count_numbers; ++i) {
    //     numbers[i] = i;
    //     file << numbers[i] << "\n";
    // }
    file.close();
    std::cout << "File created successfully." << std::endl;
}