#include <algorithm> /* std::algorithm */
#include <array> /* std::array */
#include <climits> /* CHAR_BIT */
#include <iostream> /* std::cout, std::endl */
#include <numeric> /* std::accumulate */
#include <string> /* std::string */
#include <vector> /* std::vector */

#define ARR_SIZE (4)

void ArrSum() {
    std::cout << "\033[1;34m" << "Array Sum Test:" << "\033[0m" << std::endl;

    std::array<long, ARR_SIZE> arr {1, 2, 3};
    std::cout << "Array sum is: " << std::accumulate(arr.begin(), arr.end(), 0) << std::endl << std::endl;
}

void ArrayMultiplication() {
    std::cout << "\033[1;34m" << "Array Multiplication Test:" << "\033[0m" << std::endl;

    std::array<long, ARR_SIZE> arr {1, 2, 3, 4};
    std::cout << "Array multiplication is: " << std::accumulate(arr.begin(), arr.end(), 1, std::multiplies<long>()) << std::endl << std::endl;
}

void CountOnBits() {
    std::cout << "\033[1;34m" << "Count On Test:" << "\033[0m" << std::endl;

    struct CountOnBits {
        long operator()(long a_result, long a_currNum) {
            size_t countOnBits {0};
            
            for (size_t i {0};i < sizeof(long) * CHAR_BIT;++i) {
               countOnBits += (a_currNum >> i) & 1;
            }

            return a_result + countOnBits;
        }
    };

    std::array<long, ARR_SIZE> arr {1, 2, 3, 4};
    std::cout << "Array On Bits is: " << std::accumulate(arr.begin(), arr.end(), 0, CountOnBits()) << std::endl << std::endl;
}

void CountOffBits() {
    std::cout << "\033[1;34m" << "Count Off Test:" << "\033[0m" << std::endl;

    struct CountOnBits {
        long operator()(long a_result, long a_currNum) {
            size_t countOnBits {0};
            
            for (size_t i {0};i < sizeof(long) * CHAR_BIT;++i) {
               countOnBits += !((a_currNum >> i) & 1);
            }

            return a_result + countOnBits;
        }
    };

    std::array<long, ARR_SIZE> arr {1, 2, 3, 4};
    std::cout << "Array Off Bits is: " << std::accumulate(arr.begin(), arr.end(), 0, CountOnBits()) << std::endl << std::endl;
}

void ToggleBits() {
    std::cout << "\033[1;34m" << "Toggle Bits Test:" << "\033[0m" << std::endl;

    std::array<long, ARR_SIZE> newArr {};

    struct ToggleBits {
        long operator()(long a_currNum) {           
            return ~a_currNum;
        }
    };

    std::array<long, ARR_SIZE> arr {1, 2, 3, 4};
    std::cout << "Toggle Number is: " << std::transform(arr.begin(), arr.end(), newArr.begin(), ToggleBits()) << std::endl << std::endl;
}

void AllEven() {
    std::cout << "\033[1;34m" << "All Even Test:" << "\033[0m" << std::endl;

    struct AllEven {
        bool operator()(long a_currNum) {           
            return (!(a_currNum % 2) ? true : false);
        }
    };

    std::array<long, ARR_SIZE> arr {1, 2, 3, 4};

    std::cout << "Is All Even Test 1 (positive/negative numbers): " << std::all_of(arr.begin(), arr.end(), AllEven()) << std::endl;

    std::array<long, ARR_SIZE> arr2 {2, 4, 6, 8};

    std::cout << "Is All Even Test 2 (positive numbers): " << std::all_of(arr2.begin(), arr2.end(), AllEven()) << std::endl << std::endl;
}

void FirstDivisibleByFive () {
    std::cout << "\033[1;34m" << "First Divisible By Five Test:" << "\033[0m" << std::endl;

    struct FirstDivisibleByFive {
        bool operator()(long a_currNum) {           
            return (!(a_currNum % 5) ? true : false);
        }
    };

    std::array<long, ARR_SIZE> arr {1, 7, 5, 10};

    std::cout << "The First Number That Divisible By Five is: " << *std::find_if(arr.begin(), arr.end(), FirstDivisibleByFive()) << std::endl;
}

int main() {
    ArrSum();
    ArrayMultiplication();
    CountOnBits();
    CountOffBits();
    ToggleBits();
    AllEven();
    FirstDivisibleByFive();

    return 0;
}