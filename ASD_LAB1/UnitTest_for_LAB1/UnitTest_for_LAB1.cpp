#include "pch.h"
#include "CppUnitTest.h"
#include "..\ASD_LAB1\ClassList_for_LAB1.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestforLAB1
{
	TEST_CLASS(UnitTestforLAB1)
	{
	public:

		// Declaring pointers to lists
		List* New_List;
		List* Add_List;

		// Initializing pointers to lists
		TEST_METHOD_INITIALIZE(INITIALIZE)
		{
			New_List = new List();
			Add_List = new List();
		}

		// Removing pointers to lists
		TEST_METHOD_CLEANUP(CLEANUP)
		{
			delete New_List;
			delete Add_List;
		}

		// Checking for adding a new item to the end of the list if the list is empty
		TEST_METHOD(Test_Method_Push_Back_Empty_List)
		{
			int element_value = 1;
			size_t size = New_List->get_size();
			Assert::IsTrue(size == 0);
			New_List->push_back(element_value);
			Assert::IsTrue(New_List->get_size() == size + 1);
			Assert::IsTrue(New_List->at(0) == element_value);
		};

		// Checking for adding a new item to the end of the list if the list is not empty
		TEST_METHOD(Test_Method_Push_Back_Not_Empty_List)
		{
			int element_value = 2;
			New_List->push_front(0);
			New_List->push_front(1);
			size_t size = New_List->get_size();
			Assert::IsTrue(size != 0);
			New_List->push_back(element_value);
			Assert::IsTrue(New_List->get_size() == size + 1);
			Assert::IsTrue(New_List->at(2) == element_value);
		};

		// Checking for adding a new item to the top of the list if the list is empty
		TEST_METHOD(Test_Method_Push_Front_Empty_List)
		{
			int element_value = 1;
			size_t size = New_List->get_size();
			Assert::IsTrue(size == 0);
			New_List->push_front(element_value);
			Assert::IsTrue(New_List->get_size() == size + 1);
			Assert::IsTrue(New_List->at(0) == element_value);
		}

		// Checking for adding a new item to the top of the list if the list is not empty
		TEST_METHOD(Test_Method_Push_Front_Not_Empty_List)
		{
			int element_value = 1;
			New_List->push_front(0);
			size_t size = New_List->get_size();
			Assert::IsTrue(size != 0);
			New_List->push_front(element_value);
			Assert::IsTrue(New_List->get_size() == size + 1);
			Assert::IsTrue(New_List->at(0) == element_value);
		}

		// Checking the deletion of the last list item if the list is empty
		TEST_METHOD(Test_Method_Pop_Back_Empty_List)
		{
			try 
			{
				size_t size = New_List->get_size();
				Assert::IsTrue(size == 0);
				New_List->pop_back();
				Assert::IsTrue(size == New_List->get_size());
			}
			catch (const invalid_argument error)
			{
				Assert::AreEqual("The list is empty, there are no available items to delete", error.what());
			}
		}

		// Checking the deletion of a single item from a non-empty list.
		TEST_METHOD(Test_Method_Pop_Back_Single_Element)
		{
			New_List->push_back(1);
			size_t size = New_List->get_size();
			Assert::IsTrue(size == 1);
			New_List->pop_back();
			Assert::IsTrue(New_List->get_size() == 0);
		}

		// Checking the deletion of the last list item if the list is not empty
		TEST_METHOD(Test_Method_Pop_Back_Not_Empty_List)
		{
			New_List->push_back(0);
			New_List->push_back(1);
			New_List->push_back(2);
			size_t size = New_List->get_size();
			Assert::IsTrue(size != 0);
			New_List->pop_back();
			Assert::IsTrue(New_List->get_size() == size - 1);
		}

		// Checking the deletion of the first list item if the list is empty.
		TEST_METHOD(Test_Method_Pop_Front_Empty_List)
		{
			try
			{
				size_t size = New_List->get_size();
				Assert::IsTrue(size == 0);
				New_List->pop_front();
				Assert::IsTrue(New_List->get_size() == size);
			}
			catch (const invalid_argument error)
			{
				Assert::AreEqual("The list is empty, there are no available items to delete", error.what());
			}
		}

		// Checking the deletion of a single item from a non-empty list.
		TEST_METHOD(Test_Method_Pop_Front_Single_Element)
		{
			New_List->push_back(1);
			size_t size = New_List->get_size();
			Assert::IsTrue(size == 1);
			New_List->pop_front();
			Assert::IsTrue(New_List->get_size() == 0);
		}

		// Checking the deletion of the first list item if the list is not empty.
		TEST_METHOD(Test_Method_Pop_Front_Not_Empty_List)
		{
			New_List->push_back(0);
			New_List->push_back(1);
			New_List->push_back(3);
			size_t size = New_List->get_size();
			Assert::IsTrue(size != 0);
			New_List->pop_front();
			Assert::IsTrue(New_List->get_size() == size - 1);
			Assert::IsTrue(New_List->at(0) == 1);
		}

		// Checking the addition of a new element by an index that is smaller than the size of the list when the list is not empty.
		TEST_METHOD(Test_Method_Isert_Element_Index_Less_Size_Not_Empty_List)
		{
			int element_value = 10;
			New_List->push_back(0);
			New_List->push_back(1);
			New_List->push_back(2);
			Assert::IsTrue(New_List->get_size() != 0);
			New_List->insert(element_value, 1);
			Assert::IsTrue(New_List->at(1) == element_value);
		}

		// Checking the addition of a new element by an index that is equal to the size of the list when the list is not empty.
		TEST_METHOD(Test_Method_Isert_Element_Index_Equal_Size_Not_Empty_List)
		{
			try
			{
				int element_value = 10;
				New_List->push_back(0);
				New_List->push_back(1);
				New_List->push_back(2);
				Assert::IsTrue(New_List->get_size() != 0);
				New_List->insert(element_value, 3);
			}
			catch (const out_of_range error) {
				Assert::AreEqual("Specifying the index of an element outside the allowed range", error.what());
			}
		}

		// Checking the addition of a new element by an index that is zero if the list is not empty.
		TEST_METHOD(Test_Method_Isert_Element_Index_Equal_Zero_Not_Empty_List)
		{
			int element_value = 10;
			New_List->push_back(0);
			New_List->push_back(1);
			New_List->push_back(2);
			size_t size = New_List->get_size();
			Assert::IsTrue(size != 0);
			New_List->insert(element_value, 0);
			Assert::IsTrue(New_List->get_size() == size + 1);
			Assert::IsTrue(New_List->at(0) == element_value);
		}

		// Checking the addition of a new element by an index that is larger than the list size when the list is not empty.
		TEST_METHOD(Test_Method_Isert_Element_Index_More_Size_Not_Empty_List)
		{
			try
			{
				int element_value = 10;
				New_List->push_back(0);
				New_List->push_back(1);
				New_List->push_back(2);
				Assert::IsTrue(New_List->get_size() != 0);
				New_List->insert(element_value, 5);
			}
			catch (const out_of_range error) {
				Assert::AreEqual("Specifying the index of an element outside the allowed range", error.what());
			}
		}

		// Checking for adding a new element by an index that is larger than the list size when the list is empty.
		TEST_METHOD(Test_Method_Isert_Element_Index_More_Size_Empty_List)
		{
			try
			{
				int element_value = 1;
				Assert::IsTrue(New_List->get_size() == 0);
				New_List->insert(element_value, 5);
			}
			catch (const out_of_range error) {
				Assert::AreEqual("Specifying the index of an element outside the allowed range", error.what());
			}
		}

		// Ñhecking the addition of a new element by an index that is zero with an empty list
		TEST_METHOD(Test_Method_Isert_Element_Index_Equal_Zero_Empty_List)
		{
			try
			{
				int element_value = 1;
				Assert::IsTrue(New_List->get_size() == 0);
				New_List->insert(element_value, 0);
			}
			catch (const out_of_range error) {
				Assert::AreEqual("Specifying the index of an element outside the allowed range", error.what());
			}
		}

		// Checking for getting the value of an element from the list by an index that is smaller than the size of the list when the list is not empty.
		TEST_METHOD(Test_Method_At_Element_Index_Less_Size_Not_Empty_List)
		{
			int element_value = 1;
			New_List->push_back(0);
			New_List->push_back(element_value);
			New_List->push_back(2);
			Assert::IsTrue(New_List->get_size() != 0);
			New_List->at(1);
			Assert::IsTrue(New_List->at(1) == element_value);
		}

		// Checking for getting the value of an element from the list by an index that is equal to the size of the list when the list is not empty.
		TEST_METHOD(Test_Method_At_Element_Index_Equal_Size_Not_Empty_List)
		{
			try
			{
				New_List->push_back(0);
				New_List->push_back(1);
				New_List->push_back(2);
				size_t size = New_List->get_size();
				Assert::IsTrue(size != 0);
				New_List->at(size);
				Assert::IsTrue(New_List->at(size));
			}
			catch (const out_of_range error) {
				Assert::AreEqual("Specifying the index of an element outside the allowed range", error.what());
			}
		}

		// Checking for getting the value of an element from the list by an index that is zero if the list is not empty.
		TEST_METHOD(Test_Method_At_Element_Index_Equal_Zero_Not_Empty_List)
		{
			int element_value = 0;
			New_List->push_back(element_value);
			New_List->push_back(1);
			New_List->push_back(2);
			size_t size = New_List->get_size();
			Assert::IsTrue(size != 0);
			Assert::IsTrue(New_List->at(0) == element_value);
		}

		// Checking for getting the value of an element from the list by an index that is larger than the size of the list when the list is not empty.
		TEST_METHOD(Test_Method_At_Element_Index_More_Size_Not_Empty_List)
		{
			try
			{
				New_List->push_back(0);
				New_List->push_back(1);
				New_List->push_back(2);
				size_t size = New_List->get_size();
				Assert::IsTrue(size != 0);
				Assert::IsTrue(New_List->at(size + 5));
			}
			catch (const out_of_range error) {
				Assert::AreEqual("Specifying the index of an element outside the allowed range", error.what());
			}
		}

		// Checking to get the value of an item from the list by an index that is larger than the size of the list with an empty list.
		TEST_METHOD(Test_Method_At_Element_Index_More_Size_Empty_List)
		{
			try
			{
				int element_value = 1;
				size_t size = New_List->get_size();
				Assert::IsTrue(size == 0);
				Assert::IsTrue(New_List->at(size + 5));
			}
			catch (const out_of_range error) {
				Assert::AreEqual("Specifying the index of an element outside the allowed range", error.what());
			}
		}

		// Ñhecking the addition of a new element by an index that is zero with an empty list
		TEST_METHOD(Test_Method_At_Element_Index_Equal_Zero_Empty_List)
		{
			try
			{
				int element_value = 1;
				size_t size = New_List->get_size();
				Assert::IsTrue(size == 0);
				Assert::IsTrue(New_List->at(0));
			}
			catch (const out_of_range error) {
				Assert::AreEqual("Specifying the index of an element outside the allowed range", error.what());
			}
		}

		// Checking the removal of an item from the list by an index that is smaller than the size of the list when the list is not empty.
		TEST_METHOD(Test_Method_Remouve_Element_Index_Less_Size_Not_Empty_List)
		{
			New_List->push_back(0);
			New_List->push_back(1);
			New_List->push_back(2);
			size_t size = New_List->get_size();
			Assert::IsTrue(size != 0);
			New_List->remouve(1);
			Assert::IsTrue(New_List->get_size() == size - 1);
		}

		// Checking the deletion of an item from the list by an index that is equal to the size of the list when the list is not empty.
		TEST_METHOD(Test_Method_Remouve_Element_Index_Equal_Size_Not_Empty_List)
		{
			try
			{
				New_List->push_back(0);
				New_List->push_back(1);
				New_List->push_back(2);
				size_t size = New_List->get_size();
				Assert::IsTrue(size != 0);
				New_List->remouve(size);
				Assert::IsTrue(New_List->get_size() == size);
			}
			catch (const out_of_range error) {
				Assert::AreEqual("Specifying the index of an element outside the allowed range", error.what());
			}
		}

		// Checking the deletion of an item from the list by an index that is zero if the list is not empty.
		TEST_METHOD(Test_Method_Remouve_Element_Index_Equal_Zero_Not_Empty_List)
		{
			New_List->push_back(0);
			New_List->push_back(1);
			New_List->push_back(2);
			size_t size = New_List->get_size();
			Assert::IsTrue(size != 0);
			New_List->remouve(0);
			Assert::IsTrue(New_List->get_size() == size - 1);
		}

		// Checking the deletion of an item from the list by index, from the end of the list when the list is not empty.
		TEST_METHOD(Test_Method_Remouve_Element_Index_End_Not_Empty_List)
		{
			New_List->push_back(0);
			New_List->push_back(1);
			New_List->push_back(2);
			size_t size = New_List->get_size();
			Assert::IsTrue(size != 0);
			New_List->remouve(2);
			Assert::IsTrue(New_List->get_size() == size - 1);
		}

		// Checking the deletion of an item from the list by an index that is larger than the size of the list when the list is not empty.
		TEST_METHOD(Test_Method_Remouve_Element_Index_More_Size_Not_Empty_List)
		{
			try
			{
				New_List->push_back(0);
				New_List->push_back(1);
				New_List->push_back(2);
				size_t size = New_List->get_size();
				Assert::IsTrue(size != 0);
				New_List->remouve(size + 5);
				Assert::IsTrue(New_List->get_size() == size);
			}
			catch (const out_of_range error) {
				Assert::AreEqual("Specifying the index of an element outside the allowed range", error.what());
			}
		}

		// Checking the deletion of an item from the list by an index that is larger than the size of the list with an empty list.
		TEST_METHOD(Test_Method_Remouve_Element_Index_More_Size_Empty_List)
		{
			try
			{
				size_t size = New_List->get_size();
				Assert::IsTrue(size == 0);
				New_List->remouve(size + 5);
				Assert::IsTrue(New_List->get_size() == size);
			}
			catch (const out_of_range error) {
				Assert::AreEqual("Specifying the index of an element outside the allowed range", error.what());
			}
		}

		// Checking the deletion of an item from the list by an index that is zero when the list is empty
		TEST_METHOD(Test_Method_Remouve_Element_Index_Equal_Zero_Empty_List)
		{
			try
			{
				size_t size = New_List->get_size();
				Assert::IsTrue(size == 0);
				New_List->remouve(0);
				Assert::IsTrue(New_List->get_size() == size);
			}
			catch (const out_of_range error) {
				Assert::AreEqual("Specifying the index of an element outside the allowed range", error.what());
			}
		}

		// Checking to get the size of the list.
		TEST_METHOD(Test_Method_Get_Size)
		{
			New_List->push_back(0);
			New_List->push_back(1);
			New_List->push_back(2);
			Assert::IsTrue(New_List->get_size() == 3);
		}

		// Checking the deletion of all list items in a non-empty list.
		TEST_METHOD(Test_Method_Ñlear_Not_Empty_List)
		{
			New_List->push_back(0);
			New_List->push_back(1);
			New_List->push_back(2);
			size_t size = New_List->get_size();
			Assert::IsTrue(size != 0);
			New_List->clear();
			Assert::IsTrue(New_List->get_size() == 0);
		}

		// Checking the deletion of all list items in an empty list.
		TEST_METHOD(Test_Method_Ñlear_Empty_List)
		{
			size_t size = New_List->get_size();
			Assert::IsTrue(size == 0);
			New_List->clear();
			Assert::IsTrue(New_List->get_size() == 0);
		}

		// Checking the replacement of an element in the list with the transmitted element by an index that is smaller than the size of the list when the list is not empty.
		TEST_METHOD(Test_Method_Set_Element_Index_Less_Size_Not_Empty_List)
		{
			int element_value = 1;
			New_List->push_back(0);
			New_List->push_back(5);
			New_List->push_back(2);
			size_t size = New_List->get_size();
			Assert::IsTrue(size != 0);
			New_List->set(1, element_value);
			Assert::IsTrue(New_List->at(1) == element_value);
		}

		// Checking the replacement of an element in the list with the transmitted element by an index that is equal to the size of the list when the list is not empty.
		TEST_METHOD(Test_Method_Set_Element_Index_Equal_Size_Not_Empty_List)
		{
			try
			{
				int element_value = 3;
				New_List->push_back(0);
				New_List->push_back(1);
				New_List->push_back(2);
				size_t size = New_List->get_size();
				Assert::IsTrue(size != 0);
				New_List->set(size, element_value);
				Assert::IsTrue(New_List->at(size) != element_value);
			}
			catch (const out_of_range error) {
				Assert::AreEqual("Specifying the index of an element outside the allowed range", error.what());
			}
		}

		// Checking the replacement of an element in the list with the transmitted element by an index that is larger than the size of the list when the list is not empty.
		TEST_METHOD(Test_Method_Set_Element_Index_More_Size_Not_Empty_List)
		{
			try
			{
				int element_value = 3;
				New_List->push_back(0);
				New_List->push_back(1);
				New_List->push_back(2);
				size_t size = New_List->get_size();
				Assert::IsTrue(size != 0);
				New_List->set(size + 5, element_value);
				Assert::IsTrue(New_List->at(size + 5) != element_value);
			}
			catch (const out_of_range error) {
				Assert::AreEqual("Specifying the index of an element outside the allowed range", error.what());
			}
		}

		// Checking the replacement of an element in the list with the transmitted element by an index that is larger than the size of the list with an empty list.
		TEST_METHOD(Test_Method_Set_Element_Index_More_Size_Empty_List)
		{
			try
			{
				int element_value = 3;
				size_t size = New_List->get_size();
				Assert::IsTrue(size == 0);
				New_List->set(size + 5, element_value);
				Assert::IsTrue(New_List->at(size + 5) != element_value);
			}
			catch (const out_of_range error) {
				Assert::AreEqual("Specifying the index of an element outside the allowed range", error.what());
			}
		}

		// Ñhecking the replacement of an element in the list with the transmitted element by an index that is zero when the list is empty
		TEST_METHOD(Test_Method_Set_Element_Index_Equal_Zero_Empty_List)
		{
			try
			{
				int element_value = 1;
				size_t size = New_List->get_size();
				Assert::IsTrue(size == 0);
				New_List->set(0, element_value);
				Assert::IsTrue(New_List->at(size) != element_value);
			}
			catch (const out_of_range error) {
				Assert::AreEqual("Specifying the index of an element outside the allowed range", error.what());
			}
		}

		// Checking a non-empty list for emptiness.
		TEST_METHOD(Test_Method_isEmpty_Not_Empty_List)
		{
			New_List->push_back(0);
			New_List->push_back(1);
			New_List->push_back(2);
			Assert::IsTrue(New_List->isEmpty() == false);
		}

		// Checking an empty list for emptiness.
		TEST_METHOD(Test_Method_isEmpty_Empty_List)
		{
			Assert::IsTrue(New_List->isEmpty() == true);
		}

		// Checking the output of a non-empty list.
		TEST_METHOD(Test_Method_Operator_Output_Not_Empty_List)
		{
			New_List->push_back(0);
			New_List->push_back(1);
			New_List->push_back(2);
			stringstream output;
			output << *New_List;
			Assert::IsTrue(output.str() == "0 1 2 \n\n");
		}

		// Checking the output of an empty list.
		TEST_METHOD(Test_Method_Operator_Output_Empty_List)
		{
			stringstream output;
			output << *New_List;
			Assert::IsTrue(output.str() == "The list is empty\n\n");
		}

		// Checking the insertion of an empty list into a non-empty list, starting from the specified index.
		TEST_METHOD(Test_Method_InsertList_Empty_Add_List)
		{
			New_List->push_back(0);
			New_List->push_back(1);
			New_List->push_back(2);
			size_t size = New_List->get_size();
			Assert::IsTrue(size != 0);
			Assert::IsTrue(Add_List->get_size() == 0);
			New_List->insertList(*Add_List, 1);
			Assert::IsTrue(New_List->get_size() == size);
			stringstream output;
			output << *New_List;
			Assert::IsTrue(output.str() == "0 1 2 \n\n");
		}

		// Checking the insertion of a non-empty list into an empty list, starting with an index that is equal to the initial index (zero)
		TEST_METHOD(Test_Method_InsertList_Empty_List)
		{
			Add_List->push_back(0);
			Add_List->push_back(1);
			Add_List->push_back(2);
			size_t size = New_List->get_size();
			Assert::IsTrue(size == 0);
			Assert::IsTrue(Add_List->get_size() != 0);
			New_List->insertList(*Add_List, 0);
			Assert::IsTrue(New_List->get_size() == size + Add_List->get_size());
		}

		// Checking the insertion of a non-empty list into a non-empty list, starting with an index that is equal to the size of the original list
		TEST_METHOD(Test_Method_InsertList_Element_Index_Equal_Size_Not_Empty_List)
		{
			New_List->push_back(0);
			New_List->push_back(1);
			New_List->push_back(2);
			size_t size = New_List->get_size();
			Assert::IsTrue(size != 0);
			Add_List->push_back(3);
			Add_List->push_back(4);
			Add_List->push_back(5);
			Assert::IsTrue(Add_List->get_size() != 0);
			New_List->insertList(*Add_List, size);
			Assert::IsTrue(New_List->get_size() == size + Add_List->get_size());
			stringstream output;
			output << *New_List;
			Assert::IsTrue(output.str() == "0 1 2 3 4 5 \n\n");
		}

		// Checking the insertion of a non-empty list into a non-empty list, starting with an index that is smaller than the size of the original list.
		TEST_METHOD(Test_Method_InsertList_Element_Index_Less_Size_Not_Empty_List)
		{
			New_List->push_back(0);
			New_List->push_back(4);
			New_List->push_back(5);
			size_t size = New_List->get_size();
			Assert::IsTrue(size != 0);
			Add_List->push_back(1);
			Add_List->push_back(2);
			Add_List->push_back(3);
			Assert::IsTrue(Add_List->get_size() != 0);
			New_List->insertList(*Add_List, 1);
			Assert::IsTrue(New_List->get_size() == size + Add_List->get_size());
			stringstream output;
			output << *New_List;
			Assert::IsTrue(output.str() == "0 1 2 3 4 5 \n\n");
		}

		// Checking the insertion of a non-empty list into a non-empty list, starting with an index that is larger than the size of the original list
		TEST_METHOD(Test_Method_InsertList_Element_Index_More_Size_Not_Empty_List)
		{
			try
			{
				New_List->push_back(0);
				New_List->push_back(1);
				New_List->push_back(2);
				size_t size = New_List->get_size();
				Assert::IsTrue(size != 0);
				Add_List->push_back(3);
				Add_List->push_back(4);
				Add_List->push_back(5);
				Assert::IsTrue(Add_List->get_size() != 0);
				New_List->insertList(*Add_List, size + 5);
				stringstream output;
				output << *New_List;
				Assert::IsTrue(output.str() == "0 1 2 \n\n");
			}
			catch (const out_of_range error) {
				Assert::AreEqual("Specifying the index of an element outside the allowed range", error.what());
			}
		}

		// Checking the insertion of a non-empty list into an empty list, starting with an index that is larger than the size of the original list
		TEST_METHOD(Test_Method_InsertList_Element_Index_More_Size_Empty_List)
		{
			try
			{
				size_t size = New_List->get_size();
				Assert::IsTrue(size == 0);
				Add_List->push_back(0);
				Add_List->push_back(1);
				Add_List->push_back(2);
				Assert::IsTrue(Add_List->get_size() != 0);
				New_List->insertList(*Add_List, size + 5);
				stringstream output;
				output << *New_List;
				Assert::IsTrue(output.str() == "The list is empty\n\n");
			}
			catch (const out_of_range error) {
				Assert::AreEqual("Specifying the index of an element outside the allowed range", error.what());
			}
		}
	};
}