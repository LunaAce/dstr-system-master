#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <map>
#include <cstdlib>

using namespace std;

class User
{
public:
    string username;
    string password;
    string userType;

    User() {}
    User(const string& un, const string& pw, const string& type) : username(un), password(pw), userType(type) {}
};

void modifyUser(const string& username, const string& newUsername, const string& newPassword)
{
    // Read user data from the CSV file and store it in a map
    map<string, User> user_data;
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
        user_data[username] = User(username, password, userType);
    }
    login_file.close();

    // Check if the user is an admin
    auto it = user_data.find(username);
    if (it != user_data.end() && it->second.userType == "1")
    {
        cout << "Admin account cannot be modified!" << endl;
        return;
    }

    // Modify the user details
    it = user_data.find(username);
    if (it != user_data.end())
    {
        User& user = it->second;
        user.username = newUsername;
        user.password = newPassword;
        cout << "User details modified successfully!" << endl;
    }
    else
    {
        cout << "User not found!" << endl;
    }

    // Write the modified user data back to the CSV file
    ofstream output_file("login_data.csv", ios::out | ios::trunc);
    if (!output_file.is_open())
    {
        cerr << "Could not open the file - 'login_data.csv'" << endl;
        return;
    }

    for (const auto& pair : user_data)
    {
        output_file << pair.second.username << "," << pair.second.password << "," << pair.second.userType << endl;
    }

    output_file.close();
}

int main()
{
    string username, newUsername, newPassword;

    cout << "Enter the username to modify: ";
    cin >> username;

    // Read user data from the CSV file and check if the user is an admin
    ifstream login_file("login_data.csv");
    if (!login_file.is_open())
    {
        cerr << "Could not open the file - 'login_data.csv'" << endl;
        return 0;
    }

    bool isAdmin = false;
    string line;
    while (getline(login_file, line))
    {
        istringstream iss(line);
        string uname, password, userType;
        getline(iss, uname, ',');
        getline(iss, password, ',');
        getline(iss, userType, '\n');

        if (uname == username && userType == "1")
        {
            isAdmin = true;
            break;
        }
    }
    login_file.close();

    if (isAdmin)
    {
        cout << "Admin account cannot be modified!" << endl;
        return 0;
    }

    cout << "Enter the new username: ";
    cin >> newUsername;

    cout << "Enter the new password: ";
    cin >> newPassword;

    modifyUser(username, newUsername, newPassword);

    return 0;
}
