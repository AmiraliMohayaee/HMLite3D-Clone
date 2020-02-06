#ifndef TRANSFORMATION_H
#define TRANSFORMATION_H

#include <glm.hpp>
#include <gtc/matrix_transform.hpp>



class Transformation
{
public:
	Transformation();

	glm::mat4 Translation(glm::mat4 mat, glm::vec3& vec);
	glm::mat4 Rotation();
	glm::mat4 Scale();


	


};


#endif