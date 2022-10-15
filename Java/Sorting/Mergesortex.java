import java.util.*;
public class Mergesortex{


public static void  merge(int a[],int low,int high,int mid)
{
		int i=low,j=mid+1,k=low;
		int b[]=new int[30];
		while(i<=mid&&j<=high)
		{
		if(a[i]<a[j])
		{
			b[k++]=a[i++];
		}
		else
		{
			b[k++]=a[j++];
		}
		}
		while(i<=mid)
		{
			b[k++]=a[i++];
		}
		while(j<=high)
		{
			b[k++]=a[j++];
		}
		for(k=low;k<=high;k++)
		{
			a[k]=b[k];
		}
	}
public static void mergesort(int a[],int low,int high)
	{
		int mid;
	if(low<high)
	{
	mid=(low+high)/2;
	mergesort(a,low,mid);
	mergesort(a,mid+1,high);
	merge(a,low,mid,high);
	}
	}



public static void main(String args[])
{
	int low,high,n,i,mid; 
	int a[]=new int[30];
	Scanner sc=new Scanner(System.in);
	System.out.println("enter n");
	n=sc.nextInt();
	for(i=0;i<n;i++)
	{
		a[i]=sc.nextInt();
	}
	mergesort(a,0,n-1);
	System.out.println("Elements after sorting");
	for(i=0;i<n;i++)
	{
		System.out.println(a[i]+" ");
	}
}
}	