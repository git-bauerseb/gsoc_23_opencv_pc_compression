#include <vector>
#include "vec.h"

namespace pc_comp {
    class PointCloud {

        public:
            PointCloud() = default;
            void addPoint(Vec3f point) {m_points.push_back(point);}
            std::vector<Vec3f> point_cloud() {return m_points;}

        private:
            std::vector<Vec3f> m_points;
    };
}