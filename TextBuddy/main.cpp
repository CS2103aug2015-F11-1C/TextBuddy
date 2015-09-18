//  main.cpp
//  CE1 - Text Buddy
//  By: Johandy Tantra (A0118890X)
//
//  This file is to execute the program.
//  It reads any inputs from a file / open a new file if the file does not exist
//  It processes all the inputs until the user inputs 'exit'
//  It also rewrites the file opened to store the output.
//

#include "TextList.h"
#include <fstream>

//declaring list of commands as constant strings
const string CMD_REQUEST = "command: ";
const string CMD_ADD = "add";
const string CMD_DISPLAY = "display";
const string CMD_DELETE = "delete";
const string CMD_CLEAR = "clear";
const string CMD_EXIT = "exit";
const string CMD_SORT = "sort";
const string CMD_SEARCH = "search";

void processCommand(string destination, string cmd, TextList* list);
void initializeList(string source, TextList* list);
void overwriteFile(string destination, TextList* list);
void welcomeText(string destination);
void requestCommand(string &cmd);

int main(int argc, char* argv[]) {
	welcomeText(argv[1]);

	TextList list;      //to store all the stored information in source file

	initializeList(argv[1], &list);

	string cmd;         //to take in the commands

						//to process the commands
	while (cmd != CMD_EXIT) {
		requestCommand(cmd);

		processCommand(argv[1], cmd, &list);

		//saves to the output file after every command is executed
		overwriteFile(argv[1], &list);
	}

	return 0;
}

void processCommand(string destination, string cmd, TextList* list) {
	if (cmd == CMD_ADD) {
		string text;

		getline(cin, text);

		//substr 1 is passed into the function to erase extra space because of getline
		list->addText(destination, text.substr(1));
	}
	else if (cmd == CMD_DISPLAY) {
		list->displayText();
	}
	else if (cmd == CMD_DELETE) {
		int num = 0;

		cin >> num;

		list->deleteText(destination, num);
	}
	else if (cmd == CMD_CLEAR) {
		list->clearList(destination);
	}
	else if (cmd == CMD_SORT) {
		list->sortList();
	}
	else if (cmd == CMD_SEARCH) {
		string keyword;

		cin >> keyword;

		cout << list->searchList(keyword) << endl;
	}
	
}

//To initialize the list with the contents of the source file if any
void initializeList(string source, TextList* list) {
	ifstream input(source);

	string text;

	while (getline(input, text)) {
		list->addText(source, text);
	}

	input.close();
}

//Overwrites the current file with the list of inputs stored in the current database
void overwriteFile(string destination, TextList* list) {
	ofstream output(destination);

	for (int i = 0; i < list->getNumOfTexts(); i++) {
		output << list->getText(i) << endl;
	}

	output.close();
}

//to print out the welcome text
void welcomeText(string destination) {
	cout << "Welcome to TextBuddy. " << destination << " is ready for use" << endl;
}

void requestCommand(string &cmd) {
	cout << CMD_REQUEST;

	cin >> cmd;
}

