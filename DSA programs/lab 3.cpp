#include<bits/stdc++.h>
#include<conio.h>
using namespace std;
//....................read array....................
void read_array(int MA[],int n){
for(int i=0;i<n;i++){
cout<<"Enter at index <<"<<i<<"<<= ";
cin>>MA[i];
}
}
//..................TRAVERSING THE ARRAY..............
void TRAVERSE(int MA[], int n)
{
for(int index = 0; index<n; index++) {
 cout<<"MA["<<index<<"] = "<<MA[index]<<"\n";
 }
}

//.................INSERTION IN ARRAYS....................
void INSERT (int MA[], int n) 
{
	int item;
	cout<<"\nEnter Value Which u want to insert\n";
	cin>>item;
	int k;
	cout<<"Enter index[] where u Want to Insert\n";
	cin>>k;
	if (k>n)
	{
		cout<<"invalid index number\n";
	}
	else
	{
		int j=n;
 while( j > k-1) {
 MA[j+1] = MA[j];
 j = j - 1;
 cout<<"its inside ..";
 }
 MA[k] = item; // insert "item" at location k
n = n + 1;
 cout<<"\n The array elements after insertion:\n";
 TRAVERSE (MA,n);
	}

}
//...................deletion in array..................
void DELETE (int MA[], int n)
 { int k;
  cout<<"\nEnter index of element to delete\n";
 cin>>k;
  if (k<0 || k>=n) // check for valid index range 
  { cout<<"Enter valid index number\n"; 
  } 
  else { int j = k; while( j < n-1)
   { // loop until one before the last element
    MA[j] = MA[j+1]; // shift elements to the left 
    cout<<"j is : "<<j;
    cout<<"j+1 is : "<<j+1;
	j = j + 1; } n = n - 1; // reduce the size of the array by one 
	cout<<"\n The array elements after deletion :\n";
	 TRAVERSE (MA,n); 
	 }

}
//............................LINEAR SEARCH ARRAY ELEMENTS
void SEARCH(int MA[], int n)
{
int num;
cout<<"Enter the number to search ";
cin>>num;
for (int index = 0; index < n; index++) 
 if (MA[index] == num)
 cout<<"Number "<<num<<" is at index : "<<index<<endl;
}
//.................................update array........
void UPDATE (int MA[], int n) 
{
	int item;
	cout<<"enter item to update\n";
	cin>>item;
	int k;
	cout<<"Enter index[] where u Want to Insert\n";
	cin>>k;
	if (k>n)
	{
		cout<<"Enter Valid index number\n";
	}
	else
	{
	 MA[k] = item; // update "item" at location k
	 cout<<"\n The array elements after Updation :\n";
	TRAVERSE (MA,n);	

	}

}
void Reverse(int MA[],int n)
{
	
	cout<<"Array After Reverse is \n";
	for(int i=n;i>0;i--)
	{
		cout<<"MA "<<i<<" is : "<<MA[i]<<"\n";
	}
}
void Average(int MA[],int n)
{
	int sum=0;
	cout<<"Average of Array is Below \n\n";
	for(int i=0;i<=5;i++)
	{
		sum+=MA[i];
		
	}
	int avg=sum/n;
	cout<<"Average of Elements is : "<<avg;
}
int main()
{
	
	abc:
		int MyArray[20]={0};
int item = 10, k = 3, n = 5;
cout<<"Enter Array  Values ...\n";
read_array(MyArray,n);
cout<<"Array Values Are\n";
TRAVERSE(MyArray,n);
char choice;
cout<<"Enter 'L' For Insertion \n";
cout<<"Enter 'D' For Deletion\n";
cout<<"Enter 'U' For Update\n";
cout<<"Enter 'S' For Search\n";
cout<<"Enter 'R' For Reverse\n";
cout<<"Enter 'A'   For Average\n\n";
cout<<"Enter Your Choice.......\n";
cin>>choice;
switch(choice)
{
	case 'l':
	case 'L':
		INSERT (MyArray, n); 
		cout<<"Enter any character";
		getch();
		system("cls");
		goto abc;
		break;
	case 'd':
	case 'D':
		DELETE (MyArray, n);
		cout<<"Enter any character";
		getch();
		system("cls");
		goto abc;
		break;
	case 'u':
	case 'U':
		UPDATE (MyArray,  n); 
		cout<<"Enter any character";
		getch();
		system("cls");
		goto abc;
		break;
	case 's':
	case 'S':
		SEARCH(MyArray, n);
		cout<<"Enter any character";
		getch();
		system("cls");
		goto abc;
		break;
	case 'r':
	case 'R':
		Reverse(MyArray,n);
		cout<<"Enter any character";
		getch();
		system("cls");
		goto abc;
		break;
	case 'a':
	case 'A':
		Average(MyArray,n);
		cout<<"Enter any character";
		getch();
		system("cls");
		goto abc;
		break;
	default:
		char ch;
		system("cls");
		cout<<"\n\n\n\t\t\t\t\t<<...................Invalid Choice.................>>\n";
		cout<<"\n\n\n\t\t\t\t\tEnter 'C' TOo Continue .....\n";
		cin>>ch;
		if (ch=='X')
		{
			system("cls");
			goto abc;
		}
		else
		{
			abort();
		}
		
	
	
		
	}


		 
		

}



