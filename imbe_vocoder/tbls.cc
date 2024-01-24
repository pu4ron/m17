/*
 * Project 25 IMBE Encoder/Decoder Fixed-Point implementation
 * Developed by Pavel Yazev E-mail: pyazev@gmail.com
 * Version 1.0 (c) Copyright 2009
 * 
 * This is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3, or (at your option)
 * any later version.
 * 
 * The software is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * See the GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this; see the file COPYING.  If not, write to the Free
 * Software Foundation, Inc., 51 Franklin Street, Boston, MA
 * 02110-1301, USA.
 */
#include "typedef.h"
#include "tbls.h"


//-----------------------------------------------------------------------------
//
// Bit allocation and ancillary tables
//
//-----------------------------------------------------------------------------
const UWord16 bit_allocation_tbl[] = 
{
	0xA999, 0x9987, 
	0x9988, 0x8976, 0x5000,
	0x8887, 0x7976, 0x5400,
	0x8777, 0x7876, 0x5430,
	0x7776, 0x6776, 0x5433,
	0x7666, 0x6775, 0x4434, 0x3000,
	0x7666, 0x5675, 0x4433, 0x3300,
	0x6665, 0x5665, 0x4433, 0x3320,
	0x6655, 0x5555, 0x4443, 0x3232,
	0x6555, 0x5545, 0x5433, 0x3322, 0x2000,
	0x6554, 0x4545, 0x4433, 0x3323, 0x2100,
	0x6554, 0x4545, 0x4433, 0x2321, 0x3210,
	0x5554, 0x4445, 0x4433, 0x2232, 0x1321,
	0x5544, 0x4444, 0x4432, 0x3223, 0x2122, 0x1000,
	0x5444, 0x4434, 0x4343, 0x2322, 0x2212, 0x2100,
	0x5444, 0x4433, 0x4333, 0x3232, 0x1221, 0x2210,
	0x5444, 0x3433, 0x4333, 0x3232, 0x1221, 0x2111,
	0x5443, 0x3433, 0x4333, 0x2232, 0x1221, 0x1221, 0x1000,
	0x5443, 0x3432, 0x4323, 0x2232, 0x2122, 0x1122, 0x1100,
	0x4443, 0x3432, 0x4323, 0x2223, 0x2112, 0x2112, 0x1110,
	0x4443, 0x3332, 0x4322, 0x3222, 0x3211, 0x2111, 0x2111,
	0x4443, 0x3332, 0x2332, 0x2322, 0x1321, 0x1211, 0x1211, 0x1000,
	0x4433, 0x3332, 0x2332, 0x2322, 0x1221, 0x1211, 0x1211, 0x1100,
	0x4433, 0x3332, 0x2332, 0x2322, 0x1221, 0x1211, 0x1121, 0x1100,
	0x4333, 0x3332, 0x2332, 0x2321, 0x1221, 0x1121, 0x1112, 0x1111,
	0x4333, 0x3322, 0x2322, 0x2322, 0x1122, 0x1112, 0x1111, 0x2111, 0x0000,
	0x4333, 0x3322, 0x2322, 0x2232, 0x1112, 0x2111, 0x2111, 0x0211, 0x1000,
	0x4333, 0x3322, 0x2132, 0x2213, 0x2111, 0x2211, 0x1211, 0x1021, 0x1100,
	0x4333, 0x2322, 0x2132, 0x2223, 0x2111, 0x2111, 0x1211, 0x1021, 0x1110,
	0x4333, 0x2322, 0x2132, 0x2213, 0x2111, 0x2111, 0x1211, 0x1102, 0x1111, 0x0000,
	0x4333, 0x2322, 0x2132, 0x2213, 0x2111, 0x2211, 0x1021, 0x1110, 0x2111, 0x0000, 
	0x4333, 0x2322, 0x2132, 0x2113, 0x2111, 0x1221, 0x1102, 0x1111, 0x0211, 0x1000,
	0x4332, 0x2322, 0x1132, 0x2211, 0x3211, 0x1122, 0x1110, 0x2111, 0x1021, 0x1100,
	0x4332, 0x2322, 0x2113, 0x2221, 0x1221, 0x1112, 0x2111, 0x0211, 0x1002, 0x1110, 0x0000,
	0x4332, 0x2322, 0x2113, 0x2221, 0x1221, 0x1112, 0x1111, 0x0211, 0x1002, 0x1111, 0x0000,
	0x4332, 0x2322, 0x1113, 0x2221, 0x1221, 0x1112, 0x1111, 0x0211, 0x1100, 0x2111, 0x1000,
	0x4332, 0x2322, 0x1113, 0x2211, 0x1221, 0x1112, 0x2111, 0x0021, 0x1110, 0x0211, 0x1100,
	0x3332, 0x2322, 0x1113, 0x2211, 0x1221, 0x1111, 0x2211, 0x1002, 0x1111, 0x0021, 0x1110, 0x0000,
	0x3332, 0x2322, 0x1113, 0x2211, 0x1122, 0x1111, 0x1221, 0x1100, 0x2111, 0x1002, 0x1110, 0x0000,
	0x3332, 0x2322, 0x1111, 0x3221, 0x1112, 0x2111, 0x1122, 0x1110, 0x0211, 0x1000, 0x2111, 0x0000,
	0x3332, 0x2322, 0x1111, 0x3221, 0x1112, 0x2111, 0x1022, 0x1110, 0x0211, 0x1000, 0x2111, 0x1000,
	0x3332, 0x2322, 0x1111, 0x3221, 0x1112, 0x2111, 0x1022, 0x1110, 0x0211, 0x1100, 0x0211, 0x1000, 0x0000,
	0x3332, 0x2322, 0x1111, 0x3211, 0x1112, 0x2111, 0x1022, 0x1110, 0x0021, 0x1110, 0x0021, 0x1110, 0x0000,
	0x3322, 0x2321, 0x1111, 0x3221, 0x1112, 0x2111, 0x1102, 0x2111, 0x0002, 0x1111, 0x0002, 0x1111, 0x0000,
	0x3322, 0x2321, 0x1111, 0x3221, 0x1111, 0x2211, 0x1110, 0x2211, 0x1000, 0x2111, 0x1000, 0x2111, 0x0000,
	0x3322, 0x2322, 0x1111, 0x0322, 0x1111, 0x0221, 0x1111, 0x0221, 0x1100, 0x0211, 0x1100, 0x0211, 0x1000, 0x0000,	
	0x3322, 0x2322, 0x1111, 0x0322, 0x1111, 0x0221, 0x1111, 0x0221, 0x1100, 0x0211, 0x1000, 0x0211, 0x1100, 0x0000,
	0x3322, 0x2322, 0x1111, 0x0322, 0x1111, 0x0221, 0x1111, 0x0221, 0x1100, 0x0211, 0x1100, 0x0021, 0x1100, 0x0000
};

