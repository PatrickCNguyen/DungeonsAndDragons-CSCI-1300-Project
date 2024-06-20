#include "Action.h"
#include <fstream>
#include <random>

int split(string x, char y, string arr[], int arr_size)
{
    int size = 0;
    if (x != "")
    {
        int sl = x.length();
        int a = 0;
        int z = 0;
        for(int i=0; i<=sl; i++)
        {
            if(x[i] == y)
            {
                arr[a] = x.substr(z,i-z);
                a++;
                z = i + 1;
                size++;
            }
            if(i == sl)
            {
                arr[a] = x.substr(z,sl-z);
                size++;
            }
        }
        if (size > arr_size)
        {
            return -1;
        }
        else if (a == 0)
        {
            return 1;
        }
    }
    else
    {
        return 0;
    }
    return size;
}

action::action()
{

}

void action::readText()
{
    string file = "C:\\Users\\mjsbl\\CLionProjects\\CSCI_Final\\Riddle.txt";
    string line = "";
    ifstream inFile;
    inFile.open(file);

    string split_arr[2];

    if (inFile.is_open())
    {
        int count = 0;
        while (getline(inFile,line))
        {
            split(line, '~', split_arr, 2);
            riddle_questions.push_back(split_arr[0]);
            riddle_answers.push_back(split_arr[1]);
        }
    }
    else
    {
        cout << "file not opened" << endl;
    }

}
bool action::doorGame()
{
    enum choices {rock, paper, scissors};
    enum results {win, draw, lose};
    //user across top, computer across side
    int action_matrix[3][3] = {
            {draw, win, lose},
            {lose, draw, lose},
            {win, lose, draw}
    };

    int count = 0;
    int choice;
    int random;
    srand(time(NULL));
    while (count < 3)
    {
        cout << "Choose:" << endl;
        cout << " 1) Boulder" << endl;
        cout << " 2) Parchment" << endl;
        cout << " 3) Shears" << endl;
        cin >> choice;
        random = rand() % 3;
        int result = action_matrix[random][choice];
        if (result == win) {
            return true;
        }
        count++;
        if (count == 3)
        {
            return false;
        }
    }
    return false;
}

bool action::askQuestion(int NumLine)
{
    string answer;
    cout << riddle_questions[NumLine] << endl;
    cin >> answer;
    if (answer == riddle_answers[NumLine])
    {
        return true;
    }
    else
    {
        return false;
    }
}

void action::setRiddleAnswer(string new_answer)
{
    riddle_answers.push_back(new_answer);
}
string action::getRiddleAnswer(int index)
{
    return riddle_answers[index];
}

void action::printRiddles()
{
    for (int i=0; i<20; i++)
    {
        cout << riddle_answers[i] << endl;
    }
}
