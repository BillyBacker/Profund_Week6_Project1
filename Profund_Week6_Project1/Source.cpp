#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int notOver2(int In) {
	if (In > 2) {
		return In % 3;
	}
	else {
		return In;
	}
}
struct Matrix
{
	float Mat[3][3] = { {0,0,0}, {0,0,0}, {0,0,0} };
	float det() {
		float Ans = 0;
		int Index_array[3] = { 0,1,2 };
		for (int i = 0; i < 3; i++) {
			float mul = 1;
			for (int j = 0; j < 3; j++) {
				mul *= Mat[j][Index_array[notOver2(j + i)]];
			}
			Ans += mul;
		}
		for (int i = 0; i < 3; i++) {
			float mul = 1;
			for (int j = 0; j < 3; j++) {
				mul *= Mat[2 - j][Index_array[notOver2(j + i)]];
			}
			Ans -= mul;
		}
		return Ans;
	}
	float* operator[](int i) {
		return Mat[i];
	}
};

int main() {
	Matrix MatO, MatA, MatB, MatC;
	float ABCD[4];
	for (int i = 0; i < 3; i++) {
		printf("From Ax+By+Cz = D\n");
		printf("Enter A B C D of equation : ");
		scanf("%f %f %f %f", &ABCD[0], &ABCD[1], &ABCD[2], &ABCD[3]);
		for (int j = 0; j < 3; j++) {
			MatO[i][j] = ABCD[j];
			MatA[i][j] = ABCD[j];
			MatB[i][j] = ABCD[j];
			MatC[i][j] = ABCD[j];
		}
		MatA[i][0] = ABCD[3];
		MatB[i][1] = ABCD[3];
		MatC[i][2] = ABCD[3];

	}
	if (MatO.det() != 0) {
		printf("\nx = %.2f, y = %.2f, z = %.2f\n", MatA.det() / MatO.det(), MatB.det() / MatO.det(), MatC.det() / MatO.det());
	}
	else {
		printf("\nAnswer Undefined\n");
	}

	return 0;
}