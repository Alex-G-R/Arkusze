#include <iostream>
#include <vector>
#include <string>


class Food
{
    std::string food_name;
public:
    explicit Food(std::string food_name) : food_name(food_name) {}
    std::string print_name() { return food_name; }
};

class Bob
{
public:
    explicit Bob(std::string name)
    {
        this->name = name;
    }

    void Eat(Food& food)
    {
        std::cout << "BOB IS DEVOUERING THIS FOOD: " << food.print_name() << "\n";
        stomach.emplace_back(food);
    }
       
    void print_stomach()
    {
        std::cout << " ___bebuch____\n/\n";
        for (auto& food : stomach)
        {
            std::cout << "|->" << food.print_name() << "\n";
        }
    }

private:
    std::string name;
    std::vector<Food> stomach;
};

int main()
{
    Bob bobi("bobi");

    Food PandaBistro("PANDA BISTROOO, SUPA KLIENT");
    Food Kebab("30CM BULAAAA");

    bobi.Eat(PandaBistro);
    bobi.Eat(Kebab);
    bobi.print_stomach();
}