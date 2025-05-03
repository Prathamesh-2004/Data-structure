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
        int i = 0;

        while ((s[(index + i * i) % size].pos == 1) && i < size) {
            cout << "Collision occurred at index " << (index + i * i) % size << endl;
            i++;
        }

        if (i == size) {
            cout << "\nHash table is full.\n";
            return;
        }

        int newIndex = (index + i * i) % size;
        s[newIndex] = student(roll, name, mark); // Constructor sets pos = 1
        count++;
        cout << "Element inserted at index " << newIndex << endl;
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
        int i = 0;

        while (i < size) {
            int newIndex = (index + i * i) % size;
            if (s[newIndex].pos == 1 && s[newIndex].roll == roll) {
                s[newIndex].pos = -2;
                cout << "Record of Student with roll no " << roll << " is deleted.\n";
                return;
            }
            i++;
        }

        cout << "Record not found to delete.\n";
    }

    void search() {
        int roll;
        cout << "\nEnter Roll no. of student to search: ";
        cin >> roll;

        int index = hashv(roll);
        int i = 0;

        while (i < size) {
            int newIndex = (index + i * i) % size;
            if (s[newIndex].pos == 1 && s[newIndex].roll == roll) {
                cout << "Record Found at index " << newIndex << ": "
                     << "Name: " << s[newIndex].name
                     << ", Roll no: " << s[newIndex].roll
                     << ", Marks: " << s[newIndex].marks << endl;
                return;
            }
            i++;
        }

        cout << "Record not found.\n";
    }
};

int main() {
    Hash h;
    int choice;

    do {
        cout << "\n1. Insert\n2. Display\n3. Delete\n4. Search\n5. Exit\nEnter choice: ";
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
                h.search();
                break;
            case 5:
                cout << "Exiting the program...\n";
                break;
            default:
                cout << "Invalid choice.\n";
        }
    } while (choice != 5);

    return 0;
}
