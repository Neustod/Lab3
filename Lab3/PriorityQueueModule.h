#pragma once
#include "GlobalLibs.h"
#include <map>

class PriorityQueueModule {
private:
    struct Node {
        Data data;
        Node* next;
    };

    Node* head, * tail;
    std::map<int, std::pair<Node*, Node*>> pQueue;
    std::map<int, std::pair<Node*, Node*>> ::iterator it;

public:
    PriorityQueueModule() {
        head = NULL;
        tail = NULL;
    }

    // Push data at the end of priority list.
    void Push(int priority, Data data) {
        SetPriorHead(priority);

        if (it == pQueue.end()) {
            head = new Node();
            head->data = data;
            head->next = NULL;

            tail = head;

            pQueue.insert(std::make_pair(priority, std::make_pair(head, tail)));
        }
        else {
            Node* Next = new Node();

            Next->data = data;
            Next->next = NULL;

            tail->next = Next;
            tail = Next;
        }
    }

    // Pop data from priority list's begining. 
    Data Pop() {
        it = pQueue.begin();
        head = it->second.first;
        tail = it->second.second;

        Node* temp;
        Data data;

        if (head->next == NULL) {
            data = { head->data };

            free(head);
            head = NULL;
            tail = NULL;
            pQueue.erase(it);
        }
        else {
            data = { head->data };

            temp = head->next;
            free(head);
            head = temp;
            pQueue[it->first] = std::make_pair(head, tail);
        }
        return data;
    }

    // Find list's adress by priority and set into this.head and this.tail.
    void SetPriorHead(int priority) {
        it = pQueue.find(priority);

        if (it != pQueue.end()) {
            head = it->second.first;
            tail = it->second.second;
        }
    }

    // Delete entire queue.
    void DeleteQueue(){
        while(pQueue.size() != 0) {
            it = pQueue.begin();
            head = it->second.first;
            tail = it->second.second;

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
                tail = NULL;
                pQueue.erase(it);
            };
        }
    }

    ~PriorityQueueModule() {
        DeleteQueue();
    }
};