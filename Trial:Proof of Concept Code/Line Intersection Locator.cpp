//
//  Line Intersection Locator.cpp
//  
//
//  Created by Brendan Wheeldon on 12/14/16.
//
//

#include <stdio.h>
#include <iostream>

//  Create Struct to store expression info
struct linExpr
{
    float co;       //The coefficient of the term with a degree of 1
    float k;        //The constant (coefficient of term with degree 0)
};

float x;        //These will be the x and y coordinates of the intersection point
float y;

int main()
{
    
    //  Creating two expressions simply for testing process
    linExpr left;
    linExpr right;
    
    left.co = 4;        //These values simulate the expressions 2x+5 and 3x+1
    left.k = 5;         //This will find the intersection of y=2x+5 and y=3x+1
    right.co = 2;
    right.k = 0;
    //  In a real program, these values would be obtained through other function calls
    
    float leftCoefficient = left.co;  //These two variables are used later to find the y coordinate
    float leftConstant = left.k;      //They will not be changed in calculation
    
    std::cout << "The intersection of y = " << left.co << "x + (" << left.k << ") and y = "
              << right.co << "x + (" << right.k << ") is ";
    
    if ((left.k == right.k) && (left.co != right.co))
    {                   //Because these expressions represent lines in slope-intercept form,
        x = 0;          //the constants are y-intercepts.
    }                   //If the y-intercepts are equal, but the slopes are not, then the intersection would be at x = 0
    else
    {
        if (left.co > right.co)     //If the left coefficient is bigger,
        {
            left.co -= right.co;    //subtract the right x term from both sides
            right.co = 0;           
        }
        else if (left.co < right.co)//If the right coefficient is bigger,
        {
            right.co -= left.co;    //subtract the left x term from both sides
            left.co = 0;
        }
        else                        //If the coefficients are equall, the slopes are the same.
        {
            if (left.k == right.k)  //If the constants are also equall,
            {
                std::cout << "the entirety of the line." << std::endl;   //they are the same line.
            }
            else                    //If the constants are not equal,
            {
                std::cout << "non-existent." << std::endl; //They are parallel lines, that never intersect
            }
            return 0;               //Purely for this test. Would normally be handled differently.
        }
        if (left.co == 0)           //If the left coeffiecient was made to be zero,
        {
            left.k -= right.k;      //then put the constant on the left
            right.k = 0;
        }
        else                        //One coefficient is guaranteed to be zero, so if right = 0,
        {
            right.k -= left.k;      //then put the constant on the right
            left.k = 0;
        }
                                //We already checked if the constants were equall, so no need to do that.
    
        float dividend = ((left.co == 0) ? right.co : left.co); //We will divide by the non-zero coefficient
        left.co /= dividend;
        right.co /= dividend;           //To avoid more if statements
        left.k /= dividend;             //Simply divide all terms by dividend
        right.k /= dividend;            //Terms = to 0 will remain 0, so no harm done
    
        x = ((left.k == 0) ? right.k : left.k);      //x = the non-zero constant. It is inside the brackets incase it was = 0.
    }
    
    y = (leftCoefficient * x) + leftConstant;   //Plug in x to one of the functions
    
    std::cout << "(" << x << "," << y << ")" << std::endl;  //Display for debugging
    
};