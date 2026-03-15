#include <bits/stdc++.h>

using namespace std;

const char WALL = '#';
const char PATH = ' ';
const char VISITED = '.';
const char CURRENT = '@';
const char EXIT = 'E';

const int WIDTH = 15;
const int HEIGHT = 10;

vector<string> maze = {
    "###############",
    "#S        #   #",
    "####### # # # #",
    "#     # # # # #",
    "# ##### # # # #",
    "# #   # #   # #",
    "# #   ####### #",
    "#   #         #",
    "###############",
    "###############"
};

void printMaze() {
    cout << "\033[2J\033[1;1H"; 
    for (const string& row : maze) {
        for (char c : row) {
            if (c == '#') cout << "█"; // wall
            else if (c == '.') cout << "\033[1;34m.\033[0m"; //visited - blue
            else if (c == '@') cout << "\033[1;31m@\033[0m"; // current - red
            else if (c == 'E') cout << "\033[1;32mE\033[0m"; // exit - green
            else cout << c;
        }
        cout << endl;
    }
    this_thread::sleep_for(chrono::milliseconds(100)); 
}

bool solve(int x, int y) {
    if (x < 0 || x >= WIDTH || y < 0 || y >= HEIGHT || (maze[y][x] != ' ' && maze[y][x] != 'S' && maze[y][x] != 'E')) {
        return false;
    }
    if (maze[y][x] == 'E') return true;

    char originalChar = maze[y][x];
    maze[y][x] = CURRENT; 
    printMaze();

    maze[y][x] = VISITED; 

    
    int dx[] = {1, 0, -1, 0};
    int dy[] = {0, 1, 0, -1};

    for (int i = 0; i < 4; i++) {
        if (solve(x + dx[i], y + dy[i])) return true;
    }

    
    return false;
}

int main() {
    //start point
    int startX = 1, startY = 1;
    
    cout << "Starting DFS Visualization..." << endl;
    this_thread::sleep_for(chrono::seconds(1));

    if (solve(startX, startY)) {
        printMaze();
        cout << "\n\033[1;32mExit found!\033[0m" << endl;
    } else {
        cout << "\nNo path found." << endl;
    }

    return 0;
}