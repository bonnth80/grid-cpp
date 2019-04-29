#pragma once


template <typename T>
class gNode : Node {
public:
	gNode<T> *up;
	gNode<T> *down;

	Node()					// No-arg constructor
	{
		next = nullptr;
		previous = nullptr;
		up = nullptr;
		down = nullptr;
	}
	Node(T element)			// Constructor
	{
		this->element = element;
		next = nullptr;
		previous = nullptr;
		up = nullptr;
		down = nullptr;
	}
};

template <typename T>
class Grid {
private:
	gNode<T> *topLeft;
	gNode<T> *topRight;
	gNode<T> *bottomLeft;
	gNode<T> *bottomRight;

	int sizeRow;
	int sizeCol;
	

private:
	void addElement(<T> element);

public:
	Grid<T>() {
		topLeft = nullptr;
		topRight = nullptr;
		bottomLeft = nullptr;
		bottomRight = nullptr;

		sizeRow = 0;
		sizeCol = 0;

	};

	Grid(int x, int y, T arr[] ) {
		// stub
	};

	Grid(int x, int y, LinkedList<T> list) {
		//stub
	};
	
	// Accessors
	int getSize();
	int getRowSize();
	int getColSize();
	
	// Modifiers
	void addRow(int, LinkedList<T>);	// set default int to sizeCol -1
	void addCol(int, LinkedList<T>);	// set default int to sizeRow -1

	T getFirst() const;			// return top left element
	T getLast() const;			// return bottom right element

	LinkedList<T> removeRow(int);		// set default int to sizeCol -1
	LinkedList<T> removeCol(int);		// set default int to sizeRow -1

	void clear();


	bool contains(T) const;
	T get(int, int) const;

	bool isEmpty() const;

	T replaceAt(int, int, T);

	void reverse();			// use stack

	// Sorters
	void sortGrid();
	void sortRow(int);
	void sortAllRows();
	void sortCol(int);
	void sortAllCols();
};
