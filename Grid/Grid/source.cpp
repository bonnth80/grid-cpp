#include <iostream>
#include <string>
#include "LinkedList.h"
#include "grid.h"

using namespace std;


void printGrid(const Grid<int> &g) {
	if (g.getSize()) {
		for (int x = 0; x < g.getColSize(); x++) {
			cout << "\t";

			for (int y = 0; y < g.getRowSize(); y++)
				cout << g.get(x, y) << " ";

			cout << endl;
		}
	}
}

void printList(const LinkedList<int> list) //...
{
	cout << "\tList Size: " << list.getSize() << " | ";
	for (int i = 0; i < list.getSize(); i++)
	{
		cout << list.get(i) << " ";
	}
	cout << endl;
}


int main() {
	Grid<int> xGrid;
	LinkedList<int> xListA, xListB, xListC;	

	xListA.add(45);
	xListA.add(12);
	xListA.add(67);
	xListA.add(14);
	xListA.add(32);
	xListA.add(29);

	xListB.add(29);
	xListB.add(7);
	xListB.add(21);
	xListB.add(54);
	xListB.add(33);
	xListB.add(44);

	xListC.add(29);
	xListC.add(7);
	xListC.add(21);
	xListC.add(54);
	xListC.add(33);
	xListC.add(38);

	cout << "\nxListA: \n";
	printList(xListA);
	cout << "\nxListB: \n";
	printList(xListB);
	cout << "\nxListC: \n";
	printList(xListC);

	cout << "\nAdding rows to xGrid: \n";

	xGrid.addRow(xListA);
	xGrid.addRow(xListB);
	xGrid.addRow(xListC);

	cout << "\nxGrid: \n\t";
	cout << "Size: " << xGrid.getSize() << endl;
	printGrid(xGrid);


	cin.get();

	return 0;

}