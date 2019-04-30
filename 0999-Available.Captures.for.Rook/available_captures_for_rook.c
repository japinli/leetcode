/*----------------------------------------------------------------------------
 *
 * available_captures_for_rook.c
 *   On an 8 x 8 chessboard, there is one white rook.  There also may be
 *   empty squares, white bishops, and black pawns. These are given as
 *   characters 'R', '.', 'B', and 'p' respectively. Uppercase
 *   characters represent white pieces, and lowercase characters
 *   represent black pieces.
 *
 *   The rook moves as in the rules of Chess: it chooses one of four
 *   cardinal directions (north, east, west, and south), then moves in
 *   that direction until it chooses to stop, reaches the edge of the
 *   board, or captures an opposite colored pawn by moving to the same
 *   square it occupies.  Also, rooks cannot move into the same square
 *   as other friendly bishops.
 *
 *   Return the number of pawns the rook can capture in one move.
 *
 *----------------------------------------------------------------------------
 */


int
numRookCaptures(char **board, int boardSize, int *boardColSize)
{
    int x = -1;
    int y = -1;
    int count = 0;

    for (int i = 0; i < boardSize; i++) {
        for (int j = 0; j < boardColSize[i]; j++) {
            if (board[i][j] == 'R') {
                x = i;
                y = j;
                break;
            }
        }
    }

    /* left */
    for (int i = x - 1; i >= 0; i--) {
        if (board[i][y] == 'B') {
            break;
        } else if (board[i][y] == 'p') {
            count++;
            break;
        }
    }

    /* right */
    for (int i = x + 1; i < boardColSize[y]; i++) {
        if (board[i][y] == 'B') {
            break;
        } else if (board[i][y] == 'p') {
            count++;
            break;
        }
    }

    /* up */
    for (int i = y - 1; i >= 0; i--) {
        if (board[x][i] == 'B') {
            break;
        } else if (board[x][i] == 'p') {
            count++;
            break;
        }
    }

    /* down */
    for (int i = y + 1; i < boardSize; i++) {
        if (board[x][i] == 'B') {
            break;
        } else if (board[x][i] == 'p') {
            count++;
            break;
        }
    }

    return count;
}
