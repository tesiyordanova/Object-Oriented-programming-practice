// task.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <cstring>

struct BookShelf {
    Book shelf[20];
    unsigned int currentSize =0;

    void readFile(std::ifstream& inputFile) {
        inputFile.open("bookShelf.txt", std::ios::in);
        
        while (inputFile.eof())
        {
            Book temp;
            temp.readFile(inputFile);
            shelf[currentSize];;
            currentSize++;
        }
        

    }



};


struct Book {
    char genre[16];
    char name[128];
    double price;
    char author[64];

    void createBook() {
        std::cout << "Genre of book: ";
        std::cin.getline(genre, 16);
        std::cout << "Name of book: ";
        std::cin.getline(name, 128);
        std::cout << "Price of book: ";
        std::cin >> price;
        std::cout << "Author of book: ";
        std::cin.ignore();
        std::cin.getline(author, 64);

    }

    void printBook() {
        std::cout << "Genre of book: " << genre << std::endl;
        std::cout << "Name of book: " << name << std::endl;
        std::cout << "Price of book: " << price << std::endl;
        std::cout << "Author of book: " << author << std::endl;
    }

    void writeInFile(std::ofstream &outputFile) {
        outputFile.open("book.txt");

        if (!outputFile.is_open())
        {
            std::cout << "The file cannot be opened for reading!\n";
            return;
        }
        
        if (!outputFile)
        {
            std::cout << "The stream is not good" << std::endl;
            return;
        }

        /*outputFile << "{" << genre << "%"
            << name << "%"
            << price << "%"
            << author << "}" << std::endl;*/
        outputFile << genre << "\n"
            << name << "\n"
            << price << "\n"
            << author << std::endl;

        outputFile.close();
    }
    
    void readFile(std::ifstream& inputFile) {
        inputFile.open("book.txt", std::ios::in);
        if (!inputFile.is_open())
        {
            std::cout << "The file cannot be opened for reading!\n";
            return;
        }

        if (inputFile.eof())
        {
            std::cout << "End of file" << std::endl;
            return;
        }

        if (!inputFile)
        {
            std::cout << "The stream is not good"<<std::endl;
            return;
        }

        char buffer[256];
        inputFile.getline(buffer, 256);
        strcpy_s(genre, 16, buffer);
        inputFile.getline(buffer, 256);
        strcpy_s(name, 128, buffer);
        inputFile >> price;
        inputFile.ignore();
        inputFile.getline(buffer, 256);
        strcpy_s(author, 64, buffer);
       
        inputFile.close();
    }

};

int main()
{
    Book book1;
    book1.createBook();
    std::cout << "----------" << std::endl;
    std::cout << "From console\n";
    book1.printBook();
    std::cout << "----------" << std::endl;
    std::ofstream outputFile;
    book1.writeInFile(outputFile);

    std::cout << "From file\n";
    std::ifstream inputFile;
    book1.readFile(inputFile);
    book1.printBook();
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
//


