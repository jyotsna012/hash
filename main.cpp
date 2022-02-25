#include <cstdlib>
#include <iostream>
#include <cstring>

using namespace std;

void hashmap(int ntableSize);
int Hash(char* key);
void addStudent(char* firstName, char* lastName, int studentId, float GPA);
int numItemsIndex(int index);
void print();

int main(){

    struct Student {
      char firstName[20];
      char lastName[20];
      int studentId;
      float GPA;
      Student* next;
    };
    
    int tableSize;
    Student* HashTable[tableSize];

}
