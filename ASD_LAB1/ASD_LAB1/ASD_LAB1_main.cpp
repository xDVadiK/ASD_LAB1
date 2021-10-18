#include <iostream>
#include "ClassList_for_LAB1.h"

using namespace std;

int main()
{
    size_t index = 0; int value = 0;
    cout << "Let's create a new list and check it for emptiness\n\n";
    List New_List;
    if (New_List.isEmpty())
    {
        cout << "The list is empty\n\n";
    }
    else cout << "There are elements in the list\n\n";
    cout << "Filling the list by adding items to the end of the list: ";
    New_List.push_back(4);
    New_List.push_back(5);
    New_List.push_back(6);
    New_List.push_back(7);
    cout << New_List;
    cout << "Adding new items to the top of the list: ";
    New_List.push_front(3);
    New_List.push_front(2);
    New_List.push_front(1);
    New_List.push_front(0);
    cout << New_List;
    cout << "Deleting multiple items at the end of the list: ";
    try 
    {
        New_List.pop_back();
        New_List.pop_back();
        cout << New_List;
    }
    catch (const invalid_argument error)
    {
        cout << error.what();
        return 0;
    }
    cout << "Deleting multiple items at the top of the list: ";
    try
    {
        New_List.pop_front();
        New_List.pop_front();
        cout << New_List;
    }
    catch (const invalid_argument error)
    {
        cout << error.what();
        return 0;
    }
    index = 2;
    value = 100;
    cout << "Adding an item by index " << index << ": ";
    try
    {
        New_List.insert(value, index);
        cout << New_List;
    }
    catch (const out_of_range error)
    {
        cout << error.what();
        return 0;
    }
    index = 2;
    cout << "Getting the value of an element by index " << index << ": ";
    try
    {
        cout << New_List.at(index) << "\n\n";
    }
    catch (const out_of_range error)
    {
        cout << error.what();
        return 0;
    }
    cout << "Deleting a list item by index " << index << ": ";
    try
    {
        New_List.remouve(2);
        cout << New_List;
    }
    catch (const out_of_range error)
    {
        cout << error.what();
        return 0;
    }
    cout << "Size list: ";
    cout << New_List.get_size() << "\n\n";
    cout << "Clearing the list: ";
    New_List.clear();
    cout << New_List;
    cout << "Filling in the list again: ";
    New_List.push_back(0);
    New_List.push_back(1);
    New_List.push_back(9);
    New_List.push_back(5);
    cout << New_List;
    index = 2;
    value = 4;
    cout << "Replacing the value of an element under index " << index << " with an element with a value of " << value << ": ";
    try
    {
        New_List.set(index, value);
        cout << New_List;
    }
    catch (const out_of_range error)
    {
        cout << error.what();
        return 0;
    }
    cout << "Let's create another list and fill it with elements: ";
    List Add_List;
    Add_List.push_back(2);
    Add_List.push_back(3);
    cout << Add_List;
    index = 2;
    cout << "Let's insert the new list into the old one, starting with the index: " << index << ": ";
    try
    {
        New_List.insertList(Add_List, index);
        cout << New_List;
    }
    catch (const out_of_range error)
    {
        cout << error.what();
        return 0;
    };
    return 0;
}