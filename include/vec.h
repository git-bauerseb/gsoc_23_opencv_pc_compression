#include <stdint.h>

namespace pc_comp {

    template<typename T>
    class Vec3 {

        public:
            Vec3(T x, T y, T z) {
                m_coords[0] = x;
                m_coords[1] = y;
                m_coords[2] = z;
            }

            T x() const {return m_coords[0];}
            T y() const {return m_coords[1];}
            T z() const {return m_coords[2];}

            T& x() {return m_coords[0];}
            T& y() {return m_coords[1];}
            T& z() {return m_coords[2];}

        private:
            T m_coords[3];
    };

    typedef Vec3<float> Vec3f;
    typedef Vec3<uint32_t> Vec3u;
}