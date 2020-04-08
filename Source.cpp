#include <iostream>
using namespace std;

// 2015112147 김도훈 
class AbstractClass {
public:
	virtual void push(int n) = 0;
	virtual int pop() = 0;
	virtual int size() = 0;
};

class IntStack :public AbstractClass {
private:
	int* stack;		//���� �迭
	int stackSize;	//������ �ִ�ũ��
	int curSize;	//������ ���� ������
public:
	IntStack(int size) {//������ : �迭 �����Ҵ��� ���� ������=-1�� �ʱ�ȭ
		stack = new int[size];
		stackSize = size;
		curSize = -1;
	}
	virtual int size() {//���� ������
		return curSize+1;
	}

	bool isFull() {//������ �� á�°�
		if (curSize == stackSize - 1) {
			return true;
		}
		else return false;
	}

	bool isEmpty() {//������ ����°�
		if (curSize == -1) {
			return true;
		}
		else return false;
	}

	virtual void push(int n) {//���ÿ� ���ο� ���Ҹ� �������
		if (!isFull()) {//full �� �ƴ϶��
			stack[++curSize] = n;
			cout << "pushed " << n << endl;
		}
		else {
			cout << "it's Full, push Failed" << endl;
		}
	}


	virtual int pop() {
		if (!isEmpty()) {//empty�� �ƴ϶��
			return stack[curSize--];
		}
		else {
			return 999;
		}
	}


	void structure() {
		if (!isEmpty()) {
			cout << "size of the Stack : " << size() << endl;
			for (int i = 0; i < stackSize; i++) {
				cout << i + 1 << "\t";
			}
			cout << endl;
			for (int i = 0; i <= curSize; i++) {
				cout << stack[i] << "\t";
			}
			cout << endl << endl;
		}
		else {
			cout << "it's Empty" << endl;
		}
	}
};

int main() {
	char cmd='a';
	IntStack abStack(8);

	cout << "<< stack programm >>" << endl;
	cout << " 01 . push : + and input int" << endl;
	cout << " 02 . pop : - " << endl;
	cout << " 03 . quit : q " << endl;

	while (cmd != 'q'&&cmd != 'Q') {
		int input;
		int tmp = 0;

		cout << "enter command >> ";
		cin >> cmd;
		switch (cmd) {
		case '+':
			cin >> input;
			abStack.push(input);
			abStack.structure();
			break;
		case '-':
			tmp = abStack.pop();
			if (tmp != 999) {
				cout << "popped " << tmp << endl;
			}
			abStack.structure();
			break;
		case 'q':case 'Q':
			cout << "quit stack Program" << endl;
			break;
		default:
			cout << "wrong command entered!" << endl;
			abStack.structure();
			break;
		}
	}

}