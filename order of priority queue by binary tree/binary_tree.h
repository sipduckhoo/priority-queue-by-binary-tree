#ifndef BINARY_TREE_H
#define BINARY_TREE_H

#include <iostream>
#include <string>

using namespace std;

typedef struct btree {
	int prior; //우선순위 큐에서 쓰일 중요도, 높을수록 우선순위 높음
	string data; //트리 안의 데이터
	btree* leftnode; //왼쪽 노드
	btree* rightnode; //오른쪽 노드
}T;

class priortyqueue { //이진트리를 활용한 우선순위 큐 구현 클래스
public:
	priortyqueue(); //이진트리기반의 우선순위 큐 활성화
	~priortyqueue(); //모든 트리 노드 삭제하고 종료
	void add(string input, int p); //이진트리에 노드 삽입
	string pop_tree(); //이진트리에서 노드 하나 삭제
	void opposite_inorder(); //반대방향으로 중위순회한다. (왼쪽->자신->오른쪽이 아닌 오른쪽->자신->왼쪽, 이렇게 하면 중요도가 큰 것부터 작은것순으로 정렬되어 나옴)
	bool isEmpty(); //이진트리 비었나 확인
	int getsize() {
		return this->size;
	}
private:
	btree* head; //트리의 루트노드를 가리킴
	int size; //트리안에서의 노드개수
};

#endif BINARY_TREE_H