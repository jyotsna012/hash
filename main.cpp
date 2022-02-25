#include <cstdlib>
#include <iostream>
#include <cstring>

using namespace std;

void hashmap(int ntableSize);
int Hash(char* key);
void addStudent(char* firstName, char* lastName, int studentId, float GPA);
int numItemsIndex(int index);
void print();
void rehash(int tablesize, hashmap Hashy);

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
    
    cout << "--------------------HASHY 1----------------------------" << endl;
  int tablesize;
  tablesize = 100;
  hashmap Hashy(tablesize);
  Hashy.addStudent("Paul", "Locha", 1, 1.11);
  Hashy.addStudent("Kim", "Iced Mocha", 2, 2.22);
  Hashy.addStudent("Emma", "Strawberry Smoothie", 3, 3.33);
  Hashy.addStudent("Annie", "Hot Chocolate", 4, 4.44);
  Hashy.addStudent("Sarah", "Passion Tea", 5, 5.55);
  Hashy.addStudent("Pepper", "Caramel Mocha", 6, 6.66);
  Hashy.addStudent("Mike", "Chai Tea", 7, 7.77);
  Hashy.addStudent("Steve", "Apple Cider", 8, 8.88);
  Hashy.addStudent("Bill", "Root Beer", 9, 9.99);
  Hashy.addStudent("Marie", "Skinny Latte", 11, 1.123);
  Hashy.addStudent("Susan", "Water", 12, 2.123);
  Hashy.addStudent("Joe", "Green Tea", 13, 3.123); 
  Hashy.print();
  cout << "--------------------HASHY 2----------------------------" << endl;
  rehash(tablesize, Hashy);
}

void hashmap(int ntableSize){
  tableSize = ntableSize;
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

void addStudent(char* firstName, char* lastName, int studentId, float GPA){
  
  int index = Hash(firstName);
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

int numItemsIndex(int index){
  int count = 0;
  if(HashTable[index] -> studentId == 0){
    return 0;
  }
  
  else{
  
    count ++;
    Student* ptr = HashTable[index];
    while(ptr -> next != NULL){
        count ++;
        ptr = ptr -> next;
    }
    return count;
  }
}

print(){

void int number;
  for(int i = 0; i < tableSize; i++){
    number = numItemsIndex(i);
    cout << "-----------------" << endl;
    cout << "index = " << i << endl;
    cout << HashTable[i]->firstName<< endl;  
    cout << HashTable[i]->lastName<< endl;  
    cout << HashTable[i]->studentId<< endl;
    cout << HashTable[i]->GPA<< endl;
    cout << "number of items = " << number << endl;
    cout << "-----------------" << endl;  
  }

}

int Hash(char* key){
  int hash = 0;
  int index;
  
  index = strlen(key);
  
  for(int i =0; i < strlen(key); i++){
    hash = hash + (int)key[i];
  }
  
  index = hash % tableSize;
  return index;
  
}

void rehash(int tablesize, hashmap Hashy){
int oldtablesize = tablesize;
tablesize = tablesize+tablesize;
hashmap HashyTwo(tablesize);
for(int i =0; i < oldtablesize; i++){
  char newfirstName[80];
  char newlastName[80];
  int newid;
  float newgpa;
  if(Hashy.HashTable[i]->studentId != 0){
    strcpy(newfirstName, Hashy.HashTable[i]-> firstName);  
    strcpy(newlastName, Hashy.HashTable[i]->lastName);  
    newid = Hashy.HashTable[i]->studentId;
    newgpa = Hashy.HashTable[i]->GPA;
    HashyTwo.addStudent(newfirstName, newlastName, newid, newgpa); 
  }
}
   HashyTwo.print();
}
