#include <cstdlib>
#include <iostream>
#include <cstring>

using namespace std;

struct Student {
    char firstName[20];
    char lastName[20];
    int studentId;
    float GPA;
    Student* next;
  };

void hashtable(int ntableSize);
int Hash(char* key);
void addStudent(char* firstName, char* lastName, int studentId, float GPA);
int numItemsIndex(int index);
void print();
    
int main(){

    int tableSize=100;
    hashtable(100);
    
}

void hashtable(int ntableSize){
  int tableSize = ntableSize;
  Student* HashTable[tableSize];
  char emptys[] = "empty";
  for(int i = 0; i < tableSize; i++){
    HashTable[i] = new Student;
    strcpy(HashTable[i]->firstName, emptys);  
    strcpy(HashTable[i]->lastName, emptys);  
    HashTable[i] -> studentId = 0;
    HashTable[i] -> GPA = 0.00;
    HashTable[i] -> next = NULL;
  }
}


