#include <iostream>
#include <fstream>
#include <string>
using namespace std;

const int maze_size = 6;  //maze 크기 (가로값)
char maze[maze_size][maze_size];

bool fileStream() {
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
		if (c == '0' || c == '1') {	// 0은 열린부분, 1은 막힌부분
			{
				maze[row][col] = c;
				col++; if (col == maze_size) { col = 0; row++; } // 0이나 1값을 받을 때 마다 col 값을 증가시키고 다음 열로 넘어가야 하면 col값 증가
			}
		}
	}
	fin.close();
	return 0;
}





int main() {
	fileStream();

	for (int i= 0; i < maze_size; i++) {
		for (int j = 0; j < maze_size; j++) {
			cout << maze[i][j];
		}
		printf("\n");	
	}

	return 0;

}