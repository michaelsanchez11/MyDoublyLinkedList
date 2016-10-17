#ifndef DLINKEDLIST_H
#define DLINKEDLIST_H
// Include our DNode class
#include "DNode.h"
#include <cstdlib>
#include <fstream>

using namespace std;

namespace mike_DLinkedList
{
    class DLinkedList
    {
        public:
            typedef DNode::valueType data_type;
            typedef size_t size_type;
            // Constructor creates an empty list
            // ******************************************************************************************
            DLinkedList();
            // Summary: Constructor creates a linked list object with count set at 0.
            // ******************************************************************************************
            //
            // ******************************************************************************************
            DLinkedList(const DLinkedList& sourceList);
            // Summary: Copy constructor creates a linked list object that is a copy of sourceList
            // ******************************************************************************************
            //
            // Accessor functions for the list's head_ptr
            // ******************************************************************************************
            DNode* getHeadPtr() {return head_ptr;}
            // Summary: Returns a pointer to the head node of the list.
            // Preconditions: The list has been initialized.
            // Postconditions: A pointer to the head has been returned.
            // ******************************************************************************************
            //
            // ******************************************************************************************
            const DNode* getHeadPtr()const {return head_ptr;}
            // Summary: Returns a pointer to the head node of the list.
            // Preconditions: The list has been initialized.
            // Postconditions: A pointer to the head has been returned.
            // ******************************************************************************************
            //
            // Accessor functions for the list's tail_ptr
            // ******************************************************************************************
            DNode* getTailPtr() {return tail_ptr;}
            // Summary: Returns a pointer to the end node of the list.
            // Preconditions: The list has been initialized.
            // Postconditions: A pointer to the end of the list has been returned.
            // ******************************************************************************************
            //
            // ******************************************************************************************
            const DNode* getTailPtr()const {return tail_ptr;}
            // Summary: Returns a pointer to the end node of the list.
            // Preconditions: The list has been initialized.
            // Postconditions: A pointer to the end of the list has been returned.
            // ******************************************************************************************
            //
            // ******************************************************************************************
            size_type list_length()const {return node_count;}
            // Summary: This function returns the number of DNodes in the list.
            // Preconditions:  A list exists
            // Postconditions: Returns 0 if list is empty, otherwise it returns the number of items
            //                 in the list, i.e. count
            // ******************************************************************************************
            //
            // ******************************************************************************************
            bool isEmpty()const {return head_ptr == NULL;}
            // Summary: This function returns true if the list is empty.
            // Preconditions:  A list object exists
            // Postconditions: Returns true if the list contains no DNodes and false if the
            //                 list contains at least one DNode.
            // ******************************************************************************************
            //
            // ******************************************************************************************
            void head_insert(const DNode::valueType& value);
            // Summary: This function inserts a new DNode at the beginning of the list.
            // Preconditions:  A head_ptr exists and a new value has been passed in.
            // Postconditions: A new node has been added to the beginning of the list with the value
            // in the data_field at the head of the list.
            // ******************************************************************************************
            //
            // ******************************************************************************************
            void list_insert(DNode* loc_ptr, const DNode::valueType& value);
            // Summary: This function inserts a new node after loc_ptr.
            // Preconditions: loc_ptr is a pointer to the location where you want to insert a new DNode.
            // Postconditions: The list conatains one more DNode at loc_ptr.
            // ******************************************************************************************
            //
            // ******************************************************************************************
            DNode* list_search(const DNode::valueType& target);
            // Summary: This function looks for the DNode that has the target value in the data field.
            // Preconditions: head_ptr points to the beginning of the list. target is the data we are
            //                looking for.
            // Postconditions: A pointer to the DNode containing the target is returned or NULL is returned if the
            //                 target was not in the list.
            // ******************************************************************************************
            //
            //
            // ******************************************************************************************
            const DNode* list_search(const DNode::valueType& target)const;
            // Summary: This function looks for the DNode that has the target value in the data field.
            // Preconditions: head_ptr points to the beginning of the list. target is the data we are
            //                looking for.
            // Postconditions: A pointer to the DNode containing the target is returned or NULL is
            //                returned if the target was not in the list.
            // ******************************************************************************************
            //
            // ******************************************************************************************
            void head_remove();
            // Summary: This function removes the DNode at the beginning of the list.
            // Preconditions: There is a list with head_ptr pointing to the beginning of the list.
            // Postconditions: We have a list with the previous head node of the list removed.
            // ******************************************************************************************
            //
            // ******************************************************************************************
            void list_remove(DNode* node2rem);
            // Summary: This function removes the DNode pointed to by node2rem.
            // Preconditions: node2rem is a DNode pointer that points to the DNode we want to remove.
            // Postconditions: The list no longer contains the DNode pointed to by node2rem
            // ******************************************************************************************
            //
            // ******************************************************************************************
            void clear_list();
            // Summary: This function empties the list.
            // Preconditions: There is a current list.
            // Postconditions: list has been cleared of nodes. head_ptr now is NULL.
            // ******************************************************************************************
            //
            // Non-member overloaded operators
            // ******************************************************************************************
            friend ostream& operator <<(ostream& out, const DLinkedList& l);
            //
            // ******************************************************************************************
            //
            // destructor
            // ******************************************************************************************
            ~DLinkedList();
            // Summary: The destructor empties the list by calling clear_list().
            // ******************************************************************************************
            //
        private:
                DNode* head_ptr; // Points to front of list
                DNode* tail_ptr; // Points to end of list
                size_type node_count;   // holds the number of nodes in the list
    };

}
#endif // LINKEDLIST_H_INCLUDED
