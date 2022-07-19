// Online C++ compiler to run C++ program online
#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int main()
{
int capacity = 5;
int arr[] = {1,8,3,4,8,1,5,8,2,1,8,3,7,8,3,8,1,8,3,9};

deque<int> q(capacity);
int count=0;
int page_faults=0;
deque<int>::iterator itr;
q.clear();
for(int i:arr)
{

	// Insert it into set if not present
	// already which represents page fault
	itr = find(q.begin(),q.end(),i);
	if(!(itr != q.end()))
	{

	++page_faults;

	// Check if the set can hold equal pages
	if(q.size() == capacity)
	{
		q.erase(q.begin());
		q.push_back(i);
	}
	else{
		q.push_back(i);

	}
	}
	else
	{
	// Remove the indexes page
	q.erase(itr);

	// insert the current page
	q.push_back(i);		
	}

}
cout<<page_faults;
}
