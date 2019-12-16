#include <iostream>
#include "grade.h"
using namespace std;
grade::grade(std::string Lessonname)
    : lesson(Lessonname) {}
void grade::setLessonName(std::string name) {
    lesson = name;
}
string grade::getLessonName() {
    return lesson;
}
int biggest=0;
void grade::addNode(int * data) {
    node *add = (node*) malloc(sizeof(node));
    add->data = *data;
    add->next = NULL;
    if (grade::start == NULL){
        start = add;
    }
    else{
        node * q = start;
        while (q->next != NULL){
            q= q->next;
        }
        q->next = add;
    }
}
void grade::giveMarks() {
    int num=-1;
    cout << "For exit enter 0" << endl;
    while (num != 0){
        cout << "Mark ? ";
        cin >> num;
        if (num == 0) break;
        addNode(&num);
        if (num > biggest) biggest = num;
    }
}
void grade::displayMarks() {
    cout << "Biggest grade: " << biggest << endl;
    node * q = start;
    while (q != NULL){
        cout << q->data << " " ;
        q = q->next;
    }
    cout << endl;
}