#include <iostream>

class Node{
    int info;
    Node *next, *prim, *ultim;
    public:
        Node(){
            Node::prim = nullptr;
            Node::ultim = nullptr;
        }
    void addAtEnd();
    void displayList();
    void insertElementAfterValue(int);
    void insertElementBeforeValue(int);
    void arangeList();
};

void Node::addAtEnd(){
    Node* c;
    if(prim == nullptr){
        prim = new Node();
        std::cout << "Insert the value : " ;
        std::cin >> prim -> info;
        ultim = prim;
    } else {
        c = new Node();
        std::cout << "Insert the value : " ;

        std::cin >> c -> info;
        ultim -> next = c;
        ultim = c;
    }
    ultim -> next = nullptr;
}

void Node::displayList(){
    Node* nod;
    nod = prim;

    while(nod != nullptr){
        std::cout << nod -> info << " ";
        nod = nod -> next;
    }
    std::cout << std::endl;
}

int main(){

    return 0;
}