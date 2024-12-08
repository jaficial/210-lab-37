// COMSC-210 | Jed Aficial | Lab 37
// github link: https://github.com/jaficial/210-lab-37.git

#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <list>
using namespace std;

int gen_hash_index(string);

int gen_hash_index(string string_data){
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
    DONE PART 2: Read the data text file, into main, then find the GRAND TOTAL ascii value
             - should be 69893419
         PART 3: Change "sum_ascii" to "gen_hash_index()" 
             - Next create the hash table data structure:
                - Use a std::map named hash_table
                - Key should be an int (hash index)
                - value should be a std::list
                    - the list will contain the strings from the data.txt file
            - Display the first 100 map entries to the console 
                - access map elements with ".first" and ".second"
            - REMEMBER: the value of the map will be a linked list
            - NOTE: some strings in the data.txt file will be equal to each other, 
                    put the strings with the same hash index in the same value list 
                    corresponding to its respective hash index
                - push string to the front for each string to be appended to a list
*/


int main() {
    ifstream fin("lab-37-data.txt");
    string temp_data;
    int temp_hash_index = 0;
    int grand_total = 0;
    
    map <int, list<string>> hash_table;
    
    // NOTE: need to have test if the hash index is already in the map
    while (!fin.eof()){
        getline(fin, temp_data);
        temp_hash_index = gen_hash_index(temp_data);
        
        if (hash_table.find(temp_hash_index) != hash_table.end()){
            hash_table.insert(pair<int, list<string>> (temp_hash_index, temp_data));
        }
        
        

    }
    
    cout << "Reached the end of the file" << endl;
    cout << "This is the size of the hash table: " << hash_table.size() << endl;

    fin.close();
    return 0;
}

/* 
These targets are present in the dataset and can be used for testing:
536B9DFC93AF
1DA9D64D02A0
666D109AA22E
E1D2665B21EA
*/
