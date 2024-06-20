//
// Created by mjsbl on 11/10/2022.
//

#ifndef CSCI_FINAL_ACTION_H
#define CSCI_FINAL_ACTION_H

#endif //CSCI_FINAL_ACTION_H

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class action
{
private:
    vector<string> riddle_questions;
    vector<string> riddle_answers;
public:
    action();
    void setRiddleAnswer(string new_answer_);
    string getRiddleAnswer(int ind);
    void readText();
    bool askQuestion(int lineNum);
    bool doorGame();
    void move();
    void investigate();
    void fight();
    void cookAndEat();
    void giveUp();
    void riddles();
    void printRiddles();
};