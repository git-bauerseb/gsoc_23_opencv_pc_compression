#include <cmath>
#include <stdint.h>

namespace pc_comp {

    // Quantizing floating-point numbers to discrete values
    // provided a maximum range of values
    class Quantizer {
        public:
            Quantizer(float range, int32_t max_value)
                : m_range{range}, m_max_value{max_value} {}

            // Quantize value to [0, m_max_value]
            int32_t operator()(float value) const {
                value *= m_range / static_cast<float>(m_max_value);
                return static_cast<int32_t>(value);//static_cast<int32_t>(std::floor(value + 0.5f));
            }

        private:
            float m_range;
            int32_t m_max_value;
    };
}