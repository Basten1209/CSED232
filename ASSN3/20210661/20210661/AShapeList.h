#pragma once
#include "AShape.h"
#include "WhiteBoard.h"

    struct AShapeNode {  //AShape�� ��� ��ũ�帮��Ʈ ���
        AShape* shape;
        AShapeNode* next;
    };

    class AShapeList { //ASHapeList class : AShapeNode�� ��ũ�帮��Ʈ ����, �߰�, ���� �� ����. �Լ� ������ cpp ���Ͽ���.
    private:
        AShapeNode* head;
        AShapeNode* tail;
        int size;
    public:
        AShapeList();
        ~AShapeList();
        void addNewAShape(AShape* new_shape);
        AShapeNode* popNodeByIdx(int idx);
        const AShapeNode* getNodeByIdx(int idx) const;
        void displayAShapeList() const;
        void drawAll(WhiteBoard* board) const;
        int getSize() const;
    };
