#include <iostream>
#include <string>
using namespace std;
void lucky_ticket() {
    int count_favorable = 0;
    for (int i = 0; i <= 999999; i++) {
        int n = i;
        int digits[6];
        for (int j = 5; j >= 0; j--) {
            digits[j] = n % 10;
            n /= 10;
        }
        int sum1 = digits[0] + digits[1] + digits[2];
        int sum2 = digits[3] + digits[4] + digits[5];
        if (sum1 == sum2) count_favorable++;
    }
    double probability = (double)count_favorable / 1000000;
    cout << "Задача 1: Счастливый билет\n";
    cout << "Вероятность получить счастливый билет: " << probability << endl << endl;
}
void guess_number() {
    cout << "Задача 2: Загадай число (1-1000)\n";
    int low = 1, high = 1000;
    string answer;
    while (low < high) {
        int mid = (low + high) / 2;
        cout << "Число больше " << mid << " (д/н)? : ";
        cin >> answer;
        if (answer == "д" || answer == "Д") {
            low = mid + 1;
        }
        else {
            high = mid;
        }
    }
    cout << "Загаданное число: " << low << "\n\n";
}
void analyze_digits() {
    int count_two_same = 0;
    int count_all_diff = 0;
    int count_exactly_two_same = 0;

    for (int n = 100; n <= 999; n++) {
        int d1 = n / 100;
        int d2 = (n / 10) % 10;
        int d3 = n % 10;

        if (d1 == d2 && d2 == d3) {
            // все цифры одинаковые, не учитываем
            continue;
        }

        if (d1 == d2 || d1 == d3 || d2 == d3) {
            count_two_same++;
        }
        if (d1 != d2 && d1 != d3 && d2 != d3) {
            count_all_diff++;
        }
        // ровно две одинаковые
        if ((d1 == d2 && d1 != d3) || (d1 == d3 && d1 != d2) || (d2 == d3 && d2 != d1)) {
            count_exactly_two_same++;
        }
    }

    cout << "Задача 3: Анализ трехзначных чисел\n";
    cout << "Количество чисел с хотя бы двумя одинаковыми цифрами: " << count_two_same << endl;
    cout << "Количество чисел с разными цифрами: " << count_all_diff << endl;
    cout << "Количество чисел с ровно двумя одинаковыми цифрами: " << count_exactly_two_same << endl;
}
int main() {
    setlocale(LC_ALL, "");

    lucky_ticket();
    guess_number();
    analyze_digits();
    return 0;
}
