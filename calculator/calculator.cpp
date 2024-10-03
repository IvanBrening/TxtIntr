#include <iostream>
#include <vector>
#include <cstring>
#include <cstdlib>

void print_usage() {
    std::cout << "Usage: calculator -o [operation] operand1 operand2 [operand3 operand4]\n";
    std::cout << "Supported operations: summa (addition), subtraction (subtraction)\n";
    exit(0);
}

int main(int argc, char *argv[]) {
    if (argc < 4) {
        print_usage();
    }

    std::string operation;
    std::vector<int> operands;

    // Разбор аргументов командной строки
    for (int i = 1; i < argc; ++i) {
        if (std::strcmp(argv[i], "-o") == 0 || std::strcmp(argv[i], "--operation") == 0) {
            if (i + 1 < argc) {
                operation = argv[i + 1];
                i++;  // Пропустить имя операции
            } else {
                print_usage();
            }
        } else {
            if (operands.size() < 4) {
                operands.push_back(std::atoi(argv[i]));
            } else {
                print_usage();
            }
        }
    }

    // Проверка, что операция задана и количество операндов корректное
    if (operation.empty() || operands.size() < 2) {
        print_usage();
    }

    // Выполнение операций
    if (operation == "summa") {
        int result = 0;
        for (int operand : operands) {
            result += operand;
        }
        std::cout << "Result: " << result << std::endl;
    } else if (operation == "subtraction") {
        int result = operands[0];
        for (size_t i = 1; i < operands.size(); ++i) {
            result -= operands[i];
        }
        std::cout << "Result: " << result << std::endl;
    } else {
        print_usage();
    }

    return 0;
}
