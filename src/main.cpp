#include <iostream>
#include <glad/glad.h>
#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>



void processInput(GLFWwindow *window) {
    if(glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        std::cout << "Esc ";
    if(glfwGetKey(window, GLFW_KEY_LEFT_SHIFT) == GLFW_PRESS)
        std::cout << "Shift ";
    if(glfwGetKey(window, GLFW_KEY_UP) == GLFW_PRESS)
        std::cout << "Up ";
    if(glfwGetKey(window, GLFW_KEY_DOWN) == GLFW_PRESS)
        std::cout << "Down ";
    if(glfwGetKey(window, GLFW_KEY_LEFT) == GLFW_PRESS)
        std::cout << "Left ";
    if(glfwGetKey(window, GLFW_KEY_RIGHT) == GLFW_PRESS)
        std::cout << "Right ";
    if(glfwGetKey(window, GLFW_KEY_Z) == GLFW_PRESS)
        std::cout << "Z ";

	std::cout << std::endl;
}

int main(void) {
    std::cout << "Hello Danmaku" << std::endl;
    GLFWwindow* window;
	
    /* Initialize the library */
    if (!glfwInit())
        return -1;

	/* Add hints to specify OpenGL profile */
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

    /* Create a windowed mode window and its OpenGL context */
    window = glfwCreateWindow(800, 600, "Danmaku Game", NULL, NULL);
    if (!window) {
	    std::cout << "Failed to create window" << std::endl;
        glfwTerminate();
        return -1;
    }

    /* Make the window's context current */
    glfwMakeContextCurrent(window);

    if(!gladLoadGLLoader((GLADloadproc) glfwGetProcAddress)){
	  std::cout << "Failed to initialize GLAD" << std::endl;
	  return -1;
	};

	glViewport(0, 0, 800, 600);

    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window)){
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
	    /* Take input */
        processInput(window);
		
        /* Render here */
        glClear(GL_COLOR_BUFFER_BIT);

		/* Poll for and process events */
        glfwPollEvents();
		
        /* Swap front and back buffers */
        glfwSwapBuffers(window);
		glfwSwapInterval(1);

    }
    std::cout << "Exiting..." << std::endl;
    glfwTerminate();
    return 0;
}
