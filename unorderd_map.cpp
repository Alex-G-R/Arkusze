#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>
#include <variant>

struct Vector2I
{
    int x, y;
};

struct Vector3I
{
    int x, y, z;
};

// Define a custom struct for Color
struct Color {
    Vector3I rgb;
};

// Define a custom struct for Size
struct Size {
    Vector2I dimensions;
};

// Define a variant that includes int, double, string, Color, and Size
using PropertyValue = std::variant<int, double, std::string, Color, Size>;

// Class to manage property blocks
class PropertyBlock {
public:
    // Constructor for initializing properties in one line
    // variable number of arguments in constructors or functions. - explore further later 
    PropertyBlock(std::initializer_list<std::pair<std::string, PropertyValue>> init) {
        for (const auto& [key, value] : init) {
            properties[key] = value;
        }
    }

    // Print all properties
    void printProperties() const {
        for (const auto& [key, value] : properties) {

            if(key == "width")
            {
                std::cout << key << ": ";

                // Use std::visit to access the variant's value
                // [&] -> Capture the whole local scope by reference
                // auto&& arg -> forwarding reference binding to lvalue and rvalue
                std::visit([&](auto&& arg) {
                    // Handle each type accordingly
                    // std::is_same_v<T, U> -> Check if they are the sane type | true/false
                    // decltype(argument) -> deduce the type of the argument, simply look at it
                    // std::decay_t<T> -> 'decays' certaint qualifires like const, volitile this ensures that you will compare int with int not an const int& with int
                    // if constexpr -> Comppiler decides at runtime witch code bit to use depending on the args of the if
                    if constexpr (std::is_same_v<std::decay_t<decltype(arg)>, int>) {
                        std::cout << arg; // Handle int
                    } else if constexpr (std::is_same_v<std::decay_t<decltype(arg)>, double>) {
                        std::cout << arg; // Handle double
                    } else if constexpr (std::is_same_v<std::decay_t<decltype(arg)>, std::string>) {
                        std::cout << arg; // Handle string
                    } else if constexpr (std::is_same_v<std::decay_t<decltype(arg)>, Color>) {
                        std::cout << "Color(" << arg.rgb.x << ", " << arg.rgb.y << ", " << arg.rgb.z << ")"; // Handle Color
                    } else if constexpr (std::is_same_v<std::decay_t<decltype(arg)>, Size>) {
                        std::cout << "Size(" << arg.dimensions.x << ", " << arg.dimensions.y << ")"; // Handle Size
                    }
                }, value);

                std::cout << std::endl;
            }


        }
    }

private:
    std::unordered_map<std::string, PropertyValue> properties;
};

int main() {
    // Define all properties, including custom types
    PropertyBlock style {
            {"width", 100},
            {"opacity", 0.75},
            {"background-color", Color{255, 200, 100}},  // Custom Color type
            {"font-size", 16},
            {"dimensions", Size{1024, 768}}               // Custom Size type
    };

    // Print all properties
    style.printProperties();


    return 0;
}
