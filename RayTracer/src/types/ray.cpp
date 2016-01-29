//
//  ray.cpp
//  RayTracer
//
//  Created by Joseph Canero on 1/28/16.
//  Copyright © 2016 jcanero. All rights reserved.
//

#include "ray.hpp"

vec3 linear_blend_w2b(const ray& r)
{
    vec3 unit_vector(r.direction());
    double t = 0.5 * (unit_vector.y() + 1.0);
    return vec3::interpolate(t, vec3(1.0), vec3(0.5, 0.7, 1.0));
}

vec3 linear_blend_r2k(const ray& r)
{
    vec3 unit_vector(r.direction());
    double t = 0.5 * (unit_vector.y() + 1.0);
    return vec3::interpolate(t, vec3(1.0, 0.0, 0.0), vec3());
}