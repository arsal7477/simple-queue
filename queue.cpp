#include<iostream>
using namespace std;

class node{
    public:
    int data;
    node* next;

    node(int val){
        data =val;
        next=nullptr;
    }
};
class queue{
    node* front;
    node* rear;
    public:
    queue(){
        front=nullptr;
        rear=nullptr;
    }
    void enqueue(int val){
        node* newnode=new node(val);
        if(front==nullptr){
            front=rear=newnode;
        }
        else{
            rear->next=newnode;
            rear=newnode;

        }
    }
    void dequeue(){
      
        if(front==nullptr){
            rear=nullptr;
        }
        else if(front!=nullptr){
         node* temp=front;
            front=front->next;
            delete temp;
        }
    }
 void display() {
    node* temp = front;
    while (temp != nullptr) {
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << "nullptr";
    cout<<endl;
}
int search(int key){
    node* temp=front;
    while(temp!=nullptr){
        if(temp->data==key){
            return key;
        }
        temp=temp->next;
    }
    return -1;
}
};
int main(){
    queue q;
    q.enqueue(2);
    q.enqueue(4);
    q.enqueue(7);
    q.enqueue(9);

    q.display();

    q.dequeue();

    q.display();
    cout<<q.search(8);
    cout<<endl;
    cout<<q.search(7);
}
