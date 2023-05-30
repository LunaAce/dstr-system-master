#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <iomanip>

const int ARRAY_SIZE = 1422;

struct University
{
    int rank;
    std::string name;
    std::string locationCode;
    std::string location;
    double arScore;
    int arRank;
    double erScore;
    int erRank;
    double fsrScore;
    int fsrRank;
    double cpfScore;
    int cpfRank;
    double ifrScore;
    int ifrRank;
    double isrScore;
    int isrRank;
    int irnRank;
    double irnScore;
    double gerScore;
    int gerRank;
    double scoreScaled;
};

void readUni(const std::string &filename, University universities[], int &numUniversities)
{
    std::ifstream inputFile(filename);
    if (!inputFile)
    {
        std::cout << "Failed to open the CSV file." << std::endl;
        return;
    }

    std::string line;
    std::getline(inputFile, line); // Skip the header line

    // while retrieving info from uni.csv, it will check for invalid data, for score-related it will convert invalid data to -1.0
    // for rank-related, convert to -1
    // if rank-related is 501+ OR 601+, it will set it as 501 and 601 respectively in array, but for display purpose, it will print it out as 501+ and 601+ respectively
    numUniversities = 0;
    while (std::getline(inputFile, line) && numUniversities < ARRAY_SIZE)
    {
        std::istringstream iss(line);
        std::string data;

        std::getline(iss, data, ','); // Rank
        try
        {
            universities[numUniversities].rank = std::stoi(data);
        }
        catch (const std::exception &)
        {
            universities[numUniversities].rank = -1;
            data = "n/a";
        }

        // Check if the line starts with an integer (rank value)
        bool startsWithRank = false;
        try
        {
            std::stoi(line);
            startsWithRank = true;
        }
        catch (const std::exception &) {}

        // Read the name field
        if (startsWithRank)
        {
            // If the line starts with a rank, consider the name field as the remaining part of the line
            universities[numUniversities].name = line.substr(data.size() + 1);
        }
        else
        {
            // Otherwise, read the name field as usual
            std::getline(iss, universities[numUniversities].name, ',');
        }

        std::getline(iss, universities[numUniversities].name, ',');
        std::getline(iss, universities[numUniversities].locationCode, ',');
        std::getline(iss, universities[numUniversities].location, ',');

        std::getline(iss, data, ','); // AR Score
        try
        {
            universities[numUniversities].arScore = std::stod(data);
        }
        catch (const std::exception &)
        {
            universities[numUniversities].arScore = -1.0;
            data = "n/a";
        }

        std::getline(iss, data, ','); // AR Rank
        try
        {
            universities[numUniversities].arRank = std::stoi(data);
        }
        catch (const std::exception &)
        {
            universities[numUniversities].arRank = -1;
            data = "n/a";
        }

        std::getline(iss, data, ','); // ER Score
        try
        {
            universities[numUniversities].erScore = std::stoi(data);
        }
        catch (const std::exception &)
        {
            universities[numUniversities].erScore = -1.0;
        }

        std::getline(iss, data, ','); // ER Rank
        try
        {
            universities[numUniversities].erRank = std::stoi(data);
        }
        catch (const std::exception &)
        {
            universities[numUniversities].erRank = -1;
            data = "n/a";
        }

        std::getline(iss, data, ','); // FSR Score
        try
        {
            universities[numUniversities].fsrScore = std::stoi(data);
        }
        catch (const std::exception &)
        {
            universities[numUniversities].fsrScore = -1.0;
            data = "n/a";
        }

        std::getline(iss, data, ','); // FSR Rank
        try
        {
            universities[numUniversities].fsrRank = std::stoi(data);
        }
        catch (const std::exception &)
        {
            universities[numUniversities].fsrRank = -1;
            data = "n/a";
        }

        std::getline(iss, data, ','); // CPF Score
        try
        {
            universities[numUniversities].cpfScore = std::stoi(data);
        }
        catch (const std::exception &)
        {
            universities[numUniversities].cpfScore = -1.0;
        }

        std::getline(iss, data, ','); // CPF Rank
        try
        {
            universities[numUniversities].cpfRank = std::stoi(data);
        }
        catch (const std::exception &)
        {
            universities[numUniversities].cpfRank = -1;
            data = "n/a";
        }

        std::getline(iss, data, ','); // IFR Score
        try
        {
            universities[numUniversities].ifrScore = std::stoi(data);
        }
        catch (const std::exception &)
        {
            universities[numUniversities].ifrScore = -1.0;
            data = "n/a";
        }

        std::getline(iss, data, ','); // IFR Rank
        try
        {
            universities[numUniversities].ifrRank = std::stoi(data);
        }
        catch (const std::exception &)
        {
            universities[numUniversities].ifrRank = -1;
            data = "n/a";
        }

        std::getline(iss, data, ','); // ISR Score
        try
        {
            universities[numUniversities].isrScore = std::stoi(data);
        }
        catch (const std::exception &)
        {
            universities[numUniversities].isrScore = -1.0;
            data = "n/a";
        }

        std::getline(iss, data, ','); // ISR Rank
        try
        {
            universities[numUniversities].isrRank = std::stoi(data);
        }
        catch (const std::exception &)
        {
            universities[numUniversities].isrRank = -1;
            data = "n/a";
        }

        std::getline(iss, data, ','); // IRN Score
        try
        {
            universities[numUniversities].irnScore = std::stoi(data);
        }
        catch (const std::exception &)
        {
            universities[numUniversities].irnScore = -1.0;
            data = "n/a";
        }

        std::getline(iss, data, ','); // IRN Rank
        try
        {
            universities[numUniversities].irnRank = std::stoi(data);
        }
        catch (const std::exception &)
        {
            universities[numUniversities].irnRank = -1;
            data = "n/a";
        }

        std::getline(iss, data, ','); // GER Score
        try
        {
            universities[numUniversities].gerScore = std::stoi(data);
        }
        catch (const std::exception &)
        {
            universities[numUniversities].gerScore = -1.0;
            data = "n/a";
        }

        std::getline(iss, data, ','); // GER Rank
        try
        {
            universities[numUniversities].gerRank = std::stoi(data);
        }
        catch (const std::exception &)
        {
            universities[numUniversities].gerRank = -1;
            data = "n/a";
        }

        std::getline(iss, data, ','); // Score Scaled Rank
        try
        {
            universities[numUniversities].scoreScaled = std::stoi(data);
        }
        catch (const std::exception &)
        {
            universities[numUniversities].scoreScaled = -1.0;
            data = "n/a";
        }

        numUniversities++;
    }

    inputFile.close();
    
}



