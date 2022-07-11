// task1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

class Car {
private:
    char number[256];
    char brand[256];
    char model[256];
    char color[256];
public:
    Car() {
        this->number[0] = '\0';
        this->brand[0] = '\0';
        this->model[0] = '\0';
        this->color[0] = '\0';
    };
    Car(const char* number, const char* brand, const char* model, const char* color) {
        strcpy_s(this->number, number);
        strcpy_s(this->brand, brand);
        strcpy_s(this->model, model);
        strcpy_s(this->color, color);
    }
    Car(const Car& other) {
        strcpy_s(this->number, other.number);
        strcpy_s(this->brand, other.brand);
        strcpy_s(this->model, other.model);
        strcpy_s(this->color, other.color);
    }

    const char* getNumber() {
        return this->number;
    }

    const char* getBrand() {
        return this->brand;
    }

    const char* getModel() {
        return this->model;
    }

    const char* getColor() {
        return this->color;
    }
    
    void setNumber(const char* number) {
        strcpy_s(this->number, number);
    }

    void setBrand(const char* brand) {
        strcpy_s(this->brand, brand);
    }

    void setModel(const char* model) {
        strcpy_s(this->model, model);
    }

    void setColor(const char* color) {
        strcpy_s(this->color, color);
    }

    bool numPalinrom() {
        char number[4];
        int size = 0;
        for (size_t i = 0;this->number[i] !='\0'; i++)
        {
            if (number[i]>='0' && number[i]<='9')
            {
                number[size++] = this->number[i];
            }
        }
        for (size_t i = 0; i<=size/2; i++)
        {
            if (number[i]!=number[size-1-i])
            {
                return false;
            }
        }
        return true;
    }
};


int main()
{
    Car carOne = { "CA1221BH", "Opel", "Vectra", "Red" };
    std::cout<<std::boolalpha<<carOne.numPalinrom();
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
