#pragma once
#include "myvcg.h"
#include <QOpenGLFunctions_4_4_Core>

//#define DEBUG

const float sin1 = sin(0.2);
const float cos1 = cos(0.2);

class MyModel : public MyMesh {
#ifdef DEBUG
	float vertices[9] = {
		-0.5f, -0.5f, -0.0f,
		0.5f, -0.5f, 0.6f,
		0.0f, 0.5f, 0.1f
	};
	int sz = 1;
#endif

#define ModeLine 0
#define ModeFill 1
	int mode = ModeLine;
	// mode = 1; 填充
	// mode = 0: 线条
	// 默认为线条

	QOpenGLFunctions_4_4_Core* gl_fun;
	unsigned int VAO;
	unsigned int VBO;
	
	float Spin[9];
	float Move[3];
	float Size[9];

	float RotateX[9] = {
		1.0f, +0.0f, 0.0f,
		0.0f, +cos1, sin1,
		0.0f, -sin1, cos1
	};

	float RotateY[9] = {
		cos1, 0.0f, -sin1,
		0.0f, 1.0f, +0.0f,
		sin1, 0.0f, +cos1
	};

	float RotateZ[9] = {
		+cos1, sin1, 0.0f,
		-sin1, cos1, 0.0f,
		+0.0f, 0.0f, 1.0f
	};

	float RotateX_[9] = {
		1.0f, +0.0f, +0.0f,
		0.0f, cos1, -sin1,
		0.0f, +sin1, cos1
	};

	float RotateY_[9] = {
		cos1, 0.0f, +sin1,
		+0.0f, 1.0f, +0.0f,
		-sin1, 0.0f, cos1
	};

	float RotateZ_[9] = {
		cos1, -sin1, 0.0f,
		+sin1, cos1, 0.0f,
		+0.0f, +0.0f, 1.0f
	};

	float Bigger[9] = {
		1.25f, 0.0f, 0.0f,
		0.0f, 1.25f, 0.0f,
		0.0f, 0.0f, 1.25f
	};

	float Smaller[9] = {
		0.8f, 0.0f, 0.0f,
		0.0f, 0.8f, 0.0f,
		0.0f, 0.0f, 0.8f
	};

	int sz1;


public: 
	MyModel(const char* filepath, QOpenGLFunctions_4_4_Core* _fun): gl_fun(_fun), MyMesh(filepath){
		InitVar();
		InitVAO_VBO();
		Update();
	}
	void InitVar() {
		memset(Spin, 0, sizeof Spin);
		memset(Move, 0, sizeof Move);
		memset(Size, 0, sizeof Size);
		Size[0] = Size[4] = Size[8] = 1;
		Spin[0] = Spin[4] = Spin[8] = 1;
	}
	void InitVAO_VBO() {

		gl_fun->glGenVertexArrays(1, &VAO);
		gl_fun->glGenBuffers(1, &VBO);
	
		gl_fun->glBindVertexArray(VAO);
		gl_fun->glBindBuffer(GL_ARRAY_BUFFER, VBO);

		//std::cout << size * sizeof(float) * 3 << std::endl;
#ifdef DEBUG
		gl_fun->glBufferData(GL_ARRAY_BUFFER, sz * sizeof(float) * 9, vertexw, GL_STATIC_DRAW);
#else	
		gl_fun->glBufferData(GL_ARRAY_BUFFER, size * sizeof(float) * 9, vertexw, GL_STATIC_DRAW);
#endif
		gl_fun->glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
		gl_fun->glEnableVertexAttribArray(0);
		
		gl_fun->glBindBuffer(GL_ARRAY_BUFFER, 0);
		gl_fun->glBindVertexArray(0);
	}
	void LoadVBO() {
		gl_fun->glBindBuffer(GL_ARRAY_BUFFER, VBO);
#ifdef DEBUG
		gl_fun->glBufferData(GL_ARRAY_BUFFER, sz * sizeof(float) * 9, vertexw, GL_STATIC_DRAW);
#else
		gl_fun->glBufferData(GL_ARRAY_BUFFER, size * sizeof(float) * 9, vertexw, GL_STATIC_DRAW);
#endif
		gl_fun->glBindBuffer(GL_ARRAY_BUFFER, 0);
	}
	
