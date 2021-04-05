#include <iostream>
#include "Text_Iter.h"
#include "TextNode.h"
#include "Text.cpp"
#include "TextIter.cpp"
#include "TextNode.cpp"

 using namespace std;

int main()
{

	char* temp = "Qwerty. \nAsd fgh zxc.";
	Text A(temp);
	TextIter B = A.Find("s");

	A.InsertDataInTheWord("jui", B);

	cout << endl << A;
	return 0;

}
