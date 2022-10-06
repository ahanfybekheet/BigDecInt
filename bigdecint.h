#pragma once
#include<iostream>
#include<vector>
using namespace std;

class BigDecInt{
    private:
        vector<int> num;
        int num_sign = 1;
    public:
        BigDecInt();
        BigDecInt(int);
        BigDecInt(string);
        int size();
        int sign();
        void operator=(BigDecInt);
        bool operator<(BigDecInt);
        bool operator==(BigDecInt);
        int& operator[](int);
        void push_back(int);
        friend BigDecInt operator-(BigDecInt,BigDecInt);
        friend BigDecInt operator+(BigDecInt,BigDecInt);

};