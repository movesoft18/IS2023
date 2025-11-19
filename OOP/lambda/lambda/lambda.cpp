#include <array>
#include <iostream>

// static в этом контексте означает внутреннее связывание
static bool containsNut(std::string str)
{
    // std::string_view::find, если не находит подстроку, возвращает
    // std::string_view::npos, являющееся очень большим числом.
    // В противном случае он возвращает индекс, в котором подстрока
    // встречается в str.
    return (str.find("nut") != std::string::npos);
}

int main()
{
    /*
    auto lambda = [объекты_захвата](параметры) -> возвр_тип
    {
        // код функции
    }
    */
    std::array<std::string, 4> arr{ "apple", "banana", "walnut", "lemon" };
    auto l = [](std::string str) {
        return (str.find("nut") != std::string::npos);
        };
    // std::find_if принимает указатель на функцию
    //const auto found = std::find_if(arr.begin(), arr.end(), containsNut) ;
    const auto found = std::find_if(arr.begin(), arr.end(), [](std::string str) {
            return (str.find("nut") != std::string::npos);
        });

    if (found == arr.end())
    {
        std::cout << "No nuts\n";
    }
    else
    {
        std::cout << "Found " << *found << '\n';
    }

    auto printHello = []() {
            std::cout << "Hello!";
        };

    []() {};

    printHello();

    return 0;
}

