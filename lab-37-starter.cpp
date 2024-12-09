// COMSC-210 | Jed Aficial | Lab 38
// github link: https://github.com/jaficial/210-lab-37.git

#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <list>
#include <iomanip>
using namespace std;

int gen_hash_index(string);
void menu_display();
void display_100(map<int, list<string>> &);
void search_key(map<int, list<string>> &);

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

void menu_display(){
    cout << endl << "" << setw(22) << "Menu Options" << endl;
    cout << "-------------------------------" << endl;
    cout << "[1] Print the First 100 Entries" << endl;
    cout << "[2] Search for a Key" << endl;
    cout << "[3] Remove a Key" << endl;
    cout << "[4] Modify a Key" << endl;
    cout << "[5] Exit" << endl;
}

void display_100(map<int, list<string>> &hash_table){
    auto hash_table_iterator = hash_table.begin();
    hash_table_iterator++;
    auto list_iterator = hash_table_iterator->second.begin();
    auto last_list_element = hash_table_iterator->second.end();
    last_list_element--;
  
    for (int i = 1; i < 101; i++){
        if ((hash_table_iterator->second.size() == 1) || (list_iterator == last_list_element)){
            cout << "" << setw(4) << i << ". " << *list_iterator << endl;
            hash_table_iterator++;
            list_iterator = hash_table_iterator->second.begin();
            last_list_element = hash_table_iterator->second.end();
            last_list_element--;
            
        }
        else {
            cout << "" << setw(4) << i << ". " << *list_iterator << endl;
            list_iterator++;
        }
    }
}

void search_key(map<int, list<string>> &){

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

    int interaction = 0;

    while (interaction != 5){
        menu_display();
        cin >> interaction;

        if (interaction == 5){
            cout << "Exiting Program..." << endl;
        }

        else if (interaction == 1){
            display_100(hash_table);
        }
    }

    fin.close();
    return 0;
}
