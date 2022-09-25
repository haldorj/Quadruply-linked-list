#pragma once

template<class T>
class List : public Node<T>
{
private:
	int NumberOfElements;
public:
	Node<T>* Root;
	Node<T>* RightTail;
	Node<T>* LeftTail;
	Node<T>* UpTail;
	Node<T>* DownTail;

	std::vector<T> Container;

	Node<T>* GetRoot() { return Root; }
	int GetNumberOfElements() { return NumberOfElements; }

	List();

	void ConstructRoot(T data); // Creates the "root", required to run the program. 
	void InsertAtRightTail(T data); // 4 tails are connected to the root.
	void InsertAtLeftTail(T data);
	void InsertAtUpTail(T data);
	void InsertAtDownTail(T data);

	// Adds nodes to all four "corners" surrounding the root after tails are placed.
	// Made early on for convinience sake.
	void InsertTopRightCorner(Node<T>* root, T data); 
	void InsertTopLeftCorner(Node<T>* root, T data);
	void InsertBotRightCorner(Node<T>* root, T data);
	void InsertBotLeftCorner(Node<T>* root, T data);
	void ConstructCorners(T topR, T topL, T botR, T botL);
	// Checks if Corners are connected to the root.
	void VerifyCorners();

	// Adds nodes in either direction relative to any node.
	// Checks if there are surrounding nodes that needs to be connected to.
	void AddNodeAbove(Node<T>* node, T data);
	void AddNodeBelow(Node<T>* node, T data);
	void AddNodeLeft(Node<T>* node, T data);
	void AddNodeRight(Node<T>* node, T data);
	
	void DeleteNode(Node<T>* node);

	// Traversal algorithm.
	// Requires there to be a straight line of nodes spanning the whole list.
	// Prints all elements in the line + nodes above, and below a given node in that line.
	void PrintList();
	void PrintListUp(Node<T>* node);
	void PrintListDown(Node<T>* node);
	void PrintListSorted();
};

template<class T>
inline List<T>::List()
{
	Root = nullptr;
	RightTail = nullptr;
	LeftTail = nullptr;
	UpTail = nullptr;
	DownTail = nullptr;

	NumberOfElements = 0;
}

template<class T>
inline void List<T>::ConstructRoot(T data)
{
	Node<T>* newNode = new Node<T>;

	newNode->Data = data;

	newNode->Right == nullptr;
	newNode->Left == nullptr;
	newNode->Up == nullptr;
	newNode->Down == nullptr;

	Root = newNode;
	RightTail = newNode;
	LeftTail = newNode;
	UpTail = newNode;
	DownTail = newNode;
}

template<class T>
inline void List<T>::InsertAtRightTail(T data)
{
	Node<T>* newNode = new Node<T>;
	newNode->Data = data;

	newNode->Left = RightTail;
	RightTail->Right = newNode;
	RightTail = newNode;

	RightTail->Right == nullptr;
}

template<class T>
inline void List<T>::InsertAtLeftTail(T data)
{
	Node<T>* newNode = new Node<T>;
	newNode->Data = data;

	newNode->Right = LeftTail;
	LeftTail->Left = newNode;
	LeftTail = newNode;
}

template<class T>
inline void List<T>::InsertAtUpTail(T data)
{
	Node<T>* newNode = new Node<T>;
	newNode->Data = data;

	newNode->Down = UpTail;
	UpTail->Up = newNode;
	UpTail = newNode;
}

template<class T>
inline void List<T>::InsertAtDownTail(T data)
{
	Node<T>* newNode = new Node<T>;
	newNode->Data = data;

	newNode->Up = DownTail;
	DownTail->Down = newNode;
	DownTail = newNode;
}

template<class T>
inline void List<T>::ConstructCorners(T topR, T topL, T botR, T botL)
{
	InsertTopRightCorner(Root, topR);
	InsertTopLeftCorner(Root, topL);
	InsertBotRightCorner(Root, botR);
	InsertBotLeftCorner(Root, botL);
}

template<class T>
inline void List<T>::VerifyCorners()
{
	std::cout << "Getting data for each corner relative to the root " << Root->Data << " :" << std::endl;
	std::cout << "Top left: ";
	std::cout << Root->Left->Up->Data << " ";
	std::cout << "Top right: ";
	std::cout << Root->Right->Up->Data << std::endl;
	std::cout << "Bottom left: ";
	std::cout << Root->Left->Down->Data << " ";
	std::cout << "Bottom right: ";
	std::cout << Root->Right->Down->Data << std::endl;
}

template<class T>
inline void List<T>::InsertTopRightCorner(Node<T>* root, T data)
{
	Node<T>* newNode = new Node<T>;
	newNode->Data = data;

	root->Right->Up = newNode;
	newNode->Down = root->Right;
	root->Up->Right = newNode;
	newNode->Left = root->Up;
}

template<class T>
inline void List<T>::InsertTopLeftCorner(Node<T>* root, T data)
{
	Node<T>* newNode = new Node<T>;
	newNode->Data = data;

	root->Left->Up = newNode;
	newNode->Down = root->Left;
	root->Up->Left = newNode;
	newNode->Right = root->Up;
}

