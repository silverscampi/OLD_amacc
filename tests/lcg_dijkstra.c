// lcg based on https://is.gd/rLyhFQ
// dijkstra based on https://www.codewithc.com/dijkstras-algorithm-in-c/
// strrev from https://stackoverflow.com/a/29408476 
// kr_strlen from K&R, apparently

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// global constants
int N;
int INFINITY;
int LOW;
int HIGH;
int MULT;
int MOD;
int SEED;
int X;


int kr_strlen(char *s) {
	char *p = s;
	while (*p != '\0')
		p++;
	return ((int) p - (int) s);
}

char *strrev(char *str) {
	if (!str || ! *str)
		return str;

	int i = kr_strlen(str) -1;
	int j = 0;
	char ch;
	while (i > j) {
		ch = str[i];
		str[i] = str[j];
		str[j] = ch;
		i--;
		j++;
	}
	return str;
}

// the worst prng you've ever seen
int lcg_gen(int low, int high) {
	//printf("X: %d\tMULT: %d\tMOD: %d\tLOW: %d\tHIGH: %d\n", X, MULT, MOD, LOW, HIGH);
	X = (X*MULT+1) % MOD;
	int res = (X * (HIGH-LOW));
	res /= MOD;
	//res *= (high-low);
	res += low;
	return res;
	
}

int dijkstra(int *cost, int source, int target) {
		char *path;
		int *dist, *prev, *selected;
		int i, m, min, start, d, j;
		if(!(path = malloc(N * sizeof(char)))) {
			printf("failed to malloc path!\n");
			exit(1);
		}
		if(!(dist = malloc(N * sizeof(int)))) {
			printf("failed to malloc dist!\n");
			exit(1);
		}
		if(!(prev = malloc(N * sizeof(int)))) {
			printf("failed to malloc prev!\n");
			exit(1);
		}
		if(!(selected = malloc(N * sizeof(int)))) {
			printf("failed to malloc selected!\n");
			exit(1);
		}

		int n;
		for (n=0; n<N; ++n) {
			selected[n] = 0;
		}

		for (i=1; i<N; ++i) {
			dist[i] = INFINITY;
			prev[i] = -1;	
		}

		start = source;
		selected[start] = 1;
		dist[start] = 0;
		
		while(selected[target] == 0) {
			min = INFINITY;
			m = 0;
			for (i=1; i<N; ++i) {
				d = dist[start] + *(cost + start*N + i);
				if (d<dist[i] && selected[i]==0) {
					dist[i] = d;
					prev[i] = start;
				}
				if (min>dist[i] && selected[i]==0) {
					min = dist[i];
					m = i;
				}
			}
			start = m;
			selected[start] = 1;
		}
		start = target;
		j = 0;
		while (start != -1) {
			path[j++] = start + 65;
			start = prev[start];
		}		
		path[j] = '\0';
		strrev(path);
		printf("%s", path);

		free(path);
		free(dist);
		free(prev);
		free(selected);

		return dist[target];	
}


int main() {

	N 		 = 100;
	INFINITY = 0x7FFFFFFF;
	LOW 	 = 100;
	HIGH 	 = 1000;
	MULT 	 = 30597;
	MOD 	 = 53777;
	SEED 	 = 123456789;
	X = (SEED*MULT+1) % MOD;

	int *cost;
	int i, j, w, ch, co;
	int source, target, x, y;
	if (!(cost = malloc(N * N * sizeof(int)))) {
		printf("failed to malloc cost!\n");
		exit(1);
	}

	for (i=1; i<N; i++) {
		for (j=1; j<N; j++) {
			*(cost + i*N + j) = INFINITY;
		}
	}

	for (x=1; x<N; x++) {
		for (y=x+1; y<N; y++) {
			int gend = lcg_gen(LOW, HIGH);
			printf("lcg_gen: %d\n", gend);
			*(cost + x*N + y) = *(cost + y*N + x) = gend;
		}
	}

	source = 2;
	target = 86;
	co = dijkstra(cost, source, target);
	printf("Shortest path from node %d to node %d costs %d.\n\n", source, target, co);

	source = 23;
	target = 47;
	co = dijkstra(cost, source, target);
	printf("Shortest path from node %d to node %d costs %d.\n\n", source, target, co);

	source = 52;
	target = 55;
	co = dijkstra(cost, source, target);
	printf("Shortest path from node %d to node %d costs %d.\n\n", source, target, co);
	
	source = 1;
	target = 99;
	co = dijkstra(cost, source, target);
	printf("Shortest path from node %d to node %d costs %d.\n\n", source, target, co);

	source = 12;
	target = 19;
	co = dijkstra(cost, source, target);
	printf("Shortest path from node %d to node %d costs %d.\n\n", source, target, co);
	
	free(cost);
	return 0;
}
