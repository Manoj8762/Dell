#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
struct polyt {
int cf, px, py, pz;
struct polyt* next;
};
typedef struct polyt* PTR;
PTR insert(PTR poly, int cf, int px, int py, int pz) {
PTR nn = (PTR)malloc(sizeof(struct polyt));
nn->cf = cf; nn->px = px; nn->py = py; nn->pz = pz;
nn->next = poly->next;
poly->next = nn;
return poly;
}
void disp(PTR poly) {
if (poly->next == poly) {
printf("Polynomial is empty.\n");
return;
}
PTR cur = poly->next;
do {
printf("%dx^%dy^%dz^%d ", cur->cf, cur->px, cur->py, cur->pz);
cur = cur->next;
if (cur != poly) printf("+ ");
} while (cur != poly);
printf("\n");
}
int evaluate(PTR poly, int x, int y, int z) {
int result = 0;
PTR cur = poly->next;
while (cur != poly) {
int termValue = cur->cf;
termValue *= pow(x, cur->px) * pow(y, cur->py) * pow(z, cur->pz);
result += termValue;
cur = cur->next;
}
return result;
}
bool fmatch(PTR p1, PTR p2) {
return p1->px == p2->px && p1->py == p2->py && p1->pz == p2->pz;
}
PTR add(PTR poly1, PTR poly2, PTR polySum) {
PTR cur1 = poly1->next, cur2;
while (cur1 != poly1) {
polySum = insert(polySum, cur1->cf, cur1->px, cur1->py, cur1->pz);
cur1 = cur1->next;
}
cur2 = poly2->next;
while (cur2 != poly2) {
cur1 = polySum->next;
bool matchfound = false;
while (cur1 != polySum) {
if (fmatch(cur1, cur2)) {
cur1->cf += cur2->cf;
matchfound = true;
break;
}
cur1 = cur1->next;
}
if (!matchfound) polySum = insert(polySum, cur2->cf, cur2->px, cur2->py, cur2->pz);
cur2 = cur2->next;
}
return polySum;
}
int main() {
PTR poly1 = (PTR)malloc(sizeof(struct polyt)); poly1->next = poly1;
PTR poly2 = (PTR)malloc(sizeof(struct polyt)); poly2->next = poly2;
PTR polySum = (PTR)malloc(sizeof(struct polyt)); polySum->next = polySum;
poly1 = insert(poly1, 6, 2, 2, 1);
poly1 = insert(poly1, 4, 0, 1, 5);
poly1 = insert(poly1, 3, 3, 1, 1);
poly1 = insert(poly1, 2, 1, 5, 1);
poly1 = insert(poly1, 2, 1, 1, 3);
printf("POLY1(x, y, z) = "); disp(poly1);
poly2 = insert(poly2, 1, 1, 1, 1);
poly2 = insert(poly2, 4, 3, 1, 1);
printf("POLY2(x, y, z) = "); disp(poly2);
polySum = add(poly1, poly2, polySum);
printf("\nPOLYSUM(x, y, z) = "); disp(polySum);
int x = 1, y = 2, z = 3;
int res = evaluate(polySum, x, y, z);
printf("\nResult of POLYSUM(%d, %d, %d): %d\n", x, y, z, res);
return 0;
}