template<class T>
inline void List<T>::InsertBotRightCorner(Node<T>* root, T data)
{
	Node<T>* newNode = new Node<T>;
	newNode->Data = data;

	root->Right->Down = newNode;
	newNode->Up = root->Right;
	root->Down->Right = newNode;
	newNode->Left = root->Down;
}

template<class T>
inline void List<T>::InsertBotLeftCorner(Node<T>* root, T data)
{
	Node<T>* newNode = new Node<T>;
	newNode->Data = data;

	root->Left->Down = newNode;
	newNode->Up = root->Left;
	root->Down->Left = newNode;
	newNode->Right = root->Down;
}

template<class T>
inline void List<T>::AddNodeAbove(Node<T>* node, T data)
{
	Node<T>* newNode = new Node<T>;
	newNode->Data = data;

	node->Up = newNode;
	newNode->Down = node;

	if (newNode->Down == UpTail) UpTail = newNode;

	if (node->Left != nullptr && node->Left->Up != nullptr)
	{
		newNode->Left = node->Left->Up;
		node->Left->Up->Right = newNode;
	}

	if (node->Right != nullptr && node->Right->Up != nullptr)
	{
		newNode->Right = node->Right->Up;
		node->Right->Up->Left = newNode;
	}
}

template<class T>
inline void List<T>::AddNodeBelow(Node<T>* node, T data)
{
	Node<T>* newNode = new Node<T>;
	newNode->Data = data;

	node->Down = newNode;
	newNode->Up = node;

	if (newNode->Up == DownTail) DownTail = newNode;

	if (node->Left != nullptr && node->Left->Down != nullptr)
	{
		newNode->Left = node->Left->Down;
		node->Left->Down->Right = newNode;
	}

	if (node->Right != nullptr && node->Right->Down != nullptr)
	{
		newNode->Right = node->Right->Down;
		node->Right->Down->Left = newNode;
	}
}

template<class T>
inline void List<T>::AddNodeLeft(Node<T>* node, T data)
{
	Node<T>* newNode = new Node<T>;
	newNode->Data = data;

	node->Left = newNode;
	newNode->Right = node;

	if (newNode->Right == LeftTail) LeftTail = newNode;

	if (node->Up != nullptr && node->Up->Left != nullptr)
	{
		newNode->Up = node->Up->Left;
		node->Up->Left->Down = newNode;
	}

	if (node->Down != nullptr && node->Down->Left != nullptr)
	{
		newNode->Down = node->Down->Left;
		node->Down->Left->Up = newNode;
	}
}

template<class T>
inline void List<T>::AddNodeRight(Node<T>* node, T data)
{
	Node<T>* newNode = new Node<T>;
	newNode->Data = data;

	node->Right = newNode;
	newNode->Left = node;

	if (newNode->Left == RightTail) RightTail = newNode;

	if (node->Up != nullptr && node->Up->Right != nullptr)
	{
		newNode->Up = node->Up->Right;
		node->Up->Right->Down = newNode;
	}

	if (node->Down != nullptr && node->Down->Right != nullptr)
	{
		newNode->Down = node->Down->Right;
		node->Down->Right->Up = newNode;
	}
}

template<class T>
inline void List<T>::DeleteNode(Node<T>* node)
{
	Node<T>* Temp = new Node<T>;
	Temp = node;

	if (node == Root)
	{
		std::cout << "Root can not be deleted." << std::endl;
		return;
	}

	if (node->Right != nullptr)
	{
		node->Right->Left = node->Left;
	}

	if (node->Left != nullptr)
	{
		node->Left->Right = node->Right;
	}

	if (node->Up != nullptr)
	{
		node->Up->Down = node->Down;
	}

	if (node->Down != nullptr)
	{
		node->Down->Up = node->Up;
	}

	delete node;
}

template<class T>
inline void List<T>::PrintList()
{
	std::cout << "Printing the whole list: " << std::endl;

	Node<T>* Temp = new Node<T>;
	Temp = LeftTail;

	if (Temp == nullptr) return;

	while (Temp != nullptr)
	{
		PrintListUp(Temp->Up);
		PrintListDown(Temp->Down);
		std::cout << Temp->Data << " ";
		Container.push_back(Temp->Data);
		Temp = Temp->Right;
		NumberOfElements++;
	}
}

template<class T>
inline void List<T>::PrintListUp(Node<T>* node)
{
	Node<T>* Temp = new Node<T>;
	Temp = node;

	if (Temp == nullptr) return;

	while (Temp != nullptr)
	{
		std::cout << Temp->Data << " ";
		Container.push_back(Temp->Data);
		Temp = Temp->Up;
		NumberOfElements++;
	}
}

template<class T>
inline void List<T>::PrintListDown(Node<T>* node)
{
	Node<T>* Temp = new Node<T>;
	Temp = node;

	if (Temp == nullptr) return;

	while (Temp != nullptr)
	{
		std::cout << Temp->Data << " ";
		Container.push_back(Temp->Data);
		Temp = Temp->Down;
		NumberOfElements++;
	}
}

template<class T>
inline void List<T>::PrintListSorted()
{
	std::cout << "Sorted list: " << std::endl;
	std::sort(Container.begin(), Container.end());
	for (int i = 0; i < Container.size(); i++)
	{
		std::cout << Container[i] << " ";
	}
}

