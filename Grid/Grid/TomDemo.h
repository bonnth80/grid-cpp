#pragma once
#include "printSets.h"

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
}

void runTomDemo() {
	//addRowColDemo();
	llConstructorDemo();
}