/**
 @file grid.h
 @author Alden Perrine
 sudoku_dancing_links

 Created by Alden Perrine on 1/23/17.
 Copyright © 2017 Alden Perrine. All rights reserved.
 
 The grid object holds all of the necessary methods and
 data structures to input and solve the sudoku.
 The main data structure used is a 2D spare array of data
 objects that are dynamically allocated and set to point to
 each other, with the rest of the pointers set to nullptr.
 An array of columns is also held and linked to the data 
 matrix to allow the cover and uncover functions access to 
 the matrix.
 The column array is accessed through a special column object
 held by the grid called header. The header only uses its right
 and left pointers, respecively pointing to the beginning and 
 the end of the column array when the grid is initialized.
 The ouput array contains pointers that will be set during the
 recursion that point to members in the data matrix. Each pointer
 points to one of the members in each row, but as the row is the
 same for all pointers in each row it is irrelavent which object
 is pointed to in the output array. A size variable is also held
 within the grid object.
 Finally the maximum rows and the maximum columns for the data 
 matrix are held as constant variables.
 */
#ifndef grid_h
#define grid_h


class grid
{
public:
    grid();
    ~grid();
    bool search();
private:
    // Member structs
    
    struct column;
    
    /* data struct
     Each data object contains pointers to the next initialized
     data member to the right, left, up, and down directions in
     the larger matrix.
     In addition, a pointer to the columns that the data object
     corresponds to and an integer representing the row that
     the object is in.
     */
    struct data
    {
    public:
        data* right;
        data* left;
        data* up;
        data* down;
        column* col;
        int row;
    };
    
    /* column struct
     The columns class is a subclass of the data object, and
     has the same corresponding left, right, up and down pointers
     to data objects. However the left and right pointers will
     only point to column objects and the column pointer will
     point to itself.
     In addition the column pointer contains 2 integers, a size
     variable that keeps track of how many data objects are in
     its column and a name fow which column it is
    */
    struct column: public data
    {
    public:
        int size;
        int name;
    };
    
    // Member functions
    void print();
    void initMatrix();
    void parseInput(int n, int r, int c);
    void askUser();
    void coverClue(data* d);
    void coverCol(column*c);
    void uncoverCol(column* c);
    column* findSmallest();
    
    // Member variables
    data** output;
    data*** matrix;
    column** columns;
    column header;
    int size;
    
    // Member constants
    const int MAX_ROWS = 729;
    const int MAX_COLS = 324;
};

#endif /* grid_h */
