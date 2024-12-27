/**
 *  hackerrank question:
 *  
 *   sorting the triangle based on its area (using Heron'S formula)
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct triangle
{
	int a;
	int b;
	int c;
};

typedef struct triangle triangle;

void sort_by_area(triangle* tr, int n) {
    float* area = (float*)malloc(n * sizeof(float)); // Dynamic allocation for array
    float s;

    // Calculate areas
    for (int i = 0; i < n; i++) {
        s = (float)(tr[i].a + tr[i].b + tr[i].c) / 2;

        //validate whether the sides form a triangle 
        if (tr[i].a + tr[i].b > tr[i].c && tr[i].a + tr[i].c > tr[i].b && tr[i].b + tr[i].c > tr[i].a) {
            area[i] = sqrt(s * (s - tr[i].a) * (s - tr[i].b) * (s - tr[i].c));
        } else {
            area[i] = 0; 
        }
    }

    // Bubble Sort by area
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (area[j] > area[j + 1]) {
                // Swap triangles
                triangle temp = tr[j];
                tr[j] = tr[j + 1];
                tr[j + 1] = temp;

                // Swap corresponding areas
                float tempArea = area[j];
                area[j] = area[j + 1];
                area[j + 1] = tempArea;
            }
        }
    }

    free(area); // Free the dynamically allocated memory
}

int main()
{
	int n;
	scanf("%d", &n);
	triangle *tr = malloc(n * sizeof(triangle));
	for (int i = 0; i < n; i++) {
		scanf("%d%d%d", &tr[i].a, &tr[i].b, &tr[i].c);
	}
	sort_by_area(tr, n);
	for (int i = 0; i < n; i++) {
		printf("%d %d %d\n", tr[i].a, tr[i].b, tr[i].c);
	}
	return 0;
}
