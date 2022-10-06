#include "bigdecint.h"
#include<iostream>
#include<bits/stdc++.h>


using namespace std;



BigDecInt::BigDecInt(int int_num){
    if(int_num<0){
        num_sign = -1;
    }
    int_num = abs(int_num);
    int num_size = int(log10(int_num))+1;
    for(int i=0;i<num_size;i++){
        num.push_back(int_num%10);
        int_num /=10;
    }
}

BigDecInt::BigDecInt(string str_num){
    if(str_num[0] == '-'){
        num_sign = -1;
        for(int i=0;i<str_num.size();i++){
            if (i==str_num.size()-1)
                break;
            num.push_back(int(str_num[str_num.size()-1-i])-48);
        }
    }else if(str_num[0] == '+'){
        for(int i=0;i<str_num.size();i++){
            if (i==str_num.size()-1)
                break;
            num.push_back(int(str_num[str_num.size()-1-i])-48);
        }
    }
    else{
        for(int i=0;i<str_num.size();i++){
            num.push_back(int(str_num[str_num.size()-1-i])-48);
        }
    }
}

int BigDecInt::size(){
    return num.size();
}

int BigDecInt::sign(){
    return num_sign;
}
int& BigDecInt::operator[](int i){
    return num.at(i);
}

void BigDecInt::operator=(BigDecInt num_2){
    num = num_2.num;
    num_sign = num_2.num_sign;

}
bool BigDecInt::operator<(BigDecInt num_2){
    if (BigDecInt::sign() == -1 &&num_2.sign()==1){
        return true;
    }else if (BigDecInt::sign() == 1 &&num_2.sign()== -1){
        return false;
    }else if(BigDecInt::sign() == -1 &&num_2.sign()== -1){
        if (BigDecInt::size()>num_2.size()){
            return true;
        }else if(BigDecInt::size()<num_2.size()){
            return false;
        }
        else{
            int i=0;
            do
            {
                if(num[BigDecInt::size()-i-1]<num_2[BigDecInt::size()-i-1]){
                    return false;
                }
                i++;
            } while (num[BigDecInt::size()-i]==num_2[BigDecInt::size()-i] && i<BigDecInt::size());
            
        }
        return true;
    }else{
        if (BigDecInt::size()>num_2.size()){
            return false;
        }else if(BigDecInt::size()<num_2.size()){
            return true;
        }
        else{
            int i=0;
            do
            {
                if(num[BigDecInt::size()-i-1]<num_2[BigDecInt::size()-i-1]){
                    return true;
                }
                i++;
            } while (num[BigDecInt::size()-i]==num_2[BigDecInt::size()-i] && i<BigDecInt::size());
            
        }
        return false;
    }
}

void BigDecInt::push_back(int i){
    num.push_back(i);
}

bool BigDecInt::operator==(BigDecInt num_2){
    if(BigDecInt::sign()!=num_2.sign()){
        return false;
    }else{
            for(int i=0;i<BigDecInt::size();i++){
                if(num[i]!=num_2[i]){
                    return false;
                }
            }
    }
    return true;
}

ostream& operator<<(ostream& ouput,BigDecInt num){
    
    if (num.sign()==-1){
        ouput<<'-';
    }
    bool first_zeros=true;
    for(int i=1;i<=num.size();i++){
        if(num[num.size()-i]!=0){
            first_zeros=false;
        }
        if(!first_zeros){
            ouput<<num[num.size()-i];
        }
    }
    return ouput;
}
BigDecInt operator-(BigDecInt num,BigDecInt num_2){
    BigDecInt res("");

    if(num.sign()==-1){
        res = num+num_2;
        res.num_sign = -1;
        return res;
    }

    if(num_2.sign() == -1){
        res = num+num_2;
        return res;
    }
    if(num<num_2){
        res = num_2 - num;
        res.num_sign = -1;
        return res;

    }
    if(num.size()>num_2.size()){
        int z = num.size() - num_2.size();
        for(int i=0;i<z;i++){
            num_2.push_back(0);
        }
    }
    if(num.size()<num_2.size()){
        int z = num.size() - num_2.size();
        for(int i=0;i<z;i++){
            num.push_back(0);
        }
    }

    for(int i=0;i<num.size();i++){
        if(num[i]<num_2[i]){
            num[i]+=10;
            num[i+1]--;
        }
            res.push_back(num[i]-num_2[i]);
    }
    return res;
}

BigDecInt operator+(BigDecInt num,BigDecInt num_2){
    BigDecInt res("");
    if(num.size()>num_2.size()){
        for(int i=0;i<=num.size()-num_2.size();i++){
            num_2.push_back(0);
        }
    }
    if(num.size()<num_2.size()){
        for(int i=0;i<=num_2.size()-num.size();i++){
            num.push_back(0);
        }
    }

    if(num.sign()==-1){
        res = num_2 -num;
        return res;
    }


    for(int i=0;i<num.size();i++){
        int temp = (num[i]+num_2[i])%10;
        int carry=(num[i]+num_2[i])/10;
        res.num.push_back(temp);
        if (i==num.size()-1){
            if(carry!=0){
                res.num.push_back(carry);
            }
        }else{
            num[i+1]+=carry;
        }
    }
    return res;
}
bool operator>(BigDecInt num,BigDecInt num_2){
    return !(num<num_2&&!(num==num_2));
}

int main() {
    BigDecInt num1("123456789012345678901234567890"); 
    BigDecInt num2("+113456789011345678901134567890"); 
    BigDecInt num3("-200000000000000000000000000000"); 
    BigDecInt num4 = num2 + num1; 
    BigDecInt num5 = num3 - num2; 
    cout << "num1 = " << num1 << endl; 
    cout << "num2 = " << num2 << endl; 
    //Next statement will print 236913578023691357802369135780 
    cout << "num2 + num1 = " << num4 << endl;
    //Next statement will print -313456789011345678901134567890
    cout << "num2 - num1 = " << num5 << endl;



}