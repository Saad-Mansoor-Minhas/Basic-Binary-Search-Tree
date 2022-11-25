#include<iostream>
#include<windows.system.h>

using namespace std;

class node
{
private:
	int value;
	node* left;
	node* right;

public:

	void set_value(int v)
	{
		value = v;
	}

	int get_value()
	{
		return value;
	}

	void set_left_node(node* n)
	{
		left = n;
	}

	node* get_left_node()
	{
		return left;
	}

	void set_right_node(node* n)
	{
		right = n;
	}

	node* get_right_node()
	{
		return right;
	}


};

class tree
{
private:
	node* root;
	int nov;

public:
	tree()
	{
		root = NULL;
		nov = 0;
	}

	void insertion(int v)
	{
		node* newnode = new node;
		newnode->set_value(v);
		newnode->set_left_node(NULL);
		newnode->set_right_node(NULL);

		if (root == NULL)
		{
			root = newnode;
		}
		else
		{
			node* previous = NULL;
			node* current = root;

			while (current != NULL)
			{
				previous = current;
				if (v < current->get_value())
				{
					current = current->get_left_node();
				}
				else
				{
					current = current->get_right_node();
				}

			}

			if (previous->get_value() > v)
			{
				previous->set_left_node(newnode);
			}
			else
			{
				previous->set_right_node(newnode);
			}



		}

	}

	void display()
	{
		node* current = root;

		cout << "pre-order: " << endl;
		display_pre_order(current);
		cout << endl;

		current = root;
		cout << "\npost-order: " << endl;
		display_post_order(current);
		cout << endl;

		current = root;
		cout << "\nIn-order: " << endl;
		display_inorder(current);
		cout << endl;

	}

	void display_pre_order(node* n)
	{

		if (n != NULL)
		{
			cout << n->get_value() << " ";
			display_pre_order(n->get_left_node());
			display_pre_order(n->get_right_node());

		}

	}

	void display_post_order(node* n)
	{

		if (n != NULL)
		{
			display_post_order(n->get_left_node());
			display_post_order(n->get_right_node());
			cout << n->get_value() << " ";
		}

	}

	void display_inorder(node* n)
	{
		if (n != NULL)
		{
			display_inorder(n->get_left_node());
			cout << n->get_value() << " ";
			display_inorder(n->get_right_node());

		}
	}

	void max_value()
	{
		node* current = root;

		while (current->get_right_node() != NULL)
		{
			current = current->get_right_node();
		}

		cout << "Max Value: " << current->get_value() << endl;

	}

	void min_value()
	{
		node* current = root;

		while (current->get_left_node() != NULL)
		{
			current = current->get_left_node();
		}

		cout << "Min Value: " << current->get_value() << endl;

	}

	void search(int v)
	{
		node* current = root;

		while ((current != NULL) && (current->get_value() != v))
		{
			if (v < current->get_value())
			{
				current = current->get_left_node();
			}
			else
			{
				current = current->get_right_node();
			}

		}


		if (current == NULL)
		{
			cout << "value doesnot exists" << endl;
		}

		else if (current->get_value() == v)
		{
			cout << "value you entered exists in bst" << endl;
		}




	}

};

int main()
{
	tree t1;
	int choice;

	while (1 > 0)
	{
		system("cls");
		t1.display();
		cout << "\nChoose an option" << endl;
		cout << " 1. insert\n 2. delete\n 3. Maximum Value\n 4. Minimum Value\n 5. Search\n 6. Exit \n Enter your choice: ";
		cin >> choice;
		system("cls");

		switch (choice)
		{
		case 1:
		{
			int v;
			cout << "Enter value: ";
			cin >> v;
			t1.insertion(v);
			system("pause");
			system("cls");
		}
		break;

		case 2:
		{

		}
		break;

		case 3:
		{
			t1.max_value();
			system("pause");
			system("cls");
		}
		break;

		case 4:
		{
			t1.min_value();
			system("pause");
			system("cls");
		}
		break;

		case 5:
		{
			int v;
			cout << "enter the value you want to search: ";
			cin >> v;
			t1.search(v);
			system("pause");
			system("cls");
		}
		break;

		case 6:
		{
			exit(0);
		}
		break;

		}

	}



}
