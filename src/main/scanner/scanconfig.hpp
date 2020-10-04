#ifndef SCANCONFIG_H_
#define SCANCONFIG_H_

#include <opencv2/core.hpp>
#include <Eigen/Dense>

namespace scanner {
    class scanconfig {
        public:    
            static const int CLOCKWISE = 0,
                COUNTERCLOCKWISE = 1;     
            const int STEP = 1.8,
                HALF_STEP = 0.9;
            float angle, step_resolution; 
            int direction;

            scanconfig();
            
            void load();
    };
}

#endif
