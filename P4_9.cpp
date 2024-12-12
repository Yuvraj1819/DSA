#include <iostream>
using namespace std;
class Queue{
	int queue[4];
	int n=4;
	int rear=-1;
	int front=-1;
	public: void enqueue(){
			int data;
			if((rear+1)%n==front){
				cout<<"Overflow";
			}
			else if (front ==-1 && rear==-1){
				cout<<"Enter the data: ";
				cin>>data;
				front=0;
				rear=0;
				queue[rear]=data;
			}
			else{
				cout<<"Enter the data: ";
				cin>>data;
				rear=(rear+1)%n;
				queue[rear]=data;
			}
		}
		void dequeue(){
			if (front==-1){
				cout<<"Under flow";
			}
			else if(front==rear){
				cout<<"Deleted element is "<<queue[front];
				front=rear=-1;
			}
			else {
				cout<<"Deleted element is "<<queue[front];
				front=(front+1)%n;
			}
		}
		void display(){
			if(front==-1){
				cout<<"Queue is empty";
			}
			else{
				int i=front;
				while(true){
					cout<<" "<<queue[i]<<" ";
					if(i==rear){break;}
					i=(i+1)%n;	
				}
			}
		}
};
int main(){
	Queue queue;
	int ch;
	do{
		cout<<"\n1. Enqueue"<<endl;
		cout<<"2. Dequeue"<<endl;
		cout<<"3. Display"<<endl;
		cout<<"4. Exit"<<endl;
		cin>>ch;
		switch(ch){
		case 1: queue.enqueue();
			break;
		case 2: queue.dequeue();
			break;
		case 3: queue.display();
			break;
		case 4: cout<<"Exiting...";
			break;
		default: cout<<"Invalid";
		}
	}while(ch!=4);
	return 0;
}