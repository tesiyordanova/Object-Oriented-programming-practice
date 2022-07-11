// task2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

class Word {
private:
    char* word;
    unsigned size;
public:
    Word() {
        this->word=nullptr;
        this->size = 0;
    }
    Word(const char* word) {
        if (word == nullptr)
        {
            this->word = nullptr;
            this->size = 0;
            std::cout << "unvalid argument";
            return;
        }
        int len = 0;
        for (; word[len] !='\0'; len++)
        {}
        this->word = new char[len + 1];
        if (this->word==nullptr)
        {
            std::cout << "cannot allocate memory";
            return;
        }
        for (size_t i = 0; i < len; i++)
        {
            this->word[i] = word[i];
        }
        this->size = len;
    }

    Word(const Word& other) {
        if (other.word!=nullptr)
        {
            this->word = new char[other.size + 1];
            if (this->word!=nullptr)
            {
                for (size_t i = 0; i < other.size; i++)
                {
                    this->word[i] = other.word[i];
                }
                this->size = other.size;
                return;
            }
            this->size = 0;
            std::cout << "cannot allocate memory";
            return;
        }
        this->word = nullptr;
        this->size = 0;
        std::cout << "cannot allocate memory";
        return;
    }
    ~Word() {
        if (this->word!=nullptr)
        {
            delete[] this->word;
        }
    }

    void addLetter(const char& end) {
        if (this->word!=nullptr)
        {
            char* word_copy = new char[this->size + 2];
            std::cout << "new size: " << this->size << std::endl;
            if (word_copy!=nullptr)
            {
                int i = 0;
                for (; i < this->size; i++)
                {
                    word_copy[i] = this->word[i];
                }
                std::cout << "new size: " << i << std::endl;
                word_copy[i] = end;
                delete[] this->word;
                this->word = word_copy;
                this->size++;
                std::cout << "final size: " << this->size << std::endl;
                return;
            }
            std::cout << "cannot allocate memory";
                return;
        }
        this->word = new char[2];
        if (this->word!=nullptr)
        {
            this->word[0] = end;
            this->size ++;
            return;
        }
        std::cout<<"cannot allocate memory";
        
    }
    void print() {
        for (size_t i = 0; i<this->size; i++)
        {
            std::cout << this->word[i];
        }
    }

    char findElement(const int& num) {
        if (this->word==nullptr || num>this->size)
        {
            std::cout << "null elements";
        }
        for (size_t i = 0; i < this->size; i++)
        {
           if (num-1 == i)
           {
              return this->word[i];
           }
        }
        
       
    }

    bool oneBiggerThanOder(const Word& other) {
        std::cout << this->size << " " << other.size;
        if (this->word == nullptr)
        {
            return false;
        }
        else if (other.word==nullptr)
        {
            return true;
        }
        if (this->size==other.size)
        {
            for (size_t i = 0; i < this->size; i++)
            {
                if (this->word[i] > other.word[i])
                {
                    return true;
                }
                else if (this->word[i] < other.word[i])
                {
                    return false;
                }
            }

        }
       
        return this->size > other.size;
        
        
    }
};

int main()
{
    Word word = {"cbbb"};

    int num = 3;
    std::cout << std::endl;
    std::cout << std::endl;
    std::cout<<word.findElement(num);

    std::cout << std::endl;
    std::cout << std::endl;
    Word second = { "bbbb"};
    std::cout<<std::boolalpha<<word.oneBiggerThanOder(second);

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
