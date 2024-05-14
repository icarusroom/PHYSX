#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <string>
#include <iostream>

#define TINYOBJLOADER_IMPLEMENTATION
#include "tiny_obj_loader.h"

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

static glm::mat4 WorldProjection;

int main(void)
{
    GLFWwindow* window;

    /* Initialize the library */
    if (!glfwInit())
        return -1;

    /* Create a windowed mode window and its OpenGL context */
    window = glfwCreateWindow(800, 800, "Gracielle Ann Jacinto", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        return -1;
    }

    /* Make the window's context current */
    glfwMakeContextCurrent(window);
    gladLoadGL();

    WorldProjection = glm::ortho(
        -400.f,
        400.f,
        -400.f,
        400.f,
        -400.f,
        400.f
        );

    /* Obj */
    OpenGLShader defaultShader = openGLShader("Shaders/samplefrag");
    OpenGLObject sphere = OpenGLObject("3D/sphere.obj");
    sphere.AssignShade(defaultShader);
    sphere.Scale = glm::vec3(100, 100, 100);

    
    while (!glfwWindowShouldClose(window))
    {
        /* Render here */
        glClear(GL_COLOR_BUFFER_BIT);

        sphere.Color = glm::vec3(0.4f, 0, 0);
        sphere.Position = glm::vec3(0, 0, 0);
        sphere.Draw();

        /* Swap front and back buffers */
        glfwSwapBuffers(window);

        /* Poll for and process events */
        glfwPollEvents(); //keyboard controls
    }

    glfwTerminate();
    return 0;
}