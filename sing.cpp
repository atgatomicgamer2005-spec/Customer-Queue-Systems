#include <iostream>
#include <queue>
#include <string>
using namespace std;

struct Customer {
    int id;
    string name;
};

int main() {
    queue<Customer> q;
    int choice, idCounter = 1;
    string name;

    cout << "=== CUSTOMER QUEUE SYSTEM ===" << endl;
    cout << "Real-world application of Queue (FIFO)" << endl;

    do {
        cout << "\n1. Enqueue Customer\n2. Dequeue Customer\n3. Front Customer\n4. Display Queue\n5. Queue Size\n0. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch(choice) {
            case 1:
                cout << "Enter customer name: ";
                cin >> name;
                q.push({idCounter++, name});
                cout << name << " enqueued. Queue size: " << q.size() << endl;
                break;
            case 2:
                if(!q.empty()){
                    cout << "Dequeued: " << q.front().name << endl;
                    q.pop();
                } else {
                    cout << "Queue Underflow! No customers." << endl;
                }
                break;
            case 3:
                if(!q.empty())
                    cout << "Front: " << q.front().name << " (ID: " << q.front().id << ")" << endl;
                else
                    cout << "Queue empty" << endl;
                break;
            case 4:
                if(q.empty()){
                    cout << "Queue empty" << endl;
                } else {
                    queue<Customer> temp = q;
                    cout << "Queue: FRONT -> ";
                    while(!temp.empty()){
                        cout << temp.front().name << " -> ";
                        temp.pop();
                    }
                    cout << "REAR" << endl;
                }
                break;
            case 5:
                cout << "Size: " << q.size() << endl;
                break;
        }
    } while(choice != 0);

    return 0;
}
