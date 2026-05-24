#include <iostream>
#include <clocale>
using namespace std;
char a;

struct Stack
{
	char data;
	Stack* prev;
};

Stack* push(Stack*& top, char val)
{
	Stack* p = new Stack;
	p->data = val;
	p->prev = top;
	top = p;
	return top;
}

Stack* make_stack(int n)
{
	Stack* top = nullptr;
	char x;
	for (int i = 0; i < n; i++)
	{
		cin >> x;
		push(top, x);
	}
	return top;
}

void print_stack(Stack* top)
{
	Stack* p = top;
	while (p)
	{
		cout << p->data << " ";
		p = p->prev;
	}
	cout << endl;
}

char pop(Stack*& top)
{
	if (!top) return 0;
	Stack* p = top;
	char val = p->data;
	top = top->prev;
	delete p;
	return val;
}

int main()
{
	setlocale(LC_ALL, "RU");
	int n;
	cout << "Введите колличество элементов: "; cin >> n;
	cout << "Введите элементы стека: ";
	Stack* st = make_stack(n);
	cout << "Стек: ";
	print_stack(st);

	// удаление элемента с заданным ключем 

	char b;
	cout << "Введите ключ для удаления: ";
	cin >> b;
	int k = 0;
	Stack* st2 = make_stack(0);
	for (int i = 0; i < n; i++)
	{
		char t = pop(st);
		if (t != b) 
		{
			push(st2, t);
		}
		else
		{
			k += 1;
		}
	}
	n = n - k;
	for (int i = 0; i < n; i++)
	{
		char t = pop(st2);
		push(st, t);
	}
	cout << "Стек после удаления: ";
	print_stack(st);

	// добавить к элементов перед заданным 

	k = 0; 
	cout << "Введите колличество слов для добавления: ";
	cin >> k;
	int s = 0;
	cout << "Введите номер элемента	перед которым добавляют элементы: ";
	cin >> s;
	for (int i = 0; i < n - s + 1; i++)
	{
		char t = pop(st);
		push(st2, t);
	}
	cout << "Ввкдите элементы: ";
	for (int i = 0; i < k; i++)
	{
		cin >> a;
		push(st, a);
	}
	for (int i = 0; i < n - s + 1; i++)
	{
		char t = pop(st2);
		push(st, t);
	}
	print_stack(st);

	return 0;
}