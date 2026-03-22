#include <iostream>
#include <algorithm>
#include <string>
#include <cmath>
using namespace std;

void decimal_to_binary(long long int x, string &binary);
void binary_to_decimal(string decimal);

int main() {

    int user_input = 0; 

    cout << "Welcome to binary converter! Enter 1 to convert a decimal number to binary, or 2 to convert a binary number to decimal. "  << endl;
    cin >> user_input;

    if (user_input == 1){
    string binary;
    long long int x = 0;

    cout << "Okay! Enter the number you would like to convert to to binary: " << endl;
    cin >> x;
    cout << "Your number in binary is: " << endl;

    if (x < 0){
        x = -x;
        cout << "-";
    } else if (x == 0){
        cout << 0 << endl;
        return 0;
    } else if (x == 1){
        cout << 1 << endl;
        return 0;
    } 

    unsigned i;
    for (i = 0; pow(2, i) < x; i++) {
    } 
        if (pow(2, i) != x) {
        i--;
        } else if (pow(2,i) == x){
            for (int j = 0; j < i + 1; j++){
                binary += '0';
            }
            binary[0] = '1';
            cout << binary << endl;
            return 0;
        }

    for (int j = 0; j < i + 1; j++){
        binary += '0';
    }
    
    binary[i] = '1';
    x = x - pow(2,i);
    
    decimal_to_binary(x, binary);

    reverse(binary.begin(), binary.end());

    cout << binary << endl;
    } else if (user_input == 2){
        string decimal;

        cout << "Okay! Enter the binary number you would like to convert to decimal: " << endl;
        cin >> decimal;
        cout << "Your number in decimal is: " << endl;
        binary_to_decimal(decimal);
    } else {
        cout << "Sorry, please pick option 1 or 2. " << endl;
    }

    return 0;
}
    
    
    void decimal_to_binary(long long int x, string &binary) {
    if (x == 0){
        return;
    }
    unsigned j = 0;
    
    for  (j = 0; pow(2, j) < x; j++) {
    } 
        if (pow(2, j) != x) {
        j--;
        }

        binary[j] = '1';
        
      decimal_to_binary(x - pow(2,j), binary);
     
        }

    void binary_to_decimal(string decimal){
        int binary = 0;

        reverse(decimal.begin(), decimal.end());

        for (int i = 0; i < decimal.size(); i++){
        int x = decimal[i] - '0';
        binary += pow(2,i) * x;
        }
    
        cout << binary << endl;
    }
    
    