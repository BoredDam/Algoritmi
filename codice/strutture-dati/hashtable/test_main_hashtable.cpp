#include <iostream>
#include "hashtable.hpp"

int main(){
    hashTable<char> tab(3);
    tab.insert('b');
    tab.print();
    tab.del('b');
    tab.print();
    tab.insert('a');
    tab.print();

    std::cout<<"\n ---------------------------- \n\n";

    hashTable<int> tab2(10);
    int numb = 0;
    while(!tab2.isFull()){
        tab2.insert(numb);
        numb++;
    }
    tab2.print();
}