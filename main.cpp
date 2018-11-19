#include <iostream>
#include <fstream>
#include <intrin.h> 

int main() {
	std::ofstream output;
	output.open("test.txt");
	unsigned __int64 size = 32768;
	//int array[32768];

	//for (unsigned long j = 0; j < 32768; j++)
		//array[j] = 0;
	unsigned __int64 t1 = 0;
	unsigned __int64 t = 0;
	int temp = 0;
	std::cout << "direct bypass";
	for (size; size < 2359296; size *= 2) { //direct bypass
		int * array = new int [size] {0};
		for (unsigned i = 0; i < 1000; i++) {
			unsigned __int64 t1 = __rdtsc();
			for (unsigned long j = 0; j < size; j++) {
				t1 = __rdtsc();
				temp = array[j];
				t = t + __rdtsc() - t1;
			}
			t = t + __rdtsc() - t1;
		}
		std::cout << std::endl << t / 1000;
		t = 0;
		delete[] array;
	}

	t = 0;
	size = 32768;
	unsigned __int64 index = 0;
	std::cout << std::endl << "reverse bypass";
	for (size; size < 2359296; size *= 2) { //direct bypass
		int * array = new int [size] {0};
		for (unsigned i = 0; i < 1000; i++) {
			t1 = __rdtsc();
			for (unsigned long j = 0; j < size; j++) {
				index = size - 1 - j;
				t1 = __rdtsc();
				temp = array[j];
				t = t + __rdtsc() - t1;
			}
				
		}
		std::cout << std::endl << t / 1000;
		t = 0;
		delete[] array;
	}
	
	size = 32768;
	t = 0;
	std::cout << std::endl << "random bypass";
	for (size; size < 2359296; size *= 2) { //direct bypass
		int * array = new int [size] {0};
		for (unsigned i = 0; i < 1000; i++) {
			for (unsigned long j = 0; j < size; j++) {
				index = (rand()*rand()*rand()) % size;
				t1 = __rdtsc();
				temp = array[index];
				t = t + __rdtsc() - t1;
			}
		}
		std::cout << std::endl << t / 1000;
		t = 0;
		delete[] array;
	}
	std::cin.get();
}
