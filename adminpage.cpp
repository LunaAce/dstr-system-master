#include "adminpage.h"
#include <iostream>
#include <ctime>
#include <chrono>
#include <string>
#include <sstream>
#include <iomanip>

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


int main(){
    UserList userList;
    UserData users[ARRAY_SIZE];
    int numUsers = readCSV("favourite.csv", users, ARRAY_SIZE);
    userList.addUser("admin", "admin", "2022-02-12 12:12:12");
    userList.addUser("user", "user", "2021-07-18 12:12:12");
    userList.addUser("user1", "user", "2023-05-20 12:12:12");
    
    displayAdminMenu(userList, users, numUsers);

    return 0;
}
