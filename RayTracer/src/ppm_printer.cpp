//
//  ppm_printer.cpp
//  RayTracer
//
//  Created by Joseph Canero on 1/28/16.
//  Copyright © 2016 jcanero. All rights reserved.
//

#include "ppm_printer.hpp"
#include "types/vec3.h"

using namespace std;

void print_ppm_2color(int x_start, int y_start, double blue)
{
    cout << "P3\n" << x_start << " " << y_start << "\n255\n";
    for (int y = y_start - 1; y >= 0; y--)
    {
        for (int x = 0; x < x_start; x++)
        {
            vec3 v((double) x / x_start, (double) y / y_start, blue);
            
            int ir = int(255.99 * v.r());
            int ig = int(255.99 * v.g());
            int ib = int(255.99 * v.b());
            
            cout << ir << " " << ig << " " << ib << endl;
        }
    }
}

void write_ppm_2color(int x_start, int y_start, double blue, string fname)
{
    fstream f;
    f.open(fname, ios_base::out);
    
    if (!f.is_open())
        return;
    
    f << "P3\n" << x_start << " " << y_start << "\n255\n";
    for (int y = y_start - 1; y >= 0; y--)
    {
        for (int x = 0; x < x_start; x++)
        {
            vec3 v((double) x / x_start, (double) y / y_start, blue);
            
            int ir = int(255.99 * v.r());
            int ig = int(255.99 * v.g());
            int ib = int(255.99 * v.b());
            
            f << ir << " " << ig << " " << ib << endl;
        }
    }
    
    f.close();
}