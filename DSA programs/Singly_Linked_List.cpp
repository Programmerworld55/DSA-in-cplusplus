#include<iostream>
#include<conio.h>
#include<stdlib.h>

using namespace std;

void insertAtBeginning(int);
void insertAtEnd(int);
void insertBetween(int,int,int);
void display();
void removeBeginning();
void removeEnd();
void removeSpecific(int);
void reverseLinkedList();
void copy_linkedlist(struct Node* source, struct Node** dest);
struct Node* copiedList = NULL;

struct Node
{
	int data;
 	struct Node *next;
}*head = NULL;

int main()
{
 	int choice,value,choice1,loc1,loc2;
 	system("cls");
 	while(1){
 		mainMenu:
 		cout<<"\n\n****** MENU ******\n1. Insert\n2. Display\n3. Delete\n4. Exit\n5. Reverselinkedlist\n6.Copy Linked list\n\nEnter your  choice:";
 		cin>>choice;
	 	switch(choice)
	 	{
		 	case 1: cout<<"Enter the value to be insert: ";
					cin>>value;
				while(1)
			 	{
					cout<<"Where you want to insert: \n1. At Beginning\n2. At End\n3. Between\nEnter your choice: ";
					cin>>choice1;
					switch(choice1)
					{
						case 1: insertAtBeginning(value);
						break;
						case 2: insertAtEnd(value);
						break;
						case 3: cout<<"Enter the two values where you wanto insert: ";
								cin>>loc1>>loc2;
								insertBetween(value,loc1,loc2);
						break;
						default: cout<<"\nWrong Input!! Try again!!!\n\n";
						goto mainMenu;
					}
					goto subMenuEnd;
				}
				subMenuEnd:
			break;
 			case 2: display();
			break;
 			case 3: cout<<"Ho do you want to Delete: \n1. From Beginning\n2. From End\n3. Spesific\nEnter your choice: ";
					cin>>choice1;
					switch(choice1)
					{
			 			case 1: removeBeginning();
						break;
						case 2: removeEnd();
			 			break;
			 			case 3: cout<<"Enter the value which you wanto delete: ";
								cin>>loc2;
								removeSpecific(loc2);
						break;
			 			default: cout<<"\nWrong Input!! Try again!!!\n\n";
						goto mainMenu;
					}
			break;
			case 4: exit(0);
			case 5: reverseLinkedList();
            break;
            cout << "New copied list elements:\n";
            case 6:
    		copy_linkedlist(head, &copiedList);
   			 break;
 			default: cout<<"\nWrong input!!! Try again!!\n\n";
 		}			
 	}
 	return 0;
}

void insertAtBeginning(int value)
{
 	struct Node *newNode;
	newNode = (struct Node*)malloc(sizeof(struct Node));
	newNode->data = value;
	if(head == NULL)
	{
		newNode->next = NULL;
		head = newNode;
	}
	else
	{
		newNode->next = head;
		head = newNode;
	}
	cout<<"\nOne node inserted!!!\n";
}

void insertAtEnd(int value)
{
	struct Node *newNode;
	newNode = (struct Node*)malloc(sizeof(struct Node));
	newNode->data = value;
	newNode->next = NULL;
	if(head == NULL)
		head = newNode;
	else
	{
	 	struct Node *temp = head;
	 	while(temp->next != NULL)
			temp = temp->next;
	 	temp->next = newNode;
	}
	cout<<"\nOne node inserted!!!\n";
}

void insertBetween(int value, int loc1, int loc2)
{
 	struct Node *newNode;
 	newNode = (struct Node*)malloc(sizeof(struct Node));
 	newNode->data = value;
 	if(head == NULL)
 	{
 		newNode->next = NULL;
 		head = newNode;
 	}
 	else
 	{
 		struct Node *temp = head;
 		while(temp->data != loc1 && temp->data != loc2)
			temp = temp->next;
 		newNode->next = temp->next;
 		temp->next = newNode;
 	}
 	cout<<"\nOne node inserted!!!\n";
}

void removeBeginning()
{
 	if(head == NULL)
		cout<<"\n\nList is Empty!!!";
 	else
 	{
 		struct Node *temp = head;
 		if(head->next == NULL)
 		{
			head = NULL;
			free(temp);
 		}
	 	else
	 	{
			head = temp->next;
	 		free(temp);
			cout<<"\nOne node deleted!!!\n\n";
	 	}	
	}
}

void removeEnd()
{
 	if(head == NULL)
 	{
 		cout<<"\nList is Empty!!!\n";
 	}
 	else 
 	{
 		struct Node *temp1 = head,*temp2;
 		if(head->next == NULL)
			head = NULL;
 		else
 		{
			while(temp1->next != NULL)
			{
				 temp2 = temp1;
				 temp1 = temp1->next;
			}
			temp2->next = NULL;
 		}
		 free(temp1);
 		cout<<"\nOne node deleted!!!\n\n";
 	}
}

void removeSpecific(int delValue)
{
	struct Node *temp1 = head, *temp2;
	while(temp1->data != delValue)
	{
		if(temp1 -> next == NULL){
		cout<<"\nGiven node not found in the list!!!";
		//goto functionEnd;
 		}
 		else{
			temp2 = temp1;
			temp1 = temp1 -> next;
		}
	}
	temp2 -> next = temp1 -> next;
	free(temp1);
	cout<<"\nOne node deleted!!!\n\n";
	//functionEnd:
}

void display()
{
 	if(head == NULL){
 		cout<<"\nList is Empty\n";
 	}
 	else{
		struct Node *temp = head;
		cout<<"\n\nList elements are - \n";
		while(temp->next != NULL){
			cout<<temp->data<<"\t";
			temp = temp->next;
		}
		cout<<temp->data;
 	}
}
void reverseLinkedList() {
    struct Node *prev = NULL, *current = head, *nextNode = NULL;
    while (current != NULL) {
        nextNode = current->next;
        current->next = prev;
        prev = current;
        current = nextNode;
    }
    head = prev;
    cout << "\nLinked List reversed.\n";
}
void copy_linkedlist(struct Node* source, struct Node** dest)
{
    struct Node* current = source;
    struct Node* newList = NULL;
    struct Node* tail = NULL;

    // Traverse the source list and copy each node to the new list
    while (current != NULL)
    {
        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = current->data;
        newNode->next = NULL;

        if (newList == NULL)
        {
            newList = newNode;
            tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
        }

        current = current->next;
    }

    // Set the destination list (copiedList) to the newly created list
    *dest = newList;
  
    cout << "New copied list elements:\n";
    struct Node* temp = newList;
    while (temp != NULL)
    {
        cout << temp->data << "\t";
        temp = temp->next;
    }
    cout << endl;
}
