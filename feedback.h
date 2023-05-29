#include <iostream>
#include <fstream>
#include <string>



// struct FeedbackRecord
// {
//     int userID;
//     int uniID;
//     std::string feedback;
//     std::string adminReply;
// };

void replyFeedback()
{
 
}


void giveFeedback()
{
    string line;
    string feedback;
    ofstream output_file("feedback.csv", ios::out | ios::app);

    // Read the current user's username from the CSV file
    string currentuser, currentuni;
    ifstream current_user_file("current_user.csv");
    ifstream current_uni_file("current_uni.csv");

    if (!current_user_file.is_open())
    {
        cerr << "Could not open the file - 'current_user.csv'" << endl;
        return;
    }

    getline(current_user_file, currentuser);
    current_user_file.close();

    // Read feedback for the current user from the CSV file

    if (!current_uni_file.is_open())
    {
        cerr << "Could not open the file - 'current_uni.csv'" << endl;
        return;
    }
    getline(current_uni_file, currentuni);
    current_user_file.close();
    cout << "Enter your feedback: ";
    cin >> feedback;
    output_file << currentuser << "," << currentuni << "," << feedback << ","
                << "\n";
    cout << "Added to Feedback! " << endl;
}

void readfeedback()
{
    // Read the current user's username from the CSV file
    string currentuser;
    ifstream current_user_file("current_user.csv");

    if (!current_user_file.is_open())
    {
        cerr << "Could not open the file - 'current_user.csv'" << endl;
        return;
    }

    getline(current_user_file, currentuser);
    current_user_file.close();

    // Read feedback for the current user from the CSV file
    string feedback_file_name = "feedback.csv";
    ifstream feedback_file(feedback_file_name);

    if (!feedback_file.is_open())
    {
        cerr << "Could not open the file - " << feedback_file_name << endl;
        return;
    }

    string line;
    bool feedback_found = false;

    while (getline(feedback_file, line))
    {
        istringstream iss(line);
        string username, feedback_text;
        string university, feedback_reply;
        getline(iss, username, ',');
        getline(iss, university, ',');
        getline(iss, feedback_text, ',');
        getline(iss, feedback_reply, '\n');

        if (username == currentuser)
        {
            cout << "Feedback for University " << university << ":" << endl;
            cout << "Your Feedback: " << feedback_text << endl;
            cout << "Admin Reply  : " << endl;
            feedback_found = true;
        }
    }

    feedback_file.close();

    if (!feedback_found)
    {
        cout << "No feedback found for " << currentuser << endl;
    }
}

void savefavourite()
{
    string line;
    ofstream output_file("favourite.csv", ios::out | ios::app);

    // Read the current user's username from the CSV file
    string currentuser,currentuni;
    string checkuser, checkuni;
    ifstream current_user_file("current_user.csv");
    ifstream current_uni_file("current_uni.csv");
    ifstream check_file("favourite.csv");

    if (!current_user_file.is_open())
    {
        cerr << "Could not open the file - 'current_user.csv'" << endl;
        return;
    }
    while (getline(current_user_file, line))
    {
        istringstream iss(line);
        getline(iss, currentuser);

    }
    current_user_file.close();

    // Read feedback for the current user from the CSV file

    if (!current_uni_file.is_open())
    {
        cerr << "Could not open the file - 'current_uni.csv'" << endl;
        return;
    }

    while (getline(current_uni_file, line))
    {
        istringstream iss(line);
        getline(iss, currentuni);
    }
    current_user_file.close();

    if (!check_file.is_open())
    {
        cerr << "Could not open the file - 'favourite_file.csv'" << endl;
        return;
    }
    while (getline(check_file, line))
    {
        istringstream iss(line);
        getline(iss, checkuser, ',');
        getline(iss, checkuni, '\n');
    }
    current_user_file.close();

    if (currentuser == checkuser && currentuni == checkuni)
    {
        cout << "You have added to favourite before! " << endl;
    }
    else{
        output_file << currentuser << "," << currentuni << "\n";
        cout << "Added to Favourite! " << endl;
    }
}

void viewfavourite()
{
    // Read the current user's username from the CSV file
    string currentuser;
    ifstream current_user_file("current_user.csv");

    if (!current_user_file.is_open())
    {
        cerr << "Could not open the file - 'current_user.csv'" << endl;
        return;
    }

    getline(current_user_file, currentuser);
    current_user_file.close();

    // Read feedback for the current user from the CSV file
    string feedback_file_name = "favourite.csv";
    ifstream feedback_file(feedback_file_name);

    if (!feedback_file.is_open())
    {
        cerr << "Could not open the file - " << feedback_file_name << endl;
        return;
    }

    string line;
    bool feedback_found = false;
    cout << "Your favourite University: " << endl;
    while (getline(feedback_file, line))
    {
        istringstream iss(line);
        string username, feedback_text;
        string university, feedback_reply;
        getline(iss, username, ',');
        getline(iss, university, '\n');
        
        if (username == currentuser)
        {
            cout << university << endl;
            feedback_found = true;
        }
    }

    feedback_file.close();

    if (!feedback_found)
    {
        cout << "No favourite University found for " << currentuser << endl;
    }
}

void uni_menu()
{
    while (true)
    {
        int choice;
        cout << "1. Save to Favourite" << endl;
        cout << "2. Write Feedback" << endl;
        cout << "0. Back" << endl;
        cout << "Enter your Choice: ";
        cin >> choice;

        switch (choice)
        {
        case 0:
            
            break;

        case 1:
            savefavourite();
            break;

        case 2:
            giveFeedback();
            break;
        }
    }
}
