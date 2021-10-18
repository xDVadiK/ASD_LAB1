#pragma once

using namespace std;

class List // Parent class
{
private:

	class Node // Child class
	{
	public:

		int data; // The value of the list item
		Node* next; // Pointer to the next item in the list

		// Constructor of the child class
		Node(int data = 0, Node* next = nullptr) {
			this->data = data;
			this->next = next;
		};
		// Child class destructor
		~Node()
		{
			data = 0;
			next = nullptr;
		};
	};

	size_t size; // List size
	Node* head; // Pointer to the first item in the list
	Node* last; // Pointer to the last item in the list

public:

	// Constructor of the parent class
	List(size_t size = 0, Node* head = nullptr, Node* last = nullptr)
	{
		this->size = size;
		this->head = head;
		this->last = last;
	}
	// Parent class destructor
	~List()
	{
		clear();
		size = 0;
		head = nullptr;
		last = nullptr;
	};

	void push_back(int); // Adding a new item to the end of the list
	void push_front(int); // Adding a new item to the top of the list
	void pop_back(); // Deleting the last item in the list
	void pop_front(); // Deleting the first item in the list
	void insert(int, size_t); // Adding an element by index (inserting before an element that was previously available by this index)
	int at(size_t); // Getting the value of an element by index
	void remouve(size_t); // Deleting a list item by index
	size_t get_size(); // Getting the list size
	void clear(); // Deleting all list items
	void set(size_t, int); // Replacing an element by index with the transmitted element
	bool isEmpty(); // Checking the list for emptiness
	friend ostream& operator << (ostream& stream, const List& Node); // Overloading the output operator
	void insertList(const List&, size_t); // Inserting another list into the list starting from the index
};

// Adding a new item to the end of the list
void List::push_back(int element_value)
{
	if (head == nullptr)
	{
		Node* new_list_item = new Node(element_value, nullptr);
		head = new_list_item;
		last = new_list_item;
		size++;
	}
	else
	{
		Node* new_list_item = new Node(element_value, nullptr);
		last->next = new_list_item;
		last = new_list_item;
		size++;
	}

};

// Adding a new item to the top of the list
void List::push_front(int element_value)
{
	if (head == nullptr)
	{
		Node* new_list_item = new Node(element_value, nullptr);
		head = new_list_item;
		last = new_list_item;
		size++;
	}
	else
	{
		Node* new_list_item = new Node(element_value, head);
		head = new_list_item;
		size++;
	}
};

// Deleting the last item in the list
void List::pop_back()
{
	if (get_size() > 0)
	{
		if (get_size() == 1)
		{
			clear();
		}
		else 
		{
			Node* list_item = last;
			Node* current_item = head;
			while (current_item->next->next != nullptr)
			{
				current_item = current_item->next;
			}
			last = current_item;
			current_item->next = nullptr;
			delete list_item;
			size--;
		}
	}
	else throw invalid_argument("The list is empty, there are no available items to delete");
};

// Deleting the first item in the list
void List::pop_front()
{
	if (get_size() > 0)
	{
		if (get_size() == 1)
		{
			clear();
		}
		else 
		{
			Node* list_item = head;
			head = head->next;
			delete list_item;
			size--;
		}
	}
	else throw invalid_argument("The list is empty, there are no available items to delete");
};

// Adding an element by index (inserting before an element that was previously available by this index)
void List::insert(int element_value, size_t element_index)
{
	if (element_index < size && get_size() > 0)
	{
		if (element_index == 0)
		{
			push_front(element_value);
		}
		else {
			size_t counter = 0;
			Node* current_item = head;
			while (counter != element_index - 1)
			{
				current_item = current_item->next;
				counter++;
			}
			Node* new_list_item = new Node(element_value, current_item->next);
			current_item->next = new_list_item;
			size++;
		}
	}
	else throw out_of_range("Specifying the index of an element outside the allowed range");
}

// Getting the value of an element by index 
int List::at(size_t element_index)
{
	if (element_index < size && get_size() > 0)
	{
		int counter = 0;
		Node* current_item = head;
		while (counter != element_index) {
			current_item = current_item->next;
			counter++;
		}
		return current_item->data;
	}
	else throw out_of_range("Specifying the index of an element outside the allowed range");
}

// Deleting a list item by index
void List::remouve(size_t element_index)
{
	if (element_index < size && get_size() > 0)
	{
		if (element_index == 0)
		{
			pop_front();
		}
		else if (element_index == size - 1)
		{
			pop_back();
		}
		else
		{
			int counter = 0;
			Node* current_item = head;
			Node* delete_item;
			while (counter != element_index - 1)
			{
				current_item = current_item->next;
				counter++;
			};
			delete_item = current_item->next;
			current_item->next = current_item->next->next;
			delete delete_item;
			size--;
		}
	}
	else throw out_of_range("Specifying the index of an element outside the allowed range");
}

// Getting the list size
size_t List::get_size()
{
	return size;
}

// Deleting all list items
void List::clear()
{
	if (!isEmpty())
	{
		Node* current_item = head;
		while (current_item != nullptr)
		{
			current_item = current_item->next;
			delete head;
			head = current_item;
		}
		head = nullptr;
		last = nullptr;
		size = 0;
	}
};

// Replacing an element by index with the transmitted element
void List::set(size_t element_index, int element_value)
{
	if (element_index < size && get_size() > 0)
	{
		int counter = 0;
		Node* current_item = head;
		while (counter != element_index)
		{
			current_item = current_item->next;
			counter++;
		};
		current_item->data = element_value;
	}
	else throw out_of_range("Specifying the index of an element outside the allowed range");
};

// Checking the list for emptiness
bool List::isEmpty()
{
	return (size == 0);
};

// Overloading the output operator
ostream& operator<<(ostream& stream, const List& List)
{
	if (List.head != nullptr)
	{
		List::Node* current = List.head;
		while (current != nullptr)
		{
			stream << current->data << " ";
			current = current->next;
		}
		stream << "\n\n";
		return stream;
	}
	else return stream << "The list is empty\n\n";

};

// Inserting another list into the list starting from the index
void List::insertList(const List& Add_List, size_t element_index)
{
	if (Add_List.size != 0)
	{
		if (element_index <= size && get_size() >= 0)
		{
			if (element_index < size)
			{
				Node* current_item = Add_List.head;
				int counter = 0;
				while (counter != Add_List.size)
				{
					insert(current_item->data, element_index);
					current_item = current_item->next;
					element_index++;
					counter++;
				}
			}
			else if (element_index == size)
			{
				Node* current_item = Add_List.head;
				while (current_item != nullptr)
				{
					push_back(current_item->data);
					current_item = current_item->next;
				}
			}
		}
		else throw out_of_range("Specifying the index of an element outside the allowed range");
	}
}