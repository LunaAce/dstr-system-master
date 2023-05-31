
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <map>
#include <cctype>
#include <cstdlib>
#include <ctime>
#include <chrono>
#include <iomanip>

using namespace std;

#include "feedback.h"
#include "searchUni.h"
#include "modify_user.h"
#include "adminpage.h"
#include "navigateFeedback.h"
#include "linearsearchUni.h"
#include "exit.h"

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

// void admin_signin()
// {
//     string username, password;
//     string userType, lastLogin;
//     // Read user data from the CSV file and store it in a map
//     map<string, string> admin_data;
//     string line;

//     ifstream login_file("login_data.csv");

//     if (!login_file.is_open())
//     {
//         cerr << "Could not open the file - 'login_data.csv'" << endl;
//         return;
//     }

//     while (getline(login_file, line))
//     {
//         istringstream iss(line);
//         getline(iss, username, ',');
//         getline(iss, password, ',');
//         getline(iss, userType, ',');
//         getline(iss, lastLogin, '\n');
//         admin_data[username] = password;
//     }
//     login_file.close();

//     int loginAttempt = 0;
//     string inputUsername, inputPassword;

//     while (loginAttempt < 5)
//     {
//         cout << "Please enter your username: ";
//         cin >> inputUsername;
//         cout << "Please enter your password: ";
//         cin >> inputPassword;

//         // Check if the input username and password match the stored data
//         auto it = admin_data.find(inputUsername);
//         if (it != admin_data.end() && it->second == inputPassword)
//         {
//             cout << "Welcome " << inputUsername << "!\n";
//             admin_mainmenu();
//             break;
//         }
//         else
//         {
//             cout << "Invalid login attempt. Please try again.\n";
//         }

//         loginAttempt++;
//     }

//     if (loginAttempt == 5)
//     {
//         cout << "Too many login attempts! The program will now terminate.\n";
//     }

//     cout << "Thank you for logging in.\n";
// }

