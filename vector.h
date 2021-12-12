#ifndef VECTOR_H
#define VECTOR_H

#include <math.h>
#include <stdlib.h>

#ifdef VECTOR_12_BYTE_ACCURACY
        typedef long double kpnt_t;
        #define sqrt_kpnt sqrtl
#else
    #ifdef VECTOR_4_BYTE_ACCURACY
        typedef float kpnt_t;
        #define sqrt_kpnt sqrtf
    #else
        typedef double kpnt_t;
        #define sqrt_kpnt sqrt
    #endif
#endif

typedef double angle;
typedef struct vector_2D{ kpnt_t x,y; } Vector_2D;

#define _Vector_2D_ADD(v1, v2) v1.x + v2.x, v1.y + v2.y
Vector_2D Vector_2D_Add(Vector_2D v1, Vector_2D v2){
    Vector_2D res = {_Vector_2D_ADD(v1, v2)};
    return res;
}
#define _Vector_2D_SUBT(v1, v2) v1.x - v2.x, v1.y - v2.y
Vector_2D Vector_2D_Subt(Vector_2D v1, Vector_2D v2){
    Vector_2D res = {_Vector_2D_SUBT(v1, v2)};
    return res;
}
#define _Vector_2D_MUL(v, f) v.x * f, v.y * f
Vector_2D Vector_2D_Mul(Vector_2D v, kpnt_t f){
    Vector_2D res = {_Vector_2D_MUL(v, f)};
    return res;
}
#define _Vector_2D_DIV(v, q) v.x / q, v.y / q
Vector_2D Vector_2D_Div(Vector_2D v, kpnt_t q){
    Vector_2D res = {_Vector_2D_DIV(v, q)};
    return res;
}
Vector_2D Vector_2D_Apply_Func(Vector_2D v, kpnt_t func(kpnt_t)){
    Vector_2D res = {func(v.x), func(v.y)};
    return res;
}
#define _Vector_2D_MAGNITUDE_SQ(v) v.x * v.x + v.y * v.y
#define _Vector_2D_MAGNITUDE(v) sqrt_kpnt(_Vector_2D_MAGNITUDE_SQ(v))
kpnt_t Vector_2D_Magnitude_sq(Vector_2D v){
    return _Vector_2D_MAGNITUDE_SQ(v);
}
kpnt_t Vector_2D_Magnitude(Vector_2D v){
    return sqrt_kpnt(_Vector_2D_MAGNITUDE_SQ(v));
}
Vector_2D Vector_2D_Normalize(Vector_2D v){
    kpnt_t magn = _Vector_2D_MAGNITUDE(v);
    Vector_2D res = {_Vector_2D_DIV(v, magn)};
    return res;
}
#define _Vector_2D_SCALAR(v1, v2) (v1.x * v2.x + v1.y * v2.y)
kpnt_t Vector_2D_Scalar(Vector_2D v1, Vector_2D v2){
    return _Vector_2D_SCALAR(v1, v2);
}
Vector_2D Vector_2D_Rotate_right(Vector_2D v){
    Vector_2D res = {v.y, - v.x};
    return res;
}
Vector_2D Vector_2D_Rotate_left(Vector_2D v){
    Vector_2D res = {-v.y, v.x};
    return  res;
}
Vector_2D Vector_2D_Rotate(Vector_2D v, angle rad){
    Vector_2D res = {cos(rad) * v.x - sin(rad) * v.y, sin(rad) * v.x + cos(rad) * v.y};
    return res;
}
Vector_2D Vector_2D_Angle_Set(Vector_2D v, angle rad){
    kpnt_t magn = _Vector_2D_MAGNITUDE(v);
    Vector_2D res = {- sin(rad) * magn, cos(rad) * magn};
    return res;
}
Vector_2D Vector_2D_Reflect(Vector_2D v, Vector_2D line_normal){
    kpnt_t scalar = _Vector_2D_SCALAR(v, line_normal);
    Vector_2D mul_res = {_Vector_2D_MUL(line_normal, 2 * scalar)};
    Vector_2D res = {_Vector_2D_SUBT(v, mul_res)};
    return res;
}
angle Vector_2D_Angle_Between(Vector_2D v1, Vector_2D v2){
    return atan((v1.y * v2.x - v1.x * v2.y) / (v1.x * v2.x + v1.y * v2.y));
}
kpnt_t Vector_2D_Distance(Vector_2D p1, Vector_2D p2){
    kpnt_t dx = (p1.x - p2.x);
    kpnt_t dy = (p1.y - p2.y);
    return sqrt_kpnt(dx * dx + dy * dy);
}
// Vector_3D

typedef struct vector_3D{ kpnt_t x,y,z; } Vector_3D;

#define _Vector_3D_ADD(v1, v2) v1.x + v2.x, v1.y + v2.y, v1.z + v2.z
Vector_3D Vector_3D_Add(Vector_3D v1, Vector_3D v2){
    Vector_3D res = {_Vector_3D_ADD(v1, v2)};
    return res;
}
#define _Vector_3D_SUBT(v1, v2) v1.x - v2.x, v1.y - v2.y, v1.z - v2.z
Vector_3D Vector_3D_Subt(Vector_3D v1, Vector_3D v2){
    Vector_3D res = {_Vector_3D_SUBT(v1, v2)};
    return res;
}
#define _Vector_3D_MUL(v, f) v.x * f, v.y * f, v.z * f
Vector_3D Vector_3D_Mul(Vector_3D v, kpnt_t f){
    Vector_3D res = {_Vector_3D_MUL(v, f)};
    return res;
}
#define _Vector_3D_DIV(v, q) v.x / q, v.y / q, v.z / q
Vector_3D Vector_3D_Div(Vector_3D v, kpnt_t q){
    Vector_3D res = {_Vector_3D_DIV(v, q)};
    return res;
}
Vector_3D Vector_3D_Apply_Func(Vector_3D v, kpnt_t func(kpnt_t)){
    Vector_3D res = {func(v.x), func(v.y), func(v.z)};
    return res;
}

/* Vector_3D Magnitude Math */
#define _Vector_3D_MAGNITUDE_SQ(v) v.x * v.x + v.y * v.y + v.z * v.z
#define _Vector_3D_MAGNITUDE(v) sqrt_kpnt(_Vector_3D_MAGNITUDE_SQ(v))
kpnt_t Vector_3D_Magnitude_sq(Vector_3D v){
    return _Vector_3D_MAGNITUDE_SQ(v);
}
kpnt_t Vector_3D_Magnitude(Vector_3D v){
    return _Vector_3D_MAGNITUDE(v);
}
Vector_3D Vector_3D_Normalize(Vector_3D v){
    kpnt_t magn = _Vector_3D_MAGNITUDE(v);
    Vector_3D res = {_Vector_3D_DIV(v, magn)};
    return res;
}
// misc
#define _Vector_3D_SCALAR(v1, v2) (v1.x * v2.x + v1.y * v2.y + v1.z * v2.z)
kpnt_t Vector_3D_Scalar(Vector_3D v1, Vector_3D v2){
    return _Vector_3D_SCALAR(v1, v2);
}

Vector_3D Vector_3D_Rotate(Vector_3D v, angle rad){                                             // todo
    Vector_3D res = {cos(rad) * v.x - sin(rad) * v.y, sin(rad) * v.x + cos(rad) * v.y};
    return res;
}
Vector_3D Vector_3D_Angle_Set(Vector_3D v, angle rad){                                          // todo
    kpnt_t magn = _Vector_3D_MAGNITUDE(v);
    Vector_3D res = {- sin(rad) * magn, cos(rad) * magn};
    return res;
}
Vector_3D Vector_3D_Reflect(Vector_3D v, Vector_3D line_normal){
    kpnt_t scalar = _Vector_3D_SCALAR(v, line_normal);
    Vector_3D mul_res = {_Vector_3D_MUL(line_normal, 2 * scalar)};
    Vector_3D res = {_Vector_3D_SUBT(v, mul_res)};
    return res;
}
angle Vector_3D_Angle_Between(Vector_3D v1, Vector_3D v2){                                          //todo
    return atan((v1.y * v2.x - v1.x * v2.y) / (v1.x * v2.x + v1.y * v2.y));
}
kpnt_t Vector_3D_Distance(Vector_3D p1, Vector_3D p2){
    kpnt_t dx = (p1.x - p2.x);
    kpnt_t dy = (p1.y - p2.y);
    kpnt_t dz = (p1.z - p2.z);
    return sqrt_kpnt(dx * dx + dy * dy + dz * dz);
}

#endif /* VECTOR_H */



