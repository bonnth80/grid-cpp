//#include <iostream>
#include "grid.h"

//using namespace std;
//template<typename T>
//int Grid<T>::getSize() {
//	//return getRowSize()*getColSize();
//	return 10;
//}
//
//template<typename T>
//int Grid<T>::getColSize() {
//	//return sizeCol;
//	return 5;
//}

//template <typename T>
//Grid<T>::Grid() {
//	topLeft = nullptr;
//	bottomLeft = nullptr;
//	topRight = nullptr;
//	bottomRight = nullptr;
//	sizeRow = 0;
//	sizeCol = 0;
//}
//
//template<typename T>
//int Grid<T>::getRowSize() const{
//	return sizeRow;
//}

//template<typename T>
//void Grid<T>::addRow(int index, LinkedList<T> list) {
//	// only add if list is correct size or grid is empty
//	if (list.getSize == getRowSize || getColSize == 0) {
//		gNode<T> *current = topLeft;
//		gNode<T> *previousRowNode = nullptr;
//		
//		// if there is previous data, start a new row
//		if (getColSize != 0) {
//			while (current != nullptr) {
//				previousRowNode = current;
//				current = current->lower;
//			}
//		}
//		// otherwise, define the dimensions of new grid
//		else {
//			sizeRow = list.getSize();
//		}
//
//		// if the added row is the only existing row
//		if (getColSize == 1) {
//			gNode<T> *previous = nullptr;
//
//			// set first node as topLeft and bottomLeft limits
//			topLeft = bottomLeft = new gNode<T>(list.get(i));
//			current = topLeft;
//
//			// add list elements to grid
//			for (int i = 1; i < list.getSize(); i++) {
//				current->next = new gNode<T>(list.get(i));
//				previous = current;
//				current = current->next;
//				current->previous = previous;
//			}
//
//			// set last node as topRight and bottomRight limits
//			topRight = bottomRight = current;
//		}
//
//		// if the added row is being appended onto an existing set
//		else {
//			bottomLeft = new gNode<T>(list.get(i));
//			current = bottomLeft;
//			current->upper = previousRowNode;
//			previousRowNode->lower = current;
//
//			for (int i = 1; i < list.getSize(); i++) {
//				current->next = new gNode<T>(list.get(i));
//				(current->next)->previous = current;
//
//				current->upper = previousRowNode;
//				previousRowNode->lower = current;
//
//				current = current->next;
//			}
//
//			bottomRight = current;
//		}
//
//		// increase the column size
//		sizeCol++;
//	}
//}

//template<typename T>
//void Grid<T>::addCol(int index, LinkedList<T> list) {
//	return;
//}
//
//template<typename T>
//T Grid<T>::getFirst() const {
//	if (topLeft == nullptr) {
//		throw runtime_error("Grid out of range");
//	}
//	else
//		return topLeft->element;
//}
//
//template<typename T>
//T Grid<T>::getLast() const {
//	if (bottomRight == nullptr) {
//		throw runtime_error("Grid out of Range");
//	}
//	else {
//		return bottomRight->element;
//	}
//}
//
//template<typename T>
//LinkedList<T> Grid<T>::removeRow(int index) {
//	return;
//}
//template<typename T>
//LinkedList<T> Grid<T>::removeCol(int index) {
//	return;
//}
//
//template<typename T>
//void Grid<T>::clear() {
//	//stub
//	//Remove row/col
//}
//
//template<typename T>
//bool Grid<T>::contains(T element) const{
//	return true;
//}
//
//template<typename T>
//T Grid<T>::get(int row, int col)const {
//	return T;
//}
//
//template<typename T>
//bool Grid<T>::isEmpty() const {
//	return (topLeft == nullptr && topRight == nullptr && bottomLeft == nullptr && bottomRight == nullptr);
//}
//
//template<typename T>
//T Grid<T>::replaceAt(int rowIndex, int colIndex, T element) {
//	//Returns Replaced Element
//}
//
//template<typename T>
//void Grid<T>::reverse() {
//	//Use a stack to feed rows into stack and reverse the grid
//}
//
//template<typename T>
//void Grid<T>::sortGrid() {
//	//Throw grid into Queue, sort queue using sort function, redo grid
//}
//
//template<typename T>
//void Grid<T>::sortRow(int index) {
//	//Bubble
//}
//
//template<typename T>
//void Grid<T>::sortCol(int index) {
//	//Bubble
//}
//
//template<typename T>
//void Grid<T>::sortAllCols() {
//	int counter = 0;
//	while (current < sizeRow) {
//		sortCol(counter++);
//	}
//}
//
//template<typename T>
//void Grid<T>::sortAllRows() {	
//	int counter = 0;
//	while (counter < sizeCol) {
//		sortRow(counter++);
//	}
//}