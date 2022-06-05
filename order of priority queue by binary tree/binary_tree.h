#ifndef BINARY_TREE_H
#define BINARY_TREE_H

#include <iostream>
#include <string>

using namespace std;

typedef struct btree {
	int prior; //�켱���� ť���� ���� �߿䵵, �������� �켱���� ����
	string data; //Ʈ�� ���� ������
	btree* leftnode; //���� ���
	btree* rightnode; //������ ���
}T;

class priortyqueue { //����Ʈ���� Ȱ���� �켱���� ť ���� Ŭ����
public:
	priortyqueue(); //����Ʈ������� �켱���� ť Ȱ��ȭ
	~priortyqueue(); //��� Ʈ�� ��� �����ϰ� ����
	void add(string input, int p); //����Ʈ���� ��� ����
	string pop_tree(); //����Ʈ������ ��� �ϳ� ����
	void opposite_inorder(); //�ݴ�������� ������ȸ�Ѵ�. (����->�ڽ�->�������� �ƴ� ������->�ڽ�->����, �̷��� �ϸ� �߿䵵�� ū �ͺ��� �����ͼ����� ���ĵǾ� ����)
	bool isEmpty(); //����Ʈ�� ����� Ȯ��
	int getsize() {
		return this->size;
	}
private:
	btree* head; //Ʈ���� ��Ʈ��带 ����Ŵ
	int size; //Ʈ���ȿ����� ��尳��
};

#endif BINARY_TREE_H