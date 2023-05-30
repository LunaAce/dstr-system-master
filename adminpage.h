#ifndef USERLIST_H
#define USERLIST_H

#include <string>
#include <iostream>
#include <algorithm>
#include <iostream>
#include <fstream>
#include <sstream>
#include <unordered_map>

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


#endif
