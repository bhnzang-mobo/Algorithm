/*
#pragma warning(disable:4996)
#include <iostream>
#include <cassert>
#include <string.h>
using namespace std;

char arr[1001][51];
int N;
void read() {
	scanf("%d ", &N);
	for (int i = 0; i < N; i++) {
		scanf("%s", arr[i]);
	}
}
char dict[20] = { 'a', 'b', 'k', 'd', 'e', 
				'g', 'h', 'i', 'l', 'm',
				'n', 'z' ,'o', 'p', 'r',
				's', 't', 'u', 'w', 'y' };

int prio(char ch) {
	for (int i = 0; i < 20; i++) {
		if (dict[i] == ch) {
			return i;
		}
	}
	return -1;
}
int comp(const void * a, const void * b) {
	char* w1 = (char*)a;
	char* w2 = (char*)b;

	int idx1=0, idx2=0;
	int prio1, prio2;
	while (1) {
		if (idx1 >= strlen(w1)) {
			return -1;
		}
		if (idx2 >= strlen(w2)) {
			return 1;
		}
		if (idx1 < strlen(w1) - 1 && w1[idx1] == 'n') {
			if (w1[idx1 + 1] == 'g') {
				prio1 = 11;
				idx1+=2;
			}
			else {
				prio1 = prio(w1[idx1]);
				idx1++;
			}
		}
		else {
			prio1 = prio(w1[idx1]);
			idx1++;
		}

		if (idx2 < strlen(w2) - 1 && w2[idx2] == 'n') {
			if (w2[idx2 + 1] == 'g') {
				prio2 = 11;
				idx2 += 2;
			}
			else {
				prio2 = prio(w2[idx2]);
				idx2++;
			}
		}
		else {
			prio2 = prio(w2[idx2]);
			idx2++;
		}

		if (prio1 < prio2) return -1;
		if (prio1 > prio2) return 1;
	}
	return 0;
}

int main()
{
	freopen("input.txt", "r", stdin);
	read();
	qsort(arr, N, sizeof(char)*51, comp);
	for (int i = 0; i < N; i++) {
		printf("%s\n", arr[i]);
	}
}
*/
#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int cmp(const char* s1, const char* s2)
{
	char c1, c2;

	while (1) {
		/* s1, s2 문자열에서 순서대로 한글자씩 가져옵니다. */
		c1 = *s1++;
		c2 = *s2++;
		/* 한글자씩 비교하고 다르면 -1 또는 1 리턴합니다. */
		if (c1 == '\0') {
			return -1;
		}
		else if (c2 == '\0') {
			return 1;
		}

		if (c1 == 'k') {
			if (c2 == 'k') continue;
			if (c2 <= 'c') {
				return 1;
			}
			else {
				return -1;
			}
		}

		if (c2 == 'k') {
			if (c1 == 'k') continue;
			if (c1 <= 'c') {
				return -1;
			}
			else {
				return 1;
			}
		}

		//

		if (c1 == 'n' && (char)*s1 == 'g')
		{
			s1++;
			if (c2 == 'n' && (char)*s2 == 'g')
			{
				s2++;
				continue;
			}
			else {
				if (c2 >= 'o')
					return -1;
				else
					return 1;
			}
		}
		if (c2 == 'n' && (char)*s2 == 'g')
		{
			s2++;
			if (c1 == 'n' && (char)*s1 == 'g')
			{
				s1++;
				continue;
			}
			else {
				if (c1 >= 'o')
					return 1;
				else
					return -1;
			}
		}
		
		if (c1 != c2)
			return c1 < c2 ? -1 : 1;
	}
	/* 루프를 빠져나오면 두 문자열이 같다는 의미이므로 0을 리턴합니다. */
	return 0;
}
int convert_string(const void* a, const void* b)
{
	return cmp((char*)a, (char*)b);
}
int main()
{
	int N;
	freopen("input.txt", "r", stdin);
	scanf(" %d", &N);

	char s[1000][52];

	for (int i = 0; i < N; i++) {
		scanf("%s", s[i]);
	}
	qsort(s, N, sizeof(char)*52, convert_string);
	for (int i = 0; i < N ; i++)
	{
		printf("%s\n", s[i]);
	}
	return 0;
}