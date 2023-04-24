#include <iostream>

void swap(int& a, int& b){
	int temp = a;
	a = b;
	b = temp;
}

int k_th_smallest(int* arr, int left, int right, int k) {
    if (k > 0 && k <= right - left + 1) {
        int pivotIndex = left;
        int pivot = arr[pivotIndex];
        int i = left + 1;
        int j = right;

        while (i <= j) {
            while (i <= right && arr[i] < pivot) 
            	i++;
            while (j >= left + 1 && arr[j] > pivot) 
            	j--;
            if (i <= j) {
                swap(arr[i], arr[j]);
                i++;
                j--;
            }
        }

        swap(arr[pivotIndex], arr[j]);

        if (k - 1 == j - left) {
            return arr[j];
        } else if (k - 1 < j - left) {
            return k_th_smallest(arr, left, j - 1, k);
        } else {
            return k_th_smallest(arr, j + 1, right, k - (j - left + 1));
        }
    }

    return -1;
}

void initialize_array(int* arr, int size){
	for(int i = 0; i < size; ++i){
		std::cout << "array[" << i << "]=";
		std::cin >> arr[i];
	}
}

int main(){
	int size = 0;
	std::cout << "Input size of array: ";
	std::cin >> size;
	int* arr = new int[size];
	initialize_array(arr, size);
	int k = 0;
	std::cout << "Input k: ";
	std::cin >> k;
	std::cout << k << "-th smallest element of array: " << k_th_smallest(arr, 0, size - 1, k) << std::endl;
    	delete[] arr;
}
