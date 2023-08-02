#include<iostream>
using namespace std;
int main(){
    double ln2 = 0.69314718056;
    double pi = 3.14159265359;
    double catalan = 0.915965594177219;

    for(int a = 0; a <= 10; a++){
        for(int b = 0; b <= 10; b++){
            cout<<a<<" "<<b<<" "<<(a*ln2+b*pi)/catalan<<endl;
            cout<<a<<" "<<-b<<" "<<(a*ln2-b*pi)/catalan<<endl;
        }
    }
    return 0;
}