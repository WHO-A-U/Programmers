function solution(key, lock) {
    const M = key.length;
    const N = lock.length;
    const MAP_SIZE = 2*M+N;
    const map = Array.from(Array(MAP_SIZE),()=>Array(MAP_SIZE).fill(0));
    
    for(let t=0;t<4;t++){
        for(let i=0;i<N+M-1;i++){
            for(let j=0;j<N+M-1;j++){
                initMap();
                insertKey(i,j,key);
                if(checkKeyMatchLock()===true)return true;
            }
        }
        key = rotateKey(key);
    }

    function initMap(){
        for(let i=M-1;i<M+N-1;i++){
            for(let j=M-1;j<M+N-1;j++){
                map[i][j]=lock[i-M+1][j-M+1];
            }
        }
    }

    function insertKey(row , col ,KEY){
        for(let i=row;i<row+M;i++){
            for(let j=col;j<col+M;j++){
                if(KEY[i-row][j-col]===1){
                    map[i][j]++;

                }
            }
        }
    }

    function checkKeyMatchLock(){
        for(let i=M-1;i<M+N-1;i++){
            for(let j=M-1;j<M+N-1;j++){
                if(map[i][j]!==1)return false;
            }
        }
        return true;
    }

    function rotateKey(KEY){
        let tmp = Array.from(Array(M),()=>Array(M));
        for(let i=0;i<M;i++){
            for(let j=0;j<M;j++){
                tmp[j][M-1-i]=KEY[i][j];
            }
        }
        return tmp;
    }

    return false;
}