const UWord16 bit_allocation_offset_tbl[] = 
{
	0x0002, 0x000E, 0x001E, 0x0032, 0x004A, 0x0066, 0x0086, 0x00AA, 0x00D2, 0x00FE, 0x012E, 0x0162 
};

//-----------------------------------------------------------------------------
//
// Log Magnitude Prediction Residual Block Length
//
//-----------------------------------------------------------------------------
const UWord32 lmprbl_tbl[] = 
{
	0x11122200,
	0x11222200,
	0x12222200,
	0x22222200,
	0x22222300,
	0x22223300,
	0x22233300,
	0x22333300,
	0x23333300,
	0x33333300,
	0x33333400,
	0x33334400,
	0x33344400,
	0x33444400,
	0x34444400,
	0x44444400,
	0x44444500,
	0x44445500,
	0x44455500,
	0x44555500,
	0x45555500,
	0x55555500,
	0x55555600,
	0x55556600,
	0x55566600,
	0x55666600,
	0x56666600,
	0x66666600,
	0x66666700,
	0x66667700,
	0x66677700,
	0x66777700,
	0x67777700,
	0x77777700,
	0x77777800,
	0x77778800,
	0x77788800,
	0x77888800,
	0x78888800,
	0x88888800,
	0x88888900,
	0x88889900,
	0x88899900,
	0x88999900,
	0x89999900,
	0x99999900,
	0x99999A00,
	0x9999AA00 
};



//-----------------------------------------------------------------------------
//
// Gain Quantizer Levels in signed Q5.11 format
//
//-----------------------------------------------------------------------------
const Word16 gain_qnt_tbl[] = 
{
	-5821, -5518, -5239, -4880, -4549, -4292, -4057, -3760, -3370, -2903,
	-2583, -2305, -1962, -1601, -1138,  -711,  -302,    57,   433,   795,
	 1132,  1510,  1909,  2333,  2705,  3038,  3376,  3689,  3979,  4339,
	 4754,  5129,  5435,  5695,  5991,  6300,  6596,  6969,  7342,  7751,
	 8101,  8511,  8835,  9102,  9375,  9698, 10055, 10415, 10762, 11084,
	11403, 11752, 12123, 12468, 12863, 13239, 13615, 13997, 14382, 14770,
	15301, 15849, 16640, 17809
};


