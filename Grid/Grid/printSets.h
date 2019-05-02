#pragma once

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