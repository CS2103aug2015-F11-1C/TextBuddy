//
//  TextList.cpp
//  CE1 - Text Buddy
//  By: Johandy Tantra (A0118890X)
//
//  This file is used as an implementation to TextList.h
//

#include "TextList.h"

//list of update strings after each command is executed
const string UPDATE_EMPTYLIST = "The list is empty";
const string UPDATE_ADD = "Added to ";
const string UPDATE_DELETE = "Deleted from ";
const string UPDATE_DELETE_NULL = "There is no such entry in the list";
const string UPDATE_CLEAR = "All content deleted from ";
const string UPDATE_NOT_FOUND = "No such word in the database";

TextList::TextList() {
	_numOfTexts = 0;
}

int TextList::getNumOfTexts() {
	return _numOfTexts;
}

string TextList::getText(int number) {
	return _texts[number];
}

void TextList::displayText() {
	if (!_texts.empty())
		for (int i = 0; i < _numOfTexts; i++) {
			cout << i + 1 << ". " << _texts[i] << endl;
		}
	else
		cout << UPDATE_EMPTYLIST << endl;
}

void TextList::addText(string destination, string text) {
	_texts.push_back(text);
	_numOfTexts++;

	cout << UPDATE_ADD << destination << ": \"" << text << "\"" << endl;
}

void TextList::deleteText(string destination, int number) {
	vector<string>::iterator iter = _texts.begin();

	if (_texts.empty()) {
		cout << UPDATE_EMPTYLIST << endl;
	}
	else if (number > 0 && number <= _numOfTexts) {
		cout << UPDATE_DELETE << destination << ": \"" << _texts[number - 1] << "\"" << endl;

		for (int i = 1; i < number; i++)
			iter++;

		_texts.erase(iter);

		_numOfTexts--;
	}
	else {
		cout << UPDATE_DELETE_NULL << endl;
	}
}

void TextList::clearList(string destination) {
	vector <string>::iterator iter = _texts.begin();

	while (!_texts.empty()) {
		_texts.erase(iter);
	}

	_numOfTexts = 0;

	cout << UPDATE_CLEAR << destination << endl;
}
