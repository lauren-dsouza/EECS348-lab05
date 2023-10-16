#include <stdio.h>

void print_score_possibilities(int score) {
    for(int td2 = 0; td2*8 <= score; td2++) {
        for(int td1 = 0; td1*7 <= (score-td2*8); td1++) {
            for (int td = 0; td*6 <= (score-td2*8-td1*7); td++) {
                for (int fg = 0; fg*3 <= (score-td2*8-td1*7-td*6); fg++) {
                    for (int safety = 0; safety*2 <= (score-td2*8-td1*7-td*6-fg*3); safety++) {
                        if ((td2*8+td1*7+td*6+fg*3+safety*2)==score) {
                            printf("%d TD + 2pt, %d TD + FG, %d TD, %d 3pt FG, %d Safety\n", td2, td1, td, fg, safety);
                        }
                        
                    }
                    
                }
                
            }
            
        }
    }
}

int main() {
    int score = 2;
    while (score > 1)
    {
        printf("Enter 0 or 1 to STOP\n");
        printf("Enter the NFL score:\n");
        scanf("%d", &score);
        print_score_possibilities(score);
    }

    return 0;
}
