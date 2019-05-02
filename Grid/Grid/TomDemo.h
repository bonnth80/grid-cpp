#pragma once
#include "printSets.h"
// This is a test
using namespace std;

void addRowColDemo() {
	Grid<int> xGrid;
	LinkedList<int> rowListA, rowListB, rowListC,
		colListD, colListE;

	cout << "************ Rows *************\n";
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

	cout << "\nAdding columns to xGrid: \n\t";

	xGrid.addCol(colListD);
	xGrid.addCol(colListE);

	cout << "Size: " << xGrid.getSize() << endl;
	printGrid(xGrid);
};

void llConstructorDemo() {
	LinkedList<int> xList;

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

	Grid<int> xGrid(xList,4,3);

	printGrid(xGrid);

	cout << endl;
	cout << "Has 99? (expect 0): " << xGrid.contains(99) << endl;
	cout << "Has 37? (expect 1): " << xGrid.contains(37) << endl;
	cout << "Has 50? (expect 0): " << xGrid.contains(50) << endl;
	cout << "Has 17? (expect 0): " << xGrid.contains(17) << endl;
	cout << "Has 25? (expect 1): " << xGrid.contains(25) << endl;
	cout << "Has 14? (expect 1): " << xGrid.contains(14) << endl;
	cout << "Has 82? (expect 0): " << xGrid.contains(82) << endl;

	cout << "\nIs Empty? " << xGrid.isEmpty();


}

void runTomDemo() {
	//addRowColDemo();
	llConstructorDemo();
}
