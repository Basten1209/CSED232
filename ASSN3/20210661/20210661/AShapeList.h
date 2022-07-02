#pragma once
#include "AShape.h"
#include "WhiteBoard.h"

    struct AShapeNode {  //AShape를 담는 링크드리스트 노드
        AShape* shape;
        AShapeNode* next;
    };

    class AShapeList { //ASHapeList class : AShapeNode로 링크드리스트 구현, 추가, 삭제 등 진행. 함수 설명은 cpp 파일에서.
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
