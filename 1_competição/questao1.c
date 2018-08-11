#include <stdio.h>
#include <stdlib.h>


int main() {
	
	int m, n, i, j, count;

	scanf("%d %d",&n, &m);
	
	int vet[n];
	i = n;
	j = m;
	count = 0;
	

	while ( i >= 1 && i <= 100 && i != 0 && i != 0) 
	{
		
		scanf("%d %d", &i, &j);
		
		if (count < m) {
			vet[count] = i;
			vet[count + 1] = j;
		}
		
		count++;
	}
	
	for (int count = 0; count < n; count++) {
		printf("%d ", vet[count]);
	}
	
	return 0;
}
