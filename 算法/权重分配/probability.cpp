#include <stdio.h>
int main(){
    while (1)
    {
        float probability = 0;
        float Head_jifen_buf = 0;//添加中部板形积分值优化跑偏概率
        float Mid_jifen_buf = 0;//添加中部板形积分值优化跑偏概率
        float Tail_jifen_buf = 0;//添加中部板形积分值优化跑偏概率
        printf("P Head Mid Tail\n");
        scanf("%f %f %f %f",&probability,&Head_jifen_buf,&Mid_jifen_buf,&Tail_jifen_buf);
        float Mid_P,Head_P,Tail_P = 0;

        if (Head_jifen_buf <= 1.5) { Head_P = 0; }
        else if (Head_jifen_buf > 1.5 && Head_jifen_buf <= 2.5) { Head_P = 0.5; }
        else if (Head_jifen_buf > 2.5 && Head_jifen_buf <= 3.5) { Head_P = 0.8; }
        else if (Head_jifen_buf > 3.5) { Head_P = 1; }

        if (Mid_jifen_buf <= 1) { Mid_P = 0; }//头部积分值分情况给概率
        else if (Mid_jifen_buf > 1 && Mid_jifen_buf < 2) { Mid_P = 0.5; }
        else if (Mid_jifen_buf >= 2 && Mid_jifen_buf < 3) { Mid_P = 0.8; }
        else if (Mid_jifen_buf >= 3.5) { Mid_P = 1; }

        if (Tail_jifen_buf <= 1.5) { Tail_P = 0; }
        else if (Tail_jifen_buf > 1.5 && Tail_jifen_buf <= 2.5) { Tail_P = 0.5; }
        else if (Tail_jifen_buf > 2 && Tail_jifen_buf <= 3) { Tail_P = 0.8; }
        else if (Tail_jifen_buf > 3) { Tail_P = 1; }

        float new_probability = probability*0.5 + 0.5*(Mid_P*0.6 + (Head_P*0.5 + Tail_P*0.5)*0.4);
        printf("%f\n",new_probability);
    }
    
   
}
