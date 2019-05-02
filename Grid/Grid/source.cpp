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
	LinkedList<int> rowListA, rowListB, rowListC,
		colListD, colListE;

	cout << "************ Rows *************\n";
	rowListA.add(45);
	rowListA.add(12);
	rowListA.add(67);
	rowListA.add(14);
	rowListA.add(32);
	rowListA.add(29);

	rowListB.add(29);
	rowListB.add(7);
	rowListB.add(21);
	rowListB.add(54);
	rowListB.add(33);
	rowListB.add(44);

	rowListC.add(29);
	rowListC.add(7);
	rowListC.add(21);
	rowListC.add(54);
	rowListC.add(33);
	rowListC.add(38);

	cout << "rowListA: \n";
	printList(rowListA);
	cout << "rowListB: \n";
	printList(rowListB);
	cout << "rowListC: \n";
	printList(rowListC);

	cout << "\nAdding rows to xGrid: ";

	xGrid.addRow(rowListA);
	xGrid.addRow(rowListB);
	xGrid.addRow(rowListC);

	cout << "\nxGrid: \n\t";
	cout << "Size: " << xGrid.getSize() << endl;
	printGrid(xGrid);

	cout << "\n************ Columns *************\n";
	colListD.add(120);
	colListD.add(141);
	colListD.add(192);
	
	colListE.add(241);
	colListE.add(288);
	colListE.add(252);

	cout << "colListD: ";
	printList(colListD);
	cout << "colListE: ";
	printList(colListE);

	cout << "\nAdding columns to xGrid: ";

	xGrid.addCol(colListD);
	xGrid.addCol(colListE);

	cout << "\nxGrid: \n\t";
	cout << "Size: " << xGrid.getSize() << endl;
	printGrid(xGrid);

	cin.get();

	return 0;

}