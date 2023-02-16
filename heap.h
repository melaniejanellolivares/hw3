#ifndef HEAP_H
#define HEAP_H
#include <functional>
#include <stdexcept>
#include <vector>



template <typename T, typename PComparator = std::less<T> >
class Heap
{
public:
  /**
   * @brief Construct a new Heap object
   * 
   * @param m ary-ness of heap tree (default to 2)
   * @param c binary predicate function/functor that takes two items
   *          as an argument and returns a bool if the first argument has
   *          priority over the second.
   */
  Heap(int m=2, PComparator c = PComparator());

  /**
  * @brief Destroy the Heap object
  * 
  */
  ~Heap();

  /**
   * @brief Push an item to the heap
   * 
   * @param item item to heap
   */
  void push(const T& item);

  /**
   * @brief Returns the top (priority) item
   * 
   * @return T const& top priority item
   * @throw std::underflow_error if the heap is empty
   */
  T const & top() const;

  /**
   * @brief Remove the top priority item
   * 
   * @throw std::underflow_error if the heap is empty
   */
  void pop();

  /// returns true if the heap is empty

  /**
   * @brief Returns true if the heap is empty
   * 
   */
  bool empty() const;

    /**
   * @brief Returns size of the heap
   * 
   */
  size_t size() const;

private:
  /// Add whatever helper functions and data members you need below
  std::vector<T> data;
  int m;
  PComparator c;


};

// Add implementation of member functions here

template <typename T, typename PComparator>
Heap<T,PComparator>::Heap(int m, PComparator c)
: m(m), c(c)
{

}

template <typename T, typename PComparator>
Heap<T,PComparator>::~Heap(){

}

template <typename T, typename PComparator>

size_t Heap<T,PComparator>::size() const{
	return data.size();
}



// We will start top() for you to handle the case of 
// calling top on an empty heap
template <typename T, typename PComparator>
T const & Heap<T,PComparator>::top() const
{
  // Here we use exceptions to handle the case of trying
  // to access the top element of an empty heap
  if(empty()){
    // ================================
    // throw the appropriate exception
    // ================================
    throw std::underflow_error("error");

  }
  // If we get here we know the heap has at least 1 item
  // Add code to return the top element
  return data[0];



}


// We will start pop() for you to handle the case of 
// calling top on an empty heap
template <typename T, typename PComparator>
void Heap<T,PComparator>::pop()
{
  if(empty()){
    // ================================
    // throw the appropriate exception
    // ================================
    throw std::underflow_error("error");

  }
  std::swap(data.front(), data.back());
  data.pop_back();

  if(empty()){
    return;

  }
  if(data.size() < 2){
    return;
  }

  
  size_t index = 0;
  while(true){
    size_t maxvalue = index;    
    T& current = data[index];

    for(int i = 1; i <= m; i++){

      if(m*(index) + i < data.size()){
        if(c(data[m*(index) + i], data[maxvalue])){
          maxvalue = m*(index) + i;
        }        
      }
      else{
        break;
      }
    }


    if(maxvalue == index || c(current, data[maxvalue])){
      break;
    }

    std::swap(current, data[maxvalue]);
    index = maxvalue; 
  }
  


}

template <typename T, typename PComparator>
void Heap<T,PComparator>::push(const T& item){

  if(empty()){

    data.push_back(item);

    return;

  }
  data.push_back(item);
  
  int loc = data.size() - 1;
  int parent = (loc - 1)/m;

  while(parent >= 0 && c( data[loc], data[parent])){

    std::swap(data[parent], data[loc]);
    loc = parent;
    parent = (loc - 1)/m;
  }
}

template <typename T, typename PComparator>
bool Heap<T,PComparator>::empty() const{
  return data.empty();
}


#endif

