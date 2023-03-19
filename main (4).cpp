#include <iostream>
#include "string.h"
using namespace std;
// Node Class
class Node
{
	public: string fullStudentName;
	int RedID;
	int value;
	Node * next;

	Node(int va)
	{
		value = va;
		next = nullptr;
	}
};

// Linked List Class

class LinkedList
{
	private:
		// CLASS MEMBER VARIABLES
		Node * head;
	Node * tail;
	int length;

	public:
		// LINKED LIST CONSTRUCTOR
		LinkedList(int value)
		{
			Node *newNode = new Node(value);
			head = newNode;
			tail = newNode;
			length = 1;
		}

		// Linked List Destructor
		~LinkedList()
		{
			Node *temp = head;
			while (head != nullptr)
			{
				head = head->next;
				delete temp;
				temp = head;
			}
		}

	// Printing all items in the LL
	void printList()
	{
		Node *temp = head;
		if (length == 0)
			cout << "The list is empty";
		while (temp)
		{
			cout << temp->value << endl;
			temp = temp->next;
		}
	}

	void printListName()
	{
		Node *temp = head;
		if (length == 0)
			cout << "The list is empty";
		while (temp)
		{
cout << static_cast<char>(temp->value) << endl;
			temp = temp->next;
		}
	}

	// What's the first elemnt in the list?
	void getHead()
	{
		if (head == nullptr)
		{
			cout << "Head: nullptr" << endl;
		}
		else
		{
			cout << "Head: " << head->value << endl;
		}
	}

	// What's the last element in the LL?
	void getTail()
	{
		if (tail == nullptr)
		{
			cout << "Tail: nullptr" << endl;
		}
		else
		{
			cout << "Tail: " << tail->value << endl;
		}
	}

	// How Long is the List?
	void getLength()
	{
		cout << "Length: " << length << endl;
	}

	// Get the elemt at a particular index
	Node* get(int index)
	{
		if (index < 0 || index >= length)
			return nullptr;
		Node *temp = head;
		for (int i = 0; i < index; ++i)
		{
			temp = temp->next;
		}

		return temp;
	}

	// set value at a particular index
	bool set(int index, int value)
	{
		Node *temp = get(index);
		if (temp != nullptr)
		{
			temp->value = value;
			return true;
		}

		return false;
	}

	// Add node to the end of the list
	void append(int value)
	{
		Node *newNode = new Node(value);
		if (length == 0)
		{
			head = newNode;
			tail = newNode;
		}
		else
		{
			tail->next = newNode;
			tail = newNode;
		}

		length++;
	}

	// Add a new node to the start of the list
	void prepend(int value)
	{
		Node *newNode = new Node(value);
		if (length == 0)
		{
			head = newNode;
			tail = newNode;
		}
		else
		{
			newNode->next = head;
			head = newNode;
		}

		length++;
	}

	// Insert element at a particulat index
	bool insert(int index, int value)
	{
		if (index < 0 || index > length)
			return false;
		if (index == 0)
		{
			prepend(value);
			return true;
		}

		if (index == length)
		{
			append(value);
			return true;
		}

		Node *newNode = new Node(value);
		Node *temp = get(index - 1);
		newNode->next = temp->next;
		temp->next = newNode;
		length++;
		return true;
	}

	// Delete the first node in the list
	void deleteFirst()
	{
		if (length == 0)
			return;
		Node *temp = head;
		if (length == 1)
		{
			head = nullptr;
			tail = nullptr;
		}
		else
		{
			head = head->next;
		}

		delete temp;
		length--;
	}

	// Delete the last element of the list.
	void deleteLast()
	{
		if (length == 0)
			return;
		Node *temp = head;
		if (length == 1)
		{
			head = nullptr;
			tail = nullptr;
		}
		else
		{
			Node *pre = head;
			while (temp->next)
			{
				pre = temp;
				temp = temp->next;
			}

			tail = pre;
			tail->next = nullptr;
		}

		delete temp;
		length--;
	}

	// Delete a node at a particular index
	void deleteNode(int index)
	{
		if (index < 0 || index >= length)
			return;
		if (index == 0)
			return deleteFirst();
		if (index == length - 1)
			return deleteLast();

		Node *prev = get(index - 1);
		Node *temp = prev->next;

		prev->next = temp->next;
		delete temp;
		length--;
	}

	void reverseLinkedList()
	{
		Node *prev = nullptr;
		Node *curr = head;
		Node *next = nullptr;

		while (curr != nullptr)
		{
			next = curr->next;
			curr->next = prev;
			prev = curr;
			curr = next;
		}

		tail = head;
		head = prev;
	}

	void selectionSort()
	{
		Node * i;
		Node * j;
		int minimumValue;
		Node * minimum;

		for (i = head; i != nullptr; i = i->next)
		{
			minimumValue = i->value;
			minimum = i;
			for (j = i->next; j != nullptr; j = j->next)
			{
				if (j->value < minimumValue)
				{
					minimumValue = j->value;

					minimum = j;
				}
			}

			if (minimum != i)
			{
				int temp = i->value;

				i->value = minimum->value;
				minimum->value = temp;
			}
		}
	}

