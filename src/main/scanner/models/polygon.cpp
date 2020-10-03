#include <models/polygon.hpp>

        polygon::polygon(const std::vector<Eigen::Vector2d>& vertices_) : vertices(vertices_) {
            for(int i = 1; i < vertices.size(); i++) {
                sides.push_back(line_segment(vertices[i - 1], vertices[i]));
            }

            sides.push_back(line_segment(vertices[vertices.size() - 1], vertices[0]));
        }

        rectangle polygon::frame() {
			double min_x = FLT_MAX , max_x = -FLT_MAX,
			 min_y = FLT_MAX, max_y = -FLT_MAX;
				
					for(int i = 0; i < vertices.size(); i++) {
						if(vertices[i](0) < min_x) {
							min_x = vertices[i](0);
						}
						if(vertices[i](0) > max_x) {
							max_x = vertices[i](0);
						}
						if(vertices[i](1) < min_y) {
							min_y = vertices[i](1);
						}
						if(vertices[i](1) > max_y) {
							max_y = vertices[i](1);
						}
					}		
			
			return rectangle(Eigen::Vector2f(min_x, min_y), Eigen::Vector2d(max_x, max_y));
        }

		polygon polygon::translate(const Eigen::Vector2d& r0) {		
				std::vector<Eigen::Vector2d> vertices_tr = vertices;

				for(auto& v : vertices_tr) {
					v += r0;
				}


	        return polygon(vertices_tr);
		}