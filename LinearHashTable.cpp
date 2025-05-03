#include <iostream>
using namespace std;

class student {
public:
    int roll;
    string name;
    int marks;
    int pos; // -1 = Empty, -2 = Deleted, 1 = Occupied

    student() {
        roll = 0;
        name = "";
        marks = 0;
        pos = -1;
    }

    student(int r, string n, int m) {
        roll = r;
        name = n;
        marks = m;
        pos = 1;
    }
};

class Hash {
public:
    student s[10];
    int size = 5;
    int count = 0;

    int hashv(int key) {
        return key % size;
    }

    void accept() {
        int roll, mark;
        string name;
        cout << "\nEnter the name of Student: ";
        cin >> name;
        cout << "Enter roll no of the Student: ";
        cin >> roll;
        cout << "Enter marks of student: ";
        cin >> mark;

        int index = hashv(roll);

        // Linear probing
        int cnt = 0;
        while ((s[index].pos == 1) && cnt < size) {
            cout << "Collision occurred at index " << index << endl;
            index = (index + 1) % size;
            cnt++;
        }

        if (cnt == size) {
            cout << "\nHash table is full.\n";
            return;
        }

        s[index] = student(roll, name, mark); // Constructor sets pos = 1
        count++;
        cout << "Element inserted at index " << index << endl;
    }

    void display() {
        cout << "\nHash Table Records\n";
        bool found = false;
        for (int i = 0; i < size; i++) {
            if (s[i].pos == 1) {
                cout << "Index " << i << " -> Name: " << s[i].name
                     << ", Roll no: " << s[i].roll
                     << ", Marks: " << s[i].marks << endl;
                found = true;
            }
        }
        if (!found) {
            cout << "No records in the hash table (Empty).\n";
        }
        cout << endl;
    }
    

    void remove() {
        int roll;
        cout << "\nEnter Roll no. of student to delete : ";
        cin >> roll;

        int index = hashv(roll);
        int cnt = 0;

        while (cnt < size) {
            if (s[index].pos == 1 && s[index].roll == roll) {
                s[index].pos = -2;
                cout << "Record of Student with roll no " << roll << "is deleted.\n";
                return;
            }
            index = (index + 1) % size;
            cnt++;
        }

        cout << "Record not found to delete.\n";
    }
};

int main() {
    Hash h;
    int choice;

    do {
        cout << "\n1. Insert\n2. Display\n3. Delete\n4. Exit\nEnter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                h.accept();
                break;
            case 2:
                h.display();
                break;
            case 3:
                h.remove();
                break;
            case 4:
                cout << "Exiting the program...\n";
                break;
            default:
                cout << "Invalid choice.\n";
        }
    } while (choice != 4);

    return 0;
}
