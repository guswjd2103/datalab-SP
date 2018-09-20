/*
* 
 * CS:APP Data Lab 
 * 
 * <Please put your name and userid here>
 * 
 * bits.c - Source file with your solutions to the Lab.
 *          This is the file you will hand in to your instructor.
 *
 * WARNING: Do not include the <stdio.h> header; it confuses the dlc
 * compiler. You can still use printf for debugging without including
 * <stdio.h>, although you might get a compiler warning. In general,
 * it's not good practice to ignore compiler warnings, but in this
 * case it's OK.  
 */

#if 0
/*
 * Instructions to Students:
 *
 * STEP 1: Read the following instructions carefully.
 */

You will provide your solution to the Data Lab by
editing the collection of functions in this source file.

INTEGER CODING RULES:
 
  Replace the "return" statement in each function with one
  or more lines of C code that implements the function. Your code 
  must conform to the following style:
 
  int Funct(arg1, arg2, ...) {
      /* brief description of how your implementation works */
      int var1 = Expr1;
      ...
      int varM = ExprM;

      varJ = ExprJ;
      ...
      varN = ExprN;
      return ExprR;
  }

  Each "Expr" is an expression using ONLY the following:
  1. Integer constants 0 through 255 (0xFF), inclusive. You are
      not allowed to use big constants such as 0xffffffff.
  2. Function arguments and local variables (no global variables).
  3. Unary integer operations ! ~
  4. Binary integer operations & ^ | + << >>
    
  Some of the problems restrict the set of allowed operators even further.
  Each "Expr" may consist of multiple operators. You are not restricted to
  one operator per line.

  You are expressly forbidden to:
  1. Use any control constructs such as if, do, while, for, switch, etc.
  2. Define or use any macros.
  3. Define any additional functions in this file.
  4. Call any functions.
  5. Use any other operations, such as &&, ||, -, or ?:
  6. Use any form of casting.
  7. Use any data type other than int.  This implies that you
     cannot use arrays, structs, or unions.

 
  You may assume that your machine:
  1. Uses 2s complement, 32-bit representations of integers.
  2. Performs right shifts arithmetically.
  3. Has unpredictable behavior when shifting an integer by more
     than the word size.

EXAMPLES OF ACCEPTABLE CODING STYLE:
  /*
   * pow2plus1 - returns 2^x + 1, where 0 <= x <= 31
   */
  int pow2plus1(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     return (1 << x) + 1;
  }

  /*
   * pow2plus4 - returns 2^x + 4, where 0 <= x <= 31
   */
  int pow2plus4(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     int result = (1 << x);
     result += 4;
     return result;
  }

FLOATING POINT CODING RULES

For the problems that require you to implent floating-point operations,
the coding rules are less strict.  You are allowed to use looping and
conditional control.  You are allowed to use both ints and unsigneds.
You can use arbitrary integer and unsigned constants.

You are expressly forbidden to:
  1. Define or use any macros.
  2. Define any additional functions in this file.
  3. Call any functions.
  4. Use any form of casting.
  5. Use any data type other than int or unsigned.  This means that you
     cannot use arrays, structs, or unions.
  6. Use any floating point data types, operations, or constants.


NOTES:
  1. Use the dlc (data lab checker) compiler (described in the handout) to 
     check the legality of your solutions.
  2. Each function has a maximum number of operators (! ~ & ^ | + << >>)
     that you are allowed to use for your implementation of the function. 
     The max operator count is checked by dlc. Note that '=' is not 
     counted; you may use as many of these as you want without penalty.
  3. Use the btest test harness to check your functions for correctness.
  4. Use the BDD checker to formally verify your functions
  5. The maximum number of ops for each function is given in the
     header comment for each function. If there are any inconsistencies 
     between the maximum ops in the writeup and in this file, consider
     this file the authoritative source.

/*
 * STEP 2: Modify the following functions according the coding rules.
 * 
 *   IMPORTANT. TO AVOID GRADING SURPRISES:
 *   1. Use the dlc compiler to check that your solutions conform
 *      to the coding rules.
 *   2. Use the BDD checker to formally verify that your solutions produce 
 *      the correct answers.
 */


#endif
/* Copyright (C) 1991-2014 Free Software Foundation, Inc.
   This file is part of the GNU C Library.

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library; if not, see
   <http://www.gnu.org/licenses/>.  */
/* This header is separate from features.h so that the compiler can
   include it implicitly at the start of every compilation.  It must
   not itself include <features.h> or any other header that includes
   <features.h> because the implicit include comes before any feature
   test macros that may be defined in a source file before it first
   explicitly includes a system header.  GCC knows the name of this
   header in order to preinclude it.  */
/* glibc's intent is to support the IEC 559 math functionality, real
   and complex.  If the GCC (4.9 and later) predefined macros
   specifying compiler intent are available, use them to determine
   whether the overall intent is to support these features; otherwise,
   presume an older compiler has intent to support these features and
   define these macros by default.  */
/* wchar_t uses ISO/IEC 10646 (2nd ed., published 2011-03-15) /
   Unicode 6.0.  */
/* We do not support C11 <threads.h>.  */
/* 
 * bitAnd - x&y using only ~ and | 
 *   Example: bitAnd(6, 5) = 4
 *   Legal ops: ~ |
 *   Max ops: 8
 *   Rating: 1
 */
int bitAnd(int x, int y) {
	
	return ~((~x)|(~y));/* for instance, x=6=000...00110, y=5=0000...0101. then ~x is 1111....001, ~y is 1111....1010 and (~x|~y) is 1111,,,,1011, and after do ~ operation, we can get common bit.In other words,(~x)|(~y) lead the integer that don't represented by common 1, others are 1 that are not common. So if we do ~ operation, we can get common bits.*/
}
/*
 * getByte - Extract byte n from word x
 *   Bytes numbered from 0 (LSB) to 3 (MSB)
 *   Examples: getByte(0x12345678,1) = 0x56
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 6
 *   Rating: 2
 */
int getByte(int x, int n) {
	int arb = 0xFF;  	
	return (x>>(n<<3))&arb;/* we want to extrac byte n from x, so if we do & operation with number that has 11111111 only n^th byte that is made from using left shift of 0xff, we can get byte n from x.*/


}
/* 
 * logicalShift - shift x to the right by n, using a logical shift
 *   Can assume that 0 <= n <= 31
 *   Examples: logicalShift(0x87654321,4) = 0x08765432
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 20
 *   Rating: 3 
 */
int logicalShift(int x, int n) {
	int nshift = (((0x01<<31)>>n)<<1);
	return (x>>n)&(~nshift);
/*we want to get only front 32bit of integer. And if we do (x>>n), integer has n of msb in front of integer. We don't need them, so if we do "&" operation with x>>n, we can get the right result of logical right shift. We can get 11,,10000000 (n of 1) by using shift 0x01<<31 and >>n , <<1.*/

}
 /* bitCount - returns count of number of 1's in word
 *   Examples: bitCount(5) = 2, bitCount(7) = 3
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 40
 *   Rating: 4
 */
int bitCount(int x) {
	int second = 0x33;
	int oddlong = 0x55;
	int fourfirst = 0XF;
	int eightsecond = 0xff+(0xff<<16);/*00000000111111110000*/
	int sixsecond=0xff+(0xff<<8);/*0*16+1*16*/
	int even;
	int odd;
	int result=x;
	second=second+(second<<8);
        second = second+(second<<16);/*001100110011...*/
        oddlong = oddlong+(oddlong<<8);
        oddlong= oddlong+(oddlong<<16);/*0101010101010...*/
        fourfirst = fourfirst+(fourfirst<<8);
        fourfirst = fourfirst+(fourfirst<<16);/*0000111100001111*/
	even = (result>>1)&oddlong;/*extract even number of integer by using operation "&" with 0101010... to result>>1*/ 
	odd = result&oddlong;/*extract odd number of integer by using operation "&" with 0101010... to result*/
	result = even+odd;/*we can get the number of 1 in part of each two number(even, odd) ex)if x is 1110 then even will be 101, odd will be 100 then result will be 1001. 10 means the number of front two number(2), 01 means the number of last two number(1).*/
	even = (result>>2)&second;/*we have to add 10+01, so if we do & operation with 001100011 to result>>2, result then we can get 10, 01 and if we add both of them, we can get the number of 1 in integer. In 32bit integer, we do >> operation 1,2,4,8,16 and & operation with 0101010..., 00110011..., 0000111100001111..., 0000000011111111..., 00000000000000001111111111111111 and use + operation, we can get the result*/
	odd = result&second;
	result = even+odd;
	even = (result>>4)& fourfirst;
	odd = result&fourfirst;
	result = even +odd;
	even = (result>>8)&eightsecond;
	odd = result&eightsecond;
	result = even+odd;
	even = (result>>16)&sixsecond;
	odd = result & sixsecond;
	result = even+odd;
	return result;
}
/* 
 * bang - Compute !x without using !
 *   Examples: bang(3) = 0, bang(0) = 1
 *   Legal ops: ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 4 
 */
int bang(int x) {
	
	int firstmsb = ((~x)>>31)&0x01;
	int secondmsb = ((~(~x+1))>>31)&0x01;
	return (firstmsb&secondmsb);/*we have to notice that 0 and tmin(1000..0) have same msb in case of x and -x, and other numbers have different msb in case of x and -x(= ~x+1). I use this point and try to make different in case of Tmin. In case of 0, both ~x and ~(~x+1) have 1 as msb, but others have different msb in ~x and ~(~x+1). For instance, x=10000...00, msb of ~x is 0, ~(~x+1)=~(1000...0), msb of ~(~x+1) is 0. So if we do & operation, we can get the result that we want. */
}
/* 
 * tmin - return minimum two's complement integer 
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 4
 *   Rating: 1
 */
int tmin(void) {
	int x = 0x80;
	
  	return (x<<24) ;/*Tmin is 100...0, so if we do left shift to 10000000 by 24, we can get 1000...0=Tmin.*/


}/* 
 * fitsBits - return 1 if x can be represented as an 
 *  n-bit, two's complement integer.
 *   1 <= n <= 32
 *   Examples: fitsBits(5,3) = 0, fitsBits(-4,3) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 15
 *   Rating: 2
 */
int fitsBits(int x, int n) {
  	int num = 32+~n+1;
	int xor = (x<<num)>>num;
	return !(x^xor);/*If x=1111111...101(-3), n=3, the result of (x<<(32-3))>>29 is same with original x, that means it can be represented by 3bit. And if x=5=00000....0101, n=3 then (x<<29)>>29 = 11111.....1101 which is not same with original x, that means x can't be represented by 3 bit.*/


}
/* 
 * divpwr2 - Compute x/(2^n), for 0 <= n <= 30
 *  Round toward zero
 *   Examples: divpwr2(15,1) = 7, divpwr2(-33,4) = -2
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 15
 *   Rating: 2
 */
int divpwr2(int x, int n) {
    	int inter=(x>>31)&0x01;
	int mid = (inter<<n)+(x>>31);
	return (x+mid)>>n;
}/* if x is positive, we can get the result from x>>k, but if x is negative, we have to calculate like this : (x+1<<n-1)>>n. so we have to make 1<<n-1 to 0 in case of positive. MSB of positive number is 0 and msb of negative number is 1 so we can generalize 1<<n to ((x>>31)&0x01)>>n(because (x>>31)&0x01 means msb of integer. Also, -1 is 1111...1 = (x>>31) in case of negative, and we don't have to add -1 in case of positive so we can add (x>>31) in case of positive. Then we can get the result from (x+1<<n-1)>>n in case of positive.*/

 
/* 
 * negate - return -x 
 *   Example: negate(1) = -1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 5
 *   Rating: 2
 */
int negate(int x) {
  return (~x+1); /* (~x+1)+x = 0, so -x is equal to ~x+1*/
}
/* 
 * isPositive - return 1 if x > 0, return 0 otherwise 
 *   Example: isPositive(-1) = 0.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 8
 *   Rating: 3
 */
int isPositive(int x) {
  	return!(((x>>31)&0x01)|!x); /*(x>>31)&0x01 is msb of int.But in case of zero, msb is 0 but result should be 0, so if we do | operation with !x then we can handle zero like negative, so we can get 1 if we do !. If x is positive, msb will 0 and !x will be 0, so if we do ! operation, we will get 1.*/



}
/*
 * isLessOrEqual - if x <= y  then return 1, else return 0 
 *   Example: isLessOrEqual(4,5) = 1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 24
 *   Rating: 3
 */
int isLessOrEqual(int x, int y) {
  	int sub = y+(~x+1);/*y-x*/
	int msbx = (x>>31)&0x01;/*sign of x*/
	int msby = (y>>31)&0x01;/*sign of y*/
	int firstcase = (msbx& !msby);/*(msbx& !msby) check x<0 and y>0.*/
	int secondcase = (!(msbx ^ msby) &!((sub>>31)&0x01));/*sign of x and y are same and sign of (y-x) is 0*/
	return firstcase | secondcase ;/*If firstcase is true(=1) or secondcasethen is true, return 1  */	
	/* we can think just check sign of (y-x) and lead to result, but it can't be. Because if x=10000..0, y=0000...01 then x<y. But msb(sign) of  y+(~x+1) is 1 algthough y-x is positive. So we have to think seperately. To be y>=x is true, firstcase is x<0 and y>0. Second case is sign of x and y are same, sign of y-x is 0.*/

			
}
/* ilog2 - return floor(log base 2 of x), where x > 0
 *   Example: ilog2(16) = 4
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 90
 *   Rating: 4
 */
int ilog2(int x) {
  	int result = 0;
	int temp = !!(x>>16);
	temp=temp<<4;/*make temp to check if x is bigger than 16, if temp = 0 then temp<<4 will be zero and if temp=1 then temp<<4 will be 10000*/
	result = result+(temp&0x10);/*if temp=0 that means x is smaller than 2^16 because upper 16 bits don't have 1, and if temp=1, it means x is larger than 2^16 because upper 16 bits have 1. In second case, we have to add 16 because x>2^16 -> logx>16, result will be bigger than 16*/
	x=x>>(temp&0x10);/* if temp=0000...010000, x is shifted by 16 to find first 1 in upper 16 bit and if temp=000..000, x is not shifted.*/

	temp = !!(x>>8);
	temp = temp<<3;
	result = result+(temp&0x08);
	x=x>>(temp&0x08);
	
	temp = !!(x>>4);
        temp = temp<<2;
        result = result+(temp&0x04);
        x=x>>(temp&0x04);
	
	temp = !!(x>>2);
        temp = temp<<1;
        result = result+(temp&0x02);
        x=x>>(temp&0x02);

	temp = !!(x>>1);
        result = result+(temp&0x01);

	return result;
}
/* 
 * float_neg - Return bit-level equivalent of expression -f for
 *   floating point argument f.
 *   Both the argument and result are passed as unsigned int's, but
 *   they are to be interpreted as the bit-level representations of
 *   single-precision floating point values.
 *   When argument is NaN, return argument.
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 10
 *   Rating: 2
 
*/
unsigned float_neg(unsigned uf) {
 	int exp = (0xFF<<23);
	if (((exp&uf)==exp) && ((~((0xff<<24)>>1))&uf))
		return uf;
	return uf^(0x01<<31);/* if exp is 11111111 and frac is not 00000000 then that float is considerd as NaNS. 0xff<<23 means 01111111100000...0 , if  exp&uf ==exp, then it means exp is 11111111. (~((0xff<<24)>>1)) means frac numbers and if this is not zero then (((exp&uf)==exp) && ((~((0xff<<24)>>1))&uf)) will be true that means uf is NaNs so return argument uf. If uf is not NaNs, we have to change only sign bit 0->1, 1->0 so we return the value of using ^ operation with 10000..0.*/


}
/* 
 * float_i2f - Return bit-level equivalent of expression (float) x
 *   Result is returned as unsigned int, but
 *   it is to be interpreted as the bit-level representation of a
 *   single-precision floating point values.
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
unsigned float_i2f(int x) {
	int mask = 0x80<<24;/* mask =tmin*/
	int sign = x&mask;/* to check x is negative or positive*/
	unsigned ans = ans+sign;/*we have to return the value of unsigned type, so declare ans*/
	int frac;
	int exp = 158;/*E=exp-127,max of E is 31 so max exp = 158*/
	int twentythree = 23;
	if(!x) return 0;/*if x is 0 then return 0*/
	if(x==mask){
		return mask|(9<<(twentythree+4))|(14<<twentythree);/*if x is Tmin, we have to return 0xcf000000;*/
	}
	if(ans){
		x=~x+1;
	}/* if x is negative, we have to make x to -x*/
	while(!(x&mask)){
		x=x<<1;
		exp-=1;
	}/*if we divide x by 2, we can do E++, inversely, if we do <<1 operation we have to substract 1 to E.*/
	frac = (x&(~mask))>>8;/*we can get the bit except for sign bit by x&(~mask), and it is 31bit. In single precision floating point values, frac charges 23bit, so we have to do right shift by 8*/
	if(x&0x80 && (x&0x7f||frac&1))
		frac=frac+1;/* when we do right shift 8, we have to handle the case that is longer than 23bit. x&0x80 lead the Round bit, frac&1 lead the Ground bit and x&0x7f check the sticky bit if there is 1 in over bit. If R=1 and G=1 then we have to round to even, R=1,G=0, S=1 we have to round up*/ 

        return ans+(exp<<twentythree)+frac;

}
/* 
 * float_twice - Return bit-level equivalent of expression 2*f for
 *   floating point argument f.
 *   Both the argument and result are passed as unsigned int's, but
 *   they are to be interpreted as the bit-level representation of
 *   single-precision floating point values.
 *   When argument is NaN, return argument
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
unsigned float_twice(unsigned uf) {
	int sign = uf&(0x01<<31);/* sign bit will be same as msb*/
	int exp = uf&(0xff<<23);/* exponent will be 1bit to 9 bit, so if we do & operation with 0111111110000...0 then we can get exponent part*/
	int frac = (~((0xff<<24)>>1))&uf;/*the last 23 bit will be the frac part so if we do & operation with 000...01*23 then we can get frac part*/

	if(exp==(0xff<<23))
		return uf; /*if uf is NaNs and infinity. Because infinity*2=infinity+infinity, that means NaNs.*/
	if(uf==(0x00<<24)||uf==(0x01<<31))
		return uf;/*if we multiply two to zero, the result will be zero.*/
	if((exp==0) && (frac!=0))
		return ((frac+frac)|(sign|exp));/* M=0.xxx .Therefore we can just add twice frac. if frac addition occur overflow(more than 11..1(23 bit)) then it will be added to exp bit because of | operation.*/

	return uf+(0x01<<23);/* if uf is (-1)^s *M*2^E, then *2 means (-1)^s*M*2^(E+1). in other words, we have to increase 1 to E(exponent). We can't do like denormalized value because normarlized value has leading 1 implicitly in M(1.xxxx...), so we can't do just addition between frac part but we should increase expoenent 1.*/
}
