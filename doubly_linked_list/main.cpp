//Refrensi : GeeksforGeeks
//Tanggal : 17/03/2022

#include <iostream>
#include <stdio.h>
#include <stdlib.h>

#include "multiverse.cpp"

using namespace std;

int main(){
  addnode(1);
  addnode(2);
  addnode(3);
  addnode(4);
  addnode(5);
  addnode(6);

  cout << "Linked List : ";
  traverse();

  cout << endl;

  insertAtBegin(0);
  cout << "Linked list after, inserting 0 at beginning : ";
  traverse();

  insertAtEnd(7);
  cout << "Linked list after, inserting 7 at end : ";
  traverse();

  insertAtPost(55, 3);
  cout << "Linked list after inserting 55 after 3rd Node : ";
  traverse();

  cout << endl;

  deleteAtBegin();
  cout << "Linked list after deleteting first node : ";
  traverse();

  deleteAtEnd();
  cout << "Linked list after deleteting first last : ";
  traverse();

  cout << "Linked list after deleteting node at position 6 : ";
  deleteAtPost(6);
  traverse();

  return 0;
}