//-----------------------------------------------------------------------------
//
// Gain Ste Size in unsigned Q0.16 format
//
//-----------------------------------------------------------------------------
const UWord16 gain_step_size_tbl[] = 
{
	  203,  263,  220,  190,  173, 
	  406,  263,  440,  380,  346, 
	  813,  527,  440,  760,  692, 
 	  813, 1054,  881,  760,  692, 
	 1625, 1054,  881, 1425, 1298, 
	 1625, 1976, 1652, 1425, 1298, 
	 1625, 1976, 1652, 1425, 2422, 
	 3047, 1976, 1652, 2661, 2422, 
	 3047, 1976, 3083, 2661, 2422, 
	 3047, 3688, 3083, 2661, 2422, 
	 3047, 3688, 3083, 3801, 3460, 
	 3047, 3688, 3083, 3801, 3460, 
	 5689, 3688, 3083, 3801, 3460, 
	 5689, 3688, 4404, 3801, 3460, 
	 5689, 5269, 4404, 3801, 3460, 
	 5689, 5269, 4404, 3801, 3460, 
	 5689, 5269, 4404, 3801, 5623, 
	 5689, 5269, 4404, 6177, 5623, 
	 5689, 5269, 4404, 6177, 5623, 
	 8126, 5269, 4404, 6177, 5623, 
	 8126, 5269, 4404, 6177, 5623, 
	 8126, 5269, 4404, 6177, 5623, 
	 8126, 5269, 7157, 6177, 5623, 
	 8126, 5269, 7157, 6177, 5623, 
	 8126, 8562, 7157, 6177, 5623, 
	 8126, 8562, 7157, 6177, 5623, 
	 8126, 8562, 7157, 6177, 5623, 
	 8126, 8562, 7157, 6177, 5623, 
	 8126, 8562, 7157, 6177, 7353, 
	 8126, 8562, 7157, 6177, 7353, 
	 8126, 8562, 7157, 6177, 7353, 
	 8126, 8562, 7157, 6177, 7353, 
	 8126, 8562, 7157, 8077, 7353, 
	 8126, 8562, 7157, 8077, 7353, 
	 8126, 8562, 7157, 8077, 7353, 
	 8126, 8562, 7157, 8077, 7353, 
	 8126, 8562, 7157, 8077, 7353, 
	13206, 8562, 7157, 8077, 7353, 
	13206, 8562, 7157, 8077, 7353, 
	13206, 8562, 7157, 8077, 7353, 
	13206, 8562, 7157, 8077, 7353, 
	13206, 8562, 7157, 8077, 7353, 
	13206, 8562, 7157, 8077, 7353, 
	13206, 8562, 9359, 8077, 7353, 
	13206, 8562, 9359, 8077, 7353, 
	13206, 8562, 9359, 8077, 7353, 
	13206, 8562, 9359, 8077, 7353, 
	13206, 8562, 9359, 8077, 7353
};	


//-----------------------------------------------------------------------------
//
// Standard Deviation of Higher Order DCT Coefficients in unsigned Q0.16 format
//
//-----------------------------------------------------------------------------
const UWord16 hi_ord_std_tbl[] = 
{
	20120, 15794, 13566, 12452, 11731, 11338, 10813, 11141, 11141
};

//-----------------------------------------------------------------------------
//
// Quantizer Step for Higher Order DCT Coefficients in unsigned Q1.15 format
//
//-----------------------------------------------------------------------------
const UWord16 hi_ord_step_size_tbl[] = 
{
	39322,	27853, 21299, 13107, 9175, 4915, 2621, 1311, 655, 328
};

//-----------------------------------------------------------------------------
//
// Speech Synthesis Window 
//
//-----------------------------------------------------------------------------
const Word16 ws[49] =
{
	655,  1310,  1966,  2621,  3276,  3932,  4587,  5242,  5898,  6553,
	7208,  7864,  8519,  9175,  9830, 10485, 11141, 11796, 12451, 13107,
	13762, 14417, 15073, 15728, 16384, 17039, 17694, 18350, 19005, 19660,
	20316, 20971, 21626, 22282, 22937, 23592, 24248, 24903, 25559, 26214,
	26869, 27525, 28180, 28835, 29491, 30146, 30801, 31457, 32112 
};

