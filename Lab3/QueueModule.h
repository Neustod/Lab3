#pragma once
#include "GlobalLibs.h"

class QueueModule {
private:
    struct Node {
        Data data;
        Node* next;
    };

    Node* head, * tail;

public:
    QueueModule() {
        head = NULL;
        tail = NULL;
    }

    // Push data at the end of queue.
    void Push(Data data) {
        Node* Next = new Node();
        Next->next = NULL;
        Next->data = data;

        if (head == NULL) {
            head = Next;
        }
        else {
            tail->next = Next;
        }

        tail = Next;
    }

    // Pop data from queue's begining. 
    Data Pop() {
        Data data = { -1 };

        if (head != NULL) {
            Node* temp;
            data = { head->data };

            if (head->next != NULL) {
                temp = head->next;
                free(head);
                head = temp;
            }
            else {
                free(head);
                head = NULL;
            }
        }

        return data;
    }

    // Return true if data in queue.
    bool Find(Data data) {
        Node* Current = head;

        if (head != NULL) {
            while (Current->next != NULL) {
                if (Current->data == data) {
                    return true;
                }

                Current = Current->next;
            }
        }
        return false;
    }
        
    // Print entire queue in console.
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

    // Delete entire queue.
    void DeleteQueue() {
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

    ~QueueModule() {
        DeleteQueue();
    }
};