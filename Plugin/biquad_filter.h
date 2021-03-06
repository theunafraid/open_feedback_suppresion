/*
This file is part of the Open Feedback Suppression LV2 Plugin
Copyright 2014, Jamie Jessup

Open Feedback Suppression is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

Open Feedback Suppression is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with Ardour Scene Manager. If not, see <http://www.gnu.org/licenses/>.
*/

#include <stdbool.h>
#include <stdio.h>
#include <math.h>

#ifdef __cplusplus
extern "C" {
#endif

#define PI 3.14159265358979323846264338327
#define TYPE_NOTCH "notch"
#define TYPE_PEAKING "peaking"
#define TYPE_HIPASS "hipass"
#define TYPE_LOPASS "lopass"
#define TYPE_HISHELF "hishelf"
#define TYPE_LOSHELF "loshelf"

typedef struct biQuadFilt{
    bool enabled;
    char type[10];
    float fc;
    float fs;
    float b0;
    float b1;
    float b2;
    float a0;
    float a1;
    float a2;
    float y[3];
    float x[3];
    float alpha;
    float q;
    float gain;
} BiQuadFilter;

float processFilter(BiQuadFilter *filter, float input);
float processFilterBank(BiQuadFilter *filterBank, float input, unsigned bankSize);
void newPeakingFilter(BiQuadFilter *filter, float fc, float fs, float gain, float q);
void newNotchFilter(BiQuadFilter *filter, float fc, float fs, float q);
void newNotchFilterCoeffs(BiQuadFilter *filter, float fc, float fs, float q);
void newPeakingFilterCoeffs(BiQuadFilter *filter, float fc, float fs, float gain, float q);

#ifdef __cplusplus
}
#endif