/*
const Word16 ws_ws[49] =
{

	17052, 17746, 18467, 19212, 19980, 20770, 21580, 22407, 23246, 24094,
	24945, 25793, 26631, 27453, 28248, 29008, 29724, 30385, 30983, 31507,
	31950, 32302, 32559, 32715, 32767, 32715, 32559, 32302, 31950, 31507,
	30983, 30385, 29724, 29008, 28248, 27453, 26631, 25793, 24945, 24094,
	23246, 22407, 21580, 20770, 19980, 19212, 18467, 17746, 17052 
};
*/

//-----------------------------------------------------------------------------
//
// Squared Pitch Estimation Window 64*wi^2
//
//-----------------------------------------------------------------------------
const Word16 wi[301] =
{
	   15,    18,    21,    25,    29,    34,    40,    46,    52,    59, 
	   67,    76,    86,    96,   108,   120,   133,   148,   164,   180, 
	  199,   218,   239,   261,   285,   311,   338,   367,   398,   431, 
	  465,   502,   541,   582,   625,   671,   719,   769,   822,   878, 
	  936,   997,  1061,  1128,  1198,  1271,  1347,  1426,  1508,  1594, 
	 1683,  1775,  1871,  1970,  2073,  2179,  2289,  2403,  2520,  2641, 
	 2766,  2894,  3026,  3162,  3301,  3445,  3592,  3742,  3897,  4055, 
	 4216,  4382,  4551,  4723,  4899,  5078,  5261,  5447,  5636,  5828, 
	 6023,  6221,  6423,  6626,  6833,  7042,  7253,  7467,  7683,  7900, 
	 8120,  8341,  8564,  8788,  9014,  9241,  9468,  9696,  9925, 10154, 
	10383, 10613, 10842, 11070, 11298, 11525, 11752, 11977, 12200, 12422, 
	12642, 12860, 13076, 13289, 13500, 13708, 13912, 14114, 14312, 14506, 
	14696, 14882, 15064, 15242, 15414, 15582, 15745, 15903, 16055, 16202, 
	16343, 16478, 16608, 16731, 16848, 16958, 17062, 17159, 17250, 17333, 
	17410, 17480, 17542, 17597, 17646, 17686, 17720, 17746, 17764, 17776, 
	17779, 17776, 17764, 17746, 17720, 17686, 17646, 17597, 17542, 17480, 
	17410, 17333, 17250, 17159, 17062, 16958, 16848, 16731, 16608, 16478, 
	16343, 16202, 16055, 15903, 15745, 15582, 15414, 15242, 15064, 14882, 
	14696, 14506, 14312, 14114, 13912, 13708, 13500, 13289, 13076, 12860, 
	12642, 12422, 12200, 11977, 11752, 11525, 11298, 11070, 10842, 10613, 
	10383, 10154,  9925,  9696,  9468,  9241,  9014,  8788,  8564,  8341, 
	 8120,  7900,  7683,  7467,  7253,  7042,  6833,  6626,  6423,  6221, 
	 6023,  5828,  5636,  5447,  5261,  5078,  4899,  4723,  4551,  4382, 
	 4216,  4055,  3897,  3742,  3592,  3445,  3301,  3162,  3026,  2894, 
	 2766,  2641,  2520,  2403,  2289,  2179,  2073,  1970,  1871,  1775, 
	 1683,  1594,  1508,  1426,  1347,  1271,  1198,  1128,  1061,   997, 
	  936,   878,   822,   769,   719,   671,   625,   582,   541,   502, 
	  465,   431,   398,   367,   338,   311,   285,   261,   239,   218, 
	  199,   180,   164,   148,   133,   120,   108,    96,    86,    76, 
	   67,    59,    52,    46,    40,    34,    29,    25,    21,    18, 
	   15
};

