#include "LinkedList.h"
#include "grid.h"
template<typename T>
int Grid<T>::getSize() {
	return getRowSize()*getColSize();
}
template<typename T>
int Grid<T>::getColSize() {
	return sizeCol;
}
template<typename T>
int Grid<T>::getRowSize() {
	return sizeRow;
}
template<typename T>
void Grid<T>::addRow(int index, LinkedList<T> list) {
	return;
}
template<typename T>
void Grid<T>::addCol(int index, LinkedList<T> list) {
	return;
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
	return T;
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
	while (counter < sizeCol)) {
		sortRow(counter++);
	}
}