package __Java;

public class solver {
    int[][] starting; // 0 is nothing, 1 is barrier, 2 is block, 3 is target

    public solver(int[][] g) {
        // get starting configuration
        starting = g;
    }

    public static void main(String[] args) {
        //
    }

    // backtracking solution
    boolean solve(final int col) {
        // If all queens are placed return true
        if (col == N) {
            return true;
        }

        // Just look at this column, loop through rows
        for (int i = 0; i < N; i++) {
            if (isSafe(i, col)) {
                // Place queen and see if it results in a solution
                board[i][col] = true;
                if (solve(col + 1) == true) {
                    return true;
                }
                // If it doesn't result in solution, backtrack and try next queen
                board[i][col] = false;
            }
        }

        // If queen can't be placed anywhere in this column, return false; no solution
        return false;
    }
}