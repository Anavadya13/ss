#include <stdio.h>
#include <stdlib.h>
int main() {
 int n, i, totalheadmovement = 0, initial, size, move, temp;
 printf("Enter the number of requests: ");
 scanf("%d", &n);
 int rq[n];
 printf("\nEnter the request sequence: ");
 for (int i = 0; i < n; i++) {
     scanf("%d", &rq[i]); }
 printf("\nEnter the initial head position: ");
 scanf("%d", &initial);
 printf("Enter the total disk size: ");
 scanf("%d", &size);
 printf("Direction of movement 1(high) 0(low): ");
 scanf("%d", &move);
 for (int i = 0; i < n; i++) {
 for (int j = 0; j < n - i - 1; j++) {
 if (rq[j] > rq[j + 1]) {
 temp = rq[j];
 rq[j] = rq[j + 1];
 rq[j + 1] = temp; } } }
 int index = 0;
 for (int i = 0; i < n; i++) {
 if (initial < rq[i]) {
 index = i;
 break; } }
 if (move == 1) {
 for (int i = index; i < n; i++) {
     totalheadmovement += abs(rq[i] - initial);
 initial = rq[i]; }
 if (index < n) {
 totalheadmovement += abs(size - 1 - initial);
 initial = size - 1; }
 for (int i = index - 1; i >= 0; i--) {
 totalheadmovement += abs(rq[i] - initial);
 initial = rq[i]; } }
 else {
 for (int i = index - 1; i >= 0; i--) {
 totalheadmovement += abs(rq[i] - initial);
 initial = rq[i]; }
 if (index > 0) {
 totalheadmovement += abs(initial - 0);
 initial = 0; }
 for (int i = index; i < n; i++) {
 totalheadmovement += abs(rq[i] - initial);
initial = rq[i]; } }
 printf("\nTotal head movement: %d\n", totalheadmovement);
 return 0;}
