#include "source\AVLTree.h"
#include"Prototype.h"
#include<iostream>
using namespace std;
void main() {
	int n = 0;
	int stop = 0;
	while (stop != 1) {
		cout << "Stop = false. " << endl << "Exercise: " << endl;
		cout << "1.  Insert AVLTree " << endl;
		cout << "2.  Delete AVLTree " << endl;
		cout << "3.  Even number,odd number, prime number in AVLTree " << endl;
		cout << "4.  Insert Heap" << endl;
		cout << "5.  In Graph" << endl;
		cout << "6.  Delete vertex in Graph" << endl;
		cout << "7.  Weight of AVLTree" << endl;
		cout << "8.  Weight of Heap" << endl;
		cout << "9.  AVLTree to Graph" << endl;
		cout << "10. Heap to Graph" << endl;
		cout << "11. Graph to adjacency matrix" << endl;
		cout << "12. AVLTree to adjacency matrix" << endl;
		cout << "13. Heap to adjacency matrix" << endl;
		cout << "14. Circuit in Graph" << endl;
		cout << "15. Matrix to Graph" << endl;
		cout << "16. Strong connection in Graph " << endl;
		cout << "17. Check adjacency matrix is AVLTree" << endl;
		cout << "18. Find min path with two vertex" << endl;
		cout << "19. Find min path variant" << endl;
		cout << "20. Check two graph is isomorphic" << endl;
		cout << "Request input a number n = ";
		cin >> n;      // print: Request input a number "n" 
		system("cls");
		// Check how to 
		if (!cin.fail()) {
			switch (n) {
			case 1:
				ex1();
				break;
			case 2:
				ex2();
				break;
			case 3:
				ex3();
				break;
			case 4:
				ex4();
				break;
			case 5:
				ex5();
				break;
			case 6:
				ex6();
				break;
			case 7:
				ex7();
				break;
			case 8:
				ex8();
				break;
			case 9:
				ex9();
				break;
			case 10:
				ex10();
				break;
			case 11:
				ex11();
				break;
			case 12:
				ex12();
				break;
			case 13:
				ex13();
				break;
			case 14:
				ex14();
				break;
			case 15:
				ex15();
				break;
			case 16:
				ex16();
				break;
			case 17:
				ex17();
				break;
			case 18:
				ex18();
				break;
			case 19:
				ex19();
				break;
			case 20:
				ex20();
				break;
			default:
				cout << "The invalid number!" << endl;
				break;
			}
		}
		cout << endl << "*****************************" << endl;
		while (stop != 1) {
			if (stop != 0)
				cout << "The invalid stop! " << endl;
			cout << "0. Stop = false " << endl;
			cout << "1. Stop = true " << endl;
			cout << "Please press one valid stop! ";
			cin >> stop;
			if (stop == 0)
				break;
		}
		//xóa màn hình
		system("cls");
	}
	
	//system("pause");
}