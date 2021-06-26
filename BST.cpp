#include<bits/stdc++.h>
using namespace std;


class Node
{
public:
	int data;
	Node* left;
	Node* right;
	Node(int data)
	{
		this->data = data;
		left = NULL;
		right = NULL;
	}
};

class BST
{

public:
	Node * root = NULL;






	Node* insert(Node * root , int value)
	{
		if (root == NULL)
		{
			return new Node (value);
		}

		if (value > root->data)
		{
			root->right = insert(root->right, value);
		}
		else {
			root->left = insert(root->left, value);
		}

		return root;

	}


	void inorder(Node * a)
	{
		if (a == NULL) return ;

		inorder(a->left);
		cout << a->data << " ";
		inorder(a->right);



	}

	void inorderit(Node * a)
	{
		stack<Node * > s;
		Node  * curr = a;




		while (curr != NULL || s.empty() == false)
		{
			while (curr != NULL)
			{
				s.push(curr);
				curr = curr->left;

			}

			curr = s.top();
			s.pop();


			cout << curr->data << " ";

			curr = curr->right;


		}


	}


	void preorder(Node * a)
	{
		if (a == NULL) return ;

		cout << a->data << " ";
		preorder(a->left);

		preorder(a->right);


	}

	void preorderit(Node *a )
	{
		stack<Node * > s;
		Node  * curr = a;
		s.push(a);





		while ( s.empty() == false)
		{
			curr = s.top();

			cout << curr->data;
			s.pop();

			if (curr->right != NULL) s.push(curr->right);
			if (curr->left != NULL) s.push(curr->left);





		}

	}

	void postorder(Node *a )
	{
		if (a == NULL) return ;


		postorder(a->left);

		postorder(a->right);
		cout << a->data << " ";

	}

	void postorderit(Node *a )
	{
		stack<Node * > s1, s2;

		s1.push(a);

		while (!s1.empty())
		{
			Node * curr = s1.top();

			s2.push(curr);

			s1.pop();

			if (curr->left != NULL)
			{
				s1.push(curr->left);

			}

			if (curr->right != NULL)
			{
				s1.push(curr->right);

			}

		}

		while (!s2.empty()) cout << s2.top()->data << " ", s2.pop();


	}


	Node * min_value_node(Node * a)
	{
		while (a->left != NULL)
		{
			a = a->left;
		}

		return a;

	}

	Node * delete_node(Node * a, int val)
	{
		if (a->data < val)
		{
			a->right = delete_node(a->right, val);
		}
		else if (a->data > val)
		{
			a->left = delete_node(a->left, val);

		}
		else
		{
			// one child or zero child

			if (a->left == NULL)
			{
				Node *temp = a->right;
				free(a);
				return temp;

			}
			else if (a->right == NULL)
			{
				Node *temp = a->left;
				free(a);
				return temp;

			}
			else {

				// two child


				Node * temp = min_value_node(a->right);

				a->data = temp->data;

				a->right = delete_node(a->right, temp->data);
			}



		}
		return a;
	}



	void left_view(Node * a, int depth, int* max_level)
	{
		//cout << a->data << " " << max_level << " " << depth << endl;
		if (a == NULL) return ;

		if (depth >  *max_level) cout << a->data << " ", *max_level = depth;





		if (a->left != NULL)
		{
			left_view(a->left, depth + 1, max_level);
		}
		if (a->right != NULL)
		{
			left_view(a->right, depth + 1, max_level);
		}
	}


	void bottom_view(Node *a )
	{

		map<int, int > m;

		queue<pair<Node * , int > > q;

		q.push({a, 0});


		while (!q.empty())
		{
			auto it = q.front();
			q.pop();


			Node * curr = it.first;
			int val = it.second;
			m[val] = curr->data;

			if (curr->left != NULL)
			{
				q.push({curr->left, val - 1});

			}

			if (curr->right != NULL)
			{
				q.push({curr->right, val + 1});
			}
		}

		for (auto x : m) cout << x.second << " ";



	}


	void level_order_spiral(Node *a)
	{
		stack<Node *> s1, s2;

		s1.push(a);
		while (!s1.empty() || !s2.empty())
		{
			while (!s1.empty())
			{
				Node * curr = s1.top();
				cout << curr->data << " ";


				s1.pop();
				if (curr->right != NULL) s2.push(curr->right);

				if (curr->left != NULL) s2.push(curr->left);


			}

			while (!s2.empty())
			{
				Node * curr = s2.top();
				cout << curr->data << " ";
				s2.pop();

				if (curr->left != NULL) s1.push(curr->left);

				if (curr->right != NULL) s1.push(curr->right);
			}


		}
	}


	int height( Node* node)
	{

		if (node == NULL)
			return 0;


		return 1 + max(height(node->left), height(node->right));
	}


	int diameter(Node * a)
	{

		if (a == NULL) return 0;

		int l1 = height(a->left);
		int l2 = height(a->right);


		return max(l1 + l2 + 1, max(diameter(a->right), diameter(a->left)));


	}

