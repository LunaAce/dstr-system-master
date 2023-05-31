#include <iostream>
#include <fstream>
#include <sstream>

struct Feedback
{
    string username;
    string universityName;
    string userFeedback;
    string adminReply;
    string feedbackDate;
};

class FeedbackList
{
public:
    struct FeedbackNode
    {
        FeedbackNode *prev;
        FeedbackNode *next;
        Feedback feedback;

        FeedbackNode(const Feedback &feedback)
            : feedback(feedback), prev(nullptr), next(nullptr) {}
    };

    FeedbackNode *head;
    FeedbackNode *tail;

public:
    FeedbackList() : head(nullptr), tail(nullptr) {}

    void addFeedback(const string &username, const string &universityName,
                     const string &userFeedback, const string &adminReply, const string &feedbackDate)
    {
        Feedback feedback{username, universityName, userFeedback, adminReply, feedbackDate};
        FeedbackNode *newFeedback = new FeedbackNode(feedback);

        if (head == nullptr)
        {
            head = newFeedback;
            tail = newFeedback;
        }
        else
        {
            tail->next = newFeedback;
            newFeedback->prev = tail;
            tail = newFeedback;
        }
    }

    void viewSingleFeedback()
    {
        if (head == nullptr)
        {
            cout << "No feedback available." << endl;
            return;
        }

        char option = ' ';
        FeedbackNode *curr = head;

        while (curr != nullptr)
        {
            // Display the feedback data
            cout << "\nUsername: " << curr->feedback.username << endl;
            cout << "University Name: " << curr->feedback.universityName << endl;
            cout << "User Feedback: " << curr->feedback.userFeedback << endl;
            cout << "Admin Reply: " << curr->feedback.adminReply << endl;
            cout << "Feedback Date: " << curr->feedback.feedbackDate << endl;

            cout << "\nEnter 'P' to view the previous feedback, 'N' to view the next feedback, or 'Q' to quit viewing: ";
            cin >> option;
            option = toupper(option);

            if (option == 'Q')
            {
                break;
            }
            else if (option == 'P')
            {
                if (curr->prev != nullptr)
                {
                    curr = curr->prev;
                }
                else
                {
                    cout << "No previous feedback available. Moving to the last feedback." << endl;
                    curr = tail;
                }
            }
            else if (option == 'N')
            {
                if (curr->next != nullptr)
                {
                    curr = curr->next;
                }
                else
                {
                    cout << "No next feedback available. Moving to the first feedback." << endl;
                    curr = head;
                }
            }
            else
            {
                cout << "Invalid option. Please try again." << endl;
            }
        }
    }

    void quicksortDate(FeedbackNode *low, FeedbackNode *high)
    {
        if (low != nullptr && high != nullptr && low != high && low != high->next)
        {
            FeedbackNode *pivot = partition(low, high);
            quicksortDate(low, pivot->prev);
            quicksortDate(pivot->next, high);
        }
    }

    FeedbackNode *partition(FeedbackNode *low, FeedbackNode *high)
    {
        string pivot = high->feedback.feedbackDate;
        FeedbackNode *i = low->prev;

        for (FeedbackNode *j = low; j != high; j = j->next)
        {
            if (j->feedback.feedbackDate >= pivot)
            {
                i = (i == nullptr) ? low : i->next;
                swapFeedback(i, j);
            }
        }

        i = (i == nullptr) ? low : i->next;
        swapFeedback(i, high);

        return i;
    }

    void swapFeedback(FeedbackNode *a, FeedbackNode *b)
    {
        Feedback temp = a->feedback;
        a->feedback = b->feedback;
        b->feedback = temp;
    }
};

const int MAX_FEEDBACKS = 100; // Maximum number of feedbacks

void readFeedbackCSV(const string &filename, FeedbackList &feedbackList)
{
    ifstream file(filename);

    if (!file.is_open())
    {
        cout << "Error opening file: " << filename << endl;
        return;
    }

    string line;
    int numFeedbacks = 0;

    while (getline(file, line) && numFeedbacks < MAX_FEEDBACKS)
    {
        istringstream iss(line);
        Feedback feedback;

        getline(iss, feedback.username, ',');
        getline(iss, feedback.universityName, ',');
        getline(iss, feedback.userFeedback, ',');
        getline(iss, feedback.adminReply, ',');
        getline(iss, feedback.feedbackDate, ',');

        feedbackList.addFeedback(feedback.username, feedback.universityName,
                                 feedback.userFeedback, feedback.adminReply, feedback.feedbackDate);

        numFeedbacks++;
    }

    file.close();
}

void navigateFeedback()
{
    FeedbackList feedbackList;

    // Read feedback from the CSV file and insert it into the feedback list
    readFeedbackCSV("feedback.csv", feedbackList);

    // Sort the feedback list by date in descending order
    feedbackList.quicksortDate(feedbackList.head, feedbackList.tail);

    // View the feedback
    feedbackList.viewSingleFeedback();
}
