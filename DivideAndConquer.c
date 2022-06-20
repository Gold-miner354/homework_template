#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int scale1=0,scale2=0;//合并排序和快速排序的子问题规模 

void LinearCongruential(int n,int num[]){//随机数的个数和一位数组
	int count=0,X0;//计数器以及随机数的初始值 
	int a=17,c=178,m=1000;//线性同余法中的参数 
    srand((unsigned)time(NULL));//获取新的种子 
    X0=rand();//获取随机数初始值 
    for(count=0;count<n;count++){//产生所有随机数 
    	X0=(a*X0+c)%m;
    	num[count]=X0;
	}
} 

void Merge(int num[],int merge[],int left,int right,int middle,int comp[]){//根据伪码编写的合并排序算法 
	int i=left,j=middle+1;
	int k=left;
	scale1++; 
	while(i<=middle&&j<=right){
		comp[0]++;
		if(num[i]<=num[j]){
			merge[k++]=num[i++];
		}
		else{
			merge[k++]=num[j++];
		}
	}
	while(i<=middle){
		merge[k++]=num[i++];
		comp[0]++;
	}
	while(j<=right){
		merge[k++]=num[j++];
		comp[0]++;
	}
	i=0;
	for(i=left;i<=right;i++)
		num[i]=merge[i];
}


void Mergesort(int num[],int merge[],int left,int right,int comp[]){//合并排序算法
	if(left<right){
		int middle=(left+right)/2;
		Mergesort(num,merge,left,middle,comp);
		Mergesort(num,merge,middle+1,right,comp);
		Merge(num,merge,left,right,middle,comp);
    }
}

void BubbleSort(int num[],int n,int comp[]){//冒泡排序 
	int i,j,temp;
	for(i=0;i<n;i++)
		for(j=i;j<n;j++){
			comp[2]++;
			if(num[i]>num[j]){
				temp=num[j];
				num[j]=num[i];
				num[i]=temp;
			}
		}
}

int partition(int num[],int left,int right,int comp[]){//划分,将表A[left…right]划分为满足非递减的两个子表 
    int mark=num[left];
    scale2++;
	while(left<right){
		while(left<right && num[right]>=mark){
			right--;	
			comp[1]++;	
		}
		num[left] = num[right];
		while(left<right && num[left]<=mark){
			left++;	
			comp[1]++;
		}
		num[right] = num[left]; 
	}
	num[left] = mark;
	return left;
}

void quickSort(int num[],int left,int right,int comp[]){//快速排序算法 
	if(left<right){
		int mark = partition(num,left,right,comp);	//对表进行第一次划分 
		quickSort(num,left,mark-1,comp);		//对表的左半部分进行递归 
		quickSort(num,mark+1,right,comp);	//对表的右半部分进行递归递归
	}
}

void copyarray(int num1[],int num2[],int n){//复制数组 
	int count;
	for(count=0;count<n;count++)
		num2[count]=num1[count];
}

int main(){
	int n,count;
	int comp[3]={0};//分别记录三种排序方式比较次数的计数器 
	printf("请输入规模n\n");//获取规模 
	scanf("%d",&n);
	int num[n],num1[n],num2[n];//随机数数组 
	int merge[n];
	LinearCongruential(n,num);//生成随机数 
	copyarray(num,num1,n);
	copyarray(num,num2,n);
	printf("排序前的随机数为\n");
	for(count=0;count<n;count++){//输出随机数 
		printf("%d ",num[count]);
	}
	Mergesort(num,merge,0,n-1,comp); //对随机数进行合并排序 
	quickSort(num1,0,n-1,comp);//快速排序 
	BubbleSort(num2,n,comp);//冒泡排序 
	printf("\n合并排序后的随机数为\n");
	for(count=0;count<n;count++){
		printf("%d ",num[count]);
	}
	printf("\n快速排序后的随机数为\n");
	for(count=0;count<n;count++){
		printf("%d ",num1[count]);
	}
	printf("\n冒泡排序后的随机数为\n");
	for(count=0;count<n;count++){
		printf("%d ",num2[count]);
	}
	printf("\n合并排序比较次数为:%d\n快速排序比较次数为:%d\n冒泡排序比较次数为:%d",comp[0],comp[1],comp[2]);
	printf("\n合并排序的子问题规模为%d\n快速排序的子问题规模为%d\n",scale1,scale2);
	
	return 0;
}