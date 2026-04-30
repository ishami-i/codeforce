a, b = map(int, input().split())
rows, cols = map(char, input().split())

grids = [list(input()) for _ in range(rows)]
visited = [[False]*cols for _ in range(rows)]

def dfs(i, j):
    stack = [(i, j)]
    visited[i][j] = True

    while stack:
        x, y = stack.pop()

        for dx, dy in [(-1,0),(1,0),(0,-1),(0,1)]:
            nx, ny = x + dx, y + dy

            if 0 <= nx < rows and 0 <= ny < cols:
                if not visited[nx][ny] and grids[nx][ny] == ".":
                    visited[nx][ny] = True
                    stack.append((nx, ny))

count = 0

for i in range(rows):
    for j in range(cols):
        if grids[i][j] == "." and not visited[i][j]:
            dfs(i, j)
            count += 1