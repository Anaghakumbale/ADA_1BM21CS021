#include<stdio.h>
#include<stdbool.h>
typedef struct node{
    int value;
    bool dir; //true = left,false = right 
}node;
int ismobile(node prev,node curr,node next){
        if(curr.dir==true && curr.value>prev.value){
            return 1;
        }
        else if(curr.dir==false && curr.value>next.value){
            return 2;
        }
        else{
            return 0;
        }
    }

int largestmobile(node A[],int n){
    int i=0;
    node max;
    max=A[0];
    for(i=0;i<n;i++){
        if(A[i].value>max.value && (ismobile(A[i-1],A[i],A[i+1])!=0)){
            max=A[i];
        }
    }
    for(int j=0;j<n;j++){
        if(A[j].value==max.value && A[j].dir==max.dir){
            return j;
        }
    }
}
int fact(int n){
    if(n==0 || n==1){
        return 1;
    }
    else{
        return n*fact(n-1);
    }
}
void permutation(node A[],int n){
    int lmobile;
    lmobile=largestmobile(A,n);
    node temp;
    if(ismobile(A[lmobile-1],A[lmobile],A[lmobile+1])==1){
        temp=A[lmobile];
        A[lmobile]=A[lmobile-1];
        A[lmobile-1]=temp;
    }
    else if(ismobile(A[lmobile-1],A[lmobile],A[lmobile+1])==2){
        temp=A[lmobile];
        A[lmobile]=A[lmobile+1];
        A[lmobile+1]=temp;
    }
    for(int i=0;i<n;i++){
        if(A[i].value>A[lmobile].value){
            if(A[i].dir==true){
                A[i].dir=false;
            }
            else if(A[i].dir==false){
                A[i].dir=true;
            }
        }
    }
    for(int j=0;j<n;j++){
        printf("%d ",A[j].value);
    }
}
void allperm(node A[],int n){
    for(int i=0;i<fact(n);i++){
        permutation(A,n);
        printf("\n");
    }
}

void main(){
    int m;
    node B[50];
    printf("enter number of elements\n");
    scanf("%d",&m);
    printf("enter the elements in ascending order\n");
    for(int i=0;i<m;i++){
        scanf("%d",&B[i].value);
        B[i].dir==true;
    }
    printf("the permutations are:\n");
    allperm(B,m);
}