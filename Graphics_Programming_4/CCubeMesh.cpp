#include "CCubeMesh.h"

using namespace glm;
CCubeMesh::CCubeMesh()
{
	m_Vertices = std::vector<Vertex>
	{
		//				 Position			   Color			 TexCoord			  Normal
		//            x     y     z			r	 g	   b		  u	    v		    nx	 ny	  nz
		//front-plane 
		Vertex{vec3(-.5f, -.5f ,.5f), vec3(1.0f, 1.0f, 1.0f), vec2(.0f,  .0f), vec3(.0f, .0f, 1.0f)}, //0
		Vertex{vec3(.5f,  -.5f ,.5f), vec3(1.0f, 1.0f, 1.0f), vec2(1.0f, .0f), vec3(.0f, .0f, 1.0f)}, //1
		Vertex{vec3(.5f,  .5f ,.5f), vec3(1.0f, 1.0f, 1.0f), vec2(1.0f, 1.0f), vec3(.0f, .0f, 1.0f)}, //2
		Vertex{vec3(-.5f, .5f ,.5f), vec3(1.0f, 1.0f, 1.0f), vec2(.0f,  1.0f), vec3(.0f, .0f, 1.0f)}, //3

		//back-plane 
		Vertex{vec3(-.5f,-.5f ,-.5f), vec3(1.0f, 1.0f, 1.0f), vec2(.0f,  .0f), vec3(.0f, .0f, -1.0f)}, //4
		Vertex{vec3(.5f,-.5f ,-.5f), vec3(1.0f, 1.0f, 1.0f), vec2(1.0f, .0f), vec3(.0f, .0f, -1.0f)}, //5
		Vertex{vec3(.5f, .5f ,-.5f), vec3(1.0f, 1.0f, 1.0f), vec2(1.0f, 1.0f), vec3(.0f, .0f, -1.0f)}, //6
		Vertex{vec3(-.5f, .5f ,-.5f), vec3(1.0f, 1.0f, 1.0f), vec2(.0f, 1.0f), vec3(.0f, .0f, -1.0f)}, //7

		//left-plane 
		Vertex{vec3(-.5f,-.5f , -.5f), vec3(1.0f, 1.0f, 1.0f), vec2(.0f,  .0f), vec3(-1.0f, .0f, .0f)}, //8
		Vertex{vec3(-.5f,.5f ,-.5f), vec3(1.0f, 1.0f, 1.0f), vec2(1.0f, .0f), vec3(-1.0f, .0f, .0f)}, //9
		Vertex{vec3(-.5f, .5f ,.5f), vec3(1.0f, 1.0f, 1.0f), vec2(1.0f, 1.0f), vec3(-1.0f, .0f, .0f)}, //10
		Vertex{vec3(-.5f, -.5f , .5f), vec3(1.0f, 1.0f, 1.0f), vec2(.0f, 1.0f), vec3(-1.0f, .0f, .0f)}, //11

		//right-plane
		Vertex{vec3(.5f,-.5f ,-.5f), vec3(1.0f, 1.0f, 1.0f), vec2(.0f,  .0f), vec3(1.0f, .0f, .0f)}, //12
		Vertex{vec3(.5f,.5f , -.5f), vec3(1.0f, 1.0f, 1.0f), vec2(1.0f, .0f), vec3(1.0f, .0f, .0f)}, //13
		Vertex{vec3(.5f,.5f , .5f), vec3(1.0f, 1.0f, 1.0f), vec2(1.0f, 1.0f), vec3(1.0f, .0f, .0f)}, //14
		Vertex{vec3(.5f, -.5f ,.5f), vec3(1.0f, 1.0f, 1.0f), vec2(.0f, 1.0f), vec3(1.0f, .0f, .0f)}, //15

		//top-plane 
		Vertex{vec3(-.5f, .5f , -.5f), vec3(1.0f, 1.0f, 1.0f), vec2(.0f,  .0f), vec3(.0f, 1.0f, .0f)}, //16
		Vertex{vec3(.5f, .5f , -.5f), vec3(1.0f, 1.0f, 1.0f), vec2(1.0f, .0f), vec3(.0f, 1.0f, .0f)}, //17
		Vertex{vec3(.5f, .5f ,.5f), vec3(1.0f, 1.0f, 1.0f), vec2(1.0f, 1.0f), vec3(.0f, 1.0f, .0f)}, //18
		Vertex{vec3(-.5f, .5f ,.5f), vec3(1.0f, 1.0f, 1.0f), vec2(.0f, 1.0f), vec3(.0f, 1.0f, .0f)}, //19

		//bottom-plane
		Vertex{vec3(-.5f,-.5f ,-.5f), vec3(1.0f, 1.0f, 1.0f), vec2(.0f,  .0f), vec3(.0f, -1.0f, .0f)}, //20
		Vertex{vec3(.5f,-.5f , -.5f), vec3(1.0f, 1.0f, 1.0f), vec2(1.0f, .0f), vec3(.0f, -1.0f, .0f)}, //21
		Vertex{vec3(.5f,-.5f , .5f), vec3(1.0f, 1.0f, 1.0f), vec2(1.0f, 1.0f), vec3(.0f, -1.0f, .0f)}, //22
		Vertex{vec3(-.5f,-.5f ,.5f), vec3(1.0f, 1.0f, 1.0f), vec2(.0f, 1.0f), vec3(.0f, -1.0f, .0f)}, //23
	};

	m_Indicies = std::vector<unsigned int>
	{
	    0, 1, 2,		  2, 3, 0,    // Front face
		7, 6, 5,		  5, 4, 7,    // Back face 
		8, 10, 9,		 10, 8, 11,  // Left face
		15, 13, 14,		 13, 15, 12, // Right face
		16, 18, 17,		 18, 16, 19, // Top face
		20, 21, 22,		 22, 23, 20  // Bottom face
	};
}


