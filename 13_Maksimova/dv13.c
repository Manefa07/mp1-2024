#include <stdio.h>
#include <locale.h>


void mat(int m[100][100], int* a, int* b) {
    setlocale(LC_ALL, "Rus");
    printf("������� ���������� �����: ");
    scanf_s("%d", a);
    printf("������� ���������� ��������: ");
    scanf_s("%d", b);

    printf("������� �������� �������:\n");
    for (int i = 0; i < *a; i++) {
        for (int j = 0; j < *b; j++) {
            scanf_s("%d", &m[i][j]);
        }
    }
}

void minrow(int m[100][100], int* a, int b) {
    int minRow = 0;
    int minel = m[0][0];

    // ������� ����������� ������� � ��� ������
    for (int i = 0; i < *a; i++) {
        for (int j = 0; j < b; j++) {
            if (m[i][j] < minel) {
                minel = m[i][j];
                minRow = i;
            }
        }
    }

    // ������� ������ � ����������� ���������
    for (int i = minRow; i < *a - 1; i++) {
        for (int j = 0; j < b; j++) {
            m[i][j] = m[i + 1][j];
        }
    }
    (*a)--; // ��������� ���������� �����
}

void vivod(int m[100][100], int a, int b) {
    printf("������� ����� ��������:\n");
    for (int i = 0; i < a; i++) {
        for (int j = 0; j < b; j++) {
            printf("%d ", m[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int m[100][100];
    int a, b;

    mat(m, &a, &b);
    minrow(m, &a, b);
    vivod(m, a, b);

    return 0;
}