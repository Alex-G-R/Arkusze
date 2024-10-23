#include <iostream>
#include <vector>
#include <string>


class Food
{
    std::string food_name;
    float calories;
public:
    explicit Food(std::string food_name, float calories) : food_name(food_name), calories(calories) {}
    std::string print_name() { return food_name; }
    float getCalories() { return calories; }
};

class Bob
{
public:
    explicit Bob(std::string name, float starting_weight)
    {
        this->name = name;
        this->weight = starting_weight;
    }

    void Eat(Food& food)
    {
        std::cout << "BOB IS DEVOUERING THIS FOOD: " << food.print_name() << "\n";
        float weight_gained = (food.getCalories() / 7000);
        std::cout << "Bobi gained: " << weight_gained << "kg\n";
        this->weight += weight_gained;
        std::cout << "Current weight: " << this->weight << "kg\n\n\n";
        stomach.emplace_back(food);
    }
       
    void print_stomach()
    {
        std::cout << " ___bebuch___\n/\n";
        for (auto& food : stomach)
        {
            std::cout << "|->" << food.print_name() << " - " << food.getCalories() << "kcal\n";
        }
    }

    void hit_gym()
    {
        std::cout << "bobi hit the gym fr\n\n";
        this->weight = weight - 0.3;
    }

private:
    float weight;
    std::string name;
    std::vector<Food> stomach;
};

int main()
{
    Bob bobi("bobi", 94.5);

    Food PandaBistro("PANDA BISTRO", 2400.f);
    Food Kebab("80CM ROLLO", 900.f);

    
    bobi.Eat(PandaBistro);
    bobi.Eat(Kebab);
    bobi.hit_gym();
    bobi.print_stomach();
}
