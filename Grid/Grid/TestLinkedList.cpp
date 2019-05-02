//#include <iostream>
//#include <string>
//#include "LinkedList.h"
//
//using namespace std;
//
//void printList(const LinkedList<string> list) //...
//{
//	cout << "     List Size: " << list.getSize() << " | ";
//	for (int i = 0; i < list.getSize(); i++)
//	{
//		cout << list.get(i) << " ";
//	}
//	cout << endl;
//}
//
//int main()
//{
//	// Create a list for strings
//	LinkedList<string> list;
//
//	
//	// Add elements to the list
//	list.add("America"); // Add it to the list
//	cout << "\n( 1) Add \"America\" to the list\n";
//	printList(list);
//
//	list.add(0, "Canada"); // Add it to the beginning of the list
//	cout << "\n( 2) Add \"Canada\" to the beginning of the list\n";
//	printList(list);
//
//	list.add("Russia"); // Add it to the end of the list
//	cout << "\n( 3) Add \"Russia\" to the end of the list\n";
//	printList(list);
//
//	list.add("France"); // Add it to the end of the list
//	cout << "\n( 4) Add \"France\" to the end of the list\n";
//	printList(list);
//
//	list.add(2, "Germany"); // Add it to the list at index 2
//	cout << "\n( 5) Add \"Germany\" to the list at index 2\n";
//	printList(list);
//
//	list.add(5, "Norway"); // Add it to the list at index 5
//	cout << "\n( 6) Add \"Norway\" to the list at index 5\n";
//	printList(list);
//
//	list.add(0, "Netherlands"); // Same as t.addFirst("Netherlands")
//	cout << "\n( 7) Add \"Netherlands\" to the list at index 0; same as list.addFirst(\"Netherlands\")\n";
//	printList(list);
//
//	list.removeAt(0); // Same as list.remove("Netherlands ") in this
//	cout << "\n( 8) Remove at index 0, same as list.remove(\"Netherlands\")\n";
//	printList(list);
//
//	list.removeAt(2); // Remove the element at index 2
//	cout << "\n( 9) Remove at index 2\n";
//	printList(list);
//	
//
//	list.addFirst("Test");
//	list.addFirst("Blerp");
//
//	printList(list);
//
//	Iterator<string> i = list.begin();
//
//	cout << *i << endl;
//
//	LinkedList<string> list2 = list;
//
//	//cout << "\n(11) contents in list 2\n";
//	//printList(list2);
//
//	//cout << endl;
//	//cout << "List 1 head node: " << list.getAddress(0) << endl;
//	//cout << "LIst 2 head node: " << list2.getAddress(0) << endl;
//
//	//LinkedList<string> foo;
//	//foo.add("abc");
//	//try {
//	//	cout << foo.removeLast() << endl;
//	//	cout << foo.removeLast() << endl;
//	//}
//	//catch (runtime_error& ex) {
//	//	cout << "The list size is " << foo.getSize() << endl;
//	//}
//	cout << endl;
//	return 0;
//}