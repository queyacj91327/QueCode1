// Arrangement.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "selfhead.h"

void arraytest(vector<int> nums)
{	
	int b=0;
	nums[0]=b;
}

void permutation(vector<vector<int> > &res,vector<int> num,int start) {
	if (start == num.size()) {
		res.push_back(num);
		return;
	}
	for (int i = start;i < num.size();i++) {
		if (start != i && num[start] == num[i]) continue;
		swap(num[start],num[i]);
		permutation(res,num,start + 1);
		//swap(num[start],num[i]);
	}
}
vector<vector<int> > permuteUnique(vector<int> &nums) {
	vector<vector<int> > result;
	permutation(result,nums,0);
	return result;
}


int _tmain(int argc, _TCHAR* argv[])
{
	vector<int> nums;
	vector<vector<int> > res;
	nums.push_back(1);
	nums.push_back(2);
	nums.push_back(2);
	nums.push_back(4);

	int tem[2];
	res=combination(res,nums,nums.size(),2,tem,2);
	res=permute(nums);
	return 0;
}
vector<vector<int>>combination(vector<vector<int>> &vec,vector<int> &nums,int all,int part,int tem[],int count)//组合函数（假设所有元素都不相同）
{
	for(int i=all;i>=part;i--)
	{
		tem[part-1]=i-1;
		if(part==1)
		{
			vector<int> arr;
			for(int i=0;i<count;i++)
			{
				arr.push_back(nums[tem[i]]);
			}
			vec.push_back(arr);
		}
		else
		{
			combination(vec,nums,i-1,part-1,tem,count);
		}		
	}
	return vec;
}

void Sort(vector<int>&arrays)
{
	int count=arrays.size();
	for(int i=0;i<count;i++)
	{
		for(int j=0;j<i;j++)
		{
			if(arrays[i]==arrays[j])
			{
				int tem=j+1;
				while((tem<i)&&(arrays[tem]==arrays[i]))
				{
					tem++;
				}
				swap(arrays[i],arrays[tem]);
			}
		}
	}
}
vector<vector<int>> permute(vector<int> &nums) 
{
	vector<int> vec;
	vector<vector<int>> vet;
	if(nums.size()!=0)
	{
		int start=0;
		int end=nums.size()-1;
		return arrangnment(start,end,nums,vet);
	}
	else
	{
		vet.push_back(vec);
		return vet;
	}
}
void swap(int &a,int &b)
{
	int tem;
	tem=a;
	a=b;
	b=tem;
}
vector<vector<int>> arrangnment(int start,int end,vector<int> nums,vector<vector<int>> &vet)
{
	for(int i=start;i<=end;i++)
	{
		if(start==end)
		{vet.push_back(nums);}
		else
		{
			if((nums[i]==nums[start])&&(i!=start))
			{
				continue;
			}
			swap(nums[i],nums[start]);
			arrangnment(start+1,end,nums,vet);
			//swap(nums[i],nums[start]);
		}
	}
	return vet;
}





