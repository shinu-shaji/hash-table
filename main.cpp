//============================================================================
// Name        : hashtablecpp.cpp
// Author      : shinu
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string>
using namespace std;
struct node{
	string name;
	node *next;
};

class linkedlist{
	private:

	public:
		node *head,*tail;
		linkedlist(){
			head=NULL;
			tail=NULL;
		}
		node *return_head(){
			return head;
		}

		void createlink(string data){
			node *temp = new node;
			temp->name = data;
			temp->next = NULL;
			if (head==NULL){
				head=temp;
				tail=temp;
				//printf("%p",temp);
		//		printf("\n%p",head);
			//	printf("\n%p",tail);
			}
			else{
				tail->next = temp;
				tail = temp;
			}

		}

		void display_link(){
			node *temp = head;
			while(temp!=NULL){
				cout<<"--"<<temp->name;
				temp = temp->next;
			}

		}
		void deletelink(){

		}
};

class hash_table{
private:
	static const int size = 30;
	//node *table[size] = {NULL};

	linkedlist a[size];
public:
	int hash_fun(string data){
		int hash=0;
		for(int i=0;i<data.length();i++){
			hash = hash+(int)data[i];
		}
		hash = (hash*data[0])%size;
		return hash;
	}
	void make_table(string data){
		int index = hash_fun(data);
		a[index].createlink(data);
	}
	void display(){
		for(int i = 0;i<size;i++){
			cout<<i<<" ";
			a[i].display_link();
			cout<<endl;
		}

	}

};
int main(void) {
	hash_table table1;
	table1.make_table("shinu");
	table1.make_table("shinudg");
	table1.make_table("shinuat");
	table1.make_table("shinurt");
	table1.make_table("shinufk");
	table1.make_table("shinueu");
	table1.make_table("shinu");
	table1.make_table("shinudg");
	table1.make_table("shieuat");
	table1.make_table("shiturt");
	table1.make_table("shiyufk");
	table1.make_table("shiiueu");
	table1.make_table("bh");
	table1.make_table("dh");
	table1.make_table("gh");
	table1.make_table("yh");
	table1.make_table("t");
	table1.make_table("h");
	table1.make_table("io");
	table1.display();
}
