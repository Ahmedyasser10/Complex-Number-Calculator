#include <iostream>
#include <string>
#include <cctype>
#include <regex>
using namespace std;

bool valid_complex_number(string&num){
    string c;

    regex valid_complex_num{"[(][-]?[0-9]+([.][0-9]+)*[+-][0-9]+([.][0-9]+)*[i][)]"};
    return regex_match(num,valid_complex_num);

}
void div(string&str,float&r,float&i ){
    int plus_sign,minas_sign,minas_sign2,im,sign,cnt=0;
    for(auto i: str){
        if(i=='-')
            cnt++;
    }
    if(cnt<2) {
        plus_sign = str.find('+');
        minas_sign = str.find('-');
        sign = max(plus_sign,minas_sign);
    } else{
        minas_sign=str.find('-');
        minas_sign2=str.find('-',2);
        sign = max(minas_sign,minas_sign2);
    }


    im = str.find('i');

    r = stof(str.substr(1,sign));
    i = stof(str.substr(sign,im));
}

void sum(float r1, float i1,float r2,float i2 ){
    int r,i;
    r=r1+r2;
    i=i1+i2;
    cout<<"the sum of the complex numbers is: ";
    if(i>0)
        cout<<'('<<r<<'+'<<i<<'i'<<')'<<endl;
    else
        cout<<'('<<r<<i<<'i'<<')'<<endl;


}
void sub(float r1, float i1,float r2,float i2){
    int r,i;
    r = r1-r2;
    i = i1-i2;
    cout<<"the subtraction of the complex numbers is: ";

    if(i>0)
        cout<<'('<<r<<'+'<<i<<'i'<<')'<<endl;
    else
        cout<<'('<<r<<i<<'i'<<')'<<endl;




}
void mul(float r1, float i1,float r2,float i2){
    float pr1, pi1, pi2, pi3, real, im;
    pr1 = (r1 * r2);
    pi1 = (r1 * i2);
    pi2 = (i1 * r2);
    pi3 = (i1 * i2);
    real = pr1 - pi3;
    im = pi1 + pi2;
    cout<<"the multiplication of the complex numbers is: ";
    if (im > 1) {
        cout << '(' << real << '+' << im << 'i' << ')' << endl;

    } else {
        cout << '(' << real << im << 'i' << ')' << endl;

    }

}
void div(float r1, float i1,float r2,float i2){
    float pr1, pi1, pi2, pi3, real, im,d,r,i3,r3;
    float inverse = -i2;
    pr1 = (r1 * r2);
    pi1 = (r1 * inverse);
    pi2 = (i1 * r2);
    pi3 = +(i1 * inverse);
    real= (pr1-pi3);
    im=(pi1+pi2);
    d=(abs(r2)* abs(r2))-(-(abs((i2)* abs(i2))));
    cout<<"the division of the complex numbers is: ";

    if((im/d)>0)

        cout<<(real/d)<<'+'<<(im/d)<<"i"<<endl;

    else
        cout<<(real/d)<<im/d<<"i"<<endl;



}



int main() {
float r1,i1,r2,i2;
string complex_number;
int n{1};
while(n<=2) {
    cout << "Enter a valid complex number in (a+bi) Format or type exit to exit: ";
    getline(cin,complex_number);
    if(complex_number=="exit")
        break;

    else if(valid_complex_number(complex_number)) {
        cout << "It is a valid complex number" << endl;

        if(n==1)
            div(complex_number,r1,i1);

        else {
            div(complex_number,r2,i2);

        }n++;
    }
    else
        cout<<"It is not a valid complex number"<<endl;

}

char op;

if(complex_number!="exit") {
    cout<<"Enter The operation that You want: ";
    cin>>op;
    if (op == '+')
        sum(r1, i1, r2, i2);
    else if (op == '-')
        sub(r1, i1, r2, i2);

    else if (op == '*')
        mul(r1, i1, r2, i2);

    else if (op == '-')
        div(r1, i1, r2, i2);

    else
        cout << "invalid input" << endl;
}
else{
    cout<<"Thanks For Using FCAI Complex Number Calculator"<<endl;

}


    return 0;


}
