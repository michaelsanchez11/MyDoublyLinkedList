#ifndef DNode_H
#define DNode_H
#include <cstdlib>
#include <string>
using namespace std;

class DNode
{
    public: 
        typedef int valueType;
        DNode(const valueType& data = valueType(),DNode* previousLink = NULL, DNode* linkField = NULL) // this constructor takes care of all possible overloaded constructors.
        // Mutator functions to change the data in our DNode.
        {
            this -> data = data;
            this -> previousLink = previousLink;
            this -> linkField = linkField;
        }

        void setData(const valueType& data){this-> data = data;}
        void setLink(DNode* link){this-> linkField = link;} 
        void setPrevLink(DNode* previousLink) {this -> previousLink = previousLink;}
        valueType getData() const {return data;}

        // IF EVER RETURNING A POINTER, DO THE FOLLOWING TWO FUNCTION DEFINITIONS.
        //Two version of returning a pointer.
        // 1. Allow one that cannot modify the pointer at all.
        // To use this one, we need to initialize the DNode* as... const DNode* n; Only works with const DNodes.

        const DNode* getLink() const{return linkField;}
        const DNode* getPrevLink() const{return previousLink;}

        
        // 2. Allow changes and modify the data and linkfield of any DNode. // a copy not the same value.
        DNode* getLink() {return linkField;}
        DNode* getPrevLink(){return previousLink;}
        //const DNode *n; this behavior allows the pointer DNode to inspect, however it doesnt not allow it to change anything.(Just to view the information)
        //DNode *const n; this behavior does NOT allow us to move the pointer at all. Returns constant DNode pointer.
    private:
        valueType data;
        DNode* linkField; // the "next" DNode.
        DNode* previousLink;

};
#endif