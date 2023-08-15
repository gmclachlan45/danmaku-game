#include <iostream>
#include <glad/glad.h>
#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>

#define STB_IMAGE_IMPLEMENTATION
#include <stb/stb_image.h>

#include "player.h"


void processInput(GLFWwindow *window, player* p_player) {
    if(glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        std::cout << "Esc ";
    if(glfwGetKey(window, GLFW_KEY_LEFT_SHIFT) == GLFW_PRESS)
        std::cout << "Shift ";
    if(glfwGetKey(window, GLFW_KEY_UP) == GLFW_PRESS) {
        std::cout << "Up ";
        p_player->move_up();
    }
    if(glfwGetKey(window, GLFW_KEY_DOWN) == GLFW_PRESS) {
        std::cout << "Down ";
        p_player->move_down();
    }
    if(glfwGetKey(window, GLFW_KEY_LEFT) == GLFW_PRESS) {
        std::cout << "Left ";
        p_player->move_left();
    }
    if(glfwGetKey(window, GLFW_KEY_RIGHT) == GLFW_PRESS) {
        std::cout << "Right ";
        p_player->move_right();
    }
    if(glfwGetKey(window, GLFW_KEY_Z) == GLFW_PRESS)
        std::cout << "Z ";

	std::cout << std::endl;
}


const char *vertexShaderSource = "#version 330 core\n"
    "layout (location = 0) in vec3 aPos;\n"
    "void main() {\n"
    "   gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
    "}\0";


const char *fragmentShaderSource = "#version 330 core\n"
    "out vec4 FragColor;\n"
    "void main() {\n"
    "   FragColor = vec4(1.0f, 1.0f, 1.0f, 1.0f);"
    "}\0";



int main(void) {
	std::cout << "Hello Danmaku" << std::endl;
	// Initialize OpenGL
    if (!glfwInit())
        return -1;

	/* Add hints to specify OpenGL profile */
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

	// TODO: prompt for fullscreen or windowed depending on config



	// TODO start: Create rendering engine to handle the drawing of objects and menus
    /* Create a windowed mode window and its OpenGL context */

    GLFWwindow* window;
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

    // Vertex Buffer Preamble

    float vertices[] = {
        -0.5f, 0.5f, 0.0f,
        0.5f, 0.5f, 0.0f,
        -0.5f, -0.5f, 0.0f,
        0.5f, -0.5f, 0.0f
    };

    unsigned int VBO;
    glGenBuffers(1, &VBO);


    // Shader Preamble
    unsigned int vertexShader;
    vertexShader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
    glCompileShader(vertexShader);

    int success;
    char infoLog[512];
    glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
    if(!success) {
        glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::VERTEX::COMPILATION\n" << infoLog << std::endl;
    }

    unsigned int fragmentShader;
    fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
    glCompileShader(fragmentShader);

    glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);
    if(!success) {
        glGetShaderInfoLog(fragmentShader, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::FRAGMENT::COMPILATION\n" << infoLog << std::endl;
    }

    unsigned int shaderProgram;
    shaderProgram = glCreateProgram();
    glAttachShader(shaderProgram, vertexShader);
    glAttachShader(shaderProgram, fragmentShader);
    glLinkProgram(shaderProgram);

    glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
    if(!success) {
        glGetProgramInfoLog(shaderProgram, 512, NULL, infoLog);
        std::cout <<"ERROR::SHADER::LINK\n" <<infoLog <<std::endl;
        return -1;
    }

    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);

    // Vertex Array Object preamble
    unsigned int VAO;
    glGenVertexArrays(1, &VAO);

    // bind Vertex Array Object
    glBindVertexArray(VAO);

    // Copy our vertices array into a buffer for OpenGl to use
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    //Then set the vertex attribute pointers
    glVertexAttribPointer(0,3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    // Use our shader program when we want to render an object
    glUseProgram(shaderProgram);


    glViewport(0, 0, 800, 600);


	// End of TODO
	// Game game;

    player MainPlayer;
    player* pMainPlayer = & MainPlayer;
    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window)){
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
	    /* Take input */
        processInput(window, pMainPlayer);

        /* Render here */
        glClear(GL_COLOR_BUFFER_BIT);

        // Draw the object
        glBindVertexArray(VAO);

        glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);

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
