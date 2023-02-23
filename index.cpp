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
//     - [x]  insert(index, item) - inserts item at index, shifts that index’s value and trailing elements to the right
//     - [x]  prepend(item) - can use insert above at index 0
//     - [x]  pop() - remove from end, return value
//     - [x]  deleteItem(index) - delete item at index, shifting all trailing elements left
//     - [x]  remove(item) - looks for value and removes index holding it (even if in multiple places)
//     - [x]  find(item) - looks for value and returns first index with that value, -1 if not found
//     - [ ]  resize(new_capacity) // private function
//         - when you reach capacity, resize to double the size
//         - when popping an item, if size is 1/4 of capacity, resize to half

#include <iostream>
#include <new>

class vectArr{
    public:
        int size = 0;
        int capacity = 4;

        bool is_empty(void){
            if(size == 0) return true;
            else return false;
        };

        int at(int index){
            // if (*index < 0 || *index > capacity) return 0;
            return *(pointerArray + index);
        };

        void push(int item){
            if(size + 1 > capacity){
                resize();
            }
            *(pointerArray + size) = item;
            size++;
        };

        void insert(int index, int item){
            if(size + 1 > capacity){
                resize();
            }
            
            int tempCurVal, tempPrevVal = *(pointerArray + index);
            *(pointerArray + index) = item;
            size++;
            for(int i = index + 1; i < size; i++){
                tempCurVal = *(pointerArray + i);
                *(pointerArray + i) = tempPrevVal;
                tempPrevVal = tempCurVal;
            };
        };

        void prepend(int item){
            insert(0, item);
        };

        int pop(){
            int deleteVal = *(pointerArray + size - 1);
            *(pointerArray + size - 1) = 0;
            size--;
            return deleteVal;
        };

        void deleteItem(int index){
            for(int i = index; i < size; i++){
                *(pointerArray + i) = *(pointerArray + i + 1);
            };
            size--;
        };

        void remove(int item){
            for(int i = 0; i < size; i++){
                if(*(pointerArray + i) == item) deleteItem(i);
            };
        };

        int find(int item){
            for(int i = 0; i < size; i++){
                if(*(pointerArray + i) == item) return i;
            };
            return -1;
        }

        void all(){
            for(int i = 0; i < size; i++){
                std::cout<<*(pointerArray + i)<<' ';
            };
            std::cout<<std::endl;
        };

    private:
        int * pointerArray = new (std::nothrow) int[capacity];

        void resize(){
            capacity*=2;
            int * tempPointer = new (std::nothrow) int[capacity];
            for(int i = 0; i < size; i++){
                *(tempPointer + i) = *(pointerArray + i);
            }
            delete [] pointerArray;
            pointerArray = tempPointer;
            std::cout<<"Resized pointer = "<<&pointerArray<<std::endl;
        };


};

int main(void){
    vectArr arr1;
    arr1.push(4);
    arr1.push(1);
    arr1.push(6);
    arr1.push(8);
    arr1.all();
    arr1.push(9);
    arr1.all();
}