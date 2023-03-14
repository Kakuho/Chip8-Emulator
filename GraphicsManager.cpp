#include "GraphicsManager.hpp"
#include <memory>
#include <ostream>

GraphicsManager::GraphicsManager(){
  InitGLFW();
  InitGlad();
  InitShader("shaders/VertexShader.glsl", "shaders/FragmentShader.glsl");
  GenerateVertexObjects();
  UploadVerticesToGPU();
}

GraphicsManager::GraphicsManager(std::shared_ptr<MMU>& mmu){
  mmu_ = mmu;
  InitGLFW();
  InitGlad();
  std::cout << "Innited GLAD and GLFW" << std::endl;
  InitShader("./../shaders/VertexShader.glsl", 
      "./../shaders/FragmentShader.glsl");
  std::cout << "Innited SHADERS" << std::endl;
  GenerateVertexObjects();
  std::cout << "END_INIT_GRAPHICS" << std::endl;
  InitTexture();
}

GraphicsManager::~GraphicsManager(){
  glDeleteProgram(shaderProgram);
  glDeleteVertexArrays(1, &VAO);
  glDeleteBuffers(1, &VBO);
  glfwTerminate();
}

/*****************************************************************************/

void GraphicsManager::BindMMU(std::shared_ptr<MMU>& mmu){
  mmu_ = mmu;
}

/* GPU */

void GraphicsManager::UploadVerticesToGPU() {
  /*
  glBindBuffer(GL_ARRAY_BUFFER, VBO);
  glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(float), vertices.data(), 
               GL_STATIC_DRAW);
  glBindBuffer(GL_ARRAY_BUFFER, 0);
  */
}

/* GRAPHICS */

void GraphicsManager::Render(){
  glClearColor(1.0f, 1.0f, 0.0f, 1.0f);
  glClear(GL_COLOR_BUFFER_BIT);
  /* UPDATE TEXTURED QUAD */
  UpdateTexture();
  /* DRAW THE TEXTURE ONTO THE QUAD */
  glActiveTexture(GL_TEXTURE0);
  glBindTexture(GL_TEXTURE0, textureID);
  /* DRAW VERTICES */
  glUseProgram(shaderProgram);
  glBindVertexArray(VAO);
  glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
  //mmu_->printASCII();
  /* double buffering */
  glfwSwapBuffers(window.get());
}

