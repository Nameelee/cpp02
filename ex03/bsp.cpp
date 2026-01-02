#include "Point.h"


//Vector(b-a) * Vector(point - a) > 0 : I can see 'point' 
//외적(Cross Product)의 기하학적 의미"**를 묻는 질문
//기울기(분수)를 직접 구하는 대신, 분모를 서로 곱해서(통분해서) 크기만 비교하는 과정
static Fixed getCrossProduct(Point const a, Point const b, Point const point) {
    return (b.getX() - a.getX()) * (point.getY() - a.getY()) - 
            (b.getY() - a.getY()) * (point.getX() - a.getX());
}

bool bsp(Point const a, Point const b, Point const c, Point const point) {
    Fixed ab_val = getCrossProduct(a, b, point);
    Fixed bc_val = getCrossProduct(b, c, point);
    Fixed ca_val = getCrossProduct(c, a, point);

    //과제 조건: edge나 vertex에 있는 건 false
    if (ab_val == 0 || bc_val == 0 || ca_val == 0)
        return (false);
    //bsp 함수 입장에서는 사용자가 점 A,B,C를 시계 방향으로 줄지, 반시계 방향으로 줄지 알 수가 없습니다.
    //사용자가 A→B→C 순서로 주면 **(모두 양수)**가 나옵니다.
    //사용자가 A→C→B 순서로 주면 **(모두 음수)**가 나옵니다. So all > or all < both works  
    if (ab_val > 0 && bc_val > 0 && ca_val > 0)
        return (true);

    if (ab_val < 0 && bc_val < 0 && ca_val < 0)
        return (true);
    
    return false; 
}