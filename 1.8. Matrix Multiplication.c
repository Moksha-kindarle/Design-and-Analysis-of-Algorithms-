#include <stdio.h>
int main() {
	int r1, c1, r2, c2;
	scanf("%d %d", &r1, &c1);
	int A[r1][c1];
	for(int i = 0; i < r1; i++) {
		for(int j = 0; j < c1; j++) {
			scanf("%d", &A[i][j]);
		}
	}
//ATHARVA MUKWANE 
	scanf("%d %d", &r2, &c2);
	if(c1 != r2) {
		printf("Invalid input");
		return 0;
	}
	int B[r2][c2];
	for(int i = 0; i < r2; i++) {
		for(int j = 0; j < c2; j++) {
			scanf("%d", &B[i][j]);
		}
	}
	int result[r1][c2];
	for(int i = 0; i < r1; i++) {
		for(int j = 0; j < c2; j++) {
			result[i][j] = 0;
			for(int k = 0; k < c1; k++) {
				result[i][j] += A[i][k] * B[k][j];
			}
		}
	}
	for(int i = 0; i < r1; i++) {
		for(int j = 0; j < c2; j++) {
			printf("%d ", result[i][j]);
		}
		printf("\n");
	}
	return 0;
}
