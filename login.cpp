#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <cctype>
#include <sstream>

using namespace std;

void admin_signin();
void customer_signin();
void customer_signup();
void admin_mainmenu();
void customer_mainmenu();
void display_feedback();
void display_favorites();

const int MAX_RETRIES = 3;

class User
{
public:
    string username;
    string password;

    User(const string &un, const string &pw) : username(un), password(pw) {}
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
        getline(iss, username, ',');
        getline(iss, password, '\n');
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

    if (!login_file.is_open())
    {
        cerr << "Could not open the file - 'login_data.csv'" << endl;
        return;
    }

    while (getline(login_file, line))
    {
        istringstream iss(line);
        string username, password;
        getline(iss, username, ',');
        getline(iss, password, '\n');
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
        if (it != customer_data.end() && it->second == inputPassword)
        {
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
    // Implement customer sign-up functionality
    // string username, password;
    // cout << "Enter a username: ";
    // getline(cin, username);
    // cout << "Enter a password: ";
    // getline(cin, password);
    // ofstream userFile(USER_FILE, ios::app);
    // userFile << username << "," << password << endl;
    // userFile.close();
    // cout << "Registration successful!" << endl;
}

void admin_mainmenu()
{
    // Display admin menu options
}

void customer_mainmenu()
{
    // Display customer menu options
    int choice;
    cout << "1. Display All University" << endl;
    cout << "2. Search University" << endl;
    cout << "3. View Feedback" << endl;
    cout << "0. Exit" << endl;
    cout << "Enter your Choice: ";
    cin >> choice;
}

void display_feedback()
{
    // Display customer feedback
}

void display_favorites()
{
    // Display customer favorites
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
        cout << "0. Exit" << endl;
        cout << "Enter your Choice: ";
        cin >> choice;

        switch (choice)
        {
        case 0:
            cout << "Exiting..." << endl;
            return 0;

        case 1:
            admin_signin();
            break;

        case 2:
            customer_signin();
            break;

        default:
            cout << "Invalid choice. Please try again." << endl;
        }
    }
}