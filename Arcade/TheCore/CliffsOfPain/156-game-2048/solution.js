function solution(grid, path) {
  const directions = ['L', 'D', 'R', 'U'];

  for (direction of path) {
    for (i = 0; i < 4; i++) {
      if (directions[i] == direction) {
        grid = grid.map((row, y) =>
          row.map(
            (_, x) =>
              +row
                .filter((a) => a)
                .join(' ')
                .replace(/\b(\d+) \1\b/g, (a, b) => b * 2)
                .split(' ')[x] || 0
          )
        );
      }
      grid = grid.map((_, x) => grid.map((_, y) => grid[3 - y][x]));
    }
  }
  return grid;
}
