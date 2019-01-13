#include<iostream>
#include<string>
int compare(const void* a1,const void * a2) {
	int temp_a1 = *(int*)a1;
	int temp_a2 = *(int*)a2;
	if (temp_a1 > temp_a2) {
		return -1;
	}
	else if (temp_a1 < temp_a2) {
		return 1;
	}
	else {
		return 0;
	}
}
int main() {
	int result[26];
	std::string line;
	std::cin >> line;
	for (int i = 0; i < 26; i++) {
		result[i] = -1;
	}
	for (int i = 0; i < line.length(); i++) {
		result[toupper(line[i]) - 65]++;
	}
	int max = -1;
	int temp_i = -1;
	for (int i = 0; i < 26; i++) {
		if (max < result[i]) {
			max = result[i];
			temp_i = i;
		}
	}
	
	qsort(result, 26, sizeof(int), compare);
	if (result[0] == result[1]) {
		std::cout << "?";
	}
	else {
		printf("%c",temp_i+65);
	}

	return 0;

}