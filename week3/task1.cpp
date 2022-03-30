// task1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <cstring>

enum Type {
    dummy = 0,
    dog,
    cat,
    rabbit,
};

class Animal {
private:
    Type type;
    char name[32];
    int age;
    char gender;

public:
   

    void setType(Type type) {
        this->type = type;
    }
    void setName(const char* name) {
        strcpy_s(this->name, 32, name);
    }

    void setAge(int age) {
        this->age = age;
    }

    void setGender(char gender) {
        this->gender = gender;
    }
    
    const char* getName() const
    {
        return this->name;
    }

    int getAge() const{
        return this->age;
    }

    char getGender() const{
        return this->gender;
    }

    const Type& getType() const {
        return this->type;
    }

    Animal() {
        setType(dummy);
        setName("");
        setAge(0);
        setGender('M');
    }

    Animal(Type type, const char* name, int age, char gender) {
        setType(type);
        setName(name);
        setAge(age);
        setGender(gender);
    }

    void AnimalToBinary() {
        std::ofstream stream("Animal.txt", std::ios::binary | std::ios::app);
        if (!stream.is_open())
        {
            std::cout << "File is not open!" << std::endl;
            return;
        }
        if (!stream)
        {
            std::cout << "Stream is not good!" << std::endl;
            return;
        }

        stream.write((char*)&type, sizeof(type));
        stream.write(name, sizeof(name));
        stream.write((char*)&age, sizeof(age));
        stream.write((char*)&gender, sizeof(gender));

        stream.close();
    }

    void BinaryToAnimal() {
        std::ifstream stream("Animal.txt", std::ios::binary);
        if (!stream.is_open())
        {
            std::cout << "File is not open!" << std::endl;
            return;
        }
        if (!stream)
        {
            std::cout << "Stream is not good!" << std::endl;
            return;
        }

        stream.read((char*)&type, sizeof(type));
        stream.read(name, sizeof(name));
        stream.read((char*)&age, sizeof(age));
        stream.read((char*)&gender, sizeof(gender));

        stream.close();
    }

    void printAnimal() {
        std::cout << type << std::endl
            << name << std::endl
            << age << std::endl
            << gender << std::endl;
    }
};

int main()
{
    int type;
    std::cin >> type;
    char name[32];
    std::cin.ignore();
    std::cin.getline(name, 32);
    int age;
    std::cin >> age;
    char gender;
    std::cin >> gender;

    Animal animal((Type)type, name, age, gender);
    animal.AnimalToBinary();
    Animal animalTest;
    animalTest.BinaryToAnimal();
    animalTest.printAnimal();


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
