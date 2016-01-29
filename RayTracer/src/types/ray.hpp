//
//  ray.hpp
//  RayTracer
//
//  Created by Joseph Canero on 1/28/16.
//  Copyright © 2016 jcanero. All rights reserved.
//

#ifndef ray_hpp
#define ray_hpp

#include "vec3.h"

class ray {
public:
    ray() { }
    ray(const vec3& A, const vec3& B)
    : A(A)
    , B(B) { }
    
    const vec3& origin() const { return A; }
    const vec3& direction() const { return B; }
    
    vec3 p(double t) const { return A + B.scale(t); }
    
    vec3 A, B;
};

vec3 linear_blend_w2b(const ray& r);
vec3 linear_blend_r2k(const ray& r);

#endif /* ray_hpp */
