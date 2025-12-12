#include <iostream>
#include <vector>
using namespace std;
class LearnHeapSort {
public:
	
	void static Pub_Heapify(vector<int>& arr , int n , int i) {
		// Kh?i t?o largest là g?c (root)
		int largest = i;
		// Kh?i t?o các nút con bên trái (left) và bên ph?i(right);
		int l = 2 * i + 1;
		int r = 2 * i + 2;

		// ki?m tra giá tr? l và r;
		if (l < n && arr[l] > arr[largest]) {
			largest = l;
		}
		if (r < n && arr[r] > arr[largest]) {
			largest = r;
		}

		// N?u largest không ph?i là g?c thì  swap;
		if (largest != i) {
			swap(arr[largest], arr[i]);
			// ?? quy cho cây con b? ?nh h??ng;
			Pub_Heapify(arr, n, largest);
		}

		
	}

	void static Pub_HeapSort(vector<int>& arr) {
		int n = arr.size();
		
		// Xây d?ng max heap; n có ngh?a là 0 > n/2 - 1 chính là các nút cha t? ?ó b? qua các nút lá ?
		for (int i = n / 2 - 1; i >= 0; i-- ) {
			Pub_Heapify(arr, n, i);
		}

		// L?n l??t hoán ??i ph?n t? h?n nh?t là g?c và ph?n t? cu?i cùng trong m?ng;

		for (int i = n - 1; i > 0; i--) {
			swap(arr[0] , arr[i]);

			// G?i l?i Heapfy ?? ???c max heap ?ã gi?m kích th??c.
			Pub_Heapify(arr , i , 0);
		}
	}
};
int main() {
	vector<int> arr = { 10 , 20 , 1000 , 60 , 1299  , 30 };
	LearnHeapSort::Pub_HeapSort(arr);
	for (int x : arr) cout << x << " ";
	return 0;
}