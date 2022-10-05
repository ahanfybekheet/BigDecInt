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
        BigDecInt operator+(BigDecInt);
        BigDecInt operator-(BigDecInt);
        void operator=(BigDecInt);
        bool operator>(BigDecInt);
        bool operator<(BigDecInt);
        bool operator==(BigDecInt);
        int operator[](int);


};