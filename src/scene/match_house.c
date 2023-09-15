#include "match_house.h"

mapping_idx match_board(float x, float y){
    mapping_idx ans;

    if(x >= 55 && x <= 137) ans.i = 0;
    else if(x >= 144 && x <= 220) ans.i = 1;
    else if(x >= 231 && x <= 310) ans.i = 2;
    else if(x >= 317 && x <= 390) ans.i = 3;
    else if(x >= 406 && x <= 482) ans.i = 4;
    else if(x >= 491 && x <= 568) ans.i = 5;
    else if(x >= 577 && x <= 654) ans.i = 6;
    else if(x >= 667 && x <= 748) ans.i = 7;
    else ans.i = 8;

    if(y >= 63 && y <= 137) ans.j = 0;
    else if(y >= 147 && y <= 220) ans.j = 1;
    else if(y >= 231 && y <= 310) ans.j = 2;
    else if(y >= 317 && y <= 390) ans.j = 3;
    else if(y >= 406 && y <= 482) ans.j = 4;
    else if(y >= 491 && y <= 568) ans.j = 5;
    else if(y >= 577 && y <= 654) ans.j = 6;
    else if(y >= 667 && y <= 748) ans.j = 7;
    else ans.j = 8;

    return ans;
    
}