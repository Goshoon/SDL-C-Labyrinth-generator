#include "math.h"
#include <cmath>
float lerp ( float a, float b, float t ) 
{
    return a + t *  ( b - a );
}

template <typename T> int Sign(T val) 
{
    return (T(0) < val) - (val < T(0));
}