#pragma once
#include "printSets.h"

using namespace std;

void addRowColDemo() {
	cout << "\n************* addRowColDemo() ***********\n";
	Grid<int> xGrid;
	LinkedList<int> rowListA, rowListB, rowListC,
		colListD, colListE;

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

	xGrid.addRow(rowListA);
	xGrid.addRow(rowListB);
	xGrid.addRow(rowListC);

	cout << "Size: " << xGrid.getSize() << endl;
	printGrid(xGrid);

	cout << "\n::: Columns\n";
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

	cout << "\nAdding columns to xGrid: \n\t";

	xGrid.addCol(colListD);
	xGrid.addCol(colListE);

	cout << "Size: " << xGrid.getSize() << endl;
	printGrid(xGrid);
};

void llConstructorDemo() {
	cout << "\n************ llConstructorDemo() *********";
	LinkedList<int> xList;
	cout << endl << endl;

	xList.add(23);
	xList.add(14);
	xList.add(8);
	xList.add(32);
	xList.add(18);
	xList.add(37);
	xList.add(21);
	xList.add(27);
	xList.add(15);
	xList.add(12);
	xList.add(25);
	xList.add(9);

	cout << "creating someGrid:\n";
	Grid<int> someGrid(xList,4,3);

	printGrid(someGrid);

	cout << endl;
	cout << "Has 99? (expect 0): " << someGrid.contains(99) << endl;
	cout << "Has 37? (expect 1): " << someGrid.contains(37) << endl;
	cout << "Has 50? (expect 0): " << someGrid.contains(50) << endl;
	cout << "Has 17? (expect 0): " << someGrid.contains(17) << endl;
	cout << "Has 25? (expect 1): " << someGrid.contains(25) << endl;
	cout << "Has 14? (expect 1): " << someGrid.contains(14) << endl;
	cout << "Has 82? (expect 0): " << someGrid.contains(82) << endl;

	cout << "\nIs Empty? " << someGrid.isEmpty();


}

void runTomDemo() {
	addRowColDemo();
	llConstructorDemo();
}