	void insertionSort()
	{
		Node * j;
		Node * i;
		Node * k;
		for (i = head->next; i != nullptr; i = i->next)
		{
			j = head;
			k = i;
			while (j != i && j->value < k->value)
			{
				j = j->next;
			}

			while (j != i)
			{
				int temp = j->value;
				j->value = k->value;
				k->value = temp;
				k = j;
				j = j->next;
			}
		}
	}
};

// main function
int main()
{
	LinkedList *ll1 = new LinkedList(1);
  LinkedList *RedID = new LinkedList(1);
  LinkedList *fullStudentName = new LinkedList(1);
	int choice;

	while (true)
	{
		cout << "CHOOSE FROM THE FOLLOWING OPTIONS:\n1. Make a linked list\n2. Add a "
		"node to the beginning\n3. Add a node to the end\n4. Add a node at "
		"index\n5. Delete node from the beginning\n6. Delete node from the "
		"End\n7. Delete node at Index\n8. Sort by name\n9. Sort by "
		"REDID\n10. Reverse LinkedList\n11. Sort your Red ID\n12. Sort your name\n13. Exit" <<
		endl;
		cin >> choice;
		if (choice == 1)
		{
			int llsize;
			cout << "How many elements would you like in the linked list? " << "";
			cin >> llsize;

			for (int i = 0; i < llsize; i++)
			{
				int element;
				cout << "Enter the value you would like element " << i + 1 << " to be: ";
				cin >> element;
				ll1->append(element);
			}

			ll1->deleteFirst();
		}

		if (choice == 2)
		{
			string fullStudentName;
			int RedID;
			cout << "Enter your name " << "";
			cin.ignore();
			getline(cin, fullStudentName);
			cout << "Enter your Red ID " << "";
			cin >> RedID;
			int prependValue;
			cout << "Enter the value for the node you would like to at to the beginning " << "";
			cin >> prependValue;
			ll1->prepend(prependValue);
		}
		else if (choice == 3)
		{
			string fullStudentName;
			int RedID;
			cout << "Enter your name " << "";
			cin.ignore();
			getline(cin, fullStudentName);
			cout << "Enter your Red ID " << "";
			cin >> RedID;
			int appendValue;
			cout << "Etner the value for the node you would like to add to the end " << "";
			cin >> appendValue;
			ll1->append(appendValue);
		}
		else if (choice == 4)
		{
			string fullStudentName;
			int RedID;
			cout << "Enter your name " << "";
			cin.ignore();
			getline(cin, fullStudentName);
			cout << "Enter your Red ID " << "";
			cin >> RedID;
			ll1->getLength();
			int length;
			cout << "What is the length? " << "";
			cin >> length;
			int indexValue;
			cout << "Enter the index that you would like to insert the node at " << "";
			cin >> indexValue;

			if (indexValue < 0 || indexValue >= length)
			{
				cout << "Invalid index, cannot perform operation " << "" << endl;
			}

			int nodeValue;
			cout << "Enter the value of the node that you would like to insert " << "";
			cin >> nodeValue;
			ll1->insert(indexValue, nodeValue);
		}
		else if (choice == 5)
		{
			if (ll1 == 0)
			{
				cout << "You cannot delete from an empty list " << "";
			}

			ll1->deleteFirst();
		}
		else if (choice == 6)
		{
			if (ll1 == 0)
			{
				cout << "You cannot delete from an empty list " << "";
			}

			ll1->deleteLast();
		}
		else if (choice == 7)
		{
			if (ll1 == 0)
			{
				cout << "You cannot delete from an empty list " << "";
			}

			ll1->getLength();
			int length;
			cout << "What is the length? " << "";
			cin >> length;
			int indexDelete;
			cout << "Enter the index at which you would like to delete a node " << "";
			cin >> indexDelete;
			if (indexDelete < 0 || indexDelete >= length)
			{
				cout << "Invalid index, cannot perform operation " << "" << endl;
			}

			ll1->deleteNode(indexDelete);
		}
		else if (choice == 8)
		{
			ll1->insertionSort();
			cout << "Sorted list:\n" << "";
			ll1->printList();
		}
		else if (choice == 9)
		{
			ll1->selectionSort();
			cout << "Sorted list:\n" << "";
			ll1->printList();
      
		}
		else if (choice == 10)
		{
			ll1->reverseLinkedList();
		}
      if (choice == 11)
		{

			for (int i = 0; i < 9; i++)
			{
				int element;
				cout << "Enter number " << i + 1 << " of your Red ID: ";
				cin >> element;
				RedID->append(element);
			}
			RedID->deleteFirst();
      RedID->selectionSort();
      cout << "Sorted Red ID:\n" << "";
      RedID->printList();
		}
     	if (choice == 12)
		{
			int nameSize;
			cout << "How many letters are in your name? " << "";
			cin >> nameSize;
			for (int i = 0; i < nameSize; i++)
			{
				char letter;
				cout << "Enter what letter " << i + 1 << " is for your name: ";
				cin >> letter;
				fullStudentName->append(letter);
			}

			fullStudentName->deleteFirst();
      fullStudentName->selectionSort();
      cout << "Sorted Name:\n" << "";
      fullStudentName->printListName();
		}
		else if (choice == 13)
		{
			break;
		}
		else if (choice < 1 || choice > 13)
		{
			cout << "Your selection is invlaid" << "";
			break;
		}
    }
  }