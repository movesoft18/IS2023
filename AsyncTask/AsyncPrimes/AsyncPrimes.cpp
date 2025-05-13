#include <iostream>
#include <future>   // для std::future и std::async
#include <chrono>   // для std::chrono (имитация долгой работы)
using namespace std;

bool isPrime(int n) {
    if (n <= 1) return false;
    if (n == 2) return true;
    if (n % 2 == 0) return false;

    int sqrt_n = sqrt(n);
    for (int i = 3; i <= sqrt_n; i += 2) {
        if (n % i == 0) return false;
    }
    return true;
}
// Функция, которая будет выполняться асинхронно
vector<int> calculatePrimes(int min, int max)
{
    vector<int> result;
    for (int i = min; i <= max; i++)
        if (isPrime(i))
            result.push_back(i);
    return result;  // Возвращаем результат
}

int main() {
    setlocale(LC_ALL, "");
    auto start = chrono::steady_clock::now();
    std::cout << "Основной поток: " << std::this_thread::get_id() << std::endl;
    vector<future<vector<int>>> tasks;
    // Запускаем асинхронную задачу с std::async
    tasks.emplace_back(
        std::async(
            std::launch::async,  // Запуск в отдельном потоке
            calculatePrimes,     // Функция для выполнения
            2, 40000000              // Аргументы функции
        )
    );
    tasks.emplace_back(
        std::async(
            std::launch::async,  // Запуск в отдельном потоке
            calculatePrimes,     // Функция для выполнения
            40000001, 60000000              // Аргументы функции
        )
    );
    // Основной поток продолжает работу
    std::cout << "Основной поток делает что-то еще..." << std::endl;

    // Получаем результат (если функция не завершилась - блокируем поток до её завершения)
    auto result1 = tasks[0].get();
    auto result2 = tasks[1].get();
    auto end = chrono::steady_clock::now();
    auto duration = chrono::duration<double>(end - start);
    cout << "Время: " << duration.count() << "c.\n";
    result1.insert(result1.begin() + result1.size(), result2.begin(), result2.end());
    cout << "Всего простых чисел: " << result1.size() << endl;

    return 0;
}