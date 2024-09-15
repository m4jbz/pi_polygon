#include <stdio.h>
#include <math.h>
#include "raylib.h"

#define WIDTH 680
#define HEIGHT 510
#define W_CENTER 340
#define H_CENTER 255
#define ONE 100.0F

char text[100];

double find_pi(int sides)
{
	double area_in = sides * 0.5F * sin( ((360.0F/sides)) / (180.0F/PI) );
	double area_out = sides * tan( (180.0F/sides) / (180.0F/PI) );

	return (area_in + area_out) / 2.0F;
}

double find_multiplier(int sides)
{
	double area_in = sides * 0.5F * sin( ((360.0F/sides)) / (180.0F/PI) );
	double area_out = sides * tan( (180.0F/sides) / (180.0F/PI) );

	return sqrt(area_out / area_in); 
}

void draw(int n)
{
	double pi = find_pi(n);
	double N = find_multiplier(n);
	InitWindow(WIDTH, HEIGHT, "Window");
	Vector2 polygon = {W_CENTER, H_CENTER};
	sprintf(text, "pi >> %.10lf\n", pi);

	while (!WindowShouldClose())
	{
		BeginDrawing();
		ClearBackground(BLACK);
		DrawCircleLines(W_CENTER, H_CENTER, ONE, WHITE);
		DrawPolyLines(polygon, n, ONE, 45.0F, GREEN);
		DrawPolyLines(polygon, n, ONE * N, 45.0F, BLUE);
		DrawText(text, W_CENTER+120, H_CENTER, 20, RED);
		EndDrawing();
	}

	CloseWindow();
}

int main()
{
	int n;

	printf("n\n:: ");
	scanf("%d", &n);

	if (n < 3) 
	{
		printf("No existe un poligono de 2 lados en un plano no ecluídeo.\n");
		return 1;
	}

	draw(n);

	return 0;
}
