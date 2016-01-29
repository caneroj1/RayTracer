//
//  ppm_printer.hpp
//  RayTracer
//
//  Created by Joseph Canero on 1/28/16.
//  Copyright © 2016 jcanero. All rights reserved.
//

#ifndef ppm_printer_hpp
#define ppm_printer_hpp

#include <iostream>
#include <fstream>

void print_ppm_2color(int x_start, int y_start, double blue);
void write_ppm_2color(int x_start, int y_start, double blue, std::string fname);

#endif /* ppm_printer_hpp */
