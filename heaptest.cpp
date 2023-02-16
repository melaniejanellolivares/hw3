#include <iostream>
#include "heap.h"
using namespace std;

int main(){
	Heap<int> heap;

	heap.push(0);

	heap.push(5);
	
	heap.push(10);
		
	heap.push(15);
	
	heap.push(20);

	cout <<"pop 1" << endl;

	heap.pop();
	heap.top();

	cout <<"pop 2" << endl;

	heap.pop();
	heap.top();


	// h1.push(3);
	// h1.push(10);
	// 	cout <<"top 1" << endl;

	// 	h1.top();

	// 	cout <<"pop 1" << endl;

	// h1.pop();
	// h1.top();


	// h1.push(9);
	// 	cout <<"top 1" << endl;

	// 	h1.top();

	// h1.push(9);
	// 		cout <<"top 2" << endl;

	// 	h1.top();
	// 	cout <<"top 3" << endl;

	// h1.push(20);
	// 	h1.top();

	
	// cout <<"pop 1" << endl;

	// h1.pop();
	// h1.top();

	// cout <<"pop 2" << endl;

	// h1.pop();
	// h1.top();

	// 	cout <<"pop 3" << endl;
	// 		h1.pop();




	





}




