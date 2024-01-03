#include <iostream>

int main() {
	// 1
	for (int i = 300; i <= 1200; i++) {
		if (i % 2 != 0) std::cout << i << " ";
		if (i % 400 == 0) {
			std::cout << std::endl;
			continue;
		}
		if (i % 100 == 0 && i != 300) std::cout << " *** ";
	}
	// 2
	signed int AA[10];
	for (int i = 0; i < 10; i++) {
		std::cin >> AA[i];
	}


	int size = 0;
	for (int i = 0; i < 10; i++) {
		if (AA[i] < 0) {
			size++;
		}
	}	

	int* BB = new int[size];
	int negativeNums = 0;
	for (int i = 0; i < 10; i++) {
		if (AA[i] < 0) {
			std::cout << AA[i] << " ";
			BB[negativeNums] = AA[i];
			negativeNums++;
		}
	}

	std::cout << std::endl <<  "Ujemnych: " << negativeNums << std::endl;
	std::cout << "Pominelo: " << 10 - negativeNums;

	delete[] BB;

	return 0;
}