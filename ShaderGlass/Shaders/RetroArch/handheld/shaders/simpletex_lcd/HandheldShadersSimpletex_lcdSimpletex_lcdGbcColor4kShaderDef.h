/*
ShaderGlass shader handheld-shaders-simpletex_lcd\simpletex_lcd+gbc-color-4k imported from RetroArch:
https://github.com/libretro/slang-shaders/blob/master/handheld/shaders/simpletex_lcd/simpletex_lcd+gbc-color-4k.slang
See original file for full credits and usage license with excerpts below. 
This file is auto-generated, do not modify directly.


simpletex_lcd+gbc-color - a simple, textured LCD shader intended for non-backlit
systems - includes GBC colour correction

- Makes use of the 'line weighting' equation from zfast_lcd_standard
[original zfast_lcd_standard code copyright (C) 2017 Greg Hogan (SoltanGris42)]

- Colour correction code taken from 'gbc-color', written by hunterk and realeased
into the public domain, with further tweaks by Pokefan531

Other code by jdgleaver

Usage notes:

- Background texture size is hard-coded (I can't find a way to get this
automatically...). User must ensure that 'BG_TEXTURE_SIZE' define is
set appropriately.

- Adjustable parameters:

> GRID_INTENSITY: Sets overall visibility of grid effect
- 1.0: Grid is shown
- 0.0: Grid is invisible (same colour as pixels)
> GRID_WIDTH: Sets effective with of grid lines
- 1.0: Normal full width
- 0.0: Minimum width
(Note - this does not mean zero width! Instead, this
is the minimum 'sane' width, below which the grid
becomes pointless...)
> GRID_BIAS: Dynamically adjusts the grid intensity based on pixel luminosity
- 0.0: Grid intensity is uniform
- 1.0: Grid intensity scales linearly with pixel luminosity
> i.e. the darker the pixel, the less the grid effect
is apparent - black pixels exhibit no grid effect at all
> DARKEN_GRID: Darkens grid (duh...)
- 0.0: Grid is white
- 1.0: Grid is black
> DARKEN_COLOUR: Simply darkens pixel colours (effectively lowers gamma level of pixels)
- 0.0: Colours are normal
- 2.0: Colours are too dark...

This program is free software; you can redistribute it and/or modify it
under the terms of the GNU General Public License as published by the Free
Software Foundation; either version 2 of the License, or (at your option)
any later version.

// Background texture size
// > 2048 x 2048 textures are suitable for screen resolutions up to
//   1200p (or 1440p if running 'square' aspect ratio systems)
//#define BG_TEXTURE_SIZE 2048.0
// > 4096 x 4096 textures are suitable for screen resolutions up to 4k

VERTEX_SHADER

// ### Magic Numbers...
// Grid pattern
// > Line weighting equation:
//   y = a * (x^4 - b * x^6)
// RGB -> Luminosity conversion
// > Photometric/digital ITU BT.709
// > Digital ITU BT.601
//#define LUMA_R 0.299
//#define LUMA_G 0.587
//#define LUMA_B 0.114
// Background texture size
// Colour correction

FRAGMENT SHADER

// Get current texture coordinate
// Get colour of current pixel
// Darken colours (if required...) and apply colour correction
// Generate grid pattern...
// > Line weighting equation:
//   y = 48 * (x^4 - (8/3) * x^6)
// > Apply grid adjustments (phase 1)
//   - GRID_WIDTH:
//        1.0: Use raw lineWeight value
//        0.0: Use lineWeight ^ 2 (makes lines thinner - realistically, this is
//                                 the thinnest we can go before the grid effect
//                                 becomes pointless, particularly with 'high resolution'
//                                 systems like the GBA)
//   - GRID_INTENSITY:
//        1.0: Grid lines are white
//        0.0: Grid lines are invisible
// > Apply grid adjustments (phase 2)
//   - GRID_BIAS:
//        0.0: Use 'unbiased' lineWeight value calculated above
//        1.0: Scale lineWeight by current pixel luminosity
//             > i.e. the darker the pixel, the lower the intensity of the grid
// Apply grid pattern
// (lineWeight == 1 -> set colour to value specified by DARKEN_GRID)
// Get background sample point
// > NB: external texture coordinates are referenced in a completely different fashion
//   here than they are in GLSL shaders...
// Sample background texture and 'colourise' according to current pixel colour
// (NB: the 'colourisation' here is lame, but the proper method is slow...)
// Blend current pixel with background according to luminosity
// (lighter colour == more transparent, more visible background)
// Note: Have to calculate luminosity a second time... tiresome, but
// it's not a particulary expensive operation...

*/

#pragma once

namespace RetroArchHandheldShadersSimpletex_lcdSimpletex_lcdGbcColor4kShaderDefs
{
static const BYTE sVertexByteCode[] =
{
68,88,66,67,110,239,
1,38,44,138,120,137,
121,214,212,137,93,170,
129,5,1,0,0,0,
140,3,0,0,5,0,
0,0,52,0,0,0,
60,1,0,0,136,1,
0,0,224,1,0,0,
240,2,0,0,82,68,
69,70,0,1,0,0,
1,0,0,0,96,0,
0,0,1,0,0,0,
60,0,0,0,0,5,
254,255,0,129,0,0,
216,0,0,0,82,68,
49,49,60,0,0,0,
24,0,0,0,32,0,
0,0,40,0,0,0,
36,0,0,0,12,0,
0,0,0,0,0,0,
92,0,0,0,0,0,
0,0,0,0,0,0,
0,0,0,0,0,0,
0,0,0,0,0,0,
1,0,0,0,1,0,
0,0,85,66,79,0,
92,0,0,0,1,0,
0,0,120,0,0,0,
64,0,0,0,0,0,
0,0,0,0,0,0,
160,0,0,0,0,0,
0,0,64,0,0,0,
2,0,0,0,180,0,
0,0,0,0,0,0,
255,255,255,255,0,0,
0,0,255,255,255,255,
0,0,0,0,103,108,
111,98,97,108,95,77,
86,80,0,102,108,111,
97,116,52,120,52,0,
2,0,3,0,4,0,
4,0,0,0,0,0,
0,0,0,0,0,0,
0,0,0,0,0,0,
0,0,0,0,0,0,
0,0,171,0,0,0,
77,105,99,114,111,115,
111,102,116,32,40,82,
41,32,72,76,83,76,
32,83,104,97,100,101,
114,32,67,111,109,112,
105,108,101,114,32,49,
48,46,49,0,73,83,
71,78,68,0,0,0,
2,0,0,0,8,0,
0,0,56,0,0,0,
0,0,0,0,0,0,
0,0,3,0,0,0,
0,0,0,0,15,15,
0,0,56,0,0,0,
1,0,0,0,0,0,
0,0,3,0,0,0,
1,0,0,0,3,3,
0,0,84,69,88,67,
79,79,82,68,0,171,
171,171,79,83,71,78,
80,0,0,0,2,0,
0,0,8,0,0,0,
56,0,0,0,0,0,
0,0,0,0,0,0,
3,0,0,0,0,0,
0,0,3,12,0,0,
65,0,0,0,0,0,
0,0,1,0,0,0,
3,0,0,0,1,0,
0,0,15,0,0,0,
84,69,88,67,79,79,
82,68,0,83,86,95,
80,111,115,105,116,105,
111,110,0,171,171,171,
83,72,69,88,8,1,
0,0,80,0,1,0,
66,0,0,0,106,8,
0,1,89,0,0,4,
70,142,32,0,0,0,
0,0,4,0,0,0,
95,0,0,3,242,16,
16,0,0,0,0,0,
95,0,0,3,50,16,
16,0,1,0,0,0,
101,0,0,3,50,32,
16,0,0,0,0,0,
103,0,0,4,242,32,
16,0,1,0,0,0,
1,0,0,0,104,0,
0,2,1,0,0,0,
54,0,0,5,50,32,
16,0,0,0,0,0,
70,16,16,0,1,0,
0,0,56,0,0,8,
242,0,16,0,0,0,
0,0,86,21,16,0,
0,0,0,0,70,142,
32,0,0,0,0,0,
1,0,0,0,50,0,
0,10,242,0,16,0,
0,0,0,0,6,16,
16,0,0,0,0,0,
70,142,32,0,0,0,
0,0,0,0,0,0,
70,14,16,0,0,0,
0,0,50,0,0,10,
242,0,16,0,0,0,
0,0,166,26,16,0,
0,0,0,0,70,142,
32,0,0,0,0,0,
2,0,0,0,70,14,
16,0,0,0,0,0,
50,0,0,10,242,32,
16,0,1,0,0,0,
246,31,16,0,0,0,
0,0,70,142,32,0,
0,0,0,0,3,0,
0,0,70,14,16,0,
0,0,0,0,62,0,
0,1,83,84,65,84,
148,0,0,0,6,0,
0,0,1,0,0,0,
0,0,0,0,4,0,
0,0,4,0,0,0,
0,0,0,0,0,0,
0,0,1,0,0,0,
0,0,0,0,0,0,
0,0,0,0,0,0,
0,0,0,0,0,0,
0,0,0,0,0,0,
0,0,0,0,0,0,
0,0,0,0,0,0,
0,0,0,0,0,0,
0,0,1,0,0,0,
0,0,0,0,0,0,
0,0,0,0,0,0,
0,0,0,0,0,0,
0,0,0,0,0,0,
0,0,0,0,0,0,
0,0,0,0,0,0,
0,0,0,0,0,0,
0,0,0,0,0,0,
0,0,0,0,0,0,
0,0,0,0,0,0,
0,0,0,0,0,0,
0,0
};


static const BYTE sFragmentByteCode[] =
{
68,88,66,67,45,122,
115,150,83,176,226,193,
151,20,173,123,45,235,
240,92,1,0,0,0,
84,11,0,0,5,0,
0,0,52,0,0,0,
220,3,0,0,16,4,
0,0,68,4,0,0,
184,10,0,0,82,68,
69,70,160,3,0,0,
1,0,0,0,24,1,
0,0,5,0,0,0,
60,0,0,0,0,5,
255,255,0,129,0,0,
120,3,0,0,82,68,
49,49,60,0,0,0,
24,0,0,0,32,0,
0,0,40,0,0,0,
36,0,0,0,12,0,
0,0,0,0,0,0,
220,0,0,0,3,0,
0,0,0,0,0,0,
0,0,0,0,0,0,
0,0,2,0,0,0,
1,0,0,0,1,0,
0,0,236,0,0,0,
3,0,0,0,0,0,
0,0,0,0,0,0,
0,0,0,0,3,0,
0,0,1,0,0,0,
1,0,0,0,0,1,
0,0,2,0,0,0,
5,0,0,0,4,0,
0,0,255,255,255,255,
2,0,0,0,1,0,
0,0,13,0,0,0,
7,1,0,0,2,0,
0,0,5,0,0,0,
4,0,0,0,255,255,
255,255,3,0,0,0,
1,0,0,0,13,0,
0,0,18,1,0,0,
0,0,0,0,0,0,
0,0,0,0,0,0,
0,0,0,0,1,0,
0,0,1,0,0,0,
0,0,0,0,95,83,
111,117,114,99,101,95,
115,97,109,112,108,101,
114,0,95,66,65,67,
75,71,82,79,85,78,
68,95,115,97,109,112,
108,101,114,0,83,111,
117,114,99,101,0,66,
65,67,75,71,82,79,
85,78,68,0,80,117,
115,104,0,171,18,1,
0,0,8,0,0,0,
48,1,0,0,80,0,
0,0,0,0,0,0,
0,0,0,0,112,2,
0,0,0,0,0,0,
4,0,0,0,2,0,
0,0,144,2,0,0,
0,0,0,0,255,255,
255,255,0,0,0,0,
255,255,255,255,0,0,
0,0,180,2,0,0,
4,0,0,0,4,0,
0,0,2,0,0,0,
144,2,0,0,0,0,
0,0,255,255,255,255,
0,0,0,0,255,255,
255,255,0,0,0,0,
201,2,0,0,8,0,
0,0,4,0,0,0,
2,0,0,0,144,2,
0,0,0,0,0,0,
255,255,255,255,0,0,
0,0,255,255,255,255,
0,0,0,0,221,2,
0,0,12,0,0,0,
4,0,0,0,2,0,
0,0,144,2,0,0,
0,0,0,0,255,255,
255,255,0,0,0,0,
255,255,255,255,0,0,
0,0,243,2,0,0,
16,0,0,0,4,0,
0,0,2,0,0,0,
144,2,0,0,0,0,
0,0,255,255,255,255,
0,0,0,0,255,255,
255,255,0,0,0,0,
11,3,0,0,32,0,
0,0,16,0,0,0,
2,0,0,0,40,3,
0,0,0,0,0,0,
255,255,255,255,0,0,
0,0,255,255,255,255,
0,0,0,0,76,3,
0,0,48,0,0,0,
16,0,0,0,0,0,
0,0,40,3,0,0,
0,0,0,0,255,255,
255,255,0,0,0,0,
255,255,255,255,0,0,
0,0,99,3,0,0,
64,0,0,0,16,0,
0,0,2,0,0,0,
40,3,0,0,0,0,
0,0,255,255,255,255,
0,0,0,0,255,255,
255,255,0,0,0,0,
114,101,103,105,115,116,
101,114,115,95,71,82,
73,68,95,73,78,84,
69,78,83,73,84,89,
0,102,108,111,97,116,
0,171,0,0,3,0,
1,0,1,0,0,0,
0,0,0,0,0,0,
0,0,0,0,0,0,
0,0,0,0,0,0,
0,0,0,0,137,2,
0,0,114,101,103,105,
115,116,101,114,115,95,
71,82,73,68,95,87,
73,68,84,72,0,114,
101,103,105,115,116,101,
114,115,95,71,82,73,
68,95,66,73,65,83,
0,114,101,103,105,115,
116,101,114,115,95,68,
65,82,75,69,78,95,
71,82,73,68,0,114,
101,103,105,115,116,101,
114,115,95,68,65,82,
75,69,78,95,67,79,
76,79,85,82,0,114,
101,103,105,115,116,101,
114,115,95,79,117,116,
112,117,116,83,105,122,
101,0,102,108,111,97,
116,52,0,171,1,0,
3,0,1,0,4,0,
0,0,0,0,0,0,
0,0,0,0,0,0,
0,0,0,0,0,0,
0,0,0,0,0,0,
32,3,0,0,114,101,
103,105,115,116,101,114,
115,95,79,114,105,103,
105,110,97,108,83,105,
122,101,0,114,101,103,
105,115,116,101,114,115,
95,83,111,117,114,99,
101,83,105,122,101,0,
77,105,99,114,111,115,
111,102,116,32,40,82,
41,32,72,76,83,76,
32,83,104,97,100,101,
114,32,67,111,109,112,
105,108,101,114,32,49,
48,46,49,0,73,83,
71,78,44,0,0,0,
1,0,0,0,8,0,
0,0,32,0,0,0,
0,0,0,0,0,0,
0,0,3,0,0,0,
0,0,0,0,3,3,
0,0,84,69,88,67,
79,79,82,68,0,171,
171,171,79,83,71,78,
44,0,0,0,1,0,
0,0,8,0,0,0,
32,0,0,0,0,0,
0,0,0,0,0,0,
3,0,0,0,0,0,
0,0,15,0,0,0,
83,86,95,84,97,114,
103,101,116,0,171,171,
83,72,69,88,108,6,
0,0,80,0,0,0,
155,1,0,0,106,8,
0,1,89,0,0,4,
70,142,32,0,1,0,
0,0,5,0,0,0,
90,0,0,3,0,96,
16,0,2,0,0,0,
90,0,0,3,0,96,
16,0,3,0,0,0,
88,24,0,4,0,112,
16,0,2,0,0,0,
85,85,0,0,88,24,
0,4,0,112,16,0,
3,0,0,0,85,85,
0,0,98,16,0,3,
50,16,16,0,0,0,
0,0,101,0,0,3,
242,32,16,0,0,0,
0,0,104,0,0,2,
2,0,0,0,56,0,
0,8,50,0,16,0,
0,0,0,0,70,16,
16,0,0,0,0,0,
70,128,32,0,1,0,
0,0,4,0,0,0,
65,0,0,5,50,0,
16,0,0,0,0,0,
70,0,16,0,0,0,
0,0,0,0,0,10,
50,0,16,0,0,0,
0,0,70,0,16,0,
0,0,0,0,2,64,
0,0,0,0,0,63,
0,0,0,63,0,0,
0,0,0,0,0,0,
50,0,0,11,194,0,
16,0,0,0,0,0,
6,20,16,128,65,0,
0,0,0,0,0,0,
6,132,32,0,1,0,
0,0,4,0,0,0,
6,4,16,0,0,0,
0,0,56,0,0,8,
50,0,16,0,0,0,
0,0,70,0,16,0,
0,0,0,0,230,138,
32,0,1,0,0,0,
4,0,0,0,69,0,
0,139,194,0,0,128,
67,85,21,0,114,0,
16,0,1,0,0,0,
70,0,16,0,0,0,
0,0,70,126,16,0,
2,0,0,0,0,96,
16,0,2,0,0,0,
47,0,0,5,114,0,
16,0,1,0,0,0,
70,2,16,0,1,0,
0,0,52,0,0,9,
18,0,16,0,0,0,
0,0,58,0,16,128,
129,0,0,0,0,0,
0,0,42,0,16,128,
129,0,0,0,0,0,
0,0,56,0,0,7,
18,0,16,0,0,0,
0,0,10,0,16,0,
0,0,0,0,10,0,
16,0,0,0,0,0,
56,0,0,7,34,0,
16,0,0,0,0,0,
10,0,16,0,0,0,
0,0,10,0,16,0,
0,0,0,0,56,0,
0,7,18,0,16,0,
0,0,0,0,26,0,
16,0,0,0,0,0,
10,0,16,0,0,0,
0,0,50,0,0,10,
18,0,16,0,0,0,
0,0,10,0,16,128,
65,0,0,0,0,0,
0,0,1,64,0,0,
171,170,42,64,26,0,
16,0,0,0,0,0,
50,0,0,10,34,0,
16,0,0,0,0,0,
10,0,16,128,65,0,
0,0,0,0,0,0,
1,64,0,0,0,0,
64,66,1,64,0,0,
0,0,128,63,56,0,
0,7,18,0,16,0,
0,0,0,0,10,0,
16,0,0,0,0,0,
1,64,0,0,0,0,
64,66,50,0,0,10,
34,0,16,0,0,0,
0,0,26,0,16,0,
0,0,0,0,26,128,
32,0,1,0,0,0,
0,0,0,0,10,0,
16,0,0,0,0,0,
56,0,0,7,18,0,
16,0,0,0,0,0,
26,0,16,0,0,0,
0,0,10,0,16,0,
0,0,0,0,56,0,
0,8,18,0,16,0,
0,0,0,0,10,0,
16,0,0,0,0,0,
10,128,32,0,1,0,
0,0,0,0,0,0,
0,0,0,8,34,0,
16,0,0,0,0,0,
1,64,0,0,154,153,
217,63,10,128,32,0,
1,0,0,0,1,0,
0,0,56,0,0,7,
226,0,16,0,0,0,
0,0,6,9,16,0,
1,0,0,0,86,5,
16,0,0,0,0,0,
25,0,0,5,226,0,
16,0,0,0,0,0,
86,14,16,0,0,0,
0,0,56,0,0,10,
226,0,16,0,0,0,
0,0,86,14,16,0,
0,0,0,0,2,64,
0,0,0,0,0,0,
215,163,112,63,215,163,
112,63,215,163,112,63,
16,0,0,10,18,0,
16,0,1,0,0,0,
150,7,16,0,0,0,
0,0,2,64,0,0,
133,235,81,63,143,194,
117,62,143,194,117,189,
0,0,0,0,47,0,
0,5,18,0,16,0,
1,0,0,0,10,0,
16,0,1,0,0,0,
16,0,0,10,130,0,
16,0,1,0,0,0,
150,7,16,0,0,0,
0,0,2,64,0,0,
0,0,0,62,113,61,
42,63,61,10,87,62,
0,0,0,0,16,0,
0,10,34,0,16,0,
0,0,0,0,150,7,
16,0,0,0,0,0,
2,64,0,0,20,174,
71,62,154,153,153,61,
72,225,58,63,0,0,
0,0,47,0,0,5,
66,0,16,0,1,0,
0,0,26,0,16,0,
0,0,0,0,47,0,
0,5,34,0,16,0,
1,0,0,0,58,0,
16,0,1,0,0,0,
56,0,0,10,226,0,
16,0,0,0,0,0,
6,9,16,0,1,0,
0,0,2,64,0,0,
0,0,0,0,47,186,
232,62,47,186,232,62,
47,186,232,62,25,0,
0,5,226,0,16,0,
0,0,0,0,86,14,
16,0,0,0,0,0,
51,0,0,10,226,0,
16,0,0,0,0,0,
86,14,16,0,0,0,
0,0,2,64,0,0,
0,0,0,0,0,0,
128,63,0,0,128,63,
0,0,128,63,16,0,
0,10,18,0,16,0,
1,0,0,0,150,7,
16,0,0,0,0,0,
2,64,0,0,208,179,
89,62,89,23,55,63,
152,221,147,61,0,0,
0,0,0,0,0,8,
34,0,16,0,1,0,
0,0,10,0,16,128,
65,0,0,0,1,0,
0,0,1,64,0,0,
0,0,128,63,0,0,
0,12,194,0,16,0,
1,0,0,0,2,64,
0,0,0,0,0,0,
0,0,0,0,0,0,
128,63,0,0,128,63,
166,142,32,128,65,0,
0,0,1,0,0,0,
0,0,0,0,50,0,
0,9,18,0,16,0,
1,0,0,0,26,0,
16,0,1,0,0,0,
42,0,16,0,1,0,
0,0,10,0,16,0,
1,0,0,0,0,0,
0,8,226,0,16,0,
1,0,0,0,86,14,
16,128,65,0,0,0,
0,0,0,0,246,15,
16,0,1,0,0,0,
56,0,0,7,18,0,
16,0,0,0,0,0,
10,0,16,0,0,0,
0,0,10,0,16,0,
1,0,0,0,50,0,
0,9,114,0,16,0,
0,0,0,0,6,0,
16,0,0,0,0,0,
150,7,16,0,1,0,
0,0,150,7,16,0,
0,0,0,0,56,0,
0,8,50,0,16,0,
1,0,0,0,70,16,
16,0,0,0,0,0,
70,128,32,0,1,0,
0,0,2,0,0,0,
65,0,0,5,50,0,
16,0,1,0,0,0,
70,0,16,0,1,0,
0,0,0,0,0,10,
50,0,16,0,1,0,
0,0,70,0,16,0,
1,0,0,0,2,64,
0,0,0,0,0,63,
0,0,0,63,0,0,
0,0,0,0,0,0,
56,0,0,10,50,0,
16,0,1,0,0,0,
70,0,16,0,1,0,
0,0,2,64,0,0,
0,0,128,57,0,0,
128,57,0,0,0,0,
0,0,0,0,69,0,
0,139,194,0,0,128,
67,85,21,0,114,0,
16,0,1,0,0,0,
70,0,16,0,1,0,
0,0,70,126,16,0,
3,0,0,0,0,96,
16,0,3,0,0,0,
50,0,0,10,114,0,
16,0,1,0,0,0,
70,2,16,0,1,0,
0,0,70,2,16,0,
0,0,0,0,70,2,
16,128,65,0,0,0,
0,0,0,0,16,0,
0,10,130,0,16,0,
0,0,0,0,70,2,
16,0,0,0,0,0,
2,64,0,0,208,179,
89,62,89,23,55,63,
152,221,147,61,0,0,
0,0,50,0,0,9,
114,32,16,0,0,0,
0,0,246,15,16,0,
0,0,0,0,70,2,
16,0,1,0,0,0,
70,2,16,0,0,0,
0,0,54,0,0,5,
130,32,16,0,0,0,
0,0,1,64,0,0,
0,0,128,63,62,0,
0,1,83,84,65,84,
148,0,0,0,47,0,
0,0,2,0,0,0,
0,0,0,0,2,0,
0,0,43,0,0,0,
0,0,0,0,0,0,
0,0,1,0,0,0,
0,0,0,0,0,0,
0,0,0,0,0,0,
0,0,0,0,0,0,
0,0,0,0,0,0,
2,0,0,0,0,0,
0,0,0,0,0,0,
0,0,0,0,0,0,
0,0,1,0,0,0,
0,0,0,0,2,0,
0,0,0,0,0,0,
0,0,0,0,0,0,
0,0,0,0,0,0,
0,0,0,0,0,0,
0,0,0,0,0,0,
0,0,0,0,0,0,
0,0,0,0,0,0,
0,0,0,0,0,0,
0,0,0,0,0,0,
0,0,0,0,0,0,
0,0
};

}

namespace RetroArch
{
class HandheldShadersSimpletex_lcdSimpletex_lcdGbcColor4kShaderDef : public ShaderDef
{
public:
	HandheldShadersSimpletex_lcdSimpletex_lcdGbcColor4kShaderDef() : ShaderDef{}
	{
		Name = "simpletex_lcd+gbc-color-4k";
		VertexByteCode = RetroArchHandheldShadersSimpletex_lcdSimpletex_lcdGbcColor4kShaderDefs::sVertexByteCode;
		VertexLength = sizeof(RetroArchHandheldShadersSimpletex_lcdSimpletex_lcdGbcColor4kShaderDefs::sVertexByteCode);
		FragmentByteCode = RetroArchHandheldShadersSimpletex_lcdSimpletex_lcdGbcColor4kShaderDefs::sFragmentByteCode;
		FragmentLength = sizeof(RetroArchHandheldShadersSimpletex_lcdSimpletex_lcdGbcColor4kShaderDefs::sFragmentByteCode);
		Params.push_back(ShaderParam("GRID_INTENSITY", -1, 0, 4, 0.000000f, 1.000000f, 1.000000f, 0.050000f, "Grid Intensity"));
		Params.push_back(ShaderParam("GRID_WIDTH", -1, 4, 4, 0.000000f, 1.000000f, 1.000000f, 0.050000f, "Grid Width"));
		Params.push_back(ShaderParam("GRID_BIAS", -1, 8, 4, 0.000000f, 1.000000f, 0.000000f, 0.050000f, "Grid Bias"));
		Params.push_back(ShaderParam("DARKEN_GRID", -1, 12, 4, 0.000000f, 1.000000f, 0.000000f, 0.050000f, "Darken Grid"));
		Params.push_back(ShaderParam("DARKEN_COLOUR", -1, 16, 4, 0.000000f, 2.000000f, 0.000000f, 0.050000f, "Darken Colours"));
		Params.push_back(ShaderParam("MVP", 0, 0, 64, 0.000000f, 0.000000f, 0.000000f, 0.000000f, ""));
		Params.push_back(ShaderParam("SourceSize", -1, 64, 16, 0.000000f, 0.000000f, 0.000000f, 0.000000f, ""));
		Params.push_back(ShaderParam("OriginalSize", -1, 48, 16, 0.000000f, 0.000000f, 0.000000f, 0.000000f, ""));
		Params.push_back(ShaderParam("OutputSize", -1, 32, 16, 0.000000f, 0.000000f, 0.000000f, 0.000000f, ""));
		Samplers.push_back(ShaderSampler("Source", 2));
		Samplers.push_back(ShaderSampler("BACKGROUND", 3));
/*
VertexSource = %*VERTEX_SOURCE*%;
*/
/*
FragmentSource = %*FRAGMENT_SOURCE*%;
*/
	}
};
}
