#include <iostream>
#include <fstream>
#include <functional>
#include "llrec.h"
using namespace std;

/**
 * Reads integers (separated by whitespace) from a file
 * into a linked list.
 *
 * @param[in] filename
 *  The name of the file containing the data to read
 * @return
 *  Pointer to the linked list (or NULL if empty or the
 *  file is invalid)
 */
Node* readList(const char* filename);

/**
 * Prints the integers in a linked list pointed to
 * by head.
 */
void print(Node* head);

/**
 * Deallocates the linked list nodes
 */
void dealloc(Node* head);


Node* readList(const char* filename)
{
    Node* h = NULL;
    ifstream ifile(filename);
    int v;
    if( ! (ifile >> v) ) return h;
    h = new Node(v, NULL);
    Node *t = h;
    while ( ifile >> v ) {
        t->next = new Node(v, NULL);
        t = t->next;
    }
    return h;
}

void print(Node* head)
{
		int cnt = 0;
    while(head) {
        cout << head->val << " ";
        head = head->next;
				cnt++;
    }
    cout << " (" << cnt << ")" << endl;
}

void dealloc(Node* head)
{
    Node* temp;
    while(head) {
        temp = head->next;
        delete head;
        head = temp;
    }
}

// -----------------------------------------------
//   Add any helper functions or
//   function object struct declarations
// -----------------------------------------------





int main(int argc, char* argv[])
{
    if(argc < 2) {
        cout << "Please provide an input file" << endl;
        return 1;
    }

    // -----------------------------------------------
    // Feel free to update any code below this point
    // -----------------------------------------------
    Node* head = readList(argv[1]);
    cout << "Original list: ";
    print(head);

    // Test out your linked list code
    // Node* one = new Node;
    // one->val = 1;
    // Node* two = new Node;
    // two->val = 2;
    // Node* three = new Node;
    // three->val = 4;
    
    
    
    
    // one->next = two;
    // two->next = three;
    // three->next = NULL;

    
    
    // Node* head = one;
		Node* smaller = NULL;
		Node* larger = NULL;
		
		llpivot (head, smaller, larger, 1);

		cout << "LL-Pivot list small: ";
    print(smaller);
		cout << "LL-Pivot list large: ";

		    print(larger);
	cout << "LL-Pivot list head: ";
	print(head);
    


    
    return 0;

}
