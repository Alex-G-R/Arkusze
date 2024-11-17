#include <iostream>
#include <type_traits>
#include <vector>
#include <algorithm>

// Function template
template<typename Type>
Type add(Type num1, Type num2)
{
    return num1 + num2;
}

// Variable template
template<typename Type>
constexpr Type speed_of_light = Type(299792458);

// Class templates
template<typename Type>
struct Pair
{
    Pair(Type x, Type y)
    {
        this->x = x;
        this->y = y;
    }

    Type x, y;

    void print_pair()
    {
        std::cout << "X: " << x << ", Y: " << y << "\n";
    }
};

// Lambda template
auto add_helper = [](auto a, auto b)
{
    using ResultType = decltype(a + b); // Determine the type of the result
    std::cout << typeid(ResultType).name() << ": " << add(a, b) << "\n";
};

template <typename T>
void process_vector(std::vector<T>& vec) {
    auto print = [](const T& value) {
        std::cout << value << " ";
    };

    std::for_each(vec.begin(), vec.end(), print);
    std::cout << "\n";
}

int main()
{
    // Function template
    std::cout << "Function templates\nint: " << add<int>(10, 5) << "\n";
    std::cout << "float: "<< add<float>(3.26, 1.8) << "\n";
    add_helper(3.55, 6.4);
    std::cout << "double: "<< add<double>(0.34, 1.67) << "\n\nVariable templates\n";

    // Variable template
    std::cout << "int: " << speed_of_light<int> << "\n";
    std::cout << "float: " << speed_of_light<float> << "\n";
    std::cout << "double: " << speed_of_light<double> << "\n\nClass templates\n";

    // Class templates
    auto numbers = Pair<float>(3.45, 2.33);
    numbers.print_pair();

    std::cout << std::endl;

    // More lambdas
    auto combine = []<typename T, typename U>(T a, U b) {
        return std::to_string(a) + std::to_string(b);
    };

    std::cout << combine(42, 3.14) << "\n"; // "423.14"

    std::vector<int> vec = {1, 2, 3, 4, 5};
    process_vector(vec); // Output: 1 2 3 4 5
}