void GraphicsManager::ProcessInput(){
  if(glfwGetKey(window.get(), GLFW_KEY_ESCAPE) == GLFW_PRESS){
    glfwSetWindowShouldClose(window.get(), true);
  }
  /* key pressing */
  if(glfwGetKey(window.get(), GLFW_KEY_1) == GLFW_PRESS){
    mmu_->KeyPress(0x01);
  }
  if(glfwGetKey(window.get(), GLFW_KEY_2) == GLFW_PRESS){
    mmu_->KeyPress(0x02);
  }
  if(glfwGetKey(window.get(), GLFW_KEY_3) == GLFW_PRESS){
    mmu_->KeyPress(0x03);
  }
  if(glfwGetKey(window.get(), GLFW_KEY_4) == GLFW_PRESS){
    mmu_->KeyPress(0x0C);
  }
  if(glfwGetKey(window.get(), GLFW_KEY_Q) == GLFW_PRESS){
    mmu_->KeyPress(0x04);
  }
  if(glfwGetKey(window.get(), GLFW_KEY_W) == GLFW_PRESS){
    mmu_->KeyPress(0x05);
  }
  if(glfwGetKey(window.get(), GLFW_KEY_E) == GLFW_PRESS){
    mmu_->KeyPress(0x06);
  }
  if(glfwGetKey(window.get(), GLFW_KEY_R) == GLFW_PRESS){
    mmu_->KeyPress(0x0D);
  }
  if(glfwGetKey(window.get(), GLFW_KEY_A) == GLFW_PRESS){
    mmu_->KeyPress(0x07);
  }
  if(glfwGetKey(window.get(), GLFW_KEY_S) == GLFW_PRESS){
    mmu_->KeyPress(0x08);
  }
  if(glfwGetKey(window.get(), GLFW_KEY_D) == GLFW_PRESS){
    mmu_->KeyPress(0x09);
  }
  if(glfwGetKey(window.get(), GLFW_KEY_F) == GLFW_PRESS){
    mmu_->KeyPress(0x0E);
  }
  if(glfwGetKey(window.get(), GLFW_KEY_Z) == GLFW_PRESS){
    mmu_->KeyPress(0x0A);
  }
  if(glfwGetKey(window.get(), GLFW_KEY_X) == GLFW_PRESS){
    mmu_->KeyPress(0x00);
  }
  if(glfwGetKey(window.get(), GLFW_KEY_C) == GLFW_PRESS){
    mmu_->KeyPress(0x0B);
  }
  if(glfwGetKey(window.get(), GLFW_KEY_V) == GLFW_PRESS){
    mmu_->KeyPress(0x0F);
  }
  /* Key unpressing */
  if(glfwGetKey(window.get(), GLFW_KEY_1) == GLFW_RELEASE){
    mmu_->KeyUnpress(0x01);
  }
  if(glfwGetKey(window.get(), GLFW_KEY_2) == GLFW_RELEASE){
    mmu_->KeyUnpress(0x02);
  }
  if(glfwGetKey(window.get(), GLFW_KEY_3) == GLFW_RELEASE){
    mmu_->KeyUnpress(0x03);
  }
  if(glfwGetKey(window.get(), GLFW_KEY_4) == GLFW_RELEASE){
    mmu_->KeyUnpress(0x0C);
  }
  if(glfwGetKey(window.get(), GLFW_KEY_Q) == GLFW_RELEASE){
    mmu_->KeyUnpress(0x04);
  }
  if(glfwGetKey(window.get(), GLFW_KEY_W) == GLFW_RELEASE){
    mmu_->KeyUnpress(0x05);
  }
  if(glfwGetKey(window.get(), GLFW_KEY_E) == GLFW_RELEASE){
    mmu_->KeyUnpress(0x06);
  }
  if(glfwGetKey(window.get(), GLFW_KEY_R) == GLFW_RELEASE){
    mmu_->KeyUnpress(0x0D);
  }
  if(glfwGetKey(window.get(), GLFW_KEY_A) == GLFW_RELEASE){
    mmu_->KeyUnpress(0x07);
  }
  if(glfwGetKey(window.get(), GLFW_KEY_S) == GLFW_RELEASE){
    mmu_->KeyUnpress(0x08);
  }
  if(glfwGetKey(window.get(), GLFW_KEY_D) == GLFW_RELEASE){
    mmu_->KeyUnpress(0x09);
  }
  if(glfwGetKey(window.get(), GLFW_KEY_F) == GLFW_RELEASE){
    mmu_->KeyUnpress(0x0E);
  }
  if(glfwGetKey(window.get(), GLFW_KEY_Z) == GLFW_RELEASE){
    mmu_->KeyUnpress(0x0A);
  }
  if(glfwGetKey(window.get(), GLFW_KEY_X) == GLFW_RELEASE){
    mmu_->KeyUnpress(0x00);
  }
  if(glfwGetKey(window.get(), GLFW_KEY_C) == GLFW_RELEASE){
    mmu_->KeyUnpress(0x0B);
  }
  if(glfwGetKey(window.get(), GLFW_KEY_V) == GLFW_RELEASE){
    mmu_->KeyUnpress(0x0F);
  }
}

/* Private methods */

void GraphicsManager::InitGLFW(){
  // initialises GLFW
  glfwInit();
  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
  MakeWindow();
  // some helper functions
  glfwSetFramebufferSizeCallback(window.get(), 
      [](GLFWwindow* window, int width, int height)
      {glViewport(0,0, width, height);});
}

void GraphicsManager::MakeWindow(){
  window = std::unique_ptr<GLFWwindow, DestroyglfwWin>
    (glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "LearnOpenGL", NULL, NULL));
  glfwMakeContextCurrent(window.get());
}

bool GraphicsManager::ShouldClose(){
  return glfwWindowShouldClose(window.get());
}

void GraphicsManager::PollEvents(){
  glfwPollEvents();
}

/* GLAD */

void GraphicsManager::InitGlad(){
  if(!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)){
    std::cout << "ERROR::CANNOT_LOAD_GLAD" << std::endl;
  }
}

/*** S H A D E R S ***/

void GraphicsManager::InitShader(const char* vertexShaderPath, 
    const char* fragmentShaderPath){
  ReadVertexShader(vertexShaderPath);
  ReadFragmentShader(fragmentShaderPath);
  CompileLinkShader();
  glUseProgram(shaderProgram);
}

// I tried const std::string& and it didn't work, so now i will try const char*

void GraphicsManager::ReadVertexShader(const char* vertexShaderPath){
  std::cout << vertexShaderPath << '\n';
  std::ifstream vSourceFile{vertexShaderPath};
  if(!vSourceFile){
    throw std::runtime_error{"ERROR:SHADER::VERTEX_FILE_CANNOT_BE_READ"};
  }
  else{
    vSourceFile.seekg(0, vSourceFile.end);
    unsigned int vsize = vSourceFile.tellg();
    char* vbuff = new char[vsize];
    vSourceFile.seekg(0, vSourceFile.beg);
    vSourceFile.read(vbuff, vsize);
    for(int i = 0; i < vsize; ++i){
      vertexShaderString.push_back(vbuff[i]);
    }
    delete[] vbuff;
  }
}

void GraphicsManager::ReadFragmentShader(const char* fragmentShaderPath){
  std::ifstream fSourceFile{fragmentShaderPath};
  if(!fSourceFile){
    throw std::runtime_error{"ERROR:SHADER::FRAGMENT_FILE_CANNOT_BE_READ"};
  }
  else{
    fSourceFile.seekg(0, fSourceFile.end);
    unsigned int fsize = fSourceFile.tellg();
    char* fbuff = new char[fsize];
    fSourceFile.seekg(0, fSourceFile.beg);
    fSourceFile.read(fbuff, fsize);
    for(int i = 0; i < fsize; ++i){
      fragmentShaderString.push_back(fbuff[i]);
    }
    delete[] fbuff;
  }
}

void GraphicsManager::CompileLinkShader(){
    /* Preamble */
    int success;
    char infoLog[512];
    const char* vertexShaderSource = vertexShaderString.c_str();
    const char* fragmentShaderSource = fragmentShaderString.c_str();
    /* Bind and compile vertex shader */
    unsigned int vertexShader = glCreateShader(GL_VERTEX_SHADER); 
    glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
    glCompileShader(vertexShader);
    // check for shader compile errors
    glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
    if (!success)
    {
        glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" 
                  << infoLog << std::endl;
    }
    /* Bind and compile fragment shader */
    unsigned int fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
    glCompileShader(fragmentShader);
    // check for shader compile errors
    glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);
    if (!success)
    {
        glGetShaderInfoLog(fragmentShader, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n" 
                  << infoLog << std::endl;
    }
    /* Linking shaders */
    shaderProgram = glCreateProgram();
    glAttachShader(shaderProgram, vertexShader);
    glAttachShader(shaderProgram, fragmentShader);
    glLinkProgram(shaderProgram);
    // check for linking errors
    glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
    if (!success) {
        glGetProgramInfoLog(shaderProgram, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::PROGRAM::LINKING_FAILED\n" 
                  << infoLog << std::endl;
    }
    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);
}

/* VERTEX BUFFER OBJECTS */

void GraphicsManager::GenerateVertexObjects(){
  /* INIT OBJECTS */
  glGenVertexArrays(1, &VAO);
  glGenBuffers(1, &VBO);
  glGenBuffers(1, &EBO);
  /* BINDING OBJECTS */
  glBindVertexArray(VAO);
  glBindBuffer(GL_ARRAY_BUFFER, VBO);
  glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
  /* SENDING DATA TO GPU */
  glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
  glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(elements), elements, 
      GL_STATIC_DRAW);
  /* ATTRIBUTES */
  glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)0);
  glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)
    (3*sizeof(float)));
  glEnableVertexAttribArray(0);
  glEnableVertexAttribArray(1);
  /* DEBINDING */
  /*
  glBindBuffer(GL_ARRAY_BUFFER, 0);
  glBindVertexArray(0);
  */
}

/* TEXTURE DATA */

void GraphicsManager::InitTexture(){
  GenerateBindTexture();
  SetTextureOptions();
  UpdateTexture();
}

void GraphicsManager::GenerateBindTexture(){
  glGenTextures(1, &textureID);
  glActiveTexture(GL_TEXTURE0);
  glBindTexture(GL_TEXTURE_2D, textureID);
}

void GraphicsManager::SetTextureOptions(){
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_MIRRORED_REPEAT);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_MIRRORED_REPEAT);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
}

void GraphicsManager::UpdateTexture(){
  std::vector<unsigned char> frame_data = mmu_->RawFrame();
  glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, MMU::FRAME_WIDTH, MMU::FRAME_HEIGHT, 
      0, GL_RGB, GL_UNSIGNED_BYTE, (void*)frame_data.data());
}
