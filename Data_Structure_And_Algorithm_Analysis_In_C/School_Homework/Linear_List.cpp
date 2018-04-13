#include <cstring>
#include <fstream>
#include <iostream>
#include <utility>
using std::cout;
using std::endl;
using std::ifstream;

class StudentList
{
    friend void List_Merge(StudentList &A, StudentList &B,StudentList &MergedList);

  public:
    struct Stuinfo
    {
        int stuID;
        char stuName[20];
        int Age;
    };

  private:
    struct Node
    {
        Stuinfo data;
        Node *next = nullptr;
    };

    Node *head;

  public:
    StudentList()
    {
        head = new Node;
    }
    explicit StudentList(const char *Path)
    {
        head = new Node;
        ifstream fin(Path);
        Stuinfo tmp;
        while (fin >> tmp.stuID >> tmp.stuName >> tmp.Age)
            insert(tmp);
        fin.close();
    };

    ~StudentList()
    {
        Node *cur = head, *tmp;
        do
        {
            tmp = cur;
            cur = cur->next;
            delete tmp;
        } while (cur);
    }

    void insert(Stuinfo Info)
    {
        Node *cur = head, *tmp;
        while (cur->next && Info.stuID > cur->next->data.stuID)
            cur = cur->next;
        if (!(cur->next) || Info.stuID < cur->next->data.stuID)
        {
            tmp = cur->next;
            cur->next = new Node;
            cur->next->data = Info;
            cur->next->next = tmp;
        }
        else if (Info.Age > cur->next->data.Age)
            cur->next->data = Info;
    }

    void reverse()
    {
        Node *cur = head->next, *cur_prev, *cur_next;
        cur_next = cur->next;
        cur->next = nullptr;
        cur_prev = cur;
        cur = cur_next;
        while (cur)
        {
            cur_next = cur->next;
            cur->next = cur_prev;
            cur_prev = cur;
            cur = cur_next;
        }
        head->next = cur_prev;
    }

    void Output()
    {
        Node *cur = head;
        while (cur = cur->next)
        {
            cout << "StuId: " << cur->data.stuID
                 << "\nstdName: " << cur->data.stuName
                 << "\nAge: " << cur->data.Age;
            cout << endl
                 << endl;
        }
    }
};

void List_Merge(StudentList &A, StudentList &B, StudentList &MergedList)
{
    StudentList::Node *cur;
    cur = A.head;
    while (cur = cur->next)
        MergedList.insert(cur->data);
    cur = B.head;
    while (cur = cur->next)
        MergedList.insert(cur->data);
}

int main()
{
    StudentList C;
    StudentList A("./ListA.txt");
    StudentList B("./ListB.txt");
    List_Merge(A, B, C);
    // A.Output();
    C.reverse();
    C.Output();
    return 0;
}