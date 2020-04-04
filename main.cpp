//
//  main.cpp
//  QueensFancyPrint
//
//  Created by Adrienne Flojo on 3/23/20.
//  Copyright © 2020 Adrienne Flojo. All rights reserved.
//

#include <iostream>
using namespace std;


void print(int q[]) {
    
    int i, j, k, l;
    
    typedef char box[5][7];
    
    box bb, wb, wq, bq, *board[8][8];
    
    //fill in bb=black box and wb=white box
    for(i = 0; i < 5; i++) {
        for(j = 0; j < 7; j++) {
            wb[i][j] = ' ';
            bb[i][j] = char(219);
        }
    }
    
    for(i = 0; i < 5; i++) {
    	for(j = 0; j < 7; j++) {
    		if(i == 1) {
    			if((j == 1) || (j == 3) || (j == 5)) {
    				wq[i][j] = ' ';
    				bq[i][j] = char(219);
    			}
    			else {
    					wq[i][j] = char(219);
    					bq[i][j] = ' ';
	   				}
    		}
    		else
    			if(i == 2) {
    				if((j > 0) && (j < 6)) {
    					wq[i][j] = ' ';
    					bq[i][j] = char(219);
    				}
    				else {
    					wq[i][j] = char(219);
    					bq[i][j] = ' ';
	   				}
    			}
    			else
    				if(i == 3) {
    					if((j > 0) && (j < 6)) {
    						wq[i][j] = ' ';
    						bq[i][j] = char(219);
    					}
    					else {
    					wq[i][j] = char(219);
    					bq[i][j] = ' ';
	   					}
    				}
    				else {
    					wq[i][j] = char(219);
    					bq[i][j] = ' ';
	   				}
    		
    	}
    }
    
    //fill board with pointers to bb and wb in alternate positions
    for(i = 0; i < 8; i++) {
        for(j = 0; j < 8; j++) {
            if((i+j)%2 == 0)
                board[i][j] = &wb;
            else
                board[i][j] = &bb;
        }
    }
    
    //fill the board with the 8 queens in their specific positions
    for(i = 0; i < 8; i++) {
    	if((q[i] + i) % 2 == 0)
    		board[q[i]][i] = &bq;
    	else
    		board[q[i]][i] = &wq;
    }
    
    
    //print the board via the pointers in array board
    
    //first print upper boarder
    cout << " ";
    for(i = 0; i < 7*8; i++)
        cout << '_';
    cout << '_';
    cout << endl;
    
    //now print the board
    for(i = 0; i < 8; i++) {
        for(k = 0; k < 5; k++) {
            cout << " " << char(179);   //print left border
            for(j = 0; j < 8; j++) {
                for(l = 0; l < 7; l++)
                    cout << (*board[i][j])[k][l];
            }
            cout << char(179) << endl;  //at the end of line
        }
    }
    
    //before exiting print lower border
    cout << " ";
    for(i = 0; i < 7*8; i++)
        cout << char(196);
    cout << endl;
	
}

int main() {
	
	int q[8] = {0, 1, 2, 3, 4, 5, 6, 7};
    
    print(q);
    
        
    
    return 0;
}