	void Mul3_3(float *A, float *B) {
		float C[9];
		for (int i = 0; i < 3; ++i) {
			for (int j = 0; j < 3; ++j) {
				C[i * 3 + j] = 0;
				for (int k = 0; k < 3; ++k) {
					C[i * 3 + j] += A[i * 3 + k] * B[k * 3 + j];
				}
			}
		}
		for (int i = 0; i < 9; ++i)
			A[i] = C[i];
	}

	void Mul1_3(float *A, float *B) {
		/*
			|0 0 0 | |1|
		    |0 0 0 | |1|
		    |0 0 0 | |1|
		*/
		float C[3];
		for (int i = 0; i < 3; ++i) {
			C[i] = 0;
			for (int j = 0; j < 3; ++j) {
				C[i] += B[i * 3 + j] * A[j];
			}
		}
		for (int i = 0; i < 3; ++i) {
			A[i] = C[i];
		}
	}

	void RotateToX() {
		Mul3_3(Spin, RotateX);
		Update();
	}
	void RotateToX_() {
		Mul3_3(Spin, RotateX_);
		Update();
	}
	void RotateToY() {
		Mul3_3(Spin, RotateY);
		Update();
	}
	void RotateToY_() {
		Mul3_3(Spin, RotateY_);
		Update();
	}
	void RotateToZ() {
		Mul3_3(Spin, RotateZ);
		Update();
	}
	void RotateToZ_() {
		Mul3_3(Spin, RotateZ_);
		Update();
	}

	void MoveX() {
		Move[0] += 0.02f;
		Update();
	}
	void MoveX_() {
		Move[0] -= 0.02f;
		Update();
	}
	void MoveY() {
		Move[1] += 0.02f;
		Update();
	}
	void MoveY_() {
		Move[1] -= 0.02f;
		Update();
	}
	void MoveZ() {
		Move[2] += 0.02f;
		Update();
	}
	void MoveZ_() {
		Move[2] -= 0.02f;
		Update();
	}

	void MakeBigger() {
		Mul3_3(Size, Bigger);
		Update();
	}
	void MakeSmaller() {
		Mul3_3(Size, Smaller);
		Update();
	}

	void Update() {

#ifdef DEBUG
		for (int i = 0; i < sz * 3; ++i) {
			vertexw[i * 3] = vertices[i * 3];
			vertexw[i * 3 + 1] = vertices[i * 3 + 1];
			vertexw[i * 3 + 2] = vertices[i * 3 + 2];
#else 
		for (int i = 0; i < size * 3; ++i) {
			vertexw[i * 3] = vertex[i * 3];
			vertexw[i * 3 + 1] = vertex[i * 3 + 1];
			vertexw[i * 3 + 2] = vertex[i * 3 + 2];
#endif
			
			Mul1_3(vertexw + i * 3, Spin);
			Mul1_3(vertexw + i * 3, Size);
			vertexw[i * 3] += Move[0];
			vertexw[i * 3 + 1] += Move[1];
			vertexw[i * 3 + 2] += Move[2];
#ifdef DEBUG
			std::cout << vertexw[i * 3] << "," << vertexw[i * 3 + 1] << "," << vertexw[i * 3 + 2] << std::endl;
#endif
		}
#ifdef DEBUG
		std::cout << std::endl;
#endif		
		LoadVBO();
		Draw();

	}

	void Draw() {
	
		gl_fun->glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
		gl_fun->glClear(GL_COLOR_BUFFER_BIT);


		gl_fun->glBindVertexArray(VAO);

		if (mode == ModeLine) {
			gl_fun->glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
			gl_fun->glCullFace(GL_BACK);
		}
		else {
			gl_fun->glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
		}
#ifdef DEBUG
		gl_fun->glDrawArrays(GL_TRIANGLES, 0, sz * 3);
#else
		gl_fun->glDrawArrays(GL_TRIANGLES, 0, size * 3);
#endif
		gl_fun->glBindVertexArray(0);
	}
	void ViewLine() {
		std::cout << "Turn to Line" << endl;
		mode = ModeLine;
		Update();
	}
	void ViewFill() {
		mode = ModeFill;
		Update();
	}

	void Sparse() {
		Simplify();
		Update();
	}

	void Encrypt() {
		Refine();
		Update();
	}

	void MSmooth() {
		Smooth();
		Update();
	}
};