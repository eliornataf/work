/*****************************************************************************
* File Name: Triangle
* Written by: Elior Nataf
* Date: 9/2/21
/*****************************************************************************/

/*-----------------------------Libaries & Define-----------------------------*/

#define PARAM_OK (0)
#define SIZE_INPUT_ERROR (-1)
#define CHAR_INPUT_ERROR (-2)

#define MIN_INPUT_SIZE (4)
#define MAX_INPUT_SIZE (25)
#define MIN_INPUT_CHAR ('!')
#define MAX_INPUT_CHAR ('~')

/*--------------------------Functions declarations--------------------------*/

/* Description:
 * Draw right angle triangle to sdtout.
 * Sample (N = 4):
 * *
 * **
 * ***
 * ****
 *
 * Input:
 * Size [number of lines] -> between MIN_INPUT_SIZE - MAX_INPUT_SIZE.
 * Character [character to print] -> between MIN_INPUT_CHAR - MAX_INPUT_CHAR.
 *
 * Output:
 * PARAM_INPUT_OK - parameters input ok.
 * SIZE_INPUT_ERROR - size input error.
 * CHAR_INPUT_ERROR - character input error.
 *
 * Error: 
 * SIZE_INPUT_ERROR - size input error.
 * CHAR_INPUT_ERROR - character input error.
 */
int DrawRightAngleTriangle(int size, char ch);

/*--------------------------------------------------------------------------*/

/* Description:
 * Draw right angle triangle over turned to sdtout.
 * Sample (N = 4):
 * ****
 * ***
 * **
 * *
 *
 * Input:
 * Size [number of lines] -> between MIN_INPUT_SIZE - MAX_INPUT_SIZE.
 * Character [character to print] -> between MIN_INPUT_CHAR - MAX_INPUT_CHAR.
 *
 * Output:
 * PARAM_INPUT_OK - parameters input ok.
 * SIZE_INPUT_ERROR - size input error.
 * CHAR_INPUT_ERROR - character input error.
 *
 * Error: 
 * SIZE_INPUT_ERROR - size input error.
 * CHAR_INPUT_ERROR - character input error.
 */
int DrawRightAngleTriangleOverTurned(int size, char ch);

/*--------------------------------------------------------------------------*/

/* Description:
 * Draw isosceles triangle to sdtout.
 * Sample (N = 4):
 * *
 * **
 * ***
 * ****
 * ***
 * **
 * *
 *
 * Input:
 * Size [number of lines] -> between MIN_INPUT_SIZE - MAX_INPUT_SIZE.
 * Character [character to print] -> between MIN_INPUT_CHAR - MAX_INPUT_CHAR.
 *
 * Output:
 * PARAM_INPUT_OK - parameters input ok.
 * SIZE_INPUT_ERROR - size input error.
 * CHAR_INPUT_ERROR - character input error.
 *
 * Error: 
 * SIZE_INPUT_ERROR - size input error.
 * CHAR_INPUT_ERROR - character input error.
 */
int DrawIsoscelesTriangle(int size, char ch);

/*--------------------------------------------------------------------------*/

/* Description:
 * Draw isosceles triangle to sdtout.
 * Sample (N = 4):
 *     *
 *    * *
 *   * * *
 *  * * * *
 *
 * Input:
 * Size [number of lines] -> between MIN_INPUT_SIZE - MAX_INPUT_SIZE.
 * Character [character to print] -> between MIN_INPUT_CHAR - MAX_INPUT_CHAR.
 *
 * Output:
 * PARAM_INPUT_OK - parameters input ok.
 * SIZE_INPUT_ERROR - size input error.
 * CHAR_INPUT_ERROR - character input error.
 *
 * Error: 
 * SIZE_INPUT_ERROR - size input error.
 * CHAR_INPUT_ERROR - character input error.
 */
int DrawEquilateralTriangle(int size, char ch);

/*--------------------------------------------------------------------------*/

/* Description:
 * Draw isosceles triangle over turned to sdtout.
 * Sample (N = 4):
 *  * * * *
 *   * * *
 *    * *
 *     *
 *
 * Input:
 * Size [number of lines] -> between MIN_INPUT_SIZE - MAX_INPUT_SIZE.
 * Character [character to print] -> between MIN_INPUT_CHAR - MAX_INPUT_CHAR.
 *
 * Output:
 * PARAM_INPUT_OK - parameters input ok.
 * SIZE_INPUT_ERROR - size input error.
 * CHAR_INPUT_ERROR - character input error.
 *
 * Error: 
 * SIZE_INPUT_ERROR - size input error.
 * CHAR_INPUT_ERROR - character input error.
 */
int DrawEquilateralTriangleOverTurned(int size, char ch);

/*--------------------------------------------------------------------------*/

/* Description:
 * Draw rhombus to sdtout.
 * Sample (N = 4):
 *     *
 *    * *
 *   * * *
 *  * * * *
 *   * * *
 *    * *
 *     *
 *
 * Input:
 * Size [number of lines] -> between MIN_INPUT_SIZE - MAX_INPUT_SIZE.
 * Character [character to print] -> between MIN_INPUT_CHAR - MAX_INPUT_CHAR.
 *
 * Output:
 * PARAM_INPUT_OK - parameters input ok.
 * SIZE_INPUT_ERROR - size input error.
 * CHAR_INPUT_ERROR - character input error.
 *
 * Error: 
 * SIZE_INPUT_ERROR - size input error.
 * CHAR_INPUT_ERROR - character input error.
 */
int DrawRhombus(int size, char ch);

/*--------------------------------------------------------------------------*/