	bool path_find(Node * root, vector<int> &path, int val)
	{
		if (root == NULL) return false;

		path.push_back(root->data);


		if (root->data == val)
			return true;

		if ( (root->left && path_find(root->left, path, val)) ||
		        (root->right && path_find(root->right, path, val)) )
			return true;

		path.pop_back();
		return false;

	}

	int LCA_in_BT(Node * root, int a, int b)

	{

		vector<int> path1, path2;

		if (!path_find(root, path1, a) || !path_find(root, path2, b)) return -1;

		int i;


		for (  i = 0; i < min(path1.size(), path2.size()); i++)
		{
			if (path1[i] != path2[i])
			{
				break;
			}
		}

		return path1[i - 1];

	}
	int ans = 1e-10;



	int max_sum(Node * a)
	{
		if (a == NULL) return 0;


		int val = (max_sum(a->left));

		int valr = (max_sum(a->right));

		int value = max(val, valr);

		int val1 = a->data + max(value, 0);

		ans = max(ans, val + valr + a->data);

		//	cout << ans << endl;

		return val1;







	}

	bool is_symmetric(Node * a , Node * b)
	{

		if (a == NULL && b == NULL) return true;

		if (a && b && a->data == b->data)
		{
			if (is_symmetric(a->left, b->right) && is_symmetric(a->right, b->left))
				return true;
			else return false;

		}
		else return false;

	}

	void flatten(Node *a )
	{
		if (a == NULL || (a->right == NULL && a->left == NULL)) return ;

		if (a->left != NULL)
		{
			flatten(a->left);

			Node * temp = a->right;

			a->right = a->left;

			a->left = NULL;

			Node * t = a->right;

			while (t->right != NULL)
			{
				t = t->right;
			}
			t->right = temp;



		}

		flatten(a->right);




	}


	bool is_BST(Node * a, int min, int max) // doubt
	{
		if (a == NULL) return true;

		if (a->data < min || a->data > max) return false;

		return is_BST(a->left, min, a->data) && is_BST(a->right, a->data, max);
	}


	void presuc(Node *a , Node * &pre, Node * & suc, int key)
	{

		if (a == NULL) return ;

		if (a->data == key)
		{
			if (a->left != NULL)
			{
				Node * tmp = a->left;

				while (tmp->right != NULL)
				{
					tmp = tmp->right;
				}

				pre = tmp;
			}


			if (a->right != NULL)
			{
				Node * tmp = a->right;
				while (tmp->left != NULL)
				{
					tmp = tmp->left;
				}

				suc = tmp;


			}


			return ;

		}


		if (a->data > key)
		{
			suc = a;
			presuc(a->left, pre, suc, key);
		}
		else {
			pre = a;
			presuc(a->right, pre, suc, key);

		}
	}







};

class BSTit
{
private:
	stack<Node * > s;

public:

	BSTit(Node * a)
	{
		Node * curr = a;

		while (curr != NULL)
		{
			s.push(curr), curr = curr->left;

		}


	}


	Node * curr()
	{
		return s.top();
	}

	void next()
	{
		Node * curr = s.top()->right;
		s.pop();

		while (curr != NULL)
		{
			s.push(curr), curr = curr->left;
		}


	}

	bool is_END()
	{
		return s.size() == 0;


	}

};

void iterater(BSTit s)
{
	while (!s.is_END())
	{
		cout << s.curr()->data << " ";
		s.next();
	}
}



int main()
{

	BST b;


	b.root = b.insert(b.root, 20);
	b.root = b.insert(b.root, 8);
	b.root = b.insert(b.root, 22);
	b.root = b.insert(b.root, 5);
	b.root = b.insert(b.root, 3);
	b.root = b.insert(b.root, 4);
	b.root = b.insert(b.root, 25);
	b.root = b.insert(b.root, 10);
	b.root = b.insert(b.root, 14);
	// b.inorder(b.root);
	// cout << endl;
	// b.inorderrec(b.root);
	// b.preorder(b.root);
	// cout << endl;
	// b.preorderrec(b.root);
	// b.postorder(b.root);
	// cout << endl;
	// //b.postorderit(b.root);

	// b.delete_node(b.root, 8);
	//b.inorder(b.root);
	// int t = 0;


	//b.left_view(b.root, 1, &t);

	// b.bottom_view(b.root);
	// cout << endl;

	// // b.level_order_spiral(b.root);
	// cout << b.height(b.root);

	// cout << endl;

	//cout << b.diameter(b.root);


	//cout << b.LCA_in_BT(b.root, 22, 25);

	// b.max_sum(b.root);

	// cout << b.ans << endl;

	// cout << b.is_symmetric(b.root, b.root);

	// b.flatten(b.root);

	// b.preorder(b.root);


	//cout << b.is_BST(b.root, INT_MIN, INT_MAX);

	//     20
	//    /   \
	//    8    22
	//   /  \     \
	//  5    10    25
	// /       \    
	// 3        14
	//  \ 
	//    4
	// Node* pre = NULL, *suc = NULL;

	// b.presuc(b.root, pre, suc, 17);

	// cout << pre->data << " " << suc->data << endl;

	BSTit s(b.root);

	iterater(s);


























	return 0;

}