void admin_signin()
{
    // Read user data from the CSV file and store it in an array of strings
    const int MAX_USERS = 100; // Define the maximum number of users in the file
    string login_file_name = "login_data.csv";
    string login_data[MAX_USERS];
    ifstream login_file(login_file_name);

    if (!login_file.is_open())
    {
        cerr << "Could not open the file - " << login_file_name << endl;
        return;
    }

    string line;
    char delim = ','; // Define the delimiter to split by
    int user_count = 0;

    while (getline(login_file, line))
    {
        login_data[user_count++] = line;
        if (user_count >= MAX_USERS)
        {
            break;
        }
    }

    login_file.close();

    if (user_count == 0)
    {
        cout << "No login data found." << endl;
        return;
    }

    // Prompt the user to enter their username and password
    string inputUsername, inputPassword;
    int loginAttempt = 0;

    while (loginAttempt < 5)
    {
        cout << "Please enter your username: ";
        cin >> inputUsername;
        cout << "Please enter your password: ";
        cin >> inputPassword;

        // Check if the input username and password match the stored data
        bool login_successful = false;

        for (int i = 0; i < user_count; i++)
        {
            stringstream ss(login_data[i]);
            string field;
            string fields[4];
            int field_count = 0;

            while (getline(ss, field, delim))
            {
                fields[field_count++] = field;
                if (field_count >= 4)
                {
                    break;
                }
            }

            string username = fields[0];
            string password = fields[1];
            string userType = fields[2];

            if (username == inputUsername && password == inputPassword && userType == "1")
            {
                // Update the last login time for the user
                time_t now = time(0);
                tm *ltm = localtime(&now);

                stringstream time_ss;
                time_ss << std::setw(4) << 1900 + ltm->tm_year << "-"
                        << std::setfill('0') << std::setw(2) << 1 + ltm->tm_mon << "-"
                        << std::setw(2) << ltm->tm_mday;

                string time_str = time_ss.str();
                fields[3] = time_str;

                // Write the modified contents back to the file
                login_data[i] = fields[0] + delim + fields[1] + delim + fields[2] + delim + fields[3];
                ofstream login_file_out(login_file_name);

                if (!login_file_out.is_open())
                {
                    cerr << "Could not open the file - " << login_file_name << endl;
                    return;
                }

                for (int j = 0; j < user_count; j++)
                {
                    login_file_out << login_data[j] << endl;
                }

                login_file_out.close();

                cout << "Welcome " << inputUsername << "!\n";
                // Call the customer main menu function here
                login_successful = true;
                admin_mainmenu();
                break;
            }
        }

        if (login_successful)
        {
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
    // Read user data from the CSV file and store it in an array of strings
    const int MAX_USERS = 100; // Define the maximum number of users in the file
    string login_file_name = "login_data.csv";
    string login_data[MAX_USERS];
    ifstream login_file(login_file_name);

    if (!login_file.is_open())
    {
        cerr << "Could not open the file - " << login_file_name << endl;
        return;
    }

    string line;
    char delim = ','; // Define the delimiter to split by
    int user_count = 0;

    while (getline(login_file, line))
    {
        login_data[user_count++] = line;
        if (user_count >= MAX_USERS)
        {
            break;
        }
    }

    login_file.close();

    if (user_count == 0)
    {
        cout << "No login data found." << endl;
        return;
    }

    // Prompt the user to enter their username and password
    string inputUsername, inputPassword;
    int loginAttempt = 0;

    while (loginAttempt < 5)
    {
        cout << "Please enter your username: ";
        cin >> inputUsername;
        cout << "Please enter your password: ";
        cin >> inputPassword;

        // Check if the input username and password match the stored data
        bool login_successful = false;

        for (int i = 0; i < user_count; i++)
        {
            stringstream ss(login_data[i]);
            string field;
            string fields[4];
            int field_count = 0;

            while (getline(ss, field, delim))
            {
                fields[field_count++] = field;
                if (field_count >= 4)
                {
                    break;
                }
            }

            string username = fields[0];
            string password = fields[1];
            string userType = fields[2];

            if (username == inputUsername && password == inputPassword && userType == "0")
            {
                // Update the last login time for the user
                time_t now = time(0);
                tm *ltm = localtime(&now);

                stringstream time_ss;
                time_ss << std::setw(4) << 1900 + ltm->tm_year << "-"
                        << std::setfill('0') << std::setw(2) << 1 + ltm->tm_mon << "-"
                        << std::setw(2) << ltm->tm_mday;

                string time_str = time_ss.str();
                fields[3] = time_str;

                // Write the modified contents back to the file
                login_data[i] = fields[0] + delim + fields[1] + delim + fields[2] + delim + fields[3];
                ofstream login_file_out(login_file_name);

                if (!login_file_out.is_open())
                {
                    cerr << "Could not open the file - " << login_file_name << endl;
                    return;
                }

                for (int j = 0; j < user_count; j++)
                {
                    login_file_out << login_data[j] << endl;
                }

                login_file_out.close();

                cout << "Welcome " << inputUsername << "!\n";
                // Call the customer main menu function here
                login_successful = true;
                customer_mainmenu();
                break;
            }
        }

        if (login_successful)
        {
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
    string username, password;
    string userType, lastLogin;
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
        getline(iss, username, ',');
        getline(iss, password, ',');
        getline(iss, userType, ',');
        getline(iss, lastLogin, '\n');
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
        if (it != customer_data.end() && it->second == inputPassword && userType == "0")
        {
            output_file.close();
            cout << "User " << inputUsername << " already exists. Please try again." << endl;
            tryAttempt++;
        }
        else
        {
            cout << "User " << inputUsername << " registered successfully!\n"
                 << endl;
            break;
        }
    }

    // Add the new user's data to the CSV file
    output_file << inputUsername << "," << inputPassword << ","
                << "0"
                << ",last_login"
                << "\n";
    output_file.close();
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
        cout << "4. Navigate Feedback" << endl;
        cout << "5. Reply Feedback" << endl;
        cout << "6. Top 10 favourite unviersity" << endl;
        cout << "0. Return to Sign In" << endl;
        cout << "Enter your Choice: ";
        cin >> choice;

        switch (choice)
        {
        case 0:
            return;
            // break;

        case 1:
            callDisplayAllUsers();
            break;

        case 2:
            callModifyUser();
            break;

        case 3:
            callDeleteInactiveUsers();
            break;

        case 4:
            navigateFeedback();
            break;
        case 5:
            replyFeedback();
            break;
        case 6:
            callSummarize();
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
        cout << "1. Sort University " << endl;
        cout << "2. Search University" << endl;
        cout << "3. View Feedback" << endl;
        cout << "4. View Favouritrae" << endl;
        cout << "0. Return to Sign In" << endl;
        cout << "Enter your Choice: ";
        cin >> choice;

        switch (choice)
        {
        case 0:
            return;

        case 1:
            registered_sort();
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
        cout << "2. Sort University (Insertion Sort)" << endl;
        cout << "3. Sort Unviversity (Quick Sort)" << endl;
        cout << "4. Search Univerity (Binary Search)" << endl;
        cout << "5. Search Univerity (Linear Search)" << endl;
        cout << "6. Register" << endl;
        cout << "0. Return to Sign In" << endl;
        cout << "Enter your Choice: ";
        cin >> choice;

        switch (choice)
        {
        case 0:
            return;

        case 1:
            displayUni();
            break;

        case 2:
            displayInsertionSort();
            break;

        case 3:
            displaySortedUni();
            break;

        case 4:
            displayTarget();
            break;
        case 5:
            displayLinearTarget();
            break;

        case 6:
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
