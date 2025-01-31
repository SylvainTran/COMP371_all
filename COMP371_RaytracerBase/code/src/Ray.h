#pragma once
#include <math.h>
#include <Eigen/Core>
#include <Eigen/Dense>
#include <iostream>

struct Ray {
  /**
   * The origin point of the ray.
   */
  Eigen::Vector3f o;
  /**
   * This is the direction vector of the ray, usually given as the lookat vec3f.
   */
  Eigen::Vector3f d;
  // Constructors and destructor
  Ray() {
    Eigen::Vector3f origin(0,0,0);
    Eigen::Vector3f dir(0,0,-1);
    this->o = origin;
    this->d = dir;
  };
  Ray(Eigen::Vector3f o, Eigen::Vector3f d) {
    this->o = o;
    this->d = d;
  };
  ~Ray() {
  };
  Ray(Ray& other) {
    o = other.o;
    d = other.d;
  };
  Ray& operator=(Ray& other) {
    o = other.o;
    d = other.d;
    return *this;
  };
  void setRay(Eigen::Vector3f o, Eigen::Vector3f d) {
    this->o = o;
    this->d = d;
  };
  // Returns a point at o+t(d)
  Eigen::Vector3f evaluate(float t) {
    // std::cout<<"o + t*d: "<<o + (t*d)<<std::endl;
    return o+(t*d);
  };
  //Eigen::Vector3f normalize() {
    //return d * (1/sqrt((d(0)*d(0)+d(1)*d(1)+d(2)*d(2))));
  //};
  friend std::ostream& operator<<(std::ostream& out, Ray& ray) {
    out << "Ray origin: "<<ray.o<<"\nRay dir: "<<ray.d<<std::endl;
    return out;
  };
};

