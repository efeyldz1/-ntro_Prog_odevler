###Istanbul University – Computer Engineering
###Introduction to Programming – Homework 2
###Tetris Rotate From File:

In this homework you are going to write rotate function of a tetris game. You have your bricks in a txt file in a 10x10
dimensioned matrix. You will catch the brick location and rotate it 90ᵒ in clockwise. For simplicity only two kinds of
bricks are going to be rotate by your algorithm. They are "L" character and the inverse of "L". From the input file
you can take 4 different combinations of this two bricks. Your algorithm must rotate the brick in clockwise and
write the result matrix In an output file in the same location of your executable file.


The input file name is “input.txt” and the output file name is “output.txt”. Your program can rotate the brick in the
output file which it produced before, if it is given as an input.

The sample input and output files are in the attachment.

Homeworks are collected by the system in our website. Any other delivery method is not going to be accepted.
While writing the code, students must obey the rules below.

   *  At the beginning of your code file there must be a comment part giving information about you, compiler
      environment of your code and any other issue need to be taken into consideration to run the code file.

    Ex:
    ```cpp
    // Özgür Can TURNA
    // 1306xxxxxx
    // Date : 28.11.2010
    // Development Enviorement : Visual Studio2010
    ```
   * The code file should be compiled either in Visual Studio 2010 or under GCC.4.xx(DEVCPP is using this also)
   * Only one code file is collected so do not try to send any other file or more than one file.
   * The code file must be named as “code.cpp”
  
    *input.txt*&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;*output.txt*<br/>
    0 0 0 0 0 0 0 0 0 0&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;0 0 0 0 0 0 0 0 0 0  <br/>
    0 0 0 1 0 0 0 0 0 0&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;0 0 0 0 0 0 0 0 0 0  <br/>
    0 0 0 1 0 0 0 0 0 0&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;0 0 0 0 0 0 0 0 0 0  <br/>
    0 0 0 1 1 0 0 0 0 0&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;0 0 0 1 1 1 0 0 0 0  <br/>
    0 0 0 0 0 0 0 0 0 0&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;0 0 0 1 0 0 0 0 0 0  <br/>
    0 0 0 0 0 0 0 0 0 0&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;0 0 0 0 0 0 0 0 0 0  <br/>
    0 0 0 0 0 0 0 0 0 0&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;0 0 0 0 0 0 0 0 0 0  <br/>
    0 0 0 0 0 0 0 0 0 0&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;0 0 0 0 0 0 0 0 0 0  <br/>
    0 0 0 0 0 0 0 0 0 0&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;0 0 0 0 0 0 0 0 0 0  <br/>
    0 0 0 0 0 0 0 0 0 0&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;0 0 0 0 0 0 0 0 0 0  <br/>



    *input_2.txt*&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;*output_2.txt*<br/>
    0 0 0 0 0 0 0 0 0 0&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;0 0 0 0 0 0 0 0 0 0  <br/>
    0 0 0 1 0 0 0 0 0 0&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;0 0 0 0 0 0 0 0 0 0  <br/>
    0 0 0 1 0 0 0 0 0 0&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;0 0 0 1 0 0 0 0 0 0  <br/>
    0 0 1 1 0 0 0 0 0 0&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;0 0 0 1 1 1 0 0 0 0  <br/>
    0 0 0 0 0 0 0 0 0 0&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;0 0 0 0 0 0 0 0 0 0  <br/>
    0 0 0 0 0 0 0 0 0 0&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;0 0 0 0 0 0 0 0 0 0  <br/>
    0 0 0 0 0 0 0 0 0 0&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;0 0 0 0 0 0 0 0 0 0  <br/>
    0 0 0 0 0 0 0 0 0 0&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;0 0 0 0 0 0 0 0 0 0  <br/>
    0 0 0 0 0 0 0 0 0 0&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;0 0 0 0 0 0 0 0 0 0  <br/>
    0 0 0 0 0 0 0 0 0 0&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;0 0 0 0 0 0 0 0 0 0  <br/>

