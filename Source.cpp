#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

bool AvailableElements(char* str, const char* cs1, const char* cs2);
char* Change(char* str, const char* cs1, const char* cs2);

int main()
{
	char str[101];

	cout << "Enter a string: " << endl;
	cin.getline(str, 100);

	char case1[] = "AGA";
	char case2[] = "OGO";

	if (AvailableElements(str, case1, case2))
	{
		cout << "There are \"AGA\" or \"OGO\" in string " << endl;
	}
	else
		cout << "No \"AGA\" or \"OGO\" in string " << endl;

	char* dest = new char[151];
	dest = Change(str, case1, case2);
	cout << "Modified string (param) : " << str << endl;
	cout << "Modified string (result): " << dest << endl;

	return 0;
}

bool AvailableElements(char* str, const char* cs1, const char* cs2)
{
	const char* compare1 = strstr(str, cs1);
	const char* compare2 = strstr(str, cs2);
	if (compare1 != NULL || compare2 != NULL)
		return true;
	else
		return false;

}

char* Change(char* str, const char* cs1, const char* cs2)
{
	char* t = new char[strlen(str)];
	char* p1;
	char* p2;
	long int pos1 = 0;
	long int pos3 = 0;
	*t = 0;
	while (p1 = strstr(str + pos1, cs1))
	{
		pos3 = p1 - str + 3;
		strncat(t, str + pos1, pos3 - pos1 - 3);
		strcat(t, "**");
		pos1 = pos3;
	}
	while (p2 = strstr(str + pos1, cs2))
	{
		pos3 = p2 - str + 3;
		strncat(t, str + pos1, pos3 - pos1 - 3);
		strcat(t, "**");
		pos1 = pos3;
	}
	strcat(t, str + pos1);
	strcpy(str, t);
	return t;

}