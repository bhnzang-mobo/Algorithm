#include <stdio.h>

int main()
{
	int N, ch, cnt, n = 1, i = 666;
	scanf("%d", &N);
	N--;
	while (N)
	{
		cnt = 1;
		ch = n;
		while (ch%10 == 6)
		{
			cnt *= 10;
			ch /= 10;
		}
		for (int j = 0; j < cnt && N; j++, N--)
            i = (n / cnt) * (1000 * cnt) + (666 * cnt) + j;
		n++;
	}
	printf("%d", i);
	return 0;
}