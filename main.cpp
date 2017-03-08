//
//  main.cpp
//  sudoku_dancing_links
//
//  Created by Alden Perrine on 1/23/17.
//  Copyright © 2017 Alden Perrine. All rights reserved.
//

#include "grid.h"
#include <algorithm>
int main()
{
    
    grid g;         // Create new grid object and ask for solution
    g.search();     // Find and print out solution
    return 0;
}
