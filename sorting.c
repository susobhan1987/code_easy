#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void quickSort (int arr[],int high,int low) {
    if (low < high) {
	int i,j,pivot,temp;
	i = low;
	j = high;
	pivot = i;
	while (i<j) {
		while (arr[i] < arr[pivot] && i<high)
			i++;
		while (arr[j]>arr[pivot])
			j--;
		if (i<j)
		{
			temp = arr[i];
			arr[i] = arr[j];
			arr[j] = temp;
		}
		
	}
	temp = arr[pivot];
	arr[pivot] = arr[j];
	arr[j] = temp;

	quickSort (arr,j-1,low);
	quickSort (arr,high,j+1);
    }
}

void merge (int arr[], int low, int mid, int high) {

	int temp[30];
	int i,j,k,m;
	i = low;
	j = mid+1;
	k = low;
	for (; i<= mid && j<=high;) {
		if (arr[i]< arr[j])
			temp[k++] = arr[i++];
		else
			temp[k++] = arr[j++];
	}
	while (i<=mid && j> high)
		temp[k++] = arr[i++];

	while (j<=high && i> mid)
		temp[k++] = arr[j++];

	for (i = 0; i<k; ++i)
		arr[i] = temp[i];
}

void part (int arr[], int low, int high) {

	if (low <high) {
		int mid = (low+high)/2;
		part (arr,low,mid);
		part (arr,mid+1,high);
		merge (arr,low,mid,high);
	}

}

int main () {
	int i;
 	int q_arr[] = {13,8,12,6,9,23,11,2};
 	int m_arr[] = {13,8,12,6,9,23,11,2};
 	quickSort (q_arr,7,0);
	for (i = 0;i< 8;++i)
		printf ("%d ",q_arr[i]);
 	part (m_arr,0,7);
	for (i = 0;i< 8;++i)
		printf ("%d ",m_arr[i]);

	return 0;
}
