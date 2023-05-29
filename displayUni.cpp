#include "search.h"
void menu()
{
    int choice;
    while (true)
    {
        std::cout << "Main Menu" << std::endl;
        std::cout << "1. Display All Universities Information." << std::endl;
        std::cout << "2. Quick Sort" << std::endl;  
        std::cout << "3. Binary Search" << std::endl;
        std::cout << "4. Exit" << std::endl;
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice)
        {
        case 1:
            displayUni();
            break;
        case 2:
            displaySortedUni();
            break;
        case 3:
            displayTarget();
            break;
        case 4:
            exitProgram();

        case 22:
            menu();
            break;
        default:
            std::cout << "Invalid choice. Please try again." << std::endl;
        }

        std::cout << std::endl;
    }
}



int main()
{
    menu();
    return 0;
}
