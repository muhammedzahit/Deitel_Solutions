#include <iostream>
#include "grade.h"
using namespace std;
int main(){
    grade grade("Matematik");
    grade.giveMarks();
    grade.displayMarks();
    grade.setLessonName("Fizik");
    cout << grade.getLessonName() << endl;
    return 0;
}