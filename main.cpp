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

Student hashtable(int ntableSize);
int Hash(char* key,  int tableSize);
void addStudent(char* firstName, char* lastName, int studentId, float GPA);
int numItemsIndex(int index);
void print();

int tableSize=100;
Student* HashTable[tableSize];

    
int main(){

    hashtable(tableSize);
    
}

Student hashtable(int ntableSize){
  int tableSize = ntableSize;
  char emptys[] = "empty";
  for(int i = 0; i < tableSize; i++){
    HashTable[i] = new Student;
    strcpy(HashTable[i]->firstName, emptys);  
    strcpy(HashTable[i]->lastName, emptys);  
    HashTable[i] -> studentId = 0;
    HashTable[i] -> GPA = 0.00;
    HashTable[i] -> next = NULL;
  }
    return HashTable;
}

int Hash(char* key, int tableSize){
  int hash = 0;
  int index;
  
  index = strlen(key);
  
  for(int i =0; i < strlen(key); i++){
    hash = hash + (int)key[i];
  }
  
  index = hash % tableSize;
  return index;
  
}

void addStudent(char* firstName, char* lastName, int studentId, float GPA, int tableSize){
  
  int index = Hash(firstName, tableSize);
  if(HashTable[index] -> studentId == 0){
    strcpy(HashTable[index]->firstName, firstName);  
    strcpy(HashTable[index]->lastName, lastName);  
    HashTable[index] -> studentId = studentId;
    HashTable[index] -> GPA = GPA;
    HashTable[index] -> next = NULL;

  }
  else{
  
    Student* ptr = HashTable[index];
    Student* n = new Student;
    strcpy(n->firstName, firstName);  
    strcpy(n->lastName, lastName);  
    n -> studentId = studentId;
    n -> GPA = GPA;
    n->next = NULL;
    while(ptr -> next != NULL){
      ptr = ptr -> next;
    }
    
    ptr -> next = n;
  
  }
  
  if(numItemsIndex(index) >= 4){

    cout << "needs to be rehased" << endl;
  }
}
