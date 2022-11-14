#pragma once
#include "GlobalLibs.h"

class StackModule {
private:
    struct Node {
        Data data;
        Node* next;
    };

    Node* head;

public:
    StackModule() {
        head = NULL;
    }

    // Push data at the begining of stack.
    void Push(Data data) {
        Node* Next = new Node();
        Next->data = data;

        if (head == NULL) {
            Next->next = NULL;
        }
        else {
            Next->next = head;
        }
        
        head = Next;
    }

    // Pop data from stack's begining. 
    Data Pop() {
        Data data = { -1 };

        if (head != NULL) {
            Node* temp;
            data = head->data;
                        
            if (head->next == NULL) {
                free(head);
                head = NULL;
            }
            else {
                temp = head->next;
                free(head);
                head = temp;
            }
        }

        return data;
    }

    // Return true if data in stack.
    bool Find(Data data) {
        Node* current = head;

        if (head != NULL) {
            while (current->next != NULL) {
                if (current->data == data) {
                    return true;
                }
                
                current = current->next;
            }
        }
        return false;
    }
        
    // Print entire stack in console.
    void ReadList() {
        if (head != NULL) {
            Node* Current = head;
            while (Current->next != NULL) {
                std::cout << Current->data.data << " ";
                Current = Current->next;
            }
            std::cout << Current->data.data;
        }
        else std::cout << "Elements not found.";
    };

    void DeleteNode(Data data) {
        Node* current, * prev = head;

        if (head == NULL) { return; }
        current = head->next;

        if (head->data == data) {
            head = head->next;
            free(prev);
            return;
        }

        if (current == NULL) { return; }

        while (current->next != NULL) {
            if (current->data == data) {
                prev->next = current->next;
                free(current);
                return;
            }

            prev = current;
            current = current->next;
        }
        if (current->data == data) {
            prev->next = NULL;
            free(current);
            return;
        }
    }

    // Delete entire stack.
    void DeleteStack() {
        if (head != NULL) {
            Node* prev = head, * current = head->next;

            if (current != NULL) {
                while (current->next != NULL) {
                    free(prev);
                    prev = current;
                    current = current->next;
                }
                free(prev);
                free(current);
            }
            else {
                free(head);
                head = NULL;
            }
        }
    }

    ~StackModule() {
        DeleteStack();
    }
};