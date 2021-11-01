#include <stdio.h>
void rev(int * a, int* b){
    int num1 = *a;
    int num2 = *b;
    *a= (num1%10)*100+((num1%100)/10)*10+(num1/100);
    *b= (num2%10)*100+((num2%100)/10)*10+(num2/100);

}
int main(){
    int num1, num2;
    scanf("%d %d",&num1,&num2);
    rev(&num1,&num2);
    printf("%d", num1>num2 ? num1 : num2);
    return 0;
}