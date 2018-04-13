#include <cstring>
#include <fstream>
#include <iostream>
using std::cout;
using std::ifstream;

template <typename T>
class StudentList
{

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
    Node *head, *tail;

  public:
    StudentList() = delete;
    explicit StudentList(const char *Path)
    {
        head = new Node;
        ifstream fin(Path);
        Stuinfo tmp;
        fin >> tmp.stuID >> tmp.stuName >> tmp.Age;
        insert(tmp);
        fin.close();
    };

    void insert(Stuinfo Info)
    {
        Node *cur = head,tmp;
        while (cur = cur->next, !cur->next && Info.stuID < cur->data.stuID)
        {
            tmp = cur->next;
            cur->next =
        }
    }
};

int main()
{
}