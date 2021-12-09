#include <iostream>
#include <fstream>
#include <string>
#include<vector> 
using namespace std;

int r_size = 0;
int c_size = 0;

int R_size() {			//열 개수
	ifstream fin;
	fin.open("test.txt"); // 파일 open
	char c;
	int count = -1;
	while (true)
	{
		fin.get(c);
		if (fin.fail())
		{
			break;
		}
		if (c == '{' ) {	 // '{' 개수 -1로 계산
			{
				count++;
			}
		}
	}
	return count;
	fin.close();
}

int C_size() {		//행 개수
	ifstream fin;
	fin.open("test.txt"); // 파일 open
	char c;
	int count = 0;
	while (true)
	{
		
		fin.get(c);
		if (fin.fail())
		{
			break;
		}
		if (c == '0' || c == '1' || c == 'x' || c == 'e') {	// 전체 개수에서 열 개수 나누어서 계산
			{
				count++;
			}
		}
	}
	return count;
	fin.close();
}

int main() {
	r_size = R_size(); //행 개수
	c_size = C_size()/r_size; // 열 개수
	vector< vector<int>> maze(r_size, vector<int>(c_size,0));

	ifstream fin;
	fin.open("test.txt"); // 파일 open
	char c;
	int row = 0;
	int col = 0;	//maze배열의 row, col값 초기화
	while (true)
	{
		fin.get(c);
		if (fin.fail())
		{
			break;
		}
		if (c == '0' || c == '1' || c == 'x' || c == 'e') {	// 0은 열린부분, 1은 막힌부분, x는 출구, e는 입구
			{
				maze[row][col] = c;
				col++; if (col == c_size) { col = 0; row++; } // 0이나 1값을 받을 때 마다 col 값을 증가시키고 다음 열로 넘어가야 하면 col값 증가
			}
		}
	}
	fin.close();


	for (int i = 0; i < r_size; i++) {
		for (int j = 0; j < c_size; j++) {
			cout << (char)maze[i][j];
		}
		printf("\n");
	}
	
	return 0;

}