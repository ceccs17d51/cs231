#include<stdio.h>

int quick(int a[],int l,int h){
    int piv=l,t=0;
    while (l<h){
        while (a[h]>a[piv] && h>l) h-=1;
        while (a[l]<=a[piv] && l<h) l+=1;
        if (l<h){
            t=a[l];
            a[l]=a[h];
            a[h]=t;
	}
	}
    t=a[piv];
    a[piv]=a[l];
    a[l]=t;
    return l;
}

void part(int a[],int h){	
    int l=0,j=0,s[h+1],t=1;
    s[0]=l;
    s[1]=h;
    
    while (t>=0){
        h=s[t--];
        l=s[t--];

        j=quick(a,l,h);

        if (j-1 > l){
            s[++t]=l;
            s[++t]=j-1;
	}

        if (j+1 < h){
            s[++t] = j + 1;
            s[++t] = h;
	}
    }
}

int main(){
	int a[50],i,n;
	printf("enter the no of elements:");
	scanf("%d",&n);
	printf("enter the elements");
	for(i=0;i<n;i++)
	  scanf("%d",&a[i]);
	part(a,n-1);
	for(i=0;i<n;i++)
		printf("%d ",a[i]);
	printf("\n");
	return 0;
}
