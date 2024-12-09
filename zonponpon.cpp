#include <iostream>
#include <vector>

void one()
{
    int x, y;
    std::cout << "Podaj X: "; std::cin >> x;
    std::cout << "Podaj Y: "; std::cin >> y;

    std::cout << "suma: " << x + y << "\nroznica: " << x - y << "\niloczyn: " << x * y << "\niloraz: " << x/y << "\n";
    std::cout << "\n\n\n";
}

void two()
{
    int x, y;
    std::cout << "Podaj X: "; std::cin >> x;
    std::cout << "Podaj Y: "; std::cin >> y;

    if (x > y)
    {
        std::cout << "x > y \n";
    }
    else if (y > x)
    {
        std::cout << "y > x \n";
    }
    else
    {
        std::cout << "rowne som ino roz\n";
    }
    std::cout << "\n\n\n";
}

void three()
{
    int x, y;
    std::cout << "Podaj X: "; std::cin >> x;
    std::cout << "Podaj Y: "; std::cin >> y;

    if (x % 2 && y % 2)
    {
        std::cout << "liczy som ino obie parzyste rom pom pom\n";
    }
    else
    {
        std::cout << "liczy NIE som ino obie parzyste rom pom pom\n";
    }
    std::cout << "\n\n\n";
}

void four()
{
    for (size_t i = 1; i < 11; i++)
    {
        std::cout << " " << i;
    }
    std::cout << "\n\n\n";
}

void five()
{
    int x, y;
    std::cout << "Podaj X: "; std::cin >> x;
    std::cout << "Podaj Y: "; std::cin >> y;

    std::cout << "AND: " << (x & y) << "\n";
    std::cout << "OR: " << (x | y) << "\n";
    std::cout << "XOR: " << (x ^ y) << "\n";
    std::cout << "\n\n\n";
}

int main()
{
    std::cout << "wpisz numer, zadanie 1, 2, 3, 4, 5: ";
    short decision;
    std::cin >> decision;

    if (decision == 1)
    {
        one();
        main();
    }
    else if (decision == 2)
    {
        two();
        main();
    }
    else if (decision == 3)
    {
        three();
        main();
    }
    else if (decision == 4)
    {
        four();
        main();
    }
    else if (decision == 5)
    {
        five();
        main();
    }
    else
    {
        std::cout << "zla opcja nice \n";
        main();
    }
}

