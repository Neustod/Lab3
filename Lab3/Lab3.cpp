#include "GlobalLibs.h"
#include "PriorityQueueModule.h"
#include "QueueModule.h"
#include "StackModule.h"

int main(int argc, char* argv[]) {
    PriorityQueueModule pQueue1;
    QueueModule queue1;
    StackModule stack1;

    int n, priority;
    Data d;

    std::cout << "Enter a number of list's elements >> ";
    std::cin >> n;

    std::cout << "\n[Priority Queue]\n";

    for (int i = 0; i < n; i++) {
        std::cout << "Priority = ";
        std::cin >> priority;

        std::cout << "Number = ";
        std::cin >> d.data;

        pQueue1.Push(priority, d);
    }

    for (int i = 0; i < n; i++)
        std::cout << pQueue1.Pop().data << " ";

    std::cout << "\n\n[Queue]\n";

    for (int i = 0; i < n; i++) {
        std::cout << "Number = ";
        std::cin >> d.data;

        queue1.Push(d);
    }

    for (int i = 0; i < n; i++)
        std::cout << queue1.Pop().data << " ";

    std::cout << "\n\n[Stack]\n";

    for (int i = 0; i < n; i++) {
        std::cout << "Number = ";
        std::cin >> d.data;

        stack1.Push(d);
    }

    for (int i = 0; i < n; i++)
        std::cout << stack1.Pop().data << " ";
       
    std::cout << "\n";

    return 0;
}