#include "DLinkedList.h"
#include <iostream>

namespace mike_DLinkedList
{
	DLinkedList::DLinkedList()
	{
		head_ptr = NULL;
		tail_ptr = NULL;
		node_count = 0;
	}
    // Summary: Constructor creates a linked list object with count set at 0.
    // ******************************************************************************************
    //
    // ******************************************************************************************
    /*DLinkedList::DLinkedList(const DLinkedList& sourceList)
    {
    	head_ptr = sourceList.head_ptr;
    	tail_ptr = sourceList.tail_ptr;
    	node_count = sourceList.node_count;

    }*/
    // Summary: Copy constructor creates a linked list object that is a copy of sourceList
    // ******************************************************************************************
    //
    // ******************************************************************************************
    void DLinkedList::head_insert(const DNode::valueType& value)
    {
        //creating the new Dnode to insert into the list(LinkedList works with new DNodes)
        DNode * newNode = new DNode(value);

    	if(head_ptr == NULL)
    	{
    		head_ptr = newNode;
            tail_ptr = newNode;
    	}
        else
        {
            
            newNode->setLink(head_ptr);
            head_ptr = newNode;
            head_ptr -> getLink() -> setPrevLink(head_ptr);
        }
        node_count++;
    }
    // Summary: This function inserts a new DNode at the beginning of the list.
    // Preconditions:  A head_ptr exists and a new value has been passed in.
    // Postconditions: A new node has been added to the beginning of the list with the value
    // in the data_field at the head of the list.
    // ******************************************************************************************
    //
    // ******************************************************************************************
    void DLinkedList::list_insert(DNode* loc_ptr, const DNode::valueType& value)
    {
        if(head_ptr == NULL)
            return;
        for(DNode* cur = head_ptr; cur != NULL; cur = cur ->getLink())
        {
            if(cur == loc_ptr && cur -> getLink() != NULL)
            {
                DNode * temp = new DNode(value);
                temp ->setLink(cur -> getLink());
                cur -> getLink() -> setPrevLink(temp);
                cur -> setLink(temp);
                temp -> setPrevLink(cur);
                node_count++;
                return;
            }
            if(cur == loc_ptr && cur -> getLink() == NULL)
            {
                DNode * temp = new DNode(value);
                cur -> setLink(temp);
                temp -> setPrevLink(cur);
                tail_ptr = temp;
                node_count++;
                return;
            }
        }
        return;
    }
    // Summary: This function inserts a new node after loc_ptr.
    // Preconditions: loc_ptr is a pointer to the location where you want to insert a new DNode.
    // Postconditions: The list conatains one more DNode at loc_ptr.
    // ******************************************************************************************
    //
    // ******************************************************************************************
    DNode* DLinkedList::list_search(const DNode::valueType& target)
    {
        if(head_ptr == NULL)
            return NULL;
        for(DNode* cur = head_ptr; cur!= NULL; cur = cur->getLink())
        {
            if(cur -> getData() == target)
            {
                cout << cur -> getData() << endl;
                return cur;
            }
        }
        return NULL;
    }
        // Summary: This function looks for the DNode that has the target value in the data field.
    // Preconditions: head_ptr points to the beginning of the list. target is the data we are
    //                looking for.
    // Postconditions: A pointer to the DNode containing the target is returned or NULL is returned if the
    //                 target was not in the list.
    // ******************************************************************************************
    //
    //
    // ******************************************************************************************
    const DNode* DLinkedList::list_search(const DNode::valueType& target)const
    {
        if(head_ptr == NULL)
            return NULL;
        for(DNode* cur = head_ptr; cur!= NULL; cur = cur->getLink())
        {
            if(cur -> getData() == target)
            {
                cout << cur -> getData() << endl;
                return cur;
            }
        }
        return NULL;
    }
    // Summary: This function looks for the DNode that has the target value in the data field.
    // Preconditions: head_ptr points to the beginning of the list. target is the data we are
    //                looking for.
    // Postconditions: A pointer to the DNode containing the target is returned or NULL is
    //                returned if the target was not in the list.
    // ******************************************************************************************
    //
    // ******************************************************************************************
    void DLinkedList::head_remove()
    {
        if(head_ptr == NULL)
            return;
        if(node_count == 1)
        {
            DNode* temp = head_ptr;
            head_ptr = NULL;
            tail_ptr = NULL;
            node_count --;
            delete temp;
            return;    
        }
        DNode* temp = head_ptr;
        head_ptr = head_ptr -> getLink();
        head_ptr -> setPrevLink(NULL);
        node_count--;
        //cout << node_count << endl;
        delete temp;
    }
    // Summary: This function removes the DNode at the beginning of the list.
    // Preconditions: There is a list with head_ptr pointing to the beginning of the list.
    // Postconditions: We have a list with the previous head node of the list removed.
    // ******************************************************************************************
    //
    // ******************************************************************************************
    void DLinkedList::list_remove(DNode* node2rem)
    {
        if(head_ptr == NULL)
            return;
        for(DNode* cur = head_ptr; cur != NULL;cur = cur ->getLink())
        {

            if(head_ptr == node2rem)
            {
                cout << "First else if" << endl;
                cout << "Before Head\n";
                head_remove();
                cout << "After Head\n";

                return;
            }
            if(cur == node2rem && cur ->getLink() != NULL)
            {
                cout << "if" << endl;
                DNode * temp = cur;
                cur -> getPrevLink() -> setLink(cur->getLink());
                cur -> getLink() -> setPrevLink(cur -> getPrevLink());
                node_count--;
                return;
            }
            else if(node_count == 1)
            {
                cout << "Second else if" << endl;
                cout << "Before Head\n";
                head_remove();
                cout << "After Head\n";
                return;
            }
            else if(cur == node2rem && cur -> getLink() == NULL)
            {
                cout << "last If" << endl;
                cur -> getPrevLink() -> setLink(NULL);
                tail_ptr = cur -> getPrevLink();
                node_count--;
                return;
            }
        }
        return;
    }
    // Summary: This function removes the DNode pointed to by node2rem.
    // Preconditions: node2rem is a DNode pointer that points to the DNode we want to remove.
    // Postconditions: The list no longer contains the DNode pointed to by node2rem
    // ******************************************************************************************
    //
    // ******************************************************************************************
    void DLinkedList::clear_list()
    {
        if(head_ptr == NULL)
            return;
        for(DNode* cur = head_ptr; cur != NULL; cur = cur -> getLink())
        {
            head_remove();
        }
        node_count = 0;
        return;

    }
    // Summary: This function empties the list.
    // Preconditions: There is a current list.
    // Postconditions: list has been cleared of nodes. head_ptr now is NULL.
    // ******************************************************************************************
    //
    // Non-member overloaded operators
    // ******************************************************************************************
    ostream& operator <<(ostream& out, const DLinkedList& l)
    {
        const DNode *cur = l.getHeadPtr();
        
        while(cur!= NULL)
            {
                out << cur-> getData() << " ";
                cur = cur -> getLink();
            }
        return out;
    }
    //
    // ******************************************************************************************
    //
    // ******************************************************************************************
    //void operator =(const DLinkedList& listRight);
    //
    // ******************************************************************************************
    //
    // destructor
    // ******************************************************************************************
    DLinkedList::~DLinkedList()
    {
        clear_list();
    }
    // Summary: The destructor empties the list by calling clear_list().
    // ******************************************************************************************
    //
}