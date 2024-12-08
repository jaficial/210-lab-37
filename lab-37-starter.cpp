// COMSC-210 | Jed Aficial | Lab 37
// github link: https://github.com/jaficial/210-lab-37.git

#include <iostream>
#include <string>
#include <map>
using namespace std;

int sum_ascii(string);

int sum_ascii(string string_data){
    int string_length = string_data.length();
    int ascii_total = 0;
    for (int i = 0; i < string_length; i++){
        ascii_total = ascii_total + (int) string_data[i];
    }

    return ascii_total;
}
/*
    THINGS TO DO: 
    DONE PART 1: "sum_ascii" receives a single string and returns the 
             sum of the string's ASCII values
             - do so by type casting a char into an int 
         PART 2: Read the data text file, into main, then find the GRAND TOTAL ascii value
             - should be 69893419
*/
int main() {
    char a = 'A';
    cout << a << endl;
    cout << (int) a << endl;
    int b = 66;
    cout << b << endl;
    cout << (char) b << endl;
    
    string test = "A";
    int total = sum_ascii(test);

    cout << "This is the total of string_data: " << total << endl;

    return 0;
}

/* 
These targets are present in the dataset and can be used for testing:
536B9DFC93AF
1DA9D64D02A0
666D109AA22E
E1D2665B21EA
*/
