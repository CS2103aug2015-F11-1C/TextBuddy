#pragma once
// TextList.h
// CE2 - TextBuddy++
// By: Johandy Tantra (A0118890X)
//
//
// This file is used to define the class TextList
// It has a vector to store the list of strings as well as an
// integer to indicate the number of strings are in the vector.
// Within the class you can addText to the list, deleteText from the list,
// clear the list, as well as display all texts.

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class TextList {
private:
	vector<string> _texts;          //to take in vector of texts
	int _numOfTexts;                //to store the number of texts stored in the vector

public:
	TextList();
	int getNumOfTexts();
	string getText(int number);
	void displayText();									//displays all the texts stored in the list
	void addText(string destination, string text);		//to add texts to the vector
	void deleteText(string destination, int number);	//to delete text from the vector
	void clearList(string destination);					//to empty the vector

};