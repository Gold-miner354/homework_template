#include<stdlib.h>
#include<stdio.h>
#include<time.h>

int n;//物品数量

int max(int a,int b){//寻找最大值 
   if(a>=b)
        return a;
   else 
        return b;
}
 
int KnapSackDP(int weight[],int value[],int C){//动态规划算法 
	int m[n+1][C+1];//前i个物品装入容量为j的背包中获得的最大价值
	int i,j;//计数器 
    for(i=0;i<=n;i++)//初始化
        m[i][0]=0;
    for(j=0;j<=C;j++)
        m[0][j]=0;
    for(i=1;i<=n;i++){
        for(j=1;j<=C;j++){
            if(j<weight[i-1])//无法装 
				m[i][j]=m[i-1][j];
            else//可以装 
                m[i][j]=max(m[i-1][j],m[i-1][j-weight[i-1]]+value[i-1]);	
		}
	}
        return m[n][C];
}

void RandFunc(int range,int n,int ran[]){//随机数生成算法 
    int i;
    srand((unsigned)time(NULL));
    for(i=0;i<n;i++){
        ran[i]=rand()%range+1;
    }
}

int main(){
    int C,i,V,MAX;//背包最大容量、计数器、单个物品最大价值、总的最大价值 
	int choice;//选择手动输入或者随机生成 
    clock_t Start,End;//记录起始时间 
    
    printf("请输入背包的最大容量:\n");
    scanf("%d",&C);
    printf("请输入物品数:\n");
    scanf("%d",&n);
    printf("请输入单个物品最大价值:\n");
    scanf("%d",&V);
    int weight[n],value[n];//重量和价值数组 
    printf("请选择手动输入或者随机生成，手动输入请按1，否则按0\n");
	scanf("%d",&choice); 
	if(choice){//手动输入 
		for(i=0;i<n;i++){
			printf("请输入第%d个物品的重量:\n",i+1);
			scanf("%d",&weight[i]);
			printf("请输入第%d个物品的价值:\n",i+1);
        	scanf("%d",&value[i]);
		}
	}
	else{//随机生成 
		RandFunc(C,n,weight);
        RandFunc(V,n,value);
        for(i=0;i<n;i++)
        	printf("第%d个物品的重量为%d,价值为%d\n",i+1,weight[i],value[i]);
	}
	Start=clock();
    MAX=KnapSackDP(weight,value,C);  //获得的最大价值
    End=clock();
    printf("背包所能获得最大物品价值为:%d\n",MAX);
  	printf("程序执行时间为:%ld毫秒\n",End-Start);
  	
    return 0;
}