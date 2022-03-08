// task3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

struct Prisoner {
    char name[32];
    int ID;
    int timeLeft;

    void print() {
        std::cout << "Name: " << name << std::endl;
        std::cout << "ID: " << ID << std::endl;
        std::cout << "Years left: " << timeLeft << std::endl;
    }
};

struct Prison {
    char name[32];
    Prisoner prisoners[5];

    void sotrByTime() {
        for (int i = 0; i < 5; i++)
        {
            for (int j = 0; j < 5; j++)
            {
                if (prisoners[i].timeLeft<prisoners[j].timeLeft)
                {
                    std::swap(prisoners[i], prisoners[j]);
                }
            }
        }
    }
};

void printPrisonInfo(Prison& prison) {
    std::cout << prison.name << std::endl;
    for (int i = 0; i < 5; i++)
    {
        prison.prisoners[i].print();
    }
}

int main()
{
    Prison prison;
    std::cin.getline(prison.name, 32);
    for (int i = 0; i < 5; i++)
    {
        std::cin.getline(prison.prisoners[i].name, 32);
        std::cin >> prison.prisoners[i].ID;
        std::cin >> prison.prisoners[i].timeLeft;
        std::cin.ignore();
    }

    std::cout << "===========\n";

    printPrisonInfo(prison);
    prison.sotrByTime();
    std::cout << "===========\n";
    printPrisonInfo(prison);

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
