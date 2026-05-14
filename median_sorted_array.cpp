#include <iostream>
#include <vector>
#include <cstddef>
using namespace std;


class Solution{
public:

	void swap(int& a, int& b){
		int t = a;
		a = b;
		b =t;
	}

	int partition(vector<int>& array, int low, int high){
		int pivot = array[high];
		int i = low-1;
		for(int j = low;j<high;j++){
			if(array[j] <= pivot){
				i++;
				swap(array[i], array[j]);
			}
		}
		swap(array[i+1], array[high]);
		return (i+1);
	}

	void quicksort(vector<int>& array, int low, int high){
		if(low<high){
			int pi = partition(array, low, high);
			quicksort(array, low, pi-1);
			quicksort(array, pi+1, high);
		}
	}

	double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2){
		nums1.insert(nums1.end(), nums2.begin(), nums2.end());

		if(!nums1.empty()){
			this->quicksort(nums1, 0,nums1.size()-1);
		}

		int n =nums1.size();
		if(n==0) return 0;

		if(n%2!=0){
			return (double)nums1[n/2];
		}else{
			return (nums1[(n-1)/2] + nums1[n/2])/2.0;
		}
	}
};

int main(void){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	Solution sol;

	vector<int> values_1 = {1,2,3,4,5};
	vector<int> values_2 = {6,7,8,9};
	double median = sol.findMedianSortedArrays(values_1, values_2);
	cout << "the median is: " << median << "\n";
	return 0;
}