#include <math.h>
#include <stdio.h>
#include "IntersectionApi.h"

// TestPointProjectInAxis
int testAxis(float axis[3], float triverts[3][3], float obb_center[3], float obb_halfsize[3], float obb_axes[3][3]) {
	float triMin, triMax;
	float obbMin, obbMax;
	float proj;

	// calculate the project distance
	triMin = triMax = DOT(axis, triverts[0]);
	for (int i = 1; i < 3; i++) {
		proj = DOT(axis, triverts[i]);
		if (proj < triMin) triMin = proj;
		if (proj > triMax) triMax = proj;
	}

	// test the project distance to the obb axis?
	proj = DOT(axis, obb_center);
	obbMin = proj - (fabsf(DOT(axis, obb_axes[0])) * obb_halfsize[0] +
		fabsf(DOT(axis, obb_axes[1])) * obb_halfsize[1] +
		fabsf(DOT(axis, obb_axes[2])) * obb_halfsize[2]);
	obbMax = proj + (fabsf(DOT(axis, obb_axes[0])) * obb_halfsize[0] +
		fabsf(DOT(axis, obb_axes[1])) * obb_halfsize[1] +
		fabsf(DOT(axis, obb_axes[2])) * obb_halfsize[2]);

	// test the distance to the obb project distance
	if (triMax < obbMin || triMin > obbMax) return 0;
	return 1;
}

int triOBBOverlap(float triverts[3][3], float obb_center[3],
	float obb_halfsize[3], float obb_axes[3][3]) {
	float e0[3], e1[3], e2[3];
	float normal[3], axis[3];

	// Calculate the edge vector
	SUB(e0, triverts[1], triverts[0]);
	SUB(e1, triverts[2], triverts[1]);
	SUB(e2, triverts[0], triverts[2]);

	// test obb axis
	for (int i = 0; i < 3; i++) {
		if (!testAxis(obb_axes[i], triverts, obb_center, obb_halfsize, obb_axes)) return 0;
	}

	// test trianle normal
	CROSS(normal, e0, e1);
	if (!testAxis(normal, triverts, obb_center, obb_halfsize, obb_axes)) return 0;

	// test the cross triangle normal and the obb axis
	CROSS(axis, e0, obb_axes[0]);
	if (!testAxis(axis, triverts, obb_center, obb_halfsize, obb_axes)) return 0;

	CROSS(axis, e0, obb_axes[1]);
	if (!testAxis(axis, triverts, obb_center, obb_halfsize, obb_axes)) return 0;

	CROSS(axis, e0, obb_axes[2]);
	if (!testAxis(axis, triverts, obb_center, obb_halfsize, obb_axes)) return 0;

	CROSS(axis, e1, obb_axes[0]);
	if (!testAxis(axis, triverts, obb_center, obb_halfsize, obb_axes)) return 0;

	CROSS(axis, e1, obb_axes[1]);
	if (!testAxis(axis, triverts, obb_center, obb_halfsize, obb_axes)) return 0;

	CROSS(axis, e1, obb_axes[2]);
	if (!testAxis(axis, triverts, obb_center, obb_halfsize, obb_axes)) return 0;

	CROSS(axis, e2, obb_axes[0]);
	if (!testAxis(axis, triverts, obb_center, obb_halfsize, obb_axes)) return 0;

	CROSS(axis, e2, obb_axes[1]);
	if (!testAxis(axis, triverts, obb_center, obb_halfsize, obb_axes)) return 0;

	CROSS(axis, e2, obb_axes[2]);
	if (!testAxis(axis, triverts, obb_center, obb_halfsize, obb_axes)) return 0;

	// if noOverlap return 1
	return 1;
}
