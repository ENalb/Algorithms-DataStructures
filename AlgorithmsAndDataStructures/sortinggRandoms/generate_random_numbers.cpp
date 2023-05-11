#include <iostream>
#include <fstream>
#include <cstdlib>

void generate();

int main(){
    generate();
    return 0;
}

void generate(){
    std::ofstream file("randomNumbers.txt");
    if (!file) {
        std::cerr << "Error: could not open output file." << std::endl;
    }
    for (int i = 0; i < 4000000000; ++i) {
        int number = std::rand() % 4294967295;
        file << number << std::endl;
    }
    file.close();
    std::cout << "File created successfully." << std::endl;
}
