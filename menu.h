#include <iostream>
#include <fstream>
#include <string>



void uni_menu()
{
    while (true)
    {
        int choice;
        cout << "1. Save to Favourite" << endl;
        cout << "2. Write Feedback" << endl;
        cout << "0. Back" << endl;
        cout << "Enter your Choice: ";
        cin >> choice;

        switch (choice)
        {
        case 0:

            break;

        case 1:
            savefavourite();
            break;

        case 2:
            giveFeedback();
            break;
        }
    }
}
