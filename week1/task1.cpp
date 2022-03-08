// task1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

struct Destination {
    char city[32];
    int kilometers;

    void print() {
        std::cout << city << " " << kilometers << std::endl;
    }
};

int main()
{
    Destination city1;
    std::cin.getline(city1.city, 32);
    std::cin >> city1.kilometers;
    std::cin.ignore();

    Destination city2;
    std::cin.getline(city2.city, 32);
    std::cin >> city2.kilometers;
    std::cin.ignore();

    std::cout << "The distance between " << city1.city << " and " << city2.city << " is: ";
    std::cout << city1.kilometers - city2.kilometers << std::endl;

    Destination cities[30];

    for (int i = 0; i < 30; i++)
    {
        std::cout << "Enter name of city: " << std::endl;
        std::cin.getline(cities[i].city, 32);

        std::cout << "Enter km: " << std::endl;
        std::cin >> cities[i].kilometers;
        std::cin.ignore();
    }
    for (int i = 0; i < 30; i++)
    {
        cities[i].print();
    }
    
    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
