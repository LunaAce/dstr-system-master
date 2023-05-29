#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <map>
#include <cctype>
#include <vector>
#include <cstdlib>

using namespace std;

#include "feedback.h"
#include "searchUni.h"


void admin_signin();
void customer_signin();
void customer_signup();
void admin_mainmenu();
void customer_mainmenu();

class User
{
public:
    string username;
    string password;
    string userType;

    User(const string &un, const string &pw, const string &type) : username(un), password(pw), userType(type) {}
};

void admin_signin()
{
    // Read user data from the CSV file and store it in a map
    map<string, string> admin_data;
    string line;
    ifstream login_file("login_data.csv");

    if (!login_file.is_open())
    {
        cerr << "Could not open the file - 'login_data.csv'" << endl;
        return;
    }

    while (getline(login_file, line))
    {
        istringstream iss(line);
        string username, password;
        string userType;
        getline(iss, username, ',');
        getline(iss, password, ',');
        getline(iss, userType, '\n');
        admin_data[username] = password;
    }
    login_file.close();

    int loginAttempt = 0;
    string inputUsername, inputPassword;

    while (loginAttempt < 5)
    {
        cout << "Please enter your username: ";
        cin >> inputUsername;
        cout << "Please enter your password: ";
        cin >> inputPassword;

        // Check if the input username and password match the stored data
        auto it = admin_data.find(inputUsername);
        if (it != admin_data.end() && it->second == inputPassword)
        {
            cout << "Welcome " << inputUsername << "!\n";
            admin_mainmenu();
            break;
        }
        else
        {
            cout << "Invalid login attempt. Please try again.\n";
        }

        loginAttempt++;
    }

    if (loginAttempt == 5)
    {
        cout << "Too many login attempts! The program will now terminate.\n";
    }

    cout << "Thank you for logging in.\n";
}

void customer_signin()
{
    // Read user data from the CSV file and store it in a map
    map<string, string> customer_data;
    string line;
    ifstream login_file("login_data.csv");
    ofstream output_file("current_user.csv");

    if (!login_file.is_open())
    {
        cerr << "Could not open the file - 'login_data.csv'" << endl;
        return;
    }

    while (getline(login_file, line))
    {
        istringstream iss(line);
        string username, password;
        string userType;
        getline(iss, username, ',');
        getline(iss, password, ',');
        getline(iss, userType, '\n');
        customer_data[username] = password;
    }
    login_file.close();

    int loginAttempt = 0;
    string inputUsername, inputPassword;

    while (loginAttempt < 5)
    {
        cout << "Please enter your username: ";
        cin >> inputUsername;
        cout << "Please enter your password: ";
        cin >> inputPassword;

        // Check if the input username and password match the stored data
        auto it = customer_data.find(inputUsername);
        if (it != customer_data.end() && it->second == inputPassword )
        {
            output_file << inputUsername << "\n";
            output_file.close();
            cout << "Welcome " << inputUsername << "!\n";
            customer_mainmenu();
            break;
        }
        else
        {
            cout << "Invalid login attempt. Please try again.\n";
        }

        loginAttempt++;
    }

    if (loginAttempt == 5)
    {
        cout << "Too many login attempts! The program will now terminate.\n";
    }

    cout << "Thank you for logging in.\n";
}

void customer_signup()
{

    // Create a new CSV file or open an existing one
    map<string, string> customer_data;
    ofstream output_file("login_data.csv", ios::out | ios::app);

    // Check if the input username and password match any existing data
    string line;
    ifstream input_file("login_data.csv");
    if (!input_file.is_open())
    {
        cerr << "Could not open the file - 'login_data.csv'" << endl;
        return;
    }

    while (getline(input_file, line))
    {
        istringstream iss(line);
        string username, password;
        string userType;
        getline(iss, username, ',');
        getline(iss, password, ',');
        getline(iss, userType, '\n');
        customer_data[username] = password;
    }
    input_file.close();

    int tryAttempt = 0;
    string inputUsername, inputPassword;

    while (tryAttempt < 5)
    {
        cout << "Enter a username: ";
        cin >> inputUsername;
        cout << "Enter a password: ";
        cin >> inputPassword;

        auto it = customer_data.find(inputUsername);
        if (it != customer_data.end() && it->second == inputPassword)
        {
            output_file.close();
            cout << "User " << inputUsername << " already exists. Please try again." << endl;
            tryAttempt++;
        }
        else
        {
            output_file << inputUsername << "," << inputPassword << ","
                        << "0"
                        << "\n";
            output_file.close();
            cout << "User " << inputUsername << " registered successfully!" << endl;
        
        }
    }

// Add the new user's data to the CSV file
}

void admin_mainmenu()
{

    // Display admin menu options
    while (true)
    {
        int choice;
        cout << "1. Display All User" << endl;
        cout << "2. Modify User Details" << endl;
        cout << "3. Delete User" << endl;
        cout << "4. Sort User" << endl;
        cout << "5. Reply Feedback" << endl;
        cout << "0. Exit" << endl;
        cout << "Enter your Choice: ";
        cin >> choice;

        switch (choice)
        {
        case 0:
            // exitProgram();
            break;

        case 1:
            break;

        case 2:
            break;

        case 3:
            break;

        case 4:
            break;

        default:
            cout << "Invalid choice. Please try again." << endl;
        }
    }
}

void customer_mainmenu()
{
    // Display customer menu options
    while (true)
    {
        int choice;
        cout << "1. Display All University" << endl;
        cout << "2. Search University" << endl;
        cout << "3. View Feedback" << endl;
        cout << "4. View Favourite" << endl;
        cout << "0. Exit" << endl;
        cout << "Enter your Choice: ";
        cin >> choice;

        switch (choice)
        {
        case 0:
            exitProgram();
            break;

        case 1:
            displayUni();
            break;

        case 2:
            displayTarget();
            break;

        case 3:
            readfeedback();
            break;

        case 4:
            viewfavourite();
            break;

        default:
            cout << "Invalid choice. Please try again." << endl;
        }
    }
}

void guest_mainmenu()
{
    // Display guest menu options

    while (true)
    {
        int choice;
        cout << "1. Display All University" << endl;
        cout << "2. Sort University" << endl;
        cout << "3. Search Univerity" << endl;
        cout << "4. Register" << endl;
        cout << "0. Exit" << endl;
        cout << "Enter your Choice: ";
        cin >> choice;

        switch (choice)
        {
        case 0:
            exitProgram();
            break;

        case 1:
            displayUni();
            break;

        case 2:
            break;

        case 3:
            displayTarget();

            break;

        case 4:
            customer_signup();
            break;

        default:
            cout << "Invalid choice. Please try again." << endl;
        }
    }
}


int main()
{
    // Initialize data structures and load user information
    // ...

    int choice;

    while (true)
    {
        cout << "1. Admin Sign In" << endl;
        cout << "2. Customer Sign In" << endl;
        cout << "3. Customer Sign Up" << endl;
        cout << "4. Browse as Guest" << endl;
        cout << "0. Exit" << endl;
        cout << "Enter your Choice: ";
        cin >> choice;

        switch (choice)
        {
        case 0:
            exitProgram();
            break;

        case 1:
            admin_signin();
            break;

        case 2:
            customer_signin();
            break;

        case 3:

            customer_signup();
            break;

        case 4:
            guest_mainmenu();
            break;

        default:
            cout << "Invalid choice. Please try again." << endl;
        }
    }
}

