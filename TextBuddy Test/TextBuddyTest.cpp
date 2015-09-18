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

	};
}