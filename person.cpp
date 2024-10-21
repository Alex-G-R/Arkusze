#include <iostream>
#include <string>


class Person {
    std::string name;
    std::string surname;
    bool is_male;
public:
    /* Overloading construstor */
    Person(const std::string& name, const std::string& surname, bool is_male)
    {
        this->name = name;
        this->surname = surname;
        this->is_male = is_male;
    }
    Person(const std::string& name, const std::string& surname)
    {
        this->name = name;
        this->surname = surname;
        this->is_male = NULL;
    }

    void set_sex(bool is_male)
    {
        this->is_male = is_male;
    }

    void print_person()
    {
        if (this->is_male == NULL)
        {
            std::cout << "Person: " << name << " " << surname << "\n";
            return;
        }
        std::cout << "Person: " << name << " " << surname << ", is_male: " << is_male << "\n";
    }
};

int main()
{
    Person Alex("Alex", "Grabski", true);
    Person Bob("Bob", "Babinski");

    Alex.print_person();
    Bob.print_person();
}
