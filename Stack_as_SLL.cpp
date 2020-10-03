/*  SHIVAM GUPTA
	BSC.(HON.) COMPUTER SCIENCE
	ROLL NO: 19569
	PROGRAM TO IMPLEMENT STACK AS A SINGLE LINKED LIST. 
*/

#include<iostream>
using namespace std;

template <class T>
class SLLNode
{
	public:

		T info;
		SLLNode *next;

		SLLNode()
		{
			info = 0;
			next = NULL;
		}

		SLLNode(T element, SLLNode *nxt = 0)
		{
			info = element;
			next = nxt;
		}
};

template <class T>
class SLList
{
	private:

		SLLNode <T>*head;

	public:

		SLList()
		{
			head = 0;
		}

		//ADDING ELEMENT AT HEAD
		void add_at_head(T element)
		{
			SLLNode <T>*N = new SLLNode <T>(element);
			if(head == NULL)
			{
				head = N;
			}

			else
			{
				N->next = head;
				head = N;
			}
		}

		//DELETE ELEMENT FROM HEAD
		T remove_from_head()
		{
			T el = head->info;

			if(head->next == NULL)
			{
				delete(head);
				head = NULL;
				return(el);
			}

			else 
			{
				SLLNode <T>*temp = head;
				head = head->next;
				delete(temp);
				return(el);
			}

			return 0;
		}

		T top_element()
		{
			return(head->info);
		}

		bool is_head_null()
		{
			if(head == NULL)
				return true;

			else
				return false;
		}
};

template <class T>
class Stack
{
	private:
		SLList <T> L1;

	public:

		void push(T element)
		{
			L1.add_at_head(element);
		}

		T pop()
		{
			return(L1.remove_from_head());
		}

		bool isempty()
		{
			return(L1.is_head_null());
		}

		T top_element()
		{
			return(L1.top_element());
		}
};

template <class X>
void func(Stack <X> &S1, X element)
{
	int ch;

	while(1)
	{
		cout<<"\n\n ***** Main Menu *****"
			<<"\n (1) Push element in Stack"
			<<"\n (2) Pop element from Stack"
			<<"\n (3) Check if Stack is Empty"
			<<"\n (4) Get Top Element"
			<<"\n (5) Exit"
			<<"\n\n Enter Choice: ";
		cin >> ch;

		while(!(ch > 0 && ch < 6))
		{
			cout<<" Invalid Input, Re-Enter : ";
			cin>>ch;
		}

		switch(ch)
		{
			case 1:	cout<<"\n Enter Element to be Added: ";
					cin>>element;
					S1.push(element);
					cout<<"\n Element Added....";
					break;			

			case 2: {

					bool x = S1.isempty();

					if(x == true)
						cout<<"\n Stack is Empty";

					else
						cout<<"\n Element Popped: "<<S1.pop();		
					}

					break;

			case 3: {

					bool x = S1.isempty();

					if(x == true)
						cout<<"\n Stack is Empty";

					else
						cout<<"\n Stack is not Empty";
					}

					break;

			case 4: {

					bool x = S1.isempty();

					if(x == true)
						cout<<"\n Stack is Empty";

					else
						cout<<"\n Top Element in Stack: "<< S1.top_element();	
					}

					break;

			case 5: exit(0);
		}
	}
}

int main()
{
	int ch;

	cout<<"\n\n ****** Select Datatype **********\n";
	cout<<"\n (1) INT"
		<<"\n (2) FLOAT"
		<<"\n (3) CHAR"
		<<"\n\n Enter Choice: ";

	cin>>ch;
	//INPUT VALIDATION CHECK
	while(!(ch >= 1 && ch <= 3))		
	{
		cout<<" Invalid Input, Re-Enter: ";
		cin>>ch;
	}

	if(ch == 1) 	{
		int element ;
		Stack <int> S1;
		func(S1, element);	}
	
	else if(ch == 2)
	{
		float element;
		Stack <float> S1;
		func(S1, element);
	}
	
	else if(ch == 3)
	{
		char element;
		Stack <char> S1;
		func(S1, element);
	}

	return 0;
}
