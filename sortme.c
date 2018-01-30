#include <stdio.h>
#include <stdlib.h>
int main(){
	int n;
	scanf("%d", &n);
	int* v = (int*)malloc(n*sizeof(int));
	//printf("Survived malloc!\n");
	for(int i=0; i<n; ++i) {
		scanf("%d", &v[i]);
	}
	for(int i=0; i<n; ++i) {
		for(int j=0; j<n-1; ++j) {
			if(v[j]>v[j+1]) {
				int temp = v[j+1];
				v[j+1] = v[j];
				v[j] = temp;
			}
		}
	}
	for(int i=0; i<n; ++i) {
		printf("%d ", v[i]);
	}
	printf("\n");
	free(v);
	fflush(stdout);
}
