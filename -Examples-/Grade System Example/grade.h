#include <iostream>
class grade{
private:
    std::string lesson;
    struct node{
        int data;
        struct node * next;
    };
    void addNode(int *data);
    typedef struct node node;
    node * start = NULL;
public:
    explicit grade(std::string name);
    void setLessonName(std::string name);
    std::string getLessonName();
    void giveMarks();
    void displayMarks();
};