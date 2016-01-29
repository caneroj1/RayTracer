//
//  main.cpp
//  RayTracer
//
//  Created by Joseph Canero on 1/28/16.
//  Copyright © 2016 jcanero. All rights reserved.
//

#include <iostream>
#include "src/ppm_printer.hpp"
#include "src/types/vec3.h"
#include "src/types/ray.hpp"

using namespace std;

int main(int argc, const char * argv[]) {
//    write_ppm_2color(200, 100, 0.2, "/Users/jcanero/Desktop/file.ppm");
    
    string fname("/Users/jcanero/Desktop/r2k.ppm");
    
    int x_start = 200;
    int y_start = 100;
    double blue = 0.2;
    
    fstream f;
    f.open(fname, ios_base::out);
    
    if (!f.is_open())
        return -1;
    
    vec3 lower_left_corner(-2.0, -1.0, -1.0);
    vec3 horizontal(4.0, 0.0, 0.0);
    vec3 vertical(0.0, 2.0, 0.0);
    vec3 origin;
    
    f << "P3\n" << x_start << " " << y_start << "\n255\n";
    for (int y = y_start - 1; y >= 0; y--)
    {
        for (int x = 0; x < x_start; x++)
        {
            double u = (double) x / x_start;
            double v = (double) y / y_start;
            
            ray r(origin, lower_left_corner + horizontal.scale(u) + vertical.scale(v));
            vec3 color = linear_blend_r2k(r);
            
            int ir = int(255.99 * color.r());
            int ig = int(255.99 * color.g());
            int ib = int(255.99 * color.b());
            
            f << ir << " " << ig << " " << ib << endl;
        }
    }
    
    f.close();
    
    return 0;
}
