#ifndef STRINGREALIZE_H
#define STRINGREALIZE_H

#include <iostream>

class StringRealize {
    friend std::ostream& operator << 
    (std::ostream& os, const StringRealize& str);
    friend std::istream& operator >>
    (std::istream& in, const StringRealize& str);

    public: 
        StringRealize(const char* str = NULL); // 普通构造函数  
        StringRealize(const StringRealize& str); // 拷贝构造函数  
        ~StringRealize(void);
        
        StringRealize& operator = 
        (const StringRealize& str); // 赋值函数
        StringRealize& operator + 
        (const StringRealize& str);
        bool operator == (const StringRealize& str); 

        int getLength(void);
    private:
        char* m_data;
};

#endif 