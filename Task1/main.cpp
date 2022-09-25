#include <iostream>
#include <vector>
#include <algorithm>

#include "Node.h"
#include "List.h"

int main()
{
	List<char>* L = new List<char>();

	// The root holds the value A;
	L->ConstructRoot('A');
	// 4 tails are connected to the root.

	L->InsertAtDownTail('B');
	L->InsertAtUpTail('C');
	L->InsertAtRightTail('D');
	L->InsertAtLeftTail('E');

	std::cout << std::endl;

	// The list after running this code:
	//					C			  
	//					|
	//			 E <--> A <--> D
	//					|
	//				    B
	// Each node is doubly linked to the neighbouring node.
	// A is the "root" the other nodes are the tails.
	
	// Adds nodes to all four "corners" surrounding the root A.
	L->ConstructCorners('W', 'X', 'Y', 'Z');

	// The list after running this code:
	//			 X <--> C <--> W		  
	//			 |		|	   |
	//			 E <--> A <--> D
	//			 |		|	   |
	//			 Z <--> B <--> Y
	// Each node is doubly linked to the neighbouring node.

	// Function to check if we can traverse to the corners from the root and retrieve data.
	L->VerifyCorners();

	std::cout << std::endl;

	L->InsertAtLeftTail('F');
	L->InsertAtRightTail('G');

	std::cout << std::endl;

	// The list after running this code:
	//			 X <--> C <--> W		  
	//			 |		|	   |
	//	  F <--> E <--> A <--> D <--> G
	//			 |		|	   |
	//			 Z <--> B <--> Y
	// Each node is doubly linked to the neighbouring node.

	L->InsertTopRightCorner(L->GetRoot()->Right, '1');
	L->InsertBotLeftCorner(L->GetRoot()->Left, '2');

	std::cout << std::endl;

	// The list after running this code:
	//			 X <--> C <--> W <--> 1	  
	//			 |		|	   |	  |
	//	  F <--> E <--> A <--> D <--> G
	//	  |		 |	    |      |
	//	  2	<--> Z <--> B <--> Y
	// Each node is doubly linked to the neighbouring node.

	// Inserting nodes at specific location.

	L->AddNodeAbove(L->GetRoot()->Right->Right->Up, 'H');
	L->AddNodeBelow(L->GetRoot()->Left->Left->Down, 'I');

	std::cout << std::endl;

	// The list after running this code:
	//								  H	
	//								  |
	//			 X <--> C <--> W <--> 1	  
	//			 |		|	   |	  |
	//	  F <--> E <--> A <--> D <--> G
	//	  |		 |	    |      |
	//	  2	<--> Z <--> B <--> Y
	//    |
	//    I
	// Each node is doubly linked to the neighbouring node.

	// Deleting the node one "col" to the right and one "row" up relative to the root (holds value W).
	L->DeleteNode(L->GetRoot()->Right->Up);

	std::cout << std::endl;

	// The list after running this code:
	//								  H	
	//								  |
	//			 X <--> C <---------> 1	  
	//			 |		|			  |
	//	  F <--> E <--> A <--> D <--> G
	//	  |		 |	    |      |
	//	  2	<--> Z <--> B <--> Y
	//    |
	//    I
	// Each node is doubly linked to the neighbouring node.

	L->InsertAtRightTail('J');
	L->AddNodeLeft(L->GetRoot()->Left->Up, '3');
	L->AddNodeRight(L->GetRoot()->Right->Down, '4');
	std::cout << std::endl;

	// The list after running this code:
	//								  H	
	//								  |
	//	  3	<--> X <--> C <---------> 1	  
	//	  |	     |		|	   |	  |
	//	  F <--> E <--> A <--> D <--> G <--> J
	//	  |		 |	    |      |      |
	//	  2	<--> Z <--> B <--> Y <--> 4
	//    |
	//    I
	// Each node is doubly linked to the neighbouring node.

	L->PrintList();
	std::cout << std::endl;
	std::cout << "Number of elements in the list: " << L->GetNumberOfElements() << "." << std::endl;
	std::cout << std::endl;
	L->PrintListSorted();
	std::cout << std::endl;

	return 0;
}