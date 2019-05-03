#pragma once
#include <stack>
#include "printSets.h"

// This is a test2
using namespace std;


Grid<int> addRowColDemo() {
	cout << "\n************* addRowColDemo() ***********\n";
	Grid<int> xGrid;
	LinkedList<int> rowListA, rowListB, rowListC, rowListD,
		colListD, colListE;

	cout << "::: Rows \n";
	rowListA.add(45); rowListA.add(12); rowListA.add(67);
	rowListA.add(14); rowListA.add(32);	rowListA.add(29);

	rowListB.add(29); rowListB.add(7); rowListB.add(21);
	rowListB.add(54); rowListB.add(33);	rowListB.add(44);

	rowListC.add(11); rowListC.add(22);	rowListC.add(33);
	rowListC.add(44); rowListC.add(55);	rowListC.add(66);

	rowListD.add(60); rowListD.add(74);	rowListD.add(81);
	rowListD.add(59); rowListD.add(30);	rowListD.add(47);

	cout << "rowListA: ";
	printList(rowListA);
	cout << "rowListB: ";
	printList(rowListB);
	cout << "rowListC: ";
	printList(rowListC);
	cout << "rowListD: ";
	printList(rowListD);

	cout << "\nAdding rows to xGrid: \n\t";

	xGrid.addRow(rowListA);
	xGrid.addRow(rowListB);
	xGrid.addRow(rowListC);
	xGrid.addRow(rowListD);

	cout << "Size: " << xGrid.getSize() << endl;
	printGrid(xGrid);

	cout << "\n::: Columns\n";
	colListD.add(120);
	colListD.add(141);
	colListD.add(192);
	colListD.add(113);

	colListE.add(241);
	colListE.add(288);
	colListE.add(252);
	colListE.add(256);

	cout << "colListD: ";
	printList(colListD);
	cout << "colListE: ";
	printList(colListE);

	cout << "\nAdding columns to xGrid: \n\t";

	xGrid.addCol(colListD);
	xGrid.addCol(colListE);

	cout << "Size: " << xGrid.getSize() << endl;
	printGrid(xGrid);

	return xGrid;
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

void removeDemo() {
	Grid<int> xGrid = addRowColDemo();
	cout << "\n\n************** removeDemo() *************\n";

	xGrid.removeRow();	
	cout << "\nNew Grid after removeRow(): \n\t";
	cout << "Size: " << xGrid.getSize() << endl;
	printGrid(xGrid);


	xGrid.removeCol();
	cout << "\nNew Grid after removeCol(): \n\t";
	cout << "Size: " << xGrid.getSize() << endl;
	printGrid(xGrid);

	cout << endl << endl;
	
}

void replaceAtDemo() {
	Grid<int> xGrid = addRowColDemo();
	int x = 0;
	cout << "\n\n************** replaceAtDemo() *************\n";

	x = xGrid.replaceAt(1, 12, 666);
	cout << "\nNew Grid after replaceAt(): \n\t";
	cout << "Size: " << xGrid.getSize() << endl;
	printGrid(xGrid);

	cout << "\nReplaced value: " << x << endl;;
}

void clearDemo() {
	Grid<int> xGrid = addRowColDemo();
	cout << "\n\n************** clearDemo() *************\n";

	xGrid.clear();
	cout << "\nNew Grid after clear(): \n\t";
	cout << "Size: " << xGrid.getSize() << endl;
	printGrid(xGrid);
}

void reverseDemo() {
	Grid<int> xGrid = addRowColDemo();
	cout << "\n\n************** reverseDemo() *************\n";

	xGrid.reverse();
	cout << "\nNew Grid after reverse(): \n\t";
	cout << "Size: " << xGrid.getSize() << endl;
	printGrid(xGrid);

}

void runTomDemo() {
	//addRowColDemo();
	//llConstructorDemo();
	//removeDemo();
	//replaceAtDemo();
	//clearDemo();
	reverseDemo();
	cout << endl;
}
