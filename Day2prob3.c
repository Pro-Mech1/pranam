#include<stdio.h>

int main(){
    int scores[100];
    int high,low,sum=0;
    int n;
    float average;
    printf("Enter the number of match: ");
    scanf("%d",&n);
    printf("Enter the scores of %d match:\n",n);
    for (int i = 0; i < n; i++) {
        printf("Match %d: ",i+1);
        scanf("%d",&scores[i]);
    }
    high = scores[0];
    low = scores[0];
    for (int i = 0; i < n; i++) {
        if (scores[i] > high) {
            high = scores[i];
        }
        if (scores[i] < low) {
            low = scores[i];
        }
        sum += scores[i]; 
    }
    average = (float)sum / n;

    printf("High Score: %d\n", high);
    printf("Low Score: %d\n", low);
    printf("Average Score: %.2f\n", average);

    return 0;
}