bool compareByName(const University& u1, const University& u2) {
    return u1.name < u2.name;
}




// Add more comparison functions for other attributes

void insertionSort(University* universities, int size, bool (*compare)(const University&, const University&)) {
    for (int i = 1; i < size; ++i) {
        University current = universities[i];
        int j = i - 1;
        while (j >= 0 && !compare(universities[j], current)) { // Change the comparison condition
            universities[j + 1] = universities[j];
            --j;
        }
        universities[j + 1] = current;
    }
}

void readCSVFile(const std::string& filename, University* universities, int& count, int maxSize) {
    std::ifstream file(filename);
    if (!file) {
        std::cerr << "Failed to open the file.\n";
        return;
    }

    std::string line;
    count = 0;
    while (std::getline(file, line)) {
        if (count >= maxSize) {
            std::cerr << "Exceeded maximum number of universities.\n";
            break;
        }

        std::istringstream iss(line);
        std::string item;

        // Read each value from the CSV line and populate the University struct
        if (std::getline(iss, item, ',')) {
            try {
                universities[count].rank = std::stoi(item);
            } catch (const std::invalid_argument&) {
              //  std::cerr << "Invalid rank value: " << item << '\n';
                continue;  // Skip this line and proceed to the next line
            }
        }
        if (std::getline(iss, universities[count].name, ',')) {
            std::getline(iss, universities[count].locationCode, ',');
            std::getline(iss, universities[count].location, ',');
            std::getline(iss, item, ',');
            try {
                universities[count].arScore = std::stod(item);
            } catch (const std::invalid_argument&) {
               // std::cerr << "Invalid AR score value: " << item << '\n';
                continue;  // Skip this line and proceed to the next line
            }
            // Read other values and assign them to the struct members accordingly
        }
        if (std::getline(iss, item, ',')) {
            try {
                universities[count].arRank = std::stoi(item);
            } catch (const std::invalid_argument&) {
              //  std::cerr << "Invalid rank value: " << item << '\n';
                continue;  // Skip this line and proceed to the next line
            }
        }
        if (std::getline(iss, item, ',')) {
            try {
                universities[count].erScore = std::stoi(item);
            } catch (const std::invalid_argument&) {
              //  std::cerr << "Invalid rank value: " << item << '\n';
                continue;  // Skip this line and proceed to the next line
            }
        }
        if (std::getline(iss, item, ',')) {
            try {
                universities[count].erRank = std::stoi(item);
            } catch (const std::invalid_argument&) {
              //  std::cerr << "Invalid rank value: " << item << '\n';
                continue;  // Skip this line and proceed to the next line
            }
        }
        if (std::getline(iss, item, ',')) {
            try {
                universities[count].fsrScore = std::stoi(item);
            } catch (const std::invalid_argument&) {
              //  std::cerr << "Invalid rank value: " << item << '\n';
                continue;  // Skip this line and proceed to the next line
            }
        }
        if (std::getline(iss, item, ',')) {
            try {
                universities[count].fsrRank = std::stoi(item);
            } catch (const std::invalid_argument&) {
              //  std::cerr << "Invalid rank value: " << item << '\n';
                continue;  // Skip this line and proceed to the next line
            }
        }
        if (std::getline(iss, item, ',')) {
            try {
                universities[count].cpfScore = std::stoi(item);
            } catch (const std::invalid_argument&) {
              //  std::cerr << "Invalid rank value: " << item << '\n';
                continue;  // Skip this line and proceed to the next line
            }
        }
        if (std::getline(iss, item, ',')) {
            try {
                universities[count].cpfRank = std::stoi(item);
            } catch (const std::invalid_argument&) {
              //  std::cerr << "Invalid rank value: " << item << '\n';
                continue;  // Skip this line and proceed to the next line
            }
        }
        if (std::getline(iss, item, ',')) {
            try {
                universities[count].ifrScore = std::stoi(item);
            } catch (const std::invalid_argument&) {
              //  std::cerr << "Invalid rank value: " << item << '\n';
                continue;  // Skip this line and proceed to the next line
            }
        }
        if (std::getline(iss, item, ',')) {
            try {
                universities[count].ifrRank = std::stoi(item);
            } catch (const std::invalid_argument&) {
              //  std::cerr << "Invalid rank value: " << item << '\n';
                continue;  // Skip this line and proceed to the next line
            }
        }
        if (std::getline(iss, item, ',')) {
            try {
                universities[count].isrScore = std::stoi(item);
            } catch (const std::invalid_argument&) {
              //  std::cerr << "Invalid rank value: " << item << '\n';
                continue;  // Skip this line and proceed to the next line
            }
        }
        if (std::getline(iss, item, ',')) {
            try {
                universities[count].isrRank = std::stoi(item);
            } catch (const std::invalid_argument&) {
              //  std::cerr << "Invalid rank value: " << item << '\n';
                continue;  // Skip this line and proceed to the next line
            }
        }
        if (std::getline(iss, item, ',')) {
            try {
                universities[count].irnScore = std::stoi(item);
            } catch (const std::invalid_argument&) {
              //  std::cerr << "Invalid rank value: " << item << '\n';
                continue;  // Skip this line and proceed to the next line
            }
        }
        if (std::getline(iss, item, ',')) {
            try {
                universities[count].irnRank = std::stoi(item);
            } catch (const std::invalid_argument&) {
              //  std::cerr << "Invalid rank value: " << item << '\n';
                continue;  // Skip this line and proceed to the next line
            }
        }
        if (std::getline(iss, item, ',')) {
            try {
                universities[count].gerScore = std::stoi(item);
            } catch (const std::invalid_argument&) {
              //  std::cerr << "Invalid rank value: " << item << '\n';
                continue;  // Skip this line and proceed to the next line
            }
        }
        if (std::getline(iss, item, ',')) {
            try {
                universities[count].gerRank = std::stoi(item);
            } catch (const std::invalid_argument&) {
              //  std::cerr << "Invalid rank value: " << item << '\n';
                continue;  // Skip this line and proceed to the next line
            }
        }
        if (std::getline(iss, item, ',')) {
            try {
                universities[count].scoreScaled = std::stoi(item);
            } catch (const std::invalid_argument&) {
              //  std::cerr << "Invalid rank value: " << item << '\n';
                continue;  // Skip this line and proceed to the next line
            }
        }

        ++count;
    }
}

