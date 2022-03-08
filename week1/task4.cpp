// task4.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

enum Genders {
    dummy=0,
    Male,
    Female
};

struct Doctor {
    char lastname[32];
    int yearsExperience;
    char hospital[32];
    Genders gender;

    void createDoctor() {
        int userInput;

        std::cout << "Enter name " << std::endl;
        std::cin.getline(lastname, 32);
        std::cout << "Enter years experience "<<std::endl;
        std::cin >> yearsExperience;
        std::cout << "Enter hospital" << std::endl;
        std::cin.ignore();
        std::cin.getline(hospital, 32);
        std::cout << "Enter gender(1 - male, 2 - female): "<<std::endl;
        std::cin >> userInput;
        gender = getDoctorGender(userInput);
        std::cin.ignore();
        
    }

    Genders getDoctorGender(int input)
    {
        switch (input)
        {
        case 1:
            return Male;
        case 2:
            return Female;
        default:
            return dummy;
        }
    }


    void printDoctorInfo() {
        std::cout<<"Name: " << lastname << std::endl;
        std::cout << "Years experience: " << yearsExperience << std::endl;
        std::cout << "Hospital: " << hospital << std::endl;
        std::cout << "Gender: " << gender << std::endl;
    }
     
    void changeName() {
        std::cout << "Enter new name: ";
        std::cin.getline(lastname, 32);
    }

    void changeHospital() {
        std::cout << "Enter new name: ";
        std::cin.getline(lastname, 32);
    }
};

int main()
{
    Doctor doctors[10];
    for (int i = 0; i < 10; i++)
    {
        doctors[i].createDoctor();
    }
    std::cout << "===========\n";
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            if (doctors[i].yearsExperience<doctors[j].yearsExperience)
            {
                std::swap(doctors[i], doctors[j]);
            }
        }
    }

    for (int i = 0; i < 10; i++)
    {
        doctors[i].printDoctorInfo();
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
