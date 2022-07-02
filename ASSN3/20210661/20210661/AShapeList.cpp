#include <iostream>
#include "AShapeList.h"

using namespace std;

AShapeList::AShapeList() { //생성자
	size = 0;
	head = NULL;
	tail = NULL;
}
AShapeList::~AShapeList() { //소멸자
	if (head != NULL) {
		AShapeNode* cur = head->next; //head->next를 cur에 담고, 
		while (cur != NULL) {
			AShapeNode* next = cur->next; //cur의 다음걸 next에 가리킨 후
			delete cur; //cur 할당 해제
			cur = next; //next를 cur에 담아서 cur 가 NULL이 아닐때까지 반복
		} 
	}
}
void AShapeList::addNewAShape(AShape* new_shape) { //새로운 shape 생성
	AShapeNode* s = new AShapeNode; //동적할당
	s->shape = new_shape; //s의 shape에 AShapenode 담기
	s->next = NULL; //next는 NULL

	if (size == 0) { //아직 리스트가 없을 시
		head = s;
		tail = s;
	}
	else { //리스트가 존재할 시 
		tail->next = s;
		tail = s;
	}
	size++;
}
AShapeNode* AShapeList::popNodeByIdx(int idx) { //리스트에서 특정 인덱스의 값 삭제
	AShapeNode* ppre = new AShapeNode; //동적할당
	AShapeNode* pcur = new AShapeNode; //동적할당
	ppre = head; //헤드를 가리킴
	pcur = ppre->next; //헤드의 다음 것을 가리킴
	if (idx == 0) { //첫번째 노드를 지울 시
		head = ppre->next; //헤드의 다음 것을 헤드에 담음
		size--; //사이즈 1 감소
		return ppre; //리턴
	}
	else {
		for (int i = 0; pcur != NULL; i++) { //반복문을 통해 원하는 인덱스에 해당하는 노드 찾기
			if (idx - 1 == i) {
				ppre->next = pcur->next;
				break;
			}
			ppre = ppre->next; 
			pcur = pcur->next;//이전노드의 다음노드를 삭제하려는 노드의 다음노드로 전환
		}

		size--;//사이즈 감소
		return pcur; //리턴

	}
}
const AShapeNode* AShapeList::getNodeByIdx(int idx) const {//인덱스에 맞는 노드 찾기
	AShapeNode* tmp = new AShapeNode; //동적할당
	tmp = head; //헤드를 가리킴
	int check = 0;
	for (int i = 0; tmp != NULL; i++) { //반복문으로 원하는 노드 찾고
		if (idx == i) {
			break;
		}
		tmp = tmp->next; //다음걸 가리켜서

	}
	return tmp; //리턴
}
void AShapeList::displayAShapeList() const { //리스트 모두 뽑는 함수
	AShapeNode* tmp = new AShapeNode;
	tmp = head;

	for (int i = 0; i < size; i++) { //사이즈만큼 반복함
		cout << i; //인덱스 출력
		tmp->shape->print(); // 한줄씩 멤버변수 출력
		tmp = tmp->next;//다음걸로
}
}
void AShapeList::drawAll(WhiteBoard* board) const {//모두그리기
	AShapeNode* tmp = new AShapeNode;//동적할당
	for (tmp = head; tmp != NULL; tmp = tmp->next) {//헤드부터 하나씩, NULL이 아닐때 까지
		tmp->shape->draw(board);
	}
}
int AShapeList::getSize() const {//사이즈 출력
	return size;
}
