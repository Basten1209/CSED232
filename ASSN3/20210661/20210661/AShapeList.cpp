#include <iostream>
#include "AShapeList.h"

using namespace std;

AShapeList::AShapeList() { //������
	size = 0;
	head = NULL;
	tail = NULL;
}
AShapeList::~AShapeList() { //�Ҹ���
	if (head != NULL) {
		AShapeNode* cur = head->next; //head->next�� cur�� ���, 
		while (cur != NULL) {
			AShapeNode* next = cur->next; //cur�� ������ next�� ����Ų ��
			delete cur; //cur �Ҵ� ����
			cur = next; //next�� cur�� ��Ƽ� cur �� NULL�� �ƴҶ����� �ݺ�
		} 
	}
}
void AShapeList::addNewAShape(AShape* new_shape) { //���ο� shape ����
	AShapeNode* s = new AShapeNode; //�����Ҵ�
	s->shape = new_shape; //s�� shape�� AShapenode ���
	s->next = NULL; //next�� NULL

	if (size == 0) { //���� ����Ʈ�� ���� ��
		head = s;
		tail = s;
	}
	else { //����Ʈ�� ������ �� 
		tail->next = s;
		tail = s;
	}
	size++;
}
AShapeNode* AShapeList::popNodeByIdx(int idx) { //����Ʈ���� Ư�� �ε����� �� ����
	AShapeNode* ppre = new AShapeNode; //�����Ҵ�
	AShapeNode* pcur = new AShapeNode; //�����Ҵ�
	ppre = head; //��带 ����Ŵ
	pcur = ppre->next; //����� ���� ���� ����Ŵ
	if (idx == 0) { //ù��° ��带 ���� ��
		head = ppre->next; //����� ���� ���� ��忡 ����
		size--; //������ 1 ����
		return ppre; //����
	}
	else {
		for (int i = 0; pcur != NULL; i++) { //�ݺ����� ���� ���ϴ� �ε����� �ش��ϴ� ��� ã��
			if (idx - 1 == i) {
				ppre->next = pcur->next;
				break;
			}
			ppre = ppre->next; 
			pcur = pcur->next;//��������� ������带 �����Ϸ��� ����� �������� ��ȯ
		}

		size--;//������ ����
		return pcur; //����

	}
}
const AShapeNode* AShapeList::getNodeByIdx(int idx) const {//�ε����� �´� ��� ã��
	AShapeNode* tmp = new AShapeNode; //�����Ҵ�
	tmp = head; //��带 ����Ŵ
	int check = 0;
	for (int i = 0; tmp != NULL; i++) { //�ݺ������� ���ϴ� ��� ã��
		if (idx == i) {
			break;
		}
		tmp = tmp->next; //������ �����Ѽ�

	}
	return tmp; //����
}
void AShapeList::displayAShapeList() const { //����Ʈ ��� �̴� �Լ�
	AShapeNode* tmp = new AShapeNode;
	tmp = head;

	for (int i = 0; i < size; i++) { //�����ŭ �ݺ���
		cout << i; //�ε��� ���
		tmp->shape->print(); // ���پ� ������� ���
		tmp = tmp->next;//�����ɷ�
}
}
void AShapeList::drawAll(WhiteBoard* board) const {//��α׸���
	AShapeNode* tmp = new AShapeNode;//�����Ҵ�
	for (tmp = head; tmp != NULL; tmp = tmp->next) {//������ �ϳ���, NULL�� �ƴҶ� ����
		tmp->shape->draw(board);
	}
}
int AShapeList::getSize() const {//������ ���
	return size;
}
