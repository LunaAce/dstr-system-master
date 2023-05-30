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

class User {
public:
    std::string username;
    std::string password;
    std::string lastLogin;

    User* next;

    User(std::string username, std::string password, std::string lastLogin);
};

class UserList {
private:
    User* head;
    int size;

public:
    UserList();

    void addUser(std::string username, std::string password, std::string lastLogin);
    void displayUsers(const UserList& userList);
    void deleteInactiveUsers();
    User *getHead() const
    {
        return head;
    }
};

const int ARRAY_SIZE = 100;

struct UserData {
    std::string username;
    std::string university;
};

int readCSV(const std::string& filename, UserData data[], int maxDataSize) {
    std::ifstream file(filename);

    if (!file) {
        std::cout << "Failed to open the file: " << filename << std::endl;
        return 0;
    }

    std::string line;
    int dataSize = 0;
    while (std::getline(file, line) && dataSize < maxDataSize) {
        std::stringstream ss(line);
        std::string username, university;

        if (std::getline(ss, username, ',') && std::getline(ss, university)) {
            data[dataSize].username = username;
            data[dataSize].university = university;
            dataSize++;
        }
    }

    file.close();
    return dataSize;
}


// Function to perform quicksort
void quickSort(UserData arr[], int left, int right) {
    int i = left;
    int j = right;
    std::string pivot = arr[(left + right) / 2].university;

    while (i <= j) {
        while (arr[i].university < pivot)
            i++;
        while (arr[j].university > pivot)
            j--;

        if (i <= j) {
            std::swap(arr[i], arr[j]);
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
std::unordered_map<std::string, int> countFrequency(UserData arr[], int size) {
    std::unordered_map<std::string, int> frequencyMap;
    for (int i = 0; i < size; i++) {
        frequencyMap[arr[i].university]++;
    }
    return frequencyMap;
}

// Function to print the top 10 repeated universities
void printTop10Repeated(UserData arr[], int size) {
    std::unordered_map<std::string, int> frequencyMap = countFrequency(arr, size);

    std::pair<std::string, int> sortedFreq[ARRAY_SIZE];
    int index = 0;
    for (const auto& pair : frequencyMap) {
        sortedFreq[index++] = pair;
    }

    std::sort(sortedFreq, sortedFreq + index, [](const auto& a, const auto& b) {
        return a.second > b.second;
    });

    std::cout << "Top 10 Repeated Universities:\n";
    int count = 0;
    for (int i = 0; i < index; i++) {
        std::cout << "University: " << sortedFreq[i].first << std::endl;
        std::cout << "Saved: " << sortedFreq[i].second << std::endl;
        std::cout << std::endl;
        count++;
        if (count == 10) {
            break;
        }
    }
}

void displayAdminMenu(UserList& userList, UserData users[], int numUsers) {
    int choice;

        std::cout << "Admin Home Page\n";
        std::cout << "1. Display Users\n";
        std::cout << "2. Delete Inactive Users\n";
        std::cout << "3. Summarize Favourite\n";
        std::cout << "4. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice)
        {
        case 1:
            userList.displayUsers(userList);
            break;
        case 2:
            userList.deleteInactiveUsers();
            break;
        case 3:
            printTop10Repeated(users, numUsers);
            break;
        case 4:
            std::cout << "Exiting the program...\n";
            exit(0);
        default:
            std::cout << "Invalid choice. Please try again.\n";
        }

        std::cout << "Press any key to go back to the main menu...";
        std::cin.ignore();
        std::cin.get();

        displayAdminMenu(userList, users, numUsers); // Recursive call to display the menu again
}

User::User(std::string username, std::string password, std::string lastLogin)
    : username(username), password(password), lastLogin(lastLogin), next(nullptr) {}

UserList::UserList() : head(nullptr), size(0) {}

void UserList::addUser(std::string username, std::string password, std::string lastLogin) {
    User* newUser = new User(username, password, lastLogin);
        
    if (head == nullptr) {
        head = newUser;
    }
    else {
        User* current = head;
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = newUser;
    }

    size++;
}

// Function to calculate the time difference in years between two dates
int calculateYearDifference(const std::string& date) {
    std::tm time = {};
    std::istringstream ss(date);
    ss >> time.tm_year;
    ss.ignore();
    ss >> time.tm_mon;
    ss.ignore();
    ss >> time.tm_mday;

    std::time_t now = std::time(nullptr);
    std::tm *currentTime = std::localtime(&now);

    int yearDifference = currentTime->tm_year + 1900 - time.tm_year;

    if (currentTime->tm_mon < time.tm_mon || (currentTime->tm_mon == time.tm_mon && currentTime->tm_mday < time.tm_mday))
    {
        yearDifference--;
    }

    return yearDifference;
}

void UserList::deleteInactiveUsers() {
    std::time_t now = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());

    User* current = head;
    User* prev = nullptr;

    while (current != nullptr) {
        int yearDifference = calculateYearDifference(current->lastLogin);

        if (yearDifference >= 1) {
            std::cout << "Deleting user: " << current->username << std::endl;

            if (prev == nullptr) {
                head = current->next;
                delete current;
                current = head;
            }
            else {
                prev->next = current->next;
                delete current;
                current = prev->next;
            }

            size--;
        }
        else {
            prev = current;
            current = current->next;
        }
    }
}

void UserList::displayUsers(const UserList& userList) {

    std::cout << std::left << std::setw(15) << "Username" << std::setw(10) << "Password" << std::setw(10) << "Last Login" << std::endl;
    std::cout << std::setfill('-') << std::setw(45) << "-" << std::setfill(' ') << std::endl;

    const User *current = userList.getHead();

    while (current != nullptr)
    {
        std::cout << std::left << std::setw(15) << current->username << std::setw(10) << current->password << std::setw(10) << current->lastLogin << std::endl;
        current = current->next;

    }
}




#endif
