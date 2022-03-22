#include <iostream>
#include <stdio.h>
#include <stdlib.h>

#include "multiverse.h"

using namespace std;

typedef struct node{
  int key; //bisa diganti infotype
  struct node* prev;
  struct node* next;
} node;

int i = 1;

node* head = NULL;
node* first = NULL;
node* temp = NULL;
node* tail = NULL;

void addnode(int k){
  node* ptr = (node*)malloc(sizeof(node));

  ptr->key = k;
  ptr->next = NULL;
  ptr->prev = NULL;

  if(head == NULL){
    head = ptr;
    first = head;
    tail = head;
  }else{
    temp = ptr;
    first->next = temp;
    temp->prev = first;
    first = temp;
    tail = temp;
  }

  i++;
}

void traverse(){
  node* ptr = head;

  while(ptr != NULL){
    cout << ptr->key;
    ptr = ptr->next;
  }

  cout << endl;
}

void insertAtBegin(int k){
  node *ptr = (node*)malloc(sizeof(node));

  ptr->key = k;
  ptr->next = NULL;
  ptr->prev = NULL;

  if(head == NULL){
    first = ptr;
    first = head;
    tail = head;
  }else{
    temp = ptr;
    temp->next = head;
    head->prev = temp;
    head = temp;
  }
  i++;
}

void insertAtEnd(int k){
  node* ptr = (node*)malloc(sizeof(node));

  ptr->key = k;
  ptr->next = NULL;
  ptr->prev = NULL;

  if(head == NULL){
    first = ptr;
    first = head;
    tail = head;
  }else{
    temp = ptr;
    temp->prev = tail;
    tail->next = temp;
    tail = temp;
  }
  i++;
}

void insertAtPost(int k, int pos){
  if(pos < 1 || pos > i + 1){
    cout << "Please enter a valid position" << endl;
  }else if(pos == 1){
    insertAtBegin(k);
  }else if(pos == i + 1){
    insertAtEnd(k);
  }else{
    node* src = head;

    while(pos--){
      src = src->next;
    }

    node **da, **ba;
    node* ptr = (node*)malloc(sizeof(node));

    ptr->next = NULL;
    ptr->prev = NULL;
    ptr->key = k;

    ba = &src;
    da = &(src->prev);
    ptr->next = (*ba);
    ptr->prev = (*da);
    (*da)->next = ptr;
    (*ba)->prev = ptr;
    i++;
  }
}

void deleteAtBegin(){
  head = head->next;
  i--;
}

void deleteAtEnd(){
  tail = tail->prev;
  tail->next = NULL;
  i--;
}

void deleteAtPost(int pos){
  if(pos < 1 || pos > i + 1){
    cout << "Please enter a valid position" << endl;
  }else if(pos == 1){
    deleteAtBegin();
  }else if(pos == i){
    deleteAtEnd();
  }else{
    node* src = head;
    pos--;

    while(pos--){
      src = src->next;
    }

    node **pre, **aft;
    pre = &(src->prev);
    aft = &(src->next);

    (*pre)->next = (*aft);
    (*aft)->prev = (*pre);

    i--;
  }
}
