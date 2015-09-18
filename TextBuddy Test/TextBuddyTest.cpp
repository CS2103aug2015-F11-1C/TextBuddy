#include "stdafx.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace TextBuddyTest{		
	TEST_CLASS(TextBuddy_Test){
	public:
		
		TEST_METHOD(addText_Test){
			TextList List;

			List.addText("myfile.txt", "I am flying");
			
			string expected = "I am flying";

			Assert::AreEqual(expected, List.getText(List.getNumOfTexts()-1));
		}

		TEST_METHOD(sortList_Test) {
			TextList List;

			List.addText("myfile.txt", "without wings");
			List.addText("myfile.txt", "I am flying");

			List.sortList();

			vector<string> Expected;

			Expected.push_back("I am flying");
			Expected.push_back("without wings");

			for (int i = 0; i < Expected.size(); i++) {
				Assert::AreEqual(Expected[i], List.getText(i));
			}
		}
	};
}