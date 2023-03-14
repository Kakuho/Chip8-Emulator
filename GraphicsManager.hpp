#ifndef GRAPHICS_HPP
#define GRAPHICS_HPP

#include <algorithm>
#include <array>
#include <memory>
#include <iostream>
#include <fstream>
/* E M U L A T O R */
#include "MMU.hpp"
/* G R A P H I C S */
#include "glad/glad.h"
#include <GLFW/glfw3.h>

struct DestroyglfwWin{
    void operator()(GLFWwindow* ptr){
         glfwDestroyWindow(ptr);
    }
};

class GraphicsManager {
public:
    GraphicsManager();
    GraphicsManager(std::shared_ptr<MMU>& mmu);
    ~GraphicsManager();
    /* Emulator */
    void BindMMU(std::shared_ptr<MMU>& mmu);
    /* Graphics related */
    void UploadVerticesToGPU();
    void Render();
    /* GLFW windows related */
    void ProcessInput();
    bool ShouldClose();
    void PollEvents();

private:
    /* Emulator related members */
    std::shared_ptr<MMU> mmu_;
    /* Graphics related members */
    static constexpr float vertices[]{
       // vertices          // tex
       0.5f,  0.5f, 0.0f,    1.0f, 1.0f,
       0.5f, -0.5f, 0.0f,    1.0f, 0.0f,
      -0.5f, -0.5f, 0.0f,    0.0f, 0.0f,
      -0.5f,  0.5f, 0.0f,    0.0f, 1.0f
    };
    static constexpr unsigned int elements[]{
      0, 1, 3,
      1, 2, 3
    };
    //GLuint vbo_; // VBO handle
    static constexpr unsigned int SCR_WIDTH = 800;
    static constexpr unsigned int SCR_HEIGHT = 800;
    // GLFW Initialisation
    std::unique_ptr<GLFWwindow, DestroyglfwWin> window;
    void InitGLFW();
    void MakeWindow();
    // GLAD initialisation
    void InitGlad();
    // Shader programs
    unsigned int shaderProgram;
    std::string vertexShaderString;
    std::string fragmentShaderString;
    void InitShader(const char* vertexShaderPath, const char* fragmentShaderPath);
    void ReadVertexShader(const char* vertexShaderPath);
    void ReadFragmentShader(const char* fragmentShaderPath);
    void CompileLinkShader();
    /* VAO and VBO - Buffer Objects */
    unsigned int VBO, VAO, EBO;
    void GenerateVertexObjects();
    /* TEXTURE DATA */
    unsigned int textureID;
    void InitTexture();
    void GenerateBindTexture();
    void SetTextureOptions();
    void UpdateTexture();
};

#endif
