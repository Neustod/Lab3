#include "GlobalLibs.h"
#include "PriorityQueueModule.h"
#include "QueueModule.h"
#include "StackModule.h"

int main(int argc, char* argv[]) {
    PriorityQueueModule pQueue1;
    QueueModule queue1;
    StackModule stack1;

    Data d;

    pQueue1.Push(4, { 13 });
    pQueue1.Push(0, { 20 });
    pQueue1.Push(4, { 12 });

    for (int i = 0; i < 3; i++)
        d = pQueue1.Pop();

    queue1.Push({ 74 });
    queue1.Push({ -99 });
    queue1.Push({ 2 });

    queue1.ReadList();

    for (int i = 0; i < 3; i++)
        d = queue1.Pop();

    stack1.Push({ 73 });
    stack1.Push({ 21 });
    stack1.Push({ 0 });

    for (int i = 0; i < 3; i++) 
        d = stack1.Pop();
       
    return 0;
}