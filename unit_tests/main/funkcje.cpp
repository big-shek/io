#include <cmath>
#include <algorithm>
#include "funkcje.h"

double logarytm(int val)
{
	return log(val);
}

double odchylenie(int arr[], int len)
{
	int avg = 0;
	for (int i = 0; i < len; i++) {
		avg += arr[i];
	}
	avg = avg / len;

	int x = 0;
	for (int i = 0; i < len; i++) {
		x = x + pow(arr[i] - avg, 2);
	}

	return sqrt(x / len);
}

double eksponenta(int val)
{
	return exp(val);
}

double mediana(double arr[], int len)
{
	double median = 0;
	std::sort(arr, arr + len);
	
	if (len % 2 == 0) {
		if (len == 2) {
			median = (arr[0] + arr[1]) / 2;
		} else median = (arr[len / 2 - 1] + arr[len / 2]) / 2;
	}
	else {
		median = arr[len / 2];
	}

	return median;
}