//-----------------------------------------------------------------------------
//
// Pitch Refinement Window 
//
//-----------------------------------------------------------------------------
const Word16 wr[] = 
{
	  487,   570,   658,   753,   854,   962,  1076,  1197,  1325,   1460, 
	 1602,  1752,  1909,  2074,  2246,  2426,  2614,  2810,  3014,   3227, 
	 3447,  3675,  3912,  4157,  4410,  4671,  4941,  5219,  5505,   5799, 
	 6101,  6411,  6729,  7054,  7388,  7728,  8077,  8432,  8795,   9164, 
	 9541,  9923, 10312, 10707, 11108, 11515, 11927, 12344, 12766,  13192, 
	13622, 14056, 14494, 14935, 15379, 15825, 16273, 16724, 17175,  17628, 
	18081, 18534, 18988, 19440, 19892, 20342, 20790, 21237, 21680,  22120, 
	22557, 22990, 23419, 23842, 24261, 24673, 25080, 25480, 25874,  26259, 
	26638, 27008, 27370, 27722, 28066, 28400, 28724, 29037, 29340,  29632, 
	29912, 30181, 30438, 30683, 30915, 31135, 31341, 31535, 31715,  31881, 
	32033, 32172, 32296, 32406, 32502, 32583, 32649, 32701, 32738,  32760, 
};

//-----------------------------------------------------------------------------
//
// Real Part Spectrum of Pitch Refinement Window * 256 
//
//-----------------------------------------------------------------------------
const Word16 wr_sp[] = 
{
	   16,    43,    71,   102,   135,   170,   207,   247,   289,   333, 
	  380,   430,   483,   538,   596,   657,   721,   787,   857,   930, 
	 1006,  1085,  1168,  1254,  1343,  1435,  1531,  1630,  1733,  1840, 
	 1950,  2063,  2181,  2302,  2426,  2555,  2687,  2823,  2962,  3106, 
	 3253,  3404,  3559,  3718,  3881,  4047,  4218,  4392,  4570,  4751, 
	 4937,  5126,  5319,  5516,  5716,  5920,  6128,  6339,  6554,  6772, 
	 6994,  7219,  7447,  7679,  7914,  8152,  8393,  8637,  8884,  9134, 
  	 9387,  9642,  9900, 10160, 10423, 10688, 10956, 11225, 11497, 11770, 
	12045, 12322, 12601, 12881, 13162, 13444, 13728, 14012, 14298, 14584, 
	14871, 15158, 15445, 15733, 16020, 16308, 16595, 16882, 17168, 17454, 
	17738, 18022, 18305, 18586, 18866, 19145, 19421, 19696, 19969, 20240, 
	20508, 20774, 21037, 21298, 21556, 21811, 22062, 22310, 22555, 22796, 
	23033, 23267, 23496, 23722, 23943, 24159, 24372, 24579, 24782, 24980, 
	25172, 25360, 25542, 25719, 25891, 26057, 26217, 26372, 26520, 26663, 
	26800, 26930, 27055, 27173, 27285, 27390, 27489, 27581, 27667, 27746, 
	27818, 27884, 27942, 27994, 28039, 28078, 28109, 28133, 28151, 28161, 
	28165, 28161, 28151, 28133, 28109, 28078, 28039, 27994, 27942, 27884, 
	27818, 27746, 27667, 27581, 27489, 27390, 27285, 27173, 27055, 26930, 
	26800, 26663, 26520, 26372, 26217, 26057, 25891, 25719, 25542, 25360, 
	25172, 24980, 24782, 24579, 24372, 24159, 23943, 23722, 23496, 23267, 
	23033, 22796, 22555, 22310, 22062, 21811, 21556, 21298, 21037, 20774, 
	20508, 20240, 19969, 19696, 19421, 19145, 18866, 18586, 18305, 18022, 
	17738, 17454, 17168, 16882, 16595, 16308, 16020, 15733, 15445, 15158, 
	14871, 14584, 14298, 14012, 13728, 13444, 13162, 12881, 12601, 12322, 
	12045, 11770, 11497, 11225, 10956, 10688, 10423, 10160,  9900,  9642, 
	 9387,  9134,  8884,  8637,  8393,  8152,  7914,  7679,  7447,  7219, 
	 6994,  6772,  6554,  6339,  6128,  5920,  5716,  5516,  5319,  5126, 
     4937,  4751,  4570,  4392,  4218,  4047,  3881,  3718,  3559,  3404, 
     3253,  3106,  2962,  2823,  2687,  2555,  2426,  2302,  2181,  2063, 
     1950,  1840,  1733,  1630,  1531,  1435,  1343,  1254,  1168,  1085, 
     1006,   930,   857,   787,   721,   657,   596,   538,   483,   430, 
      380,   333,   289,   247,   207,   170,   135,   102,    71,    43, 
       16
};

