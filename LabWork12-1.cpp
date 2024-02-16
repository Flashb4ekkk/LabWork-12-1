#include <iostream>

struct Elem {
    Elem* link1,
        * link2;
    int info;
};

int main() {
    Elem* p;

    //1
    p = new Elem; // 1
    p->info = 1; // 2

    //2
    p->link1 = new Elem; // 3
    p->link1->info = 2; // 4

    //3
    p->link2 = new Elem; // 5
    p->link2->info = 3; // 6
    p->link2->link1 = p->link1; // 7

    //2
    p->link1->link2 = p->link2; // 8

    //4
    p->link1->link1 = new Elem; // 9
    p->link1->link1->info = 4; //10
    p->link1->link1->link1 = p; //11

    //3
    p->link2->link2 = p->link1->link1->link2; //12

    //4
    p->link1->link1->link2 = p->link1; // 13

    delete p->link1->link1; // 14
    delete p->link1; // 15
    delete p->link2; // 16
    delete p; // 17
}
