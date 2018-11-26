#include <iostream>
#include <cctype>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

//int solution(char *S)
//{
//	int i = 0;
//	int len = 0;
//	while(S[i++] != '\0')
//	{
//		len++;
//	}

//	return len;
//}

int solution(vector<int> &T)
{
	std::sort(T.begin(), T.end());

	int count = 1;
	for (int i = 1; i < T.capacity() && count < T.capacity() / 2; i++)
		if (T[i] > T[i - 1])
			count++;
	return count;
}

int main()
{
//	cout << "Hello World!" << endl;
//	cout << "isalnum('-') " << isalnum('-') << endl;
//	cout << "isalnum('*') " << isalnum('*') << endl;
//	cout << "isalnum('A') " << isalnum('A') << endl;
//	cout << "isalnum('3') " << isalnum('3') << endl;
//	cout << "isdigit('3') " << isdigit('3') << endl;
//	cout << "isdigit('A') " << isdigit('A') << endl;

//	cout << "solution() " << solution("123456789") << endl;
//	cout << "strlen() " << strlen("123456789") << endl;

	int myints[] = {3,4,7,7,6,6};
	std::vector<int> myvector (myints, myints+6);
	cout << "return " << solution(myvector) << endl;

	return 0;
}

///* qsort example */
//#include <stdio.h>      /* printf */
//#include <stdlib.h>     /* qsort */

//int values[] = { 40, 10, 100, 90, 20, 25 };

//int compare (const void * a, const void * b)
//{
//  return ( *(int*)a - *(int*)b );
//}

//int main ()
//{
//  int n;
//  qsort (values, 6, sizeof(int), compare);
//  for (n=0; n<6; n++)
//	 printf ("%d ",values[n]);
//  return 0;
//}
