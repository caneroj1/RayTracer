//
//  vec3.h
//  RayTracer
//
//  Created by Joseph Canero on 1/28/16.
//  Copyright © 2016 jcanero. All rights reserved.
//

#ifndef vec3_h
#define vec3_h

#include "boost/tuple/tuple.hpp"
#include <cmath>

using namespace boost;

namespace vec3_detail {
    typedef tuple<double, double, double> vec3;
} // namespace vec3_detail

struct vec3 {
    vec3() {
        m_vec = make_tuple(0, 0, 0);
    }
    
    vec3(double unit) {
        m_vec = make_tuple(unit, unit, unit);
    }
    
    vec3(double x, double y , double z) {
       m_vec = make_tuple(x, y ,z);
    }
    
    vec3 operator+(const vec3& other) const {
        return vec3(x() + other.x(),
                    y() + other.y(),
                    z() + other.z());
    }
    
    vec3 operator-(const vec3& other) const {
        return vec3(x() - other.x(),
                    y() - other.y(),
                    z() - other.z());
    }
    
    double length() const {
        return sqrt(squared_length());
    }
    
    double squared_length() const {
        return x() * x() + y() * y() + z() * z();
    }
    
    vec3 unit_vector() const {
        double mag = length();
        return vec3(x() / mag,
                    y() / mag,
                    z() / mag);
    }
    
    double operator*(const vec3& other) const {
        return  x() * other.x() +
                y() * other.y() +
                z() * other.z();
    }
    
    double dot(const vec3& other) const {
        return this->operator*(other);
    }
    
    vec3 cross(const vec3& other) const {
        return vec3(
            y() * other.z() - z() * other.y(),
            -(x() * other.z() - z() * other.x()),
            x() * other.y() - y() * other.x()
        );
    }
    
    vec3 scale(double factor) const {
        return vec3(
            x() * factor,
            y() * factor,
            z() * factor
        );
    }
    
    double x() const {
        return m_vec.get<0>();
    }
    
    double r() const {
        return m_vec.get<0>();
    }
    
    double y() const {
        return m_vec.get<1>();
    }
    
    double g() const {
        return m_vec.get<1>();
    }
    
    double z() const {
        return m_vec.get<2>();
    }
    
    double b() const {
        return m_vec.get<2>();
    }
    
    static vec3 interpolate(double t, const vec3& start, const vec3& end)
    {
        return start.scale(1.0 - t) + end.scale(t);
    }
    
private:
    vec3_detail::vec3 m_vec;
};

#endif /* vec3_h */
