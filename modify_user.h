#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <map>



class User1
{
public:
    string username;
    string password;
    string userType;
    User1* next;
    User1* prev; // Pointer to the previous node

    User1() : next(nullptr), prev(nullptr) {}
    User1(const string& un, const string& pw, const string& type) : username(un), password(pw), userType(type), next(nullptr), prev(nullptr) {}
};

class UserList1
{
private:
    User1* head;
    User1* tail; // Pointer to the tail node

public:
    UserList1() : head(nullptr), tail(nullptr) {}

    void addUser(const string& username, const string& password, const string& userType)
    {
        User1* newUser = new User1(username, password, userType);

        if (head == nullptr)
        {
            head = newUser;
            tail = newUser;
        }
        else
        {
            tail->next = newUser;
            newUser->prev = tail;
            tail = newUser;
        }
    }

    User1* findUser(const string& username)
    {
        User1* temp = head;
        while (temp != nullptr)
        {
            if (temp->username == username)
            {
                return temp;
            }
            temp = temp->next;
        }
        return nullptr;
    }

    void displayUserList()
    {
        cout << "List of users:" << endl;

        User1* temp = head;
        while (temp != nullptr)
        {
            // Exclude admin users (usertype = 1)
            if (temp->userType != "1")
            {
                cout << "Username: " << temp->username << endl;
            }
            temp = temp->next;
        }
    }

    void modifyUser(const string& username, const string& newUsername, const string& newPassword)
    {
        User1* user = findUser(username);
        if (user == nullptr)
        {
            cout << "User not found!" << endl;
            return;
        }

        if (user->userType == "1")
        {
            cout << "Admin account cannot be modified!" << endl;
            return;
        }

        user->username = newUsername;
        user->password = newPassword;
        cout << "User details modified successfully!" << endl;
        displayUserDetails(user);
    }

    void modifyUsername(const string& username, const string& newUsername)
    {
        User1* user = findUser(username);
        if (user == nullptr)
        {
            cout << "User not found!" << endl;
            return;
        }

        if (user->userType == "1")
        {
            cout << "Admin account cannot be modified!" << endl;
            return;
        }

        user->username = newUsername;
        cout << "Username modified successfully!" << endl;
        displayUserDetails(user);
    }

    void modifyPassword(const string& username, const string& newPassword)
    {
        User1* user = findUser(username);
        if (user == nullptr)
        {
            cout << "User not found!" << endl;
            return;
        }

        if (user->userType == "1")
        {
            cout << "Admin account cannot be modified!" << endl;
            return;
        }

        user->password = newPassword;
        cout << "Password modified successfully!" << endl;
        displayUserDetails(user);
    }

    void displayUserDetails(User1* user)
    {
        cout << "Updated user details:" << endl;
        cout << "Username: " << user->username << endl;
        cout << "Password: " << user->password << endl;
    }

    User1* getHead() const
    {
        return head;
    }

    ~UserList1()
    {
        User1* temp = head;
        while (temp != nullptr)
        {
            User1* nextUser = temp->next;
            delete temp;
            temp = nextUser;
        }
    }
};


void loadUserList(UserList1& userList)
{
    ifstream login_file("login_data.csv");
    if (!login_file.is_open())
    {
        cerr << "Could not open the file - 'login_data.csv'" << endl;
        return;
    }

    string line;
    while (getline(login_file, line))
    {
        istringstream iss(line);
        string username, password, userType;
        getline(iss, username, ',');
        getline(iss, password, ',');
        getline(iss, userType, '\n');
        userList.addUser(username, password, userType);
    }

    login_file.close();
}

void writeUserList(const UserList1& userList)
{
    ofstream output_file("login_data.csv", ios::out | ios::trunc);
    if (!output_file.is_open())
    {
        cerr << "Could not open the file - 'login_data.csv'" << endl;
        return;
    }

    User1* temp = userList.getHead();
    while (temp != nullptr)
    {
        output_file << temp->username << "," << temp->password << "," << temp->userType << endl;
        temp = temp->next;
    }

    output_file.close();
}

void modifyUserOption(UserList1& userList, const string& username)
{
    cout << "Select an option to modify the user:" << endl;
    cout << "1. Modify username" << endl;
    cout << "2. Modify password" << endl;

    int option;
    cin >> option;

    string newUsername, newPassword;

    switch (option)
    {
        case 1:
            cout << "Enter the new username: ";
            cin >> newUsername;
            userList.modifyUsername(username, newUsername);
            break;
        case 2:
            cout << "Enter the new password: ";
            cin >> newPassword;
            userList.modifyPassword(username, newPassword);
            break;
        default:
            cout << "Invalid option!" << endl;
            break;
    }
}

void callModifyUser()
{
    UserList1 userList;
    loadUserList(userList);

    userList.displayUserList();

    string username;

    cout << "Enter the username to modify: ";
    cin >> username;

    User1* user = userList.findUser(username);
    if (user == nullptr)
    {
        cout << "User not found!" << endl;
        //return 0;
    }

    if (user->userType == "1")
    {
        cout << "Admin account cannot be modified!" << endl;
        //return 0;
    }

    modifyUserOption(userList, username);

    writeUserList(userList);

    //return 0;
}
