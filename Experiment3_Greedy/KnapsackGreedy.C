#include<stdlib.h>
#include<stdio.h>
#include<time.h>

void RandFunc(int range,int n,int ran[]){随机数生成
    int i;
    srand((unsigned)time(NULL));
    for(i=1;i<=n;i++){
        ran[i]=rand()%range+1;
    }
}

void swap(int *a,int* b){//交换 
    int temp;
    temp=*a;
    *a=*b;
    *b=temp;
}

void Sort(int n,int *w,int *v){//排序
    int i,j;
    float temp1,temp2;
    for(i=1;i<=n;i++){
        for(j=i;j<=n;j++){//冒泡排序
            temp1=(float)v[j]/(float)w[j];
            temp2=(float)v[j+1]/(float)w[j+1];
            if(temp1<temp2){
                swap(&w[j],&w[j+1]);
                swap(&v[j],&v[j+1]);
            }
        }
    }
}

int main(){
    int V,n,C,i;//单个物品最大价值、物品数量及背包容量;计数器 
    int choice;//选择 
    float left;//剩余空间 
    double Start,End;       //起始时间和结束时间

    printf("请输入物品的个数\n");
    scanf("%d",&n);
    printf("请输入单个物品最大价值\n");
    scanf("%d",&V);
    printf("请输入背包容量\n");
    scanf("%d",&C);
    int w[n+1],v[n+1];//记录物品的重量与价值
    float c[n+1],MAX=0;//物品放入比例和背包所能装入的最大价值
    for(i=0;i<=n;i++) c[i]=0;//初始化解向量
    printf("若手动输入数据请输入1，否则输入0生成随机数\n");
    scanf("%d",&choice);
    if(choice){
    	for(i=1;i<=n;i++){
            printf("请输入第%d个商品的重量\n:",i);
            scanf("%d",&w[i]);
            printf("请输入第%d个商品的价值:",i);
            scanf("%d",&v[i]);
        }
	}
	else{
		RandFunc(C,n,w);
        RandFunc(V,n,v);
	}
    Start=(double)clock();
    Sort(n,w,v);
    left=(float)C;
    for(i=1;i<=n;i++){//计算剩余空间 
        if((float)w[i]>left) break;
        c[i]=1;
        left-=(float)w[i];
    }
    if(i<=n) c[i]=left/w[i];
    End=(double)clock();
    for(i=1;i<=n;i++){
        printf("质量为%d,价值为%d的物品放入比例为:%.2f\n",w[i],v[i],c[i]);
        MAX+=(float)v[i]*c[i];
    }
    printf("最大价值为%.2f\n",MAX);
    printf("程序的时间为%.4f毫秒\n",End-Start);
    
    return 0;
}