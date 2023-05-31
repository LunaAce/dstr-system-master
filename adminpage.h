#ifndef USERLIST_H
#define USERLIST_H

#include <string>
#include <iostream>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <unordered_map>
#include <ctime>
#include <chrono>
#include <iomanip>

const int MAX_LOGIN_DATA = 100; // Maximum number of login data entries

struct LoginData
{
    string username;
    string password;
    string userType;
    string lastLogin;
};

struct UserData
{
    string username;
    string university;
};

class UserList
{

public:
    UserList();

    void addUser(string username, string password, string lastLogin);
    void displayUsers(const UserList &userList);
    void deleteInactiveUsers();
};

int readLoginData(LoginData loginData[], const string &filename)
{
    ifstream file(filename);
    if (!file)
    {
        cerr << "Failed to open the file: " << filename << endl;
        return 0;
    }

    int numEntries = 0;
    string line;
    while (getline(file, line))
    {
        istringstream iss(line);
        string username, password, userType, lastLogin;

        if (getline(iss, username, ',') &&
            getline(iss, password, ',') &&
            getline(iss, userType, ',') &&
            getline(iss, lastLogin))
        {
            loginData[numEntries].username = username;
            loginData[numEntries].password = password;
            loginData[numEntries].userType = userType;
            loginData[numEntries].lastLogin = lastLogin;
            numEntries++;

            if (numEntries >= MAX_LOGIN_DATA)
            {
                cerr << "Maximum number of login data entries reached. Some entries may have been skipped."
                     << endl;
                break;
            }
        }
        else
        {
            cerr << "Invalid login data entry: " << line << endl;
        }
    }

    return numEntries;
}

int readCSV(const string &filename, UserData data[], int maxDataSize)
{
    ifstream file(filename);

    if (!file)
    {
        cout << "Failed to open the file: " << filename << endl;
        return 0;
    }

    string line;
    int dataSize = 0;
    while (getline(file, line) && dataSize < maxDataSize)
    {
        stringstream ss(line);
        string username, university;

        if (getline(ss, username, ',') && getline(ss, university))
        {
            data[dataSize].username = username;
            data[dataSize].university = university;
            dataSize++;
        }
    }

    file.close();
    return dataSize;
}

// Function to perform quicksort
void quickSort(UserData arr[], int left, int right)
{
    int i = left;
    int j = right;
    string pivot = arr[(left + right) / 2].university;

    while (i <= j)
    {
        while (arr[i].university < pivot)
            i++;
        while (arr[j].university > pivot)
            j--;

        if (i <= j)
        {
            swap(arr[i], arr[j]);
            i++;
            j--;
        }
    }

    if (left < j)
        quickSort(arr, left, j);
    if (i < right)
        quickSort(arr, i, right);
}

// Function to count the frequency of each university
unordered_map<string, int> countFrequency(UserData arr[], int size)
{
    unordered_map<string, int> frequencyMap;
    for (int i = 0; i < size; i++)
    {
        frequencyMap[arr[i].university]++;
    }
    return frequencyMap;
}

// Function to print the top 10 repeated universities
void printTop10Repeated(UserData arr[], int size)
{
    unordered_map<string, int> frequencyMap = countFrequency(arr, size);
    const int ARRAY_SIZE = 100;
    pair<string, int> sortedFreq[ARRAY_SIZE];
    int index = 0;
    for (const auto &pair : frequencyMap)
    {
        sortedFreq[index++] = pair;
    }

    sort(sortedFreq, sortedFreq + index, [](const auto &a, const auto &b)
         { return a.second > b.second; });

    cout << "Top 10 Repeated Universities:\n";
    int count = 0;
    for (int i = 0; i < index; i++)
    {
        cout << "University: " << sortedFreq[i].first << endl;
        cout << "Saved: " << sortedFreq[i].second << endl;
        cout << endl;
        count++;
        if (count == 10)
        {
            break;
        }
    }
}

void deleteInactiveUsers(LoginData loginData[], int &numEntries)
{
    const int INACTIVE_THRESHOLD = 90; // Number of days for considering a user as inactive

    auto currentDate = std::chrono::system_clock::now();
    for (int i = 0; i < numEntries; i++)
    {
        std::istringstream iss(loginData[i].lastLogin);
        std::tm lastLoginDate = {};
        iss >> std::get_time(&lastLoginDate, "%Y-%m-%d");

        std::chrono::system_clock::time_point lastLoginTime = std::chrono::system_clock::from_time_t(std::mktime(&lastLoginDate));
        std::chrono::duration<double> diff = currentDate - lastLoginTime;
        int daysSinceLastLogin = std::chrono::duration_cast<std::chrono::hours>(diff).count() / 24;

        if (daysSinceLastLogin > INACTIVE_THRESHOLD)
        {
            // User is inactive, delete the user by shifting remaining entries
            for (int j = i; j < numEntries - 1; j++)
            {
                loginData[j] = loginData[j + 1];
            }
            numEntries--;
            i--; // Decrement i to reprocess the current index in the shifted array
        }
    }
}

void printMenu()
{
    cout << "Menu:" << endl;
    cout << "1. Display all users" << endl;
    cout << "2. Delete inactive users" << endl;
    cout << "3. Summarize favorites" << endl;
    cout << "4. Exit" << endl;
    cout << "Enter your choice: ";
}

void displayAllUsers(const LoginData loginData[], int numEntries)
{

    for (int i = 0; i < numEntries; i++)
    {
        cout << "User: " << loginData[i].username << endl;
        cout << "Password: " << loginData[i].password << endl;
        cout << "Last Login: " << loginData[i].lastLogin << endl;
        cout << endl;
    }
}

void updateCSV(const std::string &filename, LoginData loginData[], int numEntries)
{
    std::ofstream outputFile(filename);
    if (!outputFile)
    {
        std::cout << "Failed to open the CSV file." << std::endl;
        return;
    }

    //outputFile << "username,lastLogin" << std::endl;

    for (int i = 0; i < numEntries; i++)
    {
        outputFile << loginData[i].username << "," << loginData[i].password << "," << loginData[i].userType << "," << loginData[i].lastLogin << std::endl;
    }

    outputFile.close();
}

void callDisplayAllUsers()
{
    const string filename = "login_data.csv";
    LoginData loginData[MAX_LOGIN_DATA];

    int numEntries = readLoginData(loginData, filename);
    cout << "Displaying all users:" << endl;
    displayAllUsers(loginData, numEntries);
}

void callDeleteInactiveUsers()
{
    const string filename = "login_data.csv";
    LoginData loginData[MAX_LOGIN_DATA];

    int numEntries = readLoginData(loginData, filename);
    cout << "Deleting inactive users..." << endl;
    deleteInactiveUsers(loginData, numEntries);
    updateCSV(filename, loginData, numEntries);
    cout << "Inactive users deleted." << endl;
}

void callSummarize()
{
    cout << "Summarizing favorites:" << endl;
    {
        const string filename = "favourite.csv";
        const int MAX_DATA_SIZE = 100;
        UserData userData[MAX_DATA_SIZE];
        int dataSize = readCSV(filename, userData, MAX_DATA_SIZE);

        // Sort the data by university
        quickSort(userData, 0, dataSize - 1);

        // Print the top 10 repeated universities
        printTop10Repeated(userData, dataSize);
    }
}

#endif