int main() {
    const int MAX_UNIVERSITIES = 1500;
    University universities[MAX_UNIVERSITIES];
    int count = 0;

    // Modify the filename variable to match your CSV file path
    std::string filename = "uni.csv";
    readCSVFile(filename, universities, count, MAX_UNIVERSITIES);
    int choice;
    do {
        std::cout << "Choose an attribute to sort by:\n";
        std::cout << "1. Sort Name in Ascending Order\n";
        std::cout << "0. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {

            case 1:
                insertionSort(universities, count, compareByName);
                break;

            case 0:
                std::cout << "Exiting...\n";
                break;
            default:
                std::cout << "Invalid choice. Please try again.\n";
        }

        if (choice != 0) {
            // Print the sorted universities
            std::cout << "Sorted universities:\n";
            for (int i = 0; i < count; ++i) {
                std::cout << "Rank: " << universities[i].rank << "\n ";
                std::cout << "Name: " << universities[i].name << "\n ";
                std::cout << "Location Code: " << universities[i].locationCode << "\n";
                std::cout << "Location: " << universities[i].location << "\n";
                std::cout << "Ar Score: " << universities[i].arScore << "\n";
                std::cout << "Ar Rank: " << universities[i].arRank << "\n";
                std::cout << "Er Score: " << universities[i].erScore << "\n";
                std::cout << "Er Rank: " << universities[i].erRank << "\n";
                std::cout << "Fsr Score: " << universities[i].fsrScore << "\n";
                std::cout << "Fsr Rank: " << universities[i].fsrRank << "\n";
                std::cout << "Cpf Score: " << universities[i].cpfScore << "\n";
                std::cout << "Cpf Rank: " << universities[i].cpfRank << "\n";
                std::cout << "Ifr Score: " << universities[i].ifrScore << "\n";
                std::cout << "Ifr Rank: " << universities[i].ifrRank << "\n";
                std::cout << "Isr Score: " << universities[i].isrScore << "\n";
                std::cout << "Isr Rank: " << universities[i].isrRank << "\n";
                std::cout << "Irn Score: " << universities[i].irnScore << "\n";
                std::cout << "Irn Rank: " << universities[i].irnRank << "\n";
                std::cout << "Ger Score: " << universities[i].gerScore << "\n";
                std::cout << "Ger Rank: " << universities[i].gerRank << "\n";
                std::cout << "Score Scaled: " << universities[i].scoreScaled << "\n";
                // Print other attributes accordingly
            }
            std::cout << '\n';
        }
    } while (choice != 0);

    return 0;
}
