if (grid[newRow][newCol] == 1) {
            deque.addLast(new int[]{newRow, newCol, obstacles + 1});
          //{row, col, obstacles removed}
          } else {
            deque.addFirst(new int[]{newRow, newCol, obstacles});
          }