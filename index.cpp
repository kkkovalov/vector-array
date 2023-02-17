// - [ ]  Implement a vector (mutable array with automatic resizing):
//     - [x]  Practice coding using arrays and pointers, and pointer math to jump to an index instead of using indexing.
//     - [x]  New raw data array with allocated memory
//         - can allocate int array under the hood, just not use its features
//         - start with 16, or if starting number is greater, use power of 2 - 16, 32, 64, 128
//     - [x]  size() - number of items
//     - [x]  capacity() - number of items it can hold
//     - [x]  is_empty()
//     - [x]  at(index) - returns item at given index, blows up if index out of bounds
//     - [x]  push(item)
//     - [ ]  insert(index, item) - inserts item at index, shifts that index’s value and trailing elements to the right
//     - [ ]  prepend(item) - can use insert above at index 0
//     - [ ]  pop() - remove from end, return value
//     - [ ]  delete(index) - delete item at index, shifting all trailing elements left
//     - [ ]  remove(item) - looks for value and removes index holding it (even if in multiple places)
//     - [ ]  find(item) - looks for value and returns first index with that value, -1 if not found
//     - [ ]  resize(new_capacity) // private function
//         - when you reach capacity, resize to double the size
//         - when popping an item, if size is 1/4 of capacity, resize to half

#include <iostream>
#include <new>

class vectArr{
    public:
        int size = 0;
        int capacity = 16;
        bool is_empty(void){
            if(size == 0) return true;
            else return false;
        };
        int at(int* index){
            // if (*index < 0 || *index > capacity) return 0;
            return *(pointerArray + *index);
        }
        void push(int item){
            if(size + 1 > capacity){
                // resize();
            } else
            *(pointerArray + size) = item;
            size++;
        }
    private:
        int * pointerArray = new (std::nothrow) int[capacity];


};

int main(void){
    vectArr home;
    
}