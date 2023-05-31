#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <iomanip> // for setprecision
using namespace std;

const int ARRAY_SIZE = 1422;

struct University
{
    int rank;
    string name;
    string locationCode;
    string location;
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

void readUni(const string &filename, University universities[], int &numUniversities)
{
    ifstream inputFile(filename);
    if (!inputFile)
    {
        cout << "Failed to open the CSV file." << endl;
        return;
    }

    string line;
    getline(inputFile, line); // Skip the header line

    // while retrieving info from uni.csv, it will check for invalid data, for score-related it will convert invalid data to -1.0
    // for rank-related, convert to -1
    // if rank-related is 501+ OR 601+, it will set it as 501 and 601 respectively in array, but for display purpose, it will print it out as 501+ and 601+ respectively
    numUniversities = 0;
    while (getline(inputFile, line) && numUniversities < ARRAY_SIZE)
    {
        istringstream iss(line);
        string data;

        getline(iss, data, ','); // Rank
        try
        {
            universities[numUniversities].rank = stoi(data);
        }
        catch (const exception &)
        {
            universities[numUniversities].rank = -1;
            data = "n/a";
        }

        // Check if the line starts with an integer (rank value)
        bool startsWithRank = false;
        try
        {
            stoi(line);
            startsWithRank = true;
        }
        catch (const exception &)
        {
        }

        // Read the name field
        if (startsWithRank)
        {
            // If the line starts with a rank, consider the name field as the remaining part of the line
            universities[numUniversities].name = line.substr(data.size() + 1);
        }
        else
        {
            // Otherwise, read the name field as usual
            getline(iss, universities[numUniversities].name, ',');
        }

        getline(iss, universities[numUniversities].name, ',');
        getline(iss, universities[numUniversities].locationCode, ',');
        getline(iss, universities[numUniversities].location, ',');

        getline(iss, data, ','); // AR Score
        try
        {
            universities[numUniversities].arScore = stod(data);
        }
        catch (const exception &)
        {
            universities[numUniversities].arScore = -1.0;
            data = "n/a";
        }

        getline(iss, data, ','); // AR Rank
        try
        {
            universities[numUniversities].arRank = stoi(data);
        }
        catch (const exception &)
        {
            universities[numUniversities].arRank = -1;
            data = "n/a";
        }

        getline(iss, data, ','); // ER Score
        try
        {
            universities[numUniversities].erScore = stoi(data);
        }
        catch (const exception &)
        {
            universities[numUniversities].erScore = -1.0;
        }

        getline(iss, data, ','); // ER Rank
        try
        {
            universities[numUniversities].erRank = stoi(data);
        }
        catch (const exception &)
        {
            universities[numUniversities].erRank = -1;
            data = "n/a";
        }

        getline(iss, data, ','); // FSR Score
        try
        {
            universities[numUniversities].fsrScore = stoi(data);
        }
        catch (const exception &)
        {
            universities[numUniversities].fsrScore = -1.0;
            data = "n/a";
        }

        getline(iss, data, ','); // FSR Rank
        try
        {
            universities[numUniversities].fsrRank = stoi(data);
        }
        catch (const exception &)
        {
            universities[numUniversities].fsrRank = -1;
            data = "n/a";
        }

        getline(iss, data, ','); // CPF Score
        try
        {
            universities[numUniversities].cpfScore = stoi(data);
        }
        catch (const exception &)
        {
            universities[numUniversities].cpfScore = -1.0;
        }

        getline(iss, data, ','); // CPF Rank
        try
        {
            universities[numUniversities].cpfRank = stoi(data);
        }
        catch (const exception &)
        {
            universities[numUniversities].cpfRank = -1;
            data = "n/a";
        }

        getline(iss, data, ','); // IFR Score
        try
        {
            universities[numUniversities].ifrScore = stoi(data);
        }
        catch (const exception &)
        {
            universities[numUniversities].ifrScore = -1.0;
            data = "n/a";
        }

        getline(iss, data, ','); // IFR Rank
        try
        {
            universities[numUniversities].ifrRank = stoi(data);
        }
        catch (const exception &)
        {
            universities[numUniversities].ifrRank = -1;
            data = "n/a";
        }

        getline(iss, data, ','); // ISR Score
        try
        {
            universities[numUniversities].isrScore = stoi(data);
        }
        catch (const exception &)
        {
            universities[numUniversities].isrScore = -1.0;
            data = "n/a";
        }

        getline(iss, data, ','); // ISR Rank
        try
        {
            universities[numUniversities].isrRank = stoi(data);
        }
        catch (const exception &)
        {
            universities[numUniversities].isrRank = -1;
            data = "n/a";
        }

        getline(iss, data, ','); // IRN Score
        try
        {
            universities[numUniversities].irnScore = stoi(data);
        }
        catch (const exception &)
        {
            universities[numUniversities].irnScore = -1.0;
            data = "n/a";
        }

        getline(iss, data, ','); // IRN Rank
        try
        {
            universities[numUniversities].irnRank = stoi(data);
        }
        catch (const exception &)
        {
            universities[numUniversities].irnRank = -1;
            data = "n/a";
        }

        getline(iss, data, ','); // GER Score
        try
        {
            universities[numUniversities].gerScore = stoi(data);
        }
        catch (const exception &)
        {
            universities[numUniversities].gerScore = -1.0;
            data = "n/a";
        }

        getline(iss, data, ','); // GER Rank
        try
        {
            universities[numUniversities].gerRank = stoi(data);
        }
        catch (const exception &)
        {
            universities[numUniversities].gerRank = -1;
            data = "n/a";
        }

        getline(iss, data, ','); // Score Scaled Rank
        try
        {
            universities[numUniversities].scoreScaled = stoi(data);
        }
        catch (const exception &)
        {
            universities[numUniversities].scoreScaled = -1.0;
            data = "n/a";
        }

        numUniversities++;
    }

    inputFile.close();
}

void displayUni()
{

    University universities[ARRAY_SIZE];
    int numUniversities = 0;

    readUni("uni.csv", universities, numUniversities);

    // if it is -1 OR -1.0, it will print n/a
    // if it is 501 in array, it will print 501+
    // if it is 601 in array, it will print 601+
    for (int i = 0; i < numUniversities; i++)
    {
        University &uni = universities[i];
        cout << "University #" << i + 1 << endl;
        cout << "Rank: " << (uni.rank == -1 ? "n/a" : to_string(uni.rank)) << endl;
        cout << "Name: " << uni.name << endl;
        cout << "Location Code: " << uni.locationCode << endl;
        cout << "Location: " << uni.location << endl;
        cout << "AR Score: " << (uni.arScore == -1.0 ? "n/a" : to_string(uni.arScore)) << endl;
        cout << "AR Rank: " << (uni.arRank == -1 ? "n/a" : (uni.arRank == 501 ? "501+" : (uni.arRank == 601 ? "601+" : to_string(uni.arRank)))) << endl;
        cout << "ER Score: " << (uni.erScore == -1.0 ? "n/a" : to_string(uni.erScore)) << endl;
        cout << "ER Rank: " << (uni.erRank == -1 ? "n/a" : (uni.erRank == 501 ? "501+" : (uni.erRank == 601 ? "601+" : to_string(uni.erRank)))) << endl;
        cout << "FSR Score: " << (uni.fsrScore == -1.0 ? "n/a" : to_string(uni.fsrScore)) << endl;
        cout << "FSR Rank: " << (uni.fsrRank == -1 ? "n/a" : (uni.fsrRank == 501 ? "501+" : (uni.fsrRank == 601 ? "601+" : to_string(uni.fsrRank)))) << endl;
        cout << "CPF Score: " << (uni.cpfScore == -1.0 ? "n/a" : to_string(uni.cpfScore)) << endl;
        cout << "CPF Rank: " << (uni.cpfRank == -1 ? "n/a" : (uni.cpfRank == 501 ? "501+" : (uni.cpfRank == 601 ? "601+" : to_string(uni.cpfRank)))) << endl;
        cout << "IFR Score: " << (uni.ifrScore == -1.0 ? "n/a" : to_string(uni.ifrScore)) << endl;
        cout << "IFR Rank: " << (uni.ifrRank == -1 ? "n/a" : (uni.ifrRank == 501 ? "501+" : (uni.ifrRank == 601 ? "601+" : to_string(uni.ifrRank)))) << endl;
        cout << "ISR Score: " << (uni.isrScore == -1.0 ? "n/a" : to_string(uni.isrScore)) << endl;
        cout << "ISR Rank: " << (uni.isrRank == -1 ? "n/a" : (uni.isrRank == 501 ? "501+" : (uni.isrRank == 601 ? "601+" : to_string(uni.isrRank)))) << endl;
        cout << "IRN Score: " << (uni.irnScore == -1.0 ? "n/a" : to_string(uni.irnScore)) << endl;
        cout << "IRN Rank: " << (uni.irnRank == -1 ? "n/a" : (uni.irnRank == 501 ? "501+" : (uni.irnRank == 601 ? "601+" : to_string(uni.irnRank)))) << endl;
        cout << "GER Score: " << (uni.gerScore == -1.0 ? "n/a" : to_string(uni.gerScore)) << endl;
        cout << "GER Rank: " << (uni.gerRank == -1 ? "n/a" : (uni.gerRank == 501 ? "501+" : (uni.gerRank == 601 ? "601+" : to_string(uni.gerRank)))) << endl;
        cout << "Score Scaled: " << (uni.scoreScaled == -1.0 ? "n/a" : to_string(uni.scoreScaled)) << endl;
        cout << endl;
    }
}

// Brian registered user insertion sort
bool compareByErScore(const University &u1, const University &u2)
{
    return u1.erScore < u2.erScore;
}

bool compareByFsrScore(const University &u1, const University &u2)
{
    return u1.fsrScore < u2.fsrScore;
}

bool compareByArScore(const University &u1, const University &u2)
{
    return u1.arScore < u2.arScore;
}

// Add more comparison functions for other attributes

void insertionSort1(University *universities, int size, bool (*compare)(const University &, const University &))
{
    for (int i = 1; i < size; ++i)
    {
        University current = universities[i];
        int j = i - 1;
        while (j >= 0 && compare(universities[j], current))
        {
            universities[j + 1] = universities[j];
            --j;
        }
        universities[j + 1] = current;
    }
}

void readCSVFile1(const string &filename, University *universities, int &count, int maxSize)
{
    ifstream file(filename);
    if (!file)
    {
        cerr << "Failed to open the file.\n";
        return;
    }

    string line;
    count = 0;
    while (getline(file, line))
    {
        if (count >= maxSize)
        {
            cerr << "Exceeded maximum number of universities.\n";
            break;
        }

        istringstream iss(line);
        string item;

        // Read each value from the CSV line and populate the University struct
        if (getline(iss, item, ','))
        {
            try
            {
                universities[count].rank = stoi(item);
            }
            catch (const invalid_argument &)
            {
                //  cerr << "Invalid rank value: " << item << '\n';
                continue; // Skip this line and proceed to the next line
            }
        }
        if (getline(iss, universities[count].name, ','))
        {
            getline(iss, universities[count].locationCode, ',');
            getline(iss, universities[count].location, ',');
            getline(iss, item, ',');
            try
            {
                universities[count].arScore = stod(item);
            }
            catch (const invalid_argument &)
            {
                // cerr << "Invalid AR score value: " << item << '\n';
                continue; // Skip this line and proceed to the next line
            }
            // Read other values and assign them to the struct members accordingly
        }
        if (getline(iss, item, ','))
        {
            try
            {
                universities[count].arRank = stoi(item);
            }
            catch (const invalid_argument &)
            {
                //  cerr << "Invalid rank value: " << item << '\n';
                continue; // Skip this line and proceed to the next line
            }
        }
        if (getline(iss, item, ','))
        {
            try
            {
                universities[count].erScore = stoi(item);
            }
            catch (const invalid_argument &)
            {
                //  cerr << "Invalid rank value: " << item << '\n';
                continue; // Skip this line and proceed to the next line
            }
        }
        if (getline(iss, item, ','))
        {
            try
            {
                universities[count].erRank = stoi(item);
            }
            catch (const invalid_argument &)
            {
                //  cerr << "Invalid rank value: " << item << '\n';
                continue; // Skip this line and proceed to the next line
            }
        }
        if (getline(iss, item, ','))
        {
            try
            {
                universities[count].fsrScore = stoi(item);
            }
            catch (const invalid_argument &)
            {
                //  cerr << "Invalid rank value: " << item << '\n';
                continue; // Skip this line and proceed to the next line
            }
        }
        if (getline(iss, item, ','))
        {
            try
            {
                universities[count].fsrRank = stoi(item);
            }
            catch (const invalid_argument &)
            {
                //  cerr << "Invalid rank value: " << item << '\n';
                continue; // Skip this line and proceed to the next line
            }
        }
        if (getline(iss, item, ','))
        {
            try
            {
                universities[count].cpfScore = stoi(item);
            }
            catch (const invalid_argument &)
            {
                //  cerr << "Invalid rank value: " << item << '\n';
                continue; // Skip this line and proceed to the next line
            }
        }
        if (getline(iss, item, ','))
        {
            try
            {
                universities[count].cpfRank = stoi(item);
            }
            catch (const invalid_argument &)
            {
                //  cerr << "Invalid rank value: " << item << '\n';
                continue; // Skip this line and proceed to the next line
            }
        }
        if (getline(iss, item, ','))
        {
            try
            {
                universities[count].ifrScore = stoi(item);
            }
            catch (const invalid_argument &)
            {
                //  cerr << "Invalid rank value: " << item << '\n';
                continue; // Skip this line and proceed to the next line
            }
        }
        if (getline(iss, item, ','))
        {
            try
            {
                universities[count].ifrRank = stoi(item);
            }
            catch (const invalid_argument &)
            {
                //  cerr << "Invalid rank value: " << item << '\n';
                continue; // Skip this line and proceed to the next line
            }
        }
        if (getline(iss, item, ','))
        {
            try
            {
                universities[count].isrScore = stoi(item);
            }
            catch (const invalid_argument &)
            {
                //  cerr << "Invalid rank value: " << item << '\n';
                continue; // Skip this line and proceed to the next line
            }
        }
        if (getline(iss, item, ','))
        {
            try
            {
                universities[count].isrRank = stoi(item);
            }
            catch (const invalid_argument &)
            {
                //  cerr << "Invalid rank value: " << item << '\n';
                continue; // Skip this line and proceed to the next line
            }
        }
        if (getline(iss, item, ','))
        {
            try
            {
                universities[count].irnScore = stoi(item);
            }
            catch (const invalid_argument &)
            {
                //  cerr << "Invalid rank value: " << item << '\n';
                continue; // Skip this line and proceed to the next line
            }
        }
        if (getline(iss, item, ','))
        {
            try
            {
                universities[count].irnRank = stoi(item);
            }
            catch (const invalid_argument &)
            {
                //  cerr << "Invalid rank value: " << item << '\n';
                continue; // Skip this line and proceed to the next line
            }
        }
        if (getline(iss, item, ','))
        {
            try
            {
                universities[count].gerScore = stoi(item);
            }
            catch (const invalid_argument &)
            {
                //  cerr << "Invalid rank value: " << item << '\n';
                continue; // Skip this line and proceed to the next line
            }
        }
        if (getline(iss, item, ','))
        {
            try
            {
                universities[count].gerRank = stoi(item);
            }
            catch (const invalid_argument &)
            {
                //  cerr << "Invalid rank value: " << item << '\n';
                continue; // Skip this line and proceed to the next line
            }
        }
        if (getline(iss, item, ','))
        {
            try
            {
                universities[count].scoreScaled = stoi(item);
            }
            catch (const invalid_argument &)
            {
                //  cerr << "Invalid rank value: " << item << '\n';
                continue; // Skip this line and proceed to the next line
            }
        }

        ++count;
    }
}

void registered_sort()
{
    const int MAX_UNIVERSITIES = 1500;
    University universities[MAX_UNIVERSITIES];
    int count = 0;

    // Modify the filename variable to match your CSV file path
    string filename = "uni.csv";
    readCSVFile1(filename, universities, count, MAX_UNIVERSITIES);
    int choice;
    do
    {
        cout << "Choose an attribute to sort by:\n";
        cout << "1. AR Score\n";
        cout << "2. FSR Score\n";
        cout << "3. ER Score\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            insertionSort1(universities, count, compareByArScore);
            break;
        case 2:
            insertionSort1(universities, count, compareByFsrScore);
            break;
        case 3:
            insertionSort1(universities, count, compareByErScore);
            break;
            // Add cases for other attributes

        case 0:
            cout << "Exiting...\n";
            break;
        default:
            cout << "Invalid choice. Please try again.\n";
        }

        if (choice != 0)
        {
            // Print the sorted universities
            cout << "Sorted universities:\n";
            for (int i = 0; i < count; ++i)
            {
                cout << "Rank: " << universities[i].rank << "\n ";
                cout << "Name: " << universities[i].name << "\n ";
                cout << "Location Code: " << universities[i].locationCode << "\n";
                cout << "Location: " << universities[i].location << "\n";
                cout << "Ar Score: " << universities[i].arScore << "\n";
                cout << "Ar Rank: " << universities[i].arRank << "\n";
                cout << "Er Score: " << universities[i].erScore << "\n";
                cout << "Er Rank: " << universities[i].erRank << "\n";
                cout << "Fsr Score: " << universities[i].fsrScore << "\n";
                cout << "Fsr Rank: " << universities[i].fsrRank << "\n";
                cout << "Cpf Score: " << universities[i].cpfScore << "\n";
                cout << "Cpf Rank: " << universities[i].cpfRank << "\n";
                cout << "Ifr Score: " << universities[i].ifrScore << "\n";
                cout << "Ifr Rank: " << universities[i].ifrRank << "\n";
                cout << "Isr Score: " << universities[i].isrScore << "\n";
                cout << "Isr Rank: " << universities[i].isrRank << "\n";
                cout << "Irn Score: " << universities[i].irnScore << "\n";
                cout << "Irn Rank: " << universities[i].irnRank << "\n";
                cout << "Ger Score: " << universities[i].gerScore << "\n";
                cout << "Ger Rank: " << universities[i].gerRank << "\n";
                cout << "Score Scaled: " << universities[i].scoreScaled << "\n";
                // Print other attributes accordingly
            }
            cout << '\n';
        }
    } while (choice != 0);

    // return 0;
}
