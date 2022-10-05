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
int BigDecInt::operator[](int i){
    return num[i];
}

BigDecInt BigDecInt::operator+(BigDecInt num_2){
    BigDecInt res("");
    int bigger = max(BigDecInt::size(),num_2.size());
    if(BigDecInt::size()>num_2.size()){
        for(int i=0;i<=BigDecInt::size()-num_2.size();i++){
            num_2.num.push_back(0);
        }
    }
    if(BigDecInt::size()<num_2.size()){
        for(int i=0;i<=num_2.size()-BigDecInt::size();i++){
            num.push_back(0);
        }
    }

    
    for(int i=0;i<bigger;i++){
        int temp = (num.at(i)+num_2[i])%10;
        int carry=(num.at(i)+num_2[i])/10;
        res.num.push_back(temp);
        if (i==bigger-1){
            if(carry!=0){
                res.num.push_back(carry);
            }
        }else{
            num.at(i+1)+=carry;
        }
    }
    return res;
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
            for(int i=0;i<BigDecInt::size();i++){
                if(num[BigDecInt::size()-i]<num_2[BigDecInt::size()-i]){
                    return false;
                }
            }
        }
        return true;
    }else{
        if (BigDecInt::size()>num_2.size()){
            return false;
        }else if(BigDecInt::size()<num_2.size()){
            return true;
        }
        else{
            for(int i=0;i<BigDecInt::size();i++){
                if(num[BigDecInt::size()-i]<num_2[BigDecInt::size()-i]){
                    return true;
                }
            }
        }
        return false;
    }
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


bool BigDecInt::operator>(BigDecInt num_2){
    if (BigDecInt::sign() == -1 &&num_2.sign()==1){
        return false;
    }else if (BigDecInt::sign() == 1 &&num_2.sign()== -1){
        return true;
    }else if(BigDecInt::sign() == -1 &&num_2.sign()== -1){
        if (BigDecInt::size()>num_2.size()){
            return false;
        }else if(BigDecInt::size()<num_2.size()){
            return true;
        }
        else{
            for(int i=0;i<BigDecInt::size();i++){
                if(num[BigDecInt::size()-i]>num_2[BigDecInt::size()-i]){
                    return false;
                }
            }
        }
        return true;
    }else{
        if (BigDecInt::size()>num_2.size()){
            return true;
        }else if(BigDecInt::size()<num_2.size()){
            return false;
        }
        else{
            for(int i=0;i<BigDecInt::size();i++){
                if(num[BigDecInt::size()-i]>num_2[BigDecInt::size()-i]){
                    return true;
                }
            }
        }
        return false;
    }


}
ostream& operator<<(ostream& ouput,BigDecInt num){
    
    if (num.sign()==-1){
        ouput<<'-';
    }
    for(int i=1;i<=num.size();i++){
        ouput<<num[num.size()-i];
    }
    return ouput;
}


int main() {
    BigDecInt x("");
    BigDecInt y("");
    BigDecInt z= x+y;
    cout<<(x<y);



}