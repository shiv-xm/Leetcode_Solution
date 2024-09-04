class Solution:
    def robotSim(self, commands: list[int], obstacles: list[list[int]]) -> int:
        dirs = ((0, 1), (1, 0), (0, -1), (-1, 0))  # Directions: North, East, South, West
        ans = 0
        d = 0  # Initial direction: North
        x = 0  # Starting x position
        y = 0  # Starting y position
        obstaclesSet = set(tuple(obstacle) for obstacle in obstacles)  # Convert obstacles to a set of tuples

        for c in commands:
            if c == -1:
                d = (d + 1) % 4
            elif c == -2:
                d = (d + 3) % 4
            else:
                for _ in range(c):
                    new_x = x + dirs[d][0]
                    new_y = y + dirs[d][1]
                    if (new_x, new_y) in obstaclesSet:
                        break
                    x, y = new_x, new_y

            ans = max(ans, x * x + y * y)

        return ans
