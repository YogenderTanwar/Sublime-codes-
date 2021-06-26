#include<bits/stdc++.h>
using namespace std;

class Node
{
public:
	int data;
	Node* next;

	Node( int data )
	{
		this->data = data;

		next = NULL;

	}
};



class Linklist
{



public:
	Node* head = NULL;


	void append(int data)
	{
		Node * temp = new Node(data);
		if (head == NULL)
		{
			head = temp;

		}
		else {
			Node * curr = head;



			while (curr->next != NULL)
			{
				curr = curr->next;
			}

			curr->next = temp;

		}
	}

	void push(int data)
	{
		Node * temp = new Node(data);
		temp->next = head;
		head = temp;


	}


	void print()
	{
		Node * curr = head;

		while (curr != NULL)
		{
			cout << curr->data << " ";
			curr = curr->next;

		}

		cout << endl;
	}

	void Reverse()
	{
		Node * prev = NULL;
		Node * curr = head;
		Node * next = head;

		while (curr != NULL)
		{
			next = curr->next;
			curr->next = prev;
			prev = curr;
			curr = next;


		}

		head = prev;

	}

	void Reverserec()
	{
		Node * p = head;
		solve(p);

	}


	void solve( Node * p )
	{
		if (p->next == NULL)
		{
			head = p;
			return ;


		}

		solve(p->next);

		Node * q = p->next;
		q->next = p;
		p->next = NULL;



	}

	void middle_element()
	{
		Node * fast = head;
		Node * slow = head;

		while (fast != NULL && fast->next != NULL)
		{
			slow = slow->next;

			fast = fast->next->next;
		}

		cout << slow->data;



	}

	void merge_sort(Node * b)
	{
		Node * a = head;
		while (a != NULL  && b != NULL)
		{
			if (a->data > b->data)
			{
				cout << b->data << " ";
				b = b->next;
			}
			else {
				cout << a->data << " ";
				a = a->next;

			}

		}

		while (a != NULL)
		{
			cout << a->data << " ";

			a = a->next;

		}

		while (b != NULL)
		{
			cout << b->data << " ";
			b = b->next;

		}



	}
	// Node * a = head;


	Node * merge_sortrec( Node * a, Node * b)
	{

		if (a == NULL) return b;
		if (b == NULL) return a;

		if (a->data > b->data)

		{
			b->next = merge_sortrec(a, b->next);

			return b;
		}
		else {
			a->next = merge_sortrec(a->next, b);

			return a;

		}


	}



	void remove_nthnode(int n)
	{
		Node * a = head;
		Node * b = head;

		while (n--) a = a->next;

		while ( a != NULL )
		{
			a = a->next;
			b = b->next;


		}

		remove(b);

	}

	void remove(Node * temp)
	{
		Node * next = temp->next;

		temp->data = next->data;

		temp->next = next->next;

		free(next);



	}
	int t = 1;


	int get_sum(Node * a)
	{
		if (a->next == NULL)
		{
			// t++;




			return a->data;
		}

		int val = get_sum(a->next);
		//cout << t << endl;
		t = t * 10;
		int ans = val + a -> data * t;





		return  ans;


	}

	void addition(Node* b)
	{
		int sum1 = get_sum(head);
		t = 1;

		int sum2 = get_sum(b);

		// cout << sum1 << " " << sum2 << endl;

		cout << sum1 + sum2 << endl;

	}

	void attach(Node * l , Node * s, int n)
	{
		n--;

		while (n--)
		{
			l = l->next;

		}

		while (s->next != NULL) s = s->next;

		s->next = l; //attach


	}

	int get_len(Node * a)
	{
		int count = 0;

		while (a != NULL) count++, a = a->next;
		return count;

	}

	int get_intersection(Node * a, Node * b) {
		int lena = get_len(a);
		int lenb = get_len(b);

		if (lenb > lena)
		{
			swap(a, b);
		}

		int d = (abs(lena - lenb));

		// d--;
		while (d--) a = a->next;



		while (a != b)
		{
			a = a->next;
			b = b->next;

			//cout << a->data << " " << b->data << endl;

		}

		return a->data;







	}


	bool cycle_detect(Node * a)
	{
		Node * slow = a;
		Node * fast = a;

		Node * ptr = NULL;

		while (fast != NULL  && fast->next != NULL)
		{
			//cout << slow->data << endl;
			slow = slow->next;
			fast = fast->next->next;

			if (slow == fast)
			{
				ptr = slow;
				break;
			}

		}

		if (ptr == NULL) return false;
		return true;

	}

	Node * Reverse_in_group(Node * a, int k)
	{

		Node * prev = NULL;
		Node * curr = a;

		Node * next = a;

		int count = 0;

		while (count < k && next != NULL)
		{
			next = curr->next;
			curr->next = prev;
			prev = curr;
			curr = next;
			count++;


		}

		if (next != NULL)
		{
			a->next = Reverse_in_group(next, k);


		}

		return prev;




	}

	Node * rotate(Node * a, int k)
	{
		if (k == 0)
		{
			return a;

		}
		Node * kth = a;
		Node * last = a;

		int  count = 1;

		while (last->next != NULL)
		{
			if (count == k)
			{
				kth = last;

			}

			last = last->next;

			count++;

			if (count == k)
			{
				kth = last;

			}

		}

		Node * head = kth->next;
		kth->next = NULL;

		last->next = a;


		return head;

	}







};


int main()
{



	Linklist l1;

	l1.append(1);
	l1.append(2);
	l1.append(3);
	l1.append(4);
	l1.append(5);
	l1.append(7);
	l1.append(10);

	l1.print();

	//l1.rotate(l1.head, 3);



	Node * x = l1.rotate(l1.head, 0);

	while (x != NULL)
	{
		cout << x->data << " ";
		x = x->next;

	}











	// Linklist l2;
	// l2.append(1);
	// l2.append(7);
	// l2.append(9);
	// l2.append(4);
	// l2.append(5);
	// l2.append(7);
	// l2.append(9);




	// l2.print();

	// l2.attach(l2.head, l1.head, 3);

	// l1.print();


	// Node* head = new Node(50);
	// head->next = head;
	// head->next = new Node(20);
	// head->next->next = new Node(15);
	// head->next->next->next = new Node(4);
	// head->next->next->next->next = new Node(10);

	/* Create a loop for testing */
	//head->next->next->next->next->next = head->next->next;

	// Node * curr = head;
	// Linklist l3;

	// if (l3.cycle_detect(curr))
	// {
	// 	cout << "strvdtybf";

	// }
	// else cout << "NO" << endl;

















	// l1.middle_element();







	return 0;

}
