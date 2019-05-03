#pragma once
#include "LinkedList.h"
#include <stack>
#include <stdexcept>
#include <queue>
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

public:
	// Constructors
	Grid();										// done - Tom
	Grid(LinkedList<T>, int, int);				// done - Tom
	
	 //Accessors
	int getSize() const;		// done - Tom
	int getRowSize() const;		// done - Tom
	int getColSize() const;     // done - Tom
	T get(int, int) const;		// done - Tom;
	T getFirst() const;			// done - Tom; return top left element
	T getLast() const;			// done - Tom; return bottom right element
	bool contains(T) const;		// done - Tom
	bool isEmpty() const;		// done - Dave
	
	// Modifiers
	void addRow(LinkedList<T>);			// done - Tom;
	void addCol(LinkedList<T>);			// done - Tom;
	void removeRow(int i = -1);			// done - Tom;
	void removeCol(int i = -1);			// done - Tom;
	T replaceAt(int, int, T);			// done - Tom;
	void reverse();						// done - Tom; use stack	
	void clear();						// done - Tom;

	// Sorters
	void sortGrid();
	void sortRow(int);
	void sortAllRows();
	void sortCol(int);
	void sortAllCols();
};

// *********** CONSTRUCTORS *************
template<typename T>
Grid<T>::Grid() {
	// limits
	topLeft = topRight = bottomLeft = bottomRight = nullptr;

	//sizes
	sizeRow = sizeCol = 0;
}

template<typename T>
Grid<T>::Grid(LinkedList<T> list, int sizeX, int sizeY) {
	// execut only if dimensions provided are greater than 1
	// and only if the dimensions match the size of the list
	if ((list.getSize() > 0) && (sizeX > 0) && (sizeY > 0)
		&& (list.getSize() == sizeX * sizeY)) {
		LinkedList<T> tempList;

		for (int i = 0; i < sizeY; i++) {
			tempList.clear();
			for (int x = 0; x < sizeX; x++) {
				tempList.add(list.removeFirst());
			}
			addRow(tempList);
		}
	}
}

// *********** ACCESSORS ************
template<typename T>
int Grid<T>::getSize() const {
	return getRowSize()*getColSize();
}

template<typename T>
int Grid<T>::getRowSize() const {
	return sizeRow;
}

template<typename T>
int Grid<T>::getColSize() const {
	return sizeCol;
}

