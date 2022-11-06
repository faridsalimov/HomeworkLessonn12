#include <iostream>
#include <vector>
#include <Windows.h>

using namespace std;

// ===========================================
// Priority Queue template
// class Student olmalidir.
// Ortalamasi en yuxari olan telebe novbeden chixir.

// Likendlist arashdirin.
// ===========================================

class Student {
    string name;
    string surname;
    int average;

public:
    Student(const string& namee, const string& surnamee, int averagee) : name(namee), surname(surnamee), average(averagee) {}

    string GetName() {
        return name;
    }

    string GetSurname() {
        return surname;
    }

    int GetAverage() {
        return average;
    }

    void Show() {
        cout << "====================" << endl;
        cout << "Name: " << name << "\nSurname: " << surname << "\nAverage: " << average << endl;
        cout << "====================" << endl;
    }
};

class StudentQueue {
public:
    vector<Student> students;

    bool IsEmpty() const { return students.empty(); }

    void Enqueue(const Student& student) {
        students.push_back(student);
    }

    void Dequeue() {
        if (!students.empty()) {
            students.erase(students.begin());
        }
    }

    Student& Front() { return students.front(); }
};

class Students {
public:
    StudentQueue queue;

    void AddStudent(const Student& student) {
        queue.Enqueue(student);
    }

    void TopAverage() {
        while (!queue.IsEmpty()) {
            Student student = queue.Front();
            
            system("cls");
            student.Show();
            Sleep(1000);
            queue.Dequeue();
        }
    }
};

void main() {
    Students st;
    st.AddStudent(Student("Ferid", "Selimov", 12));
    st.AddStudent(Student("Kamil", "Babayev", 9));
    st.AddStudent(Student("Anar", "Atakisiyev", 11));
    st.AddStudent(Student("Aysel", "Qarayeva", 7));

    st.TopAverage();
}