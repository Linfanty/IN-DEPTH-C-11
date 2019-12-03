#include "StringRealize.h"
#include <string.h>
#include <stdio.h>

StringRealize::StringRealize(const char* str) {
    if(str == NULL) m_data = NULL;
    else {
        m_data = new char[strlen(str) + 1];
        strcpy(m_data, str);
    }
}

StringRealize::StringRealize(const StringRealize& str) {
    if(m_data == NULL) m_data = NULL;
    else {
        m_data = new char[strlen(str.m_data) + 1];
        strcpy(m_data, str.m_data);
    }
}

StringRealize::~StringRealize(void) {
    if(m_data) {
        delete[] m_data;
        m_data = NULL;
    }
}

StringRealize& StringRealize::operator = (const StringRealize& str) {
    if(this != &str) {
        delete[] m_data;
        m_data = NULL;
        
        if(str.m_data == NULL) 
            m_data = NULL;
        else {
            m_data = new char[strlen(m_data) + 1];
            strcpy(m_data, str.m_data);
        }
    }
    return *this;
}

//链接字符串‘+’号重载
StringRealize& StringRealize::operator + (const StringRealize& str) {
    char* tmp = m_data;
    m_data = new char [strlen(m_data) + strlen(str.m_data)];
    strcpy(m_data, tmp);
    strcat(m_data, str.m_data);

    delete[] tmp;
    return *this;
    /*
    StringRealize newString;
    if(str.m_data == NULL) 
        return *this;
    else if(m_data == NULL)
        newString = str;
    else {
        newString.m_data = new char[strlen(str.m_data) + 
                            strlen(m_data) + 1];
        strcpy(newString.m_data, m_data);
        strcpy(newString.m_data, str.m_data);
    }
    return newString;
    */
}

bool StringRealize::operator==(const StringRealize& str) {
    if(strlen(m_data) != strlen(str.m_data)) 
        return false;
    else return strcmp(m_data, str.m_data) ? false : true;
}

int StringRealize::getLength() {
    return strlen(m_data);
}

std::ostream& operator << (std::ostream& os, const StringRealize& str) {
    os << str.m_data;
    return os;
}

std::istream& operator >> (std::istream& in, const StringRealize& str) {
    in >> str.m_data;
    return in;
}