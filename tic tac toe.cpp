#include <iostream>
#include <time.h>
#include "chrono"
using namespace std;
using namespace std::chrono;
char a[10] = { 'o','1','2','3','4','5','6','7','8','9' };
void draw();
int  check();
int main() {
	char ch, mark;
	int  p = 1, i, choice, counter = 0;

	srand(time(NULL)); //cpu decision

	auto start = system_clock::now();
	auto end = system_clock::now();
	duration<double> elapsed_seconds = end - start;

	cout << "\t\t\tTic Tac Toe\n" << "1_ Player vs. Player\n" << "2_ Player vs. CPU\n" << "Which one? " << endl;
	cin >> ch;

	if (ch == '1')
	{
		do
		{
			draw();
			p = (p % 2) ? 1 : 2;
			mark = (p == 1) ? 'X' : 'O';

			cout << "\nPlayer " << p << ":  ";
			cin >> choice;

			if (choice == 1 && a[1] == '1')
				a[1] = mark;
			else if (choice == 2 && a[2] == '2')
				a[2] = mark;
			else if (choice == 3 && a[3] == '3')
				a[3] = mark;
			else if (choice == 4 && a[4] == '4')
				a[4] = mark;
			else if (choice == 5 && a[5] == '5')
				a[5] = mark;
			else if (choice == 6 && a[6] == '6')
				a[6] = mark;
			else if (choice == 7 && a[7] == '7')
				a[7] = mark;
			else if (choice == 8 && a[8] == '8')
				a[8] = mark;
			else if (choice == 9 && a[9] == '9')
				a[9] = mark;
			else { cout << "Invalid move "; p--; }
			i = check();
			p++;
		} while (i == -1);
		draw();

		if (i == 1) {
			cout << "==>\a Player" << --p << " win" << endl;
			cout << "\nelapsed time: " << elapsed_seconds.count() << endl;
		}

		else {
			cout << "==>\a Game draw" << endl;
			cout << "\nelapsed time: " << elapsed_seconds.count() << endl;
		}

	}
	else if (ch == '2') {
		do {
			draw();
			p = (p % 2) ? 1 : 2;
			mark = (p == 1) ? 'X' : 'O';
			if ((p % 2) != 0)
			{
				cout << "\nPlayer " << p << ": ";
				cin >> choice;
			}
			else if ((p % 2) == 0)
			{
				choice = rand() % 9 + 1;
				cout << "\nCPU " << ": ";
			}


			if (choice == 1 && a[1] == '1')
				a[1] = mark;
			else if (choice == 2 && a[2] == '2')
				a[2] = mark;
			else if (choice == 3 && a[3] == '3')
				a[3] = mark;
			else if (choice == 4 && a[4] == '4')
				a[4] = mark;
			else if (choice == 5 && a[5] == '5')
				a[5] = mark;
			else if (choice == 6 && a[6] == '6')
				a[6] = mark;
			else if (choice == 7 && a[7] == '7')
				a[7] = mark;
			else if (choice == 8 && a[8] == '8')
				a[8] = mark;
			else if (choice == 9 && a[9] == '9')
				a[9] = mark;
			else { cout << "Invalid move "; p--; }
			i = check();
			p++;
			counter++;
		} while (i == -1);
		draw();

		if (i == 1)
		{
			if ((counter % 2) != 0) {
				cout << "==>\a Player win ";
				cout << "\nelapsed time: " << elapsed_seconds.count() << endl;
			}
			else {
				cout << "==>\a CPU win ";
				cout << "\nelapsed time: " << elapsed_seconds.count() << endl;
			}
		}
		else {
			cout << "==>\a Game draw";
			cout << "\nelapsed time: " << elapsed_seconds.count() << endl;
		}
	};

}
void draw()
{
	cout << endl;
	cout << "  " << a[1] << "  |  " << a[2] << "  |  " << a[3] << endl;
	cout << "_____|_____|_____" << endl;
	cout << "  " << a[4] << "  |  " << a[5] << "  |  " << a[6] << endl;
	cout << "_____|_____|_____" << endl;
	cout << "  " << a[7] << "  |  " << a[8] << "  |  " << a[9] << endl;
}
int check()
{
	if (a[1] == a[2] && a[2] == a[3])     	return 1;
	else if (a[4] == a[5] && a[5] == a[6])	return 1;
	else if (a[7] == a[8] && a[8] == a[9])	return 1;
	else if (a[1] == a[4] && a[4] == a[7])	return 1;
	else if (a[2] == a[5] && a[5] == a[8])	return 1;
	else if (a[3] == a[6] && a[6] == a[9])	return 1;
	else if (a[1] == a[5] && a[5] == a[9])	return 1;
	else if (a[3] == a[5] && a[5] == a[7])	return 1;

	if (a[1] != '1' && a[2] != '2' && a[3] != '3' && a[4] != '4' &&
		a[5] != '5' && a[6] != '6' && a[7] != '7' && a[8] != '8' && a[9] != '9')
		return 0;

	else
		return -1;
}