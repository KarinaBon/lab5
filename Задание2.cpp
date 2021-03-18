#include <iostream>
#include <cstdlib>

const int numbers_count = 10;

int main() {
    // Request user input for range bounds
    int range_min, range_max;
    std::cout << "Enter range min number: ";
    std::cin >> range_min;

    do {
        std::cout << "Enter range max number: ";
        std::cin >> range_max;
    } while (range_min > range_max);

    // Generate random numbers in range
    int numbers[numbers_count];
    std::cout << "Generated numbers: ";
    for (int i = 0; i < numbers_count; i++) {
        numbers[i] = range_min + rand() % (range_max - range_min + 1);
        std::cout << numbers[i] << " ";
    }
    std::cout << std::endl << std::endl;

    // Output positive odd numbers and sum
    std::cout << "Positive odd numbers: ";
    int sum = 0;
    for (int i = 0; i < numbers_count; i++) {
        if (numbers[i] <= 0) continue;
        if (numbers[i] % 2 == 0) continue;

        std::cout << numbers[i] << " ";
        sum += numbers[i];
    }
    std::cout << std::endl << "Positive odd numbers sum: " << sum;
    std::cout << std::endl << std::endl;

    // Calculate and output min and max absolute numbers
    int min = numbers[0];
    int max = numbers[0];
    for (int i = 0; i < numbers_count; i++) {
        if (abs(numbers[i]) < abs(min))
            min = numbers[i];
        if (abs(numbers[i]) > abs(max))
            max = numbers[i];
    }
    std::cout << "Min absolute number: " << abs(min) << std::endl;
    std::cout << "Max absolute number: " << abs(max) << std::endl;

    // Product of numbers exclude min and max
    int result = 1;
    for (int i = 0; i < numbers_count; i++) {
        if (abs(numbers[i]) == abs(min)) continue;
        if (abs(numbers[i]) == abs(max)) continue;

        result *= numbers[i];
    }
    std::cout << "Multiplication product of number: " << result << std::endl;
}
