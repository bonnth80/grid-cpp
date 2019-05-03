#pragma once
#include "printSets.h"

using namespace std;
void sortTestDemo() {
	Grid<int> testGrid;
	LinkedList<int> rowListA, rowListB, rowListC;
	cout << "::: Rows \n";
	rowListA.add(45); rowListA.add(12); rowListA.add(67);
	rowListA.add(14); rowListA.add(32);	rowListA.add(29);

	rowListB.add(29); rowListB.add(7); rowListB.add(21);
	rowListB.add(54); rowListB.add(33);	rowListB.add(44);

	rowListC.add(29); rowListC.add(7);	rowListC.add(21);
	rowListC.add(54); rowListC.add(33);	rowListC.add(38);
	cout << "rowListA: ";
	printList(rowListA);
	cout << "rowListB: ";
	printList(rowListB);
	cout << "rowListC: ";
	printList(rowListC);

	cout << "\nAdding rows to xGrid: \n\t";

	testGrid.addRow(rowListA);
	testGrid.addRow(rowListB);
	testGrid.addRow(rowListC);

	cout << "Size: " << testGrid.getSize() << endl;
	printGrid(testGrid);
	testGrid.sortGrid();
	printGrid(testGrid);
}
