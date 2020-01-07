/*
 * =====================================================================================
 *
 *       Filename:  segmenttree.c
 *
 *    Description:  get sum on range and update
 *
 *        Version:  1.0
 *        Created:  Thursday 28 February 2019 03:25:36  IST
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (),
 *   Organization:
 *
 * =====================================================================================
 */
#include <stdlib.h>
#include<stdio.h>
long long int segtree[100003];
long long int buildseg(long long int ar[],int l,int r,int idx);
long long int buildseg(long long int ar[],int l,int r,int idx)
{	if(l==r)
	{
		segtree[idx]=ar[l];
		return segtree[idx];
	}
	else
	{
		segtree[idx]=buildseg(ar,l,(l+r)/2,2*idx+1)+buildseg(ar,(l+r)/2+1,r,2*idx+2);
		return segtree[idx];
	}

}
long long int getsum(int l,int r,int idx)
{

}
int main()
{
	long long int ar[100003];
	int n;
	scanf("%d",&n);
	for(int kk=0;kk<n;++kk)
	{
		scanf("%lld",&ar[kk]);
	}
	buildseg(ar,0,n-1,0);
	for(int kk=0;kk<2*n-1;++kk)
	{
		printf("%lld ",segtree[kk]);
	}
	return 0;
}