template<typename T>
T Grid<T>::get(int x, int y)const {
	if (getSize() == 0)
		throw ("cannot retrieve element from empty grid.");
	else {
		gNode<T> *current = topLeft;

		while (y-- > 0)
			current = current->lower;

		while (x-- > 0)
			current = current->next;

		return current->element;
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
bool Grid<T>::contains(T searchKey) const {
	gNode<T> *currentRowNode = topLeft;
	gNode<T> *currentNode = nullptr;

	while (currentRowNode != nullptr) {
		currentNode = currentRowNode;
		while (currentNode != nullptr) {
			if (currentNode->element != searchKey)
				currentNode = currentNode->next;
			else
				return true;
		}
		currentRowNode = currentRowNode->lower;
	}

	return false;
}

template<typename T>
bool Grid<T>::isEmpty() const {
	return (topLeft == nullptr && topRight == nullptr && bottomLeft == nullptr && bottomRight == nullptr);
}

// ************* MODIFIERS *************
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
void Grid<T>::removeRow(int index) {
	// interpret default arguments
	if (index == -1)
		index = sizeCol - 1;
	
	//only execute of index is in range
	if (index < sizeCol) {
		gNode<T> *previousRowNode = nullptr;
		gNode<T> *currentRowNode = topLeft;
		gNode<T> *nextRowNode = nullptr;
		gNode<T> *temp = nullptr;
		
		// navigate to row index
		while (index-- > 0) {
			currentRowNode = currentRowNode->lower;
		}

		while (currentRowNode != nullptr) {
			// get upper and lower rows
			previousRowNode = currentRowNode->upper;
			nextRowNode = currentRowNode->lower;

			// reassign uppers and lowers
			if (currentRowNode->upper != nullptr)
				(currentRowNode->upper)->lower = currentRowNode->lower;
			if (currentRowNode->lower != nullptr)
				(currentRowNode->lower)->upper = currentRowNode->upper;

			// check for limits and reassign if necessary
			if (topLeft == currentRowNode && nextRowNode != nullptr)
				topLeft = nextRowNode;

			if (bottomLeft == currentRowNode && previousRowNode != nullptr)
				bottomLeft = previousRowNode;

			if (topRight == currentRowNode && nextRowNode != nullptr)
				topRight = nextRowNode;

			if (bottomRight == currentRowNode && previousRowNode != nullptr)
				bottomRight = previousRowNode;

			// increment current pointer and delete node
			temp = currentRowNode;
			currentRowNode = currentRowNode->next;
			delete temp;
		}

		// don't forget to reduce the column size you monster
		sizeCol--;

		// also don't forget to update riw size if necessary
		if (sizeCol == 0) {
			sizeRow = 0;
			topLeft = topRight = bottomLeft = bottomRight = nullptr;
		}
	}
}

template<typename T>
void Grid<T>::removeCol(int index) {
	// interpret default arguments
	if (index == -1)
		index = sizeRow - 1;

	//only execute of index is in range
	if (index < sizeRow) {
		gNode<T> *previousColNode = nullptr;
		gNode<T> *currentColNode = topLeft;
		gNode<T> *nextColNode = nullptr;
		gNode<T> *temp = nullptr;

		// navigate to col index
		while (index-- > 0) {
			currentColNode = currentColNode->next;
		}

		while (currentColNode != nullptr) {
			// get upper and lower cols
			previousColNode = currentColNode->previous;
			nextColNode = currentColNode->next;

			// reassign uppers and lowers
			if (currentColNode->previous != nullptr)
				(currentColNode->previous)->next = currentColNode->next;
			if (currentColNode->next != nullptr)
				(currentColNode->next)->previous = currentColNode->previous;

			// check for limits and reassign if necessary
			if (topLeft == currentColNode && nextColNode != nullptr)
				topLeft = nextColNode;

			if (bottomLeft == currentColNode && previousColNode != nullptr)
				bottomLeft = previousColNode;

			if (topRight == currentColNode && nextColNode != nullptr)
				topRight = nextColNode;

			if (bottomRight == currentColNode && previousColNode != nullptr)
				bottomRight = previousColNode;

			// increment current pointer and delete node
			temp = currentColNode;
			currentColNode = currentColNode->lower;
			delete temp;
		}

		// don't forget to reduce the column size you monster
		sizeRow--;

		// also don't forget to update row size if necessary
		if (sizeRow == 0) {
			sizeCol = 0;
			topLeft = topRight = bottomLeft = bottomRight = nullptr;
		}
	}
}

template<typename T>
T Grid<T>::replaceAt(int rowIndex, int colIndex, T element) {
	// only run if given coordinates are within range
	try {
		if (rowIndex < sizeRow && colIndex < sizeCol) {
			gNode<T> *current = topLeft;

			while (colIndex-- > 0)
				current = current->lower;

			while (rowIndex-- > 0)
				current = current->next;

			T temp = current->element;
			current->element = element;

			return temp;
		}
		else {
			throw 0;
		}
	}
	catch (int exc) {
		cout << "replaceAt() index out of range\n";
		return NULL;
	}
}

template<typename T>
void Grid<T>::reverse() {
	//Use a stack to feed rows into stack and reverse the grid
	stack<T> s;
	for (int y = 0; y < sizeCol; y++) {
		for (int x = 0; x < sizeRow; x++) {
			//cout << "\npushing " << get(x, y);
			s.push(get(x, y));
		}
	}

	for (int y = 0; y < sizeCol; y++) {
		for (int x = 0; x < sizeRow; x++) {
			replaceAt(x, y, s.top());
			s.pop();
		}
	}
}

template<typename T>
void Grid<T>::clear() {
	if (getSize() > 0) {
		while (topLeft != nullptr)
			removeRow();
	}
}

// ************* SORTERS ****************
template<typename T>
void Grid<T>::sortGrid() {

	vector<T> v;
	gNode<T> *temp = nullptr;
	for (int y = 0; y < sizeCol; y++) {
		for (int x = 0; x < sizeRow; x++) {
			
			v.push_back(get(x, y));
		}
	}
	
	cout << "TEST";

	sort(v.begin(),v.end());

	for (int y = 0; y < sizeCol; y++) {
		for (int x = 0; x < sizeRow; x++) {
			
			replaceAt(y, x,v.front());
			v.erase(v.begin());
		}
	}
	
}

template<typename T>
void Grid<T>::sortRow(int index) {
	//Bubble
}

template<typename T>
void Grid<T>::sortAllRows() {
	int counter = 0;
	while (counter < sizeCol) {
		sortRow(counter++);
	}
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

//eof