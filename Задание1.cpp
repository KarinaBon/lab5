#include <iostream>
#include <cstdlib>
#include <Windows.h>
#include <stdio.h>

void swap(int *xp, int *yp) {
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n-1; i++)
        for (int j = 0; j < n-i-1; j++)
            if (arr[j] > arr[j+1])
                swap(&arr[j], &arr[j+1]);
}

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	std::cout << "\n" << "\t" << "\t" << "Генерування випадкових чисел" << " \n" << "\n" << "\n";
	
    int m = -1;
    while (m < 0) {
    	std::cout << "Введіть кількість чисел послідовності: ";
    	std::cin >> m;
	}
    std::cout << "m = " << m <<std::endl;

    int n = -1;
    while (n < 0) {
        std::cout << "Введіть кількість дійсних числел послідовності: ";
        std::cin >> n;
    }
    std::cout << "n = " << n << std::endl;

    int k = -1;
    while (k < 3 || k > 10) {
        std::cout << "Введіть кількість чисел послідовності в рядку (3 < k < 10): ";
        std::cin >> k;
    }
    std::cout << "k = " << k << std::endl;
    
	int numbers[m];
    std::cout << std::endl << "Цілі випадкові числа на проміжку  [13,399]:" << std::endl;
    for (int i = 1; i <= m; i++) {
        numbers[i - 1] = rand() % 399 + 13;
        std::cout << numbers[i - 1] << " ";
        if ((i % k) == 0)
            std::cout << std::endl;
    }
	std::cout << std::endl << "Дійсні випадкові числа на проміжку [-2,2]:" << std::endl;
    for (int i=1; i<=n; i++) {  
		
		float number = (float)rand() / RAND_MAX * 4.0 - 2.0;
		printf("%7.1f", number);
		if ((i % k) == 0)
        std::cout << std::endl;  
	}
    
    bubbleSort(numbers, m);
    std::cout << std::endl << "Парні варіанти (even):" << std::endl;
	for ( int i = 0; i < m; i++ ) {
        if ( numbers[i] % 2 == 0 ) {
    	std::cout << numbers[i] << " ";
    }   
}
std::cout << std::endl;
bubbleSort(numbers, m);
    std::cout << std::endl << "Не парні варіанти (odd):" << std::endl;
	for ( int i = m; i > 0; i-- ) {
        if ( numbers[i] % 2 == 1 ) 
    	std::cout << numbers[i] << " ";
    }
}
