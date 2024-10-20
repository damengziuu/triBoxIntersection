#ifndef INTERSECTION_API_H
#define INTERSECTION_API_H


#define CROSS(dest,v1,v2) \
dest[0] = v1[1] * v2[2] - v1[2] * v2[1]; \
dest[1] = v1[2] * v2[0] - v1[0] * v2[2]; \
dest[2] = v1[0] * v2[1] - v1[1] * v2[0];

#define DOT(v1,v2) (v1[0]*v2[0]+v1[1]*v2[1]+v1[2]*v2[2])

#define SUB(dest,v1,v2) \
dest[0] = v1[0] - v2[0]; \
dest[1] = v1[1] - v2[1]; \
dest[2] = v1[2] - v2[2];


#define FINDMINMAX(x0,x1,x2,min,max) \
  min = max = x0;   \
  if(x1<min) min=x1;\
  if(x1>max) max=x1;\
  if(x2<min) min=x2;\
  if(x2>max) max=x2;

// AABB-TRIANGLE overlaf [10/19/2024 hjx]
int triBoxOverlap(float boxcenter[3], float boxhalfSize[3], float triverts[3][3]);

/// <summary>
/// 
/// </summary>
/// <param name="triverts"></param>
/// <param name="obb_center"></param>
/// <param name="obb_halfsize"></param>
/// <param name="obb_axes"></param>
/// <returns></returns>
int triOBBOverlap(float triverts[3][3], float obb_center[3], 
	float obb_halfsize[3], float obb_axes[3][3]);

#endif
