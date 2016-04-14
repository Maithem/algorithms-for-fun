#include <stdio.h>


void swap(int v[], int x, int y) {
 int temp = v[x];
 v[x] = v[y];
 v[y] = temp;
}

void perm (int v[], int n, int i) {
	int	j;
	if (i == n) {
		for (j=0; j<n; j++) printf ("%d ", v[j]);
		printf ("\n");
	} else
		for (j=i; j<n; j++) {
			swap (v, i, j);
			perm (v, n, i+1);
			swap (v, i, j);
		}
}

int main() {

 int arr[] = {1,2,3};

 perm(arr, 3, 0);

}
