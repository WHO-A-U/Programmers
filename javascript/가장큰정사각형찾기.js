function solution(board)
{
    let answer = Math.max(board[0][0],board[0][1],board[1][0]);
    const row = board.length,col = board[0].length;
    for(let i=1;i<row;i++){
        for(let j=1;j<col;j++){
            if(board[i][j]===1)board[i][j]+=Math.min(board[i-1][j-1],board[i-1][j],board[i][j-1]);
            answer = Math.max(answer,board[i][j]); 
        }
    }
    return answer;
}