#ifndef VEVTOR_H
#define VEVTOR_H

#define SPACE_CAPACITY 5

namespace stl{
    template<typename Object>
    class Vector {
        public: 
            explicit Vector(int initsize = 0) : thesize(0), theCapacity(initsize) {
                Objects = new Object[thesize];
            }

            Vector(const Vector& V) : thesize(0), theCapacity(0), Objects(NULL) {
                *this = V;
            }

            ~Vector() {
                delete[] Objects;  
            }

            Vector& operator = (const Vector& ths) {
                if(this != ths) {
                    delete[] Objects;
                    thesize = ths.thesize;
                    theCapacity = ths.theCapacity;
                    Objects = new Object[theCapacity];  // deep clone not shallow clone: Objiect = ths.objects
                    for(int i = 0; i < ths.thesize; ++i)
                        Objects[i] = ths.Objects[i];
                } 
                return *this;
            }

            void resize(int newSize) {
                if(newSize <= thesize) return;
                if(newSize > theCapacity) resize(2 * newSize + 1);
                thesize = newSize;
            }

            void reserve(int newCapacity) {
                if(newCapacity < thesize) return;
                Object* tmp = Objects;
                Objects = new Object[newCapacity]; // allocate more large
                for(int i = 0; i < thesize; ++i) 
                    Objects[i] = tmp[i];
                delete[] tmp;
            }

            Object& operator[] (int index) {
                return Objects[index];
            }
            const Object& operator[] (int index) const {
                return Objects[index];
            }

            bool isEmpty() const {
                return size() == 0;
            }
            int size() const{
                return thesize;
            }
            int capacity() const{
                return theCapacity;
            }

            void push_back(Object obj) {
                if(thesize == theCapacity) 
                    reserve(2 * theCapacity + 1);
                Objects[thesize++] = obj;
            }
            void pop_back() {
                --thesize;
            }

            const Object& back() const {
                return Objects[size() - 1];
            }

            typedef Object* iterator;
            typedef const Object* const_iterator;

            iterator begin() {
                return &Objects[0];
            }
            iterator end() {
                return &Objects[size()];
            }
            const_iterator cbegin() {
                return &Objects[0];
            }
            const_iterator cend() const {
                return &Objects[size()];
            }

        private:
            int thesize;
            int theCapacity;
            Object* Objects; // point
    };
}

#endif