//
//  types.h
//  ObserverPattern
//
//  Created by Balu Pillai on 05/11/2020.
//  Copyright © 2020 Balu Pillai. All rights reserved.
//

#ifndef types_h
#define types_h

#define FALSE 0U
#define TRUE 1U
/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/

 typedef unsigned char         boolean;       /*        TRUE .. FALSE           */

 typedef signed char           sint8;         /*        -128 .. +127            */
 typedef unsigned char         uint8;         /*           0 .. 255             */
 typedef signed short          sint16;        /*      -32768 .. +32767          */
 typedef unsigned short        uint16;        /*           0 .. 65535           */
 typedef signed long           sint32;        /* -2147483648 .. +2147483647     */
 typedef unsigned long         uint32;        /*           0 .. 4294967295      */

 typedef signed int            sint8_least;   /* At least 7 bit + 1 bit sign    */
 typedef unsigned int          uint8_least;   /* At least 8 bit                 */
 typedef signed int            sint16_least;  /* At least 15 bit + 1 bit sign   */
 typedef unsigned int          uint16_least;  /* At least 16 bit                */
 typedef signed int            sint32_least;  /* At least 31 bit + 1 bit sign   */
 typedef unsigned int          uint32_least;  /* At least 32 bit                */
 typedef signed long long      sint64;        /* -9223372036854775808 .. 9223372036854775807      */
 typedef unsigned long long    uint64;        /*                    0 .. 18446744073709551615     */
 typedef float                 float32;
 typedef double                float64;


#endif /* types_h */
