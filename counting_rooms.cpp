#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    int rows, cols;
    cin >> rows >> cols;

    vector<string> grids(rows);

    for (int i = 0; i < rows; i++)
    {
        cin >> grids[i];
    }

    // directions positioning
    // for up and down
    int dr[] = {-1, 1, 0, 0};
    // for right and left
    int dc[] = {0, 0, -1, 1};

    // starting the count
    int count = 0;

    // starting the movement
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            // checking if it's rooms . then check neigboring in all four directions until get to a wall #
            if (grids[i][j] == '.')
            {
                count++;
                // marking the current position as visited by changing it to #
                grids[i][j] = '#';
                // using a stack to perform depth first search
                vector<pair<int, int>> stack;
                stack.push_back({i, j});

                while (!stack.empty())
                {
                    auto [x, y] = stack.back();
                    stack.pop_back();

                    // checking all four directions
                    for (int d = 0; d < 4; d++)
                    {
                        int newX = x + dr[d];
                        int newY = y + dc[d];

                        // checking if the new position is within bounds and is a room
                        if (newX >= 0 && newX < rows && newY >= 0 && newY < cols && grids[newX][newY] == '.')
                        {
                            // marking the new position as visited
                            grids[newX][newY] = '#';
                            // adding the new position to the stack
                            stack.push_back({newX, newY});
                        }
                    }
                }
            }
        }
    }
    cout << count << endl;
    return 0;
}