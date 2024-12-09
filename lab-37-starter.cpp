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
    
    while (!fin.eof()){
        getline(fin, temp_data);
        temp_hash_index = gen_hash_index(temp_data);
        
        // NOTE: checks if the key already exists in the hash_table
        // if index doesnt exist or the index is the same as the last pair, create new pair and insert to hash_table
        if (hash_table.find(temp_hash_index) == hash_table.end()){ // CITED: from geeksforgeeks: https://www.geeksforgeeks.org/map-find-function-in-c-stl/
            hash_table[temp_hash_index].push_back(temp_data);
        }
        
        // if index exists and it isn't the last index, insert it into the hash_table's key's list
        else if (hash_table.find(temp_hash_index) != hash_table.end()){
            hash_table[temp_hash_index].push_back(temp_data);
        }
        grand_total = grand_total + temp_hash_index;

    }

    auto hash_table_iterator = hash_table.begin();
    // NOTE: try using static to hold the iterator position of the value's list
    for (int i = 1; i < 101; i++){
        cout << i << ". ";
        auto list_value = hash_table_iterator.second.
    }
    
    cout << "Reached the end of the file" << endl;
    cout << "This is the size of the hash table: " << hash_table.size() << endl;
    cout << "This is the expected grand total: 69893419" << endl;
    cout << "This is the actual grand total: " << grand_total << endl; 
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
