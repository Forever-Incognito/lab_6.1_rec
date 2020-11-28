//lab_6.1_rec

#include <iostream>
#include <iomanip>
#include <time.h>

using namespace std;

void Create(int* b, const int size, const int Low, const int High, int i)
{
	b[i] = Low + rand() % (High - Low + 1);
	if (i < size - 1)
		Create(b, size, Low, High, i + 1);
}

void Print(int* b, const int size, int i)
{
	cout << setw(4) << b[i];
	if (i < size - 1)
		Print(b, size, i + 1);
	else
		cout << endl;
}

int Count(int* b, const int size, int i, int count)
{
	if (b[i] % 2 == 0 && !(b[i] > 0))
		count++;

	if (i < size - 1)
		return Count(b, size, i + 1, count);
	else
		return count;
}

int Sum(int* b, const int size, int i, int S)
{
	if (b[i] % 2 == 0 && !(b[i] > 0))
		S += b[i];

	if (i < size - 1)
		return Sum(b, size, i + 1, S);
	else
		return S;
}

void Zero(int* b, const int size, int i)
{
	if (b[i] % 2 == 0 && !(b[i] > 0))
		b[i] = 0;

	if (i < size - 1)
		Zero(b, size, i + 1);
}

int main()
{
	srand((unsigned)time(NULL));

	const int size = 24;
	int b[size];

	int Low = -15;
	int High = 75;

	Create(b, size, Low, High, 0);
	Print(b, size, 0);

	cout << " Count = " << Count(b, size, 0, 0) << endl;
	cout << " Sum = " << Sum(b, size, 0, 0) << endl;

	Zero(b, size, 0);
	Print(b, size, 0);

	return 0;
}