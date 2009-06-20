#include <string>
#ifndef VEC3F
#define VEC3F
class Vec3f {
  public:
    Vec3f();
    Vec3f(float x, float y, float z);
    Vec3f(Vec3f *old);
    ~Vec3f();
    float getLength();
    void normalize();
    void add(Vec3f *vec);
    Vec3f* addR(Vec3f *vec);
    void sub(Vec3f *vec);
    Vec3f* subR(Vec3f *vec);
    void mult(float scalar);
    void div(float scalar);
    Vec3f* getCrossProd(Vec3f *vector);
    std::string toString();
    float x;
    float y;
    float z;
};
#endif