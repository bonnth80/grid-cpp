#pragma once
#include "LinkedList.h"
#include <stdexcept>
using namespace std;

template <typename T>
class gNode {
public:
	gNode<T> *previous;
	gNode<T> *next;
	gNode<T> *upper;
	gNode<T> *lower;

	T element;

	gNode()					// No-arg constructor
	{
		next = nullptr;
		previous = nullptr;
		upper = nullptr;
		lower = nullptr;
	}
	gNode(T element)			// Constructor
	{
		this->element = element;
		next = nullptr;
		previous = nullptr;
		upper = nullptr;
		lower = nullptr;
	}
};

template <typename T>
class Grid {
private:
	// limits
	gNode<T> *topLeft;
	gNode<T> *topRight;
	gNode<T> *bottomLeft;
	gNode<T> *bottomRight;

	//sizes
	int sizeRow;
	int sizeCol;

	//void addElement(T element);

public:
	// Constructors
	Grid();

	Grid(int x, int y, T arr[] ) {
		// stub
	};

	Grid(int x, int y, LinkedList<T> list) {
		//stub
	};
	
	 //Accessors
	int getSize() const;
	int getRowSize() const;
	int getColSize() const;
	T getFirst() const;			// return top left element
	T getLast() const;			// return bottom right element
	T replaceAt(int, int, T);
	void reverse();			// use stack	
	bool contains(T) const;
	T get(int, int) const;
	bool isEmpty() const;
	
	// Modifiers
	void addRow(LinkedList<T>);	// set default int to sizeCol -1
	void addCol(LinkedList<T>);	// set default int to sizeRow -1
	LinkedList<T> removeRow(int);		// set default int to sizeCol -1
	LinkedList<T> removeCol(int);		// set default int to sizeRow -1
	void clear();

	// Sorters
	void sortGrid();
	void sortRow(int);
	void sortAllRows();
	void sortCol(int);
	void sortAllCols();
};

template <typename T>
Grid<T>::Grid() {
	topLeft = nullptr;
	bottomLeft = nullptr;
	topRight = nullptr;
	bottomRight = nullptr;
	sizeRow = 0;
	sizeCol = 0;
}

template<typename T>
int Grid<T>::getSize() const {
	return getRowSize()*getColSize();
}

template<typename T>
int Grid<T>::getRowSize() const {
	return sizeRow;
}
using namespace std;

template<typename T>
int Grid<T>::getColSize() const {
	return sizeCol;
}

template<typename T>
void Grid<T>::addRow(LinkedList<T> list) {
	// only add if list is correct size or grid is empty
	if ((list.getSize() > 0) && (list.getSize() == getRowSize() || getColSize() == 0)) {
		gNode<T> *current = topLeft;
		gNode<T> *previousRowNode = nullptr;

		// if the added row is the only existing row
		if (getColSize() == 0) {
			sizeRow = list.getSize();

			gNode<T> *previous = nullptr;

			// set first node as topLeft and bottomLeft limits
			topLeft = bottomLeft = new gNode<T>(list.get(0));
			current = topLeft;

			// add list elements to grid
			for (int i = 1; i < list.getSize(); i++) {
				current->next = new gNode<T>(list.get(i));
				previous = current;
				current = current->next;
				current->previous = previous;
			}

			// set last node as topRight and bottomRight limits
			topRight = bottomRight = current;
		}

		// if the added row is being appended onto an existing set
		else {
			previousRowNode = bottomLeft;
			bottomLeft = new gNode<T>(list.get(0));
			current = bottomLeft;
			current->upper = previousRowNode;
			previousRowNode->lower = current;

			for (int i = 1; i < list.getSize(); i++) {
				current->next = new gNode<T>(list.get(i));
				(current->next)->previous = current;

				current = current->next;
				previousRowNode = previousRowNode->next;

				current->upper = previousRowNode;
				previousRowNode->lower = current;				
			}

			bottomRight = current;
		}

		// increase the column size
		sizeCol++;
	}
}

template<typename T>
void Grid<T>::addCol(LinkedList<T> list) {
	// only add if list is correct size or grid is empty
	if ((list.getSize() > 0) && (list.getSize() == getColSize() || getColSize() == 0)) {
		gNode<T> *current = topLeft;
		gNode<T> *previousColumnNode = nullptr;

		// if the added column is the only existing column
		if (getRowSize() == 0) {
			sizeCol = list.getSize();

			gNode<T> *previous = nullptr;

			// set first node as topLeft and topRight limits
			topLeft = topRight = new gNode<T>(list.get(0));
			current = topLeft;

			// add list elements to grid
			for (int i = 1; i < list.getSize(); i++) {
				current->lower = new gNode<T>(list.get(i));
				previous = current;
				current = current->lower;
				current->upper = previous;
			}

			// set last node as bottomLeft and bottomRight limits
			bottomLeft = bottomRight = current;
		}

		// if the added column is being appended onto an existing set
		else {
			previousColumnNode = topRight;
			topRight = new gNode<T>(list.get(0));
			current = topRight;
			current->previous = previousColumnNode;
			previousColumnNode->next = current;

			for (int i = 1; i < list.getSize(); i++) {
				current->lower = new gNode<T>(list.get(i));
				(current->lower)->upper = current;

				current = current->lower;
				previousColumnNode = previousColumnNode->lower;

				current->previous = previousColumnNode;
				previousColumnNode->next = current;
			}

			bottomRight = current;
		}

		// increase the column size
		sizeRow++;
	}
}

template<typename T>
T Grid<T>::getFirst() const {
	if (topLeft == nullptr) {
		throw runtime_error("Grid out of range");
	}
	else
		return topLeft->element;
}

template<typename T>
T Grid<T>::getLast() const {
	if (bottomRight == nullptr) {
		throw runtime_error("Grid out of Range");
	}
	else {
		return bottomRight->element;
	}
}

template<typename T>
LinkedList<T> Grid<T>::removeRow(int index) {
	return;
}
template<typename T>
LinkedList<T> Grid<T>::removeCol(int index) {
	return;
}

template<typename T>
void Grid<T>::clear() {
	//stub
	//Remove row/col
}

template<typename T>
bool Grid<T>::contains(T element) const{
	return true;
}

template<typename T>
T Grid<T>::get(int row, int col)const {
	if (getSize() == 0)
		throw ("cannot retrieve element from empty grid.");
	else {
		gNode<T> *current = topLeft;

		while (row > 0) {
			current = current->lower;
			row--;
		}

		while (col > 0) {
			current = current->next;
			col--;
		}

		return current->element;
	}
}

template<typename T>
bool Grid<T>::isEmpty() const {
	return (topLeft == nullptr && topRight == nullptr && bottomLeft == nullptr && bottomRight == nullptr);
}

template<typename T>
T Grid<T>::replaceAt(int rowIndex, int colIndex, T element) {
	//Returns Replaced Element
}

template<typename T>
void Grid<T>::reverse() {
	//Use a stack to feed rows into stack and reverse the grid
}

template<typename T>
void Grid<T>::sortGrid() {
	//Throw grid into Queue, sort queue using sort function, redo grid
}

template<typename T>
void Grid<T>::sortRow(int index) {
	//Bubble
}

template<typename T>
void Grid<T>::sortCol(int index) {
	//Bubble
}

template<typename T>
void Grid<T>::sortAllCols() {
	int counter = 0;
	while (current < sizeRow) {
		sortCol(counter++);
	}
}

template<typename T>
void Grid<T>::sortAllRows() {	
	int counter = 0;
	while (counter < sizeCol) {
		sortRow(counter++);
	}
}