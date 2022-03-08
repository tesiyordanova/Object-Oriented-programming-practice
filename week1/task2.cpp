// task2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

enum Flavours {
    dummy = 0,
    Chokolate,
    Vanilla,
    Cream,
    Strawberry

};

struct IceCream {
    Flavours flavour;
    int gr;
    double price;

    void createIceCream() {
        int userInput;

        std::cout<<"Enter ice cream: " << std::endl;
        std::cout << "Enter flavour(1 - chocolate, 2 - vanilla, 3 - cream, 4 - strawberry): " << std::endl;
        std::cin >> userInput;
        flavour = getIceCreamFlavout(userInput);
        std::cout << "Enter grams: " << std::endl;
        std::cin >> gr;
        std::cout << "Enter price: " << std::endl;
        std::cin >> price;
    }

    Flavours getIceCreamFlavout(int input) {
        switch (input)
        {
           case 1:
            return Chokolate;
           case 2:
               return Vanilla;
           case 3:
               return Cream;
           case 4:
               return Strawberry;

        default:
            return dummy;
        }
    }

    void print() {
        std::cout << "Flavout: " << (Flavours)flavour << std::endl;
        std::cout << "Grams: " << gr << std::endl;
        std::cout << "Price: " << price << std::endl;
    }
};
                          


struct IceCreamFactory {
    IceCream iceCreams[4];

    void getCheapest() {
        IceCream cheap = iceCreams[0];

        for (int i = 0; i < 4; i++)
        {
            if (iceCreams[i].price<cheap.price)
            {
                cheap=iceCreams[i];
            }
        }

        cheap.print();
    }
};

int main()
{
    IceCreamFactory factory;

    for (int i = 0; i < 4; i++)
    {
        factory.iceCreams[i].createIceCream();

    }

    factory.getCheapest();
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
