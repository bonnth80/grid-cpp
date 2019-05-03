#pragma once

void printGrid(const Grid<int> &g) {
	if (g.getSize()) {
		for (int y = 0; y < g.getColSize(); y++) {
			cout << "\t";

			for (int x = 0; x < g.getRowSize(); x++)
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