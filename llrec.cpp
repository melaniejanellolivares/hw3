#include "llrec.h"


//*********************************************
// Provide your implementation of llpivot below
//*********************************************


void llpivot (Node*& head, Node*& smaller, Node*& larger, int pivot){

if(head == NULL){
		smaller = NULL;
		larger = NULL;
		return;
	} //terminate

	//case where one


		llpivot(head->next, smaller, larger, pivot);
	
		if(pivot >= head->val){
			Node* temp = smaller;
			smaller = head;
			smaller->next =temp;

		}
		else{
			Node* temp = larger;
			larger = head;
			larger->next = temp;
		}
		head = NULL;




	// if(pivot >= head->val){
        
	// 	if(head->next == NULL){ //check if next iteration is last
	// 		if(smaller == NULL){
	// 			smaller = head;
	// 			head = NULL;
	// 		}
	// 		smaller->next = head;
	// 		if(larger != NULL){
	// 			larger->next = NULL;
	// 		}				
	// 	}
	// 	else if(smaller == NULL){
	// 		Node* tempnext = head->next;
	// 		smaller = head;
	// 		head = NULL;
	// 		llpivot(tempnext, smaller, larger, pivot);
	// 	}
	// 	else{
	// 		smaller->next = head;
	// 		llpivot(head->next, smaller->next, larger, pivot);
	// 	}
            

            
  //   }
  //   else{
        
	// 		if(head ->next == NULL){ //check if next iteration is last
	// 			if(larger == NULL){
	// 				larger = head;
	// 				head = NULL;
	// 			}
	// 			larger->next = head;
	// 			if(smaller != NULL){
	// 				smaller->next = NULL;
	// 			}
							
	// 		}
	// 		else if(larger == NULL){
	// 			Node* tempnext = head->next;

	// 			larger = head;
	// 			head = NULL;

	// 			llpivot(tempnext, smaller, larger, pivot);
	// 		}
	// 		else{
	// 			std::cout << "in large head val " << head->val << std::endl;
	// 			larger->next = head;
	// 			llpivot(head->next, smaller, larger->next, pivot);
	// 		}
  //   }

	
}