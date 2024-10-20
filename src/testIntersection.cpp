#include "IntersectionApi.h"
#include <iostream>
#include <math.h>

#define pi 3.1415926

int main()
{
	// Test 1 : edge and box test
	float boxCenter[3]{ 0,0,0 };
	float boxHalfSize[3]{ 2,1,1 };
	float triVertex[3][3]{
		{2,1,1},
		{2,1,-1},
		{3,1,1}
	};

	std::cout << "Edge-edge Tri-AABB intersection: " << triBoxOverlap(boxCenter, boxHalfSize, triVertex) << "\n";

	// Test 2 : Triangle - OBB intersection test
	triVertex[0][0] = 1; triVertex[0][1] = 1; triVertex[0][2] = 0;
	triVertex[1][0] = 0; triVertex[1][1] = 2; triVertex[1][2] = 1;
	triVertex[2][0] = 2; triVertex[2][1] = 0; triVertex[2][2] = 1;
	float obb_center[3]{ 0,0,0 };
	float obb_halfsize[3]{ 1,1,1 };
	float obb_axes[3][3]{
		{cos(pi/4),-sin(pi/4),0},
		{sin(pi/4),cos(pi/4),0},
		{0,0,1}
	};
	std::cout << "Triangle-Obb test: intersection?: " << triOBBOverlap(triVertex, obb_center,
			obb_halfsize, obb_axes)<<"\n";
	std::cout << "Triangle-AABB test: intersection?: " << triBoxOverlap(obb_center, obb_halfsize,
		triVertex) << "\n";

	// Test 3 : obb half point test
	triVertex[0][0] = 1; triVertex[0][1] = 0; triVertex[0][2] = 0;
	triVertex[1][0] = 0; triVertex[1][1] = 2; triVertex[1][2] = 1;
	triVertex[2][0] = 2; triVertex[2][1] = 0; triVertex[2][2] = 1;
	std::cout << "Triangle-Obb test: intersection?: " << triOBBOverlap(triVertex, obb_center,
		obb_halfsize, obb_axes) << "\n";
	
	return 0;
}