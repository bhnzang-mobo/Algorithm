#pragma warning(disable:4996)
#include <iostream>
int arr[10];
int N, T;
int init(int num) {
	int i = 0;
	while (num) {
		arr[i++] = num % 10;
		num /= 10; // 실수 : num / 10
	}
	for (int j = 0; j < i/2; j++) {
		int tmp = arr[j];
		arr[j] = arr[i-1 - j];
		arr[i-1 - j] = tmp;
	}
	return i; //length of number
}
int calArr(int len) {
	int ret = 0, op = 1;
	for (int i = len - 1; i >= 0; i--) { // 실수 : i++ 
		ret += op * arr[i];
		op *= 10;
	}
	return ret;
}
void DFS(int idx, int len, int cnt,int *max,int *cnt_rest) {
	if (cnt <= 0) { 
		int ret = calArr(len);
		if (*max < ret) {
			*max = ret; 
			*cnt_rest = cnt;
		}
		return;
	}

	if (idx >= len) {
		int ret = calArr(len);
		if (*max < ret) {
			*max = ret;
			*cnt_rest = cnt;
		}
		return;
	}

	int digit_max = idx;

	for (int i = idx; i < len; i++) {
		if (arr[digit_max] < arr[i]) digit_max = i; // Find Maximum
	}
	if (digit_max == idx) {
		DFS(idx + 1, len, cnt, max,cnt_rest);
	}
	else {
		for (int i = idx; i < len; i++) {
			if (arr[i] == arr[digit_max]) {
				int tmp = arr[i]; //Swap
				arr[i] = arr[idx];
				arr[idx] = tmp;
				DFS(idx + 1, len, cnt - 1, max,cnt_rest);
				tmp = arr[i];//Restore Swap
				arr[i] = arr[idx];
				arr[idx] = tmp;
			}
		}
	}

}
int check(int len) {//중복된 숫자 체크
	for (int i = 0; i < len; i++) {
		for (int j = i + 1; j < len; j++) {
			if (arr[i] == arr[j]) return 1;
		}
	}
	return 0;
}
int read() {
	int num, cnt,max,cnt_rest;
	scanf("%d %d", &num, &cnt);
	cnt_rest = cnt;
	int len = init(num);
	max = calArr(len);
	DFS(0, len, cnt, &max, &cnt_rest);
	if (cnt_rest % 2 && check(len)!=1) {
		int tmp1 = max % 10;
		max /= 10;
		int tmp2 = max % 10;
		max /= 10;
		max = max * 100 + tmp1 * 10 + tmp2;
		return max;
	}
	return max;
}
int main()
{
	freopen("input.txt", "r", stdin);
	scanf("%d", &T);
	for (int i = 1; i <= T; i++) {
		printf("#%d %d\n", i, read());
	}
	return 0;
}

