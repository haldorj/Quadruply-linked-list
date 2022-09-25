#pragma once

template<typename T>
class Node
{
public:
	T Data;
	Node* Right;
	Node* Left;
	Node* Up;
	Node* Down;

	Node()
	{
		Right = nullptr;
		Left = nullptr;
		Up = nullptr;
		Down = nullptr;
	}
};