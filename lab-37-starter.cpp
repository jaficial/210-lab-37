// COMSC-210 | Jed Aficial | Lab 37
// github link: https://github.com/jaficial/210-lab-37.git

#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <list>
#include <iomanip>
using namespace std;

int gen_hash_index(string);

/* gen_hash_index iterates through each char of the string
   and adds the char's ASCII value to a total variable.
*/
int gen_hash_index(string string_data){
    int string_length = string_data.length();
    int ascii_total = 0;
    for (int i = 0; i < string_length; i++){
        ascii_total = ascii_total + (int) string_data[i];
    }

    return ascii_total;
}

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
        if (hash_table.find(temp_hash_index) == hash_table.end()){ // CITED: from geeksforgeeks: https://www.geeksforgeeks.org/map-find-function-in-c-stl/ . Cited website to learn how the .find() method works
            hash_table[temp_hash_index].push_back(temp_data);
        }
        
        // if index exists and it isn't the last index, insert it into the hash_table's key's list
        else if (hash_table.find(temp_hash_index) != hash_table.end()){
            hash_table[temp_hash_index].push_back(temp_data);
        }
        grand_total = grand_total + temp_hash_index;
    }
    
    // NOTE: found out that there is a "0" key and value pair, most likely from the last line of the data.txt file being empty
    auto hash_table_iterator = hash_table.begin();
    hash_table_iterator++;
    
    // BIG NOTE: I'VE BEEN ACCESSING RANDOM MEMORY, THAT'S WHY THE LOOPS / IF/ELSE CONDITIONS AREN'T WORKING

    auto list_iterator = hash_table_iterator->second.begin();
    auto last_list_element = hash_table_iterator->second.end();
    last_list_element--;

    // NOTE: When using the .end() method, it points to one element past the last element of the list
    //       - so be sure to iterate 1 backwards for the last element  
    for (int i = 1; i < 101; i++){
        if ((hash_table_iterator->second.size() == 1) || (list_iterator == last_list_element)){
            cout << "" << setw(4) << i << ". " << *list_iterator << endl;
            hash_table_iterator++;
            list_iterator = hash_table_iterator->second.begin();
            last_list_element = hash_table_iterator->second.end();
            last_list_element--;
            if (i != 100){
                cout << "Key " << hash_table_iterator->first << ":" << endl;
            }
        }
        else {
            cout << "" << setw(4) << i << ". " << *list_iterator << endl;
            list_iterator++;
        }
    }

    fin.close();
    return 0;
}
