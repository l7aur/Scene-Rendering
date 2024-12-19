#include "SceneRenderer.hpp"

SceneRenderer::SceneRenderer()
{
	myCamera = new gps::Camera(
        glm::vec3(0.0f, 5.0f, 3.0f),
        glm::vec3(0.0f, 5.0f, -10.0f),
        glm::vec3(0.0f, 1.0f, 0.0f),
        0.1f,
        1000.0f
    );
    initOpenGLWindow();
    initOpenGLState();
}

SceneRenderer::~SceneRenderer()
{
    delete myCamera;
    myWindow.Delete();
}

void SceneRenderer::renderScene(gps::Shader& shader)
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    //render the scene

    model = glm::mat4(1.0f);
    modelLoc = glGetUniformLocation(shader.shaderProgram, "model");

    shader.useShaderProgram();

    glm::mat4 view = myCamera->getViewMatrix();
    GLint viewLoc = glGetUniformLocation(shader.shaderProgram, "view");
    glUniformMatrix4fv(viewLoc, 1, GL_FALSE, glm::value_ptr(view));

    model = glm::rotate(model, glm::radians(myCamera->getModelAngle()), glm::vec3(0.0f, 1.0f, 0.0f));
    glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));

    projection = myCamera->getProjectionMatrix(static_cast<float>(myWindow.getWindowDimensions().width) / static_cast<float>(myWindow.getWindowDimensions().height));
    projectionLoc = glGetUniformLocation(shader.shaderProgram, "projection");
    glUniformMatrix4fv(projectionLoc, 1, GL_FALSE, glm::value_ptr(projection));

    renderObjects();
}

void SceneRenderer::initOpenGLWindow()
{
    try
    {
        myWindow.Create(1024, 768, "GKS PROJECT");
    }
    catch (const std::exception& e)
    {
        std::cerr << e.what() << '\n';
        std::exit(EXIT_FAILURE);
    }
}

void SceneRenderer::initOpenGLState()
{
    glClearColor(0.7f, 0.7f, 0.7f, 1.0f);
    glViewport(0, 0, myWindow.getWindowDimensions().width, myWindow.getWindowDimensions().height);
    glEnable(GL_FRAMEBUFFER_SRGB);
    glEnable(GL_DEPTH_TEST); // enable depth-testing
    glDepthFunc(GL_LESS); // depth-testing interprets a smaller value as "closer"
    //glEnable(GL_CULL_FACE); // cull face
    //glCullFace(GL_BACK); // cull back face
    //glFrontFace(GL_CCW); // GL_CCW for counter clock-wise
}

void SceneRenderer::initUniforms(gps::Shader& shader)
{
    shader.useShaderProgram();

    // create model matrix for teapot
    model = glm::mat4(1.0f);// glm::rotate(glm::mat4(1.0f), glm::radians(angle), glm::vec3(0.0f, 1.0f, 0.0f));
    modelLoc = glGetUniformLocation(shader.shaderProgram, "model");

    // get view matrix for current camera
    view = myCamera->getViewMatrix();
    viewLoc = glGetUniformLocation(shader.shaderProgram, "view");
    // send view matrix to shader
    glUniformMatrix4fv(viewLoc, 1, GL_FALSE, glm::value_ptr(view));

    // compute normal matrix for teapot
    normalMatrix = glm::mat3(glm::inverseTranspose(view * model));
    normalMatrixLoc = glGetUniformLocation(shader.shaderProgram, "normalMatrix");

    // create projection matrix
    float aspectRatio = static_cast<float>(myWindow.getWindowDimensions().width) / static_cast<float>(myWindow.getWindowDimensions().height);
    projection = myCamera->getProjectionMatrix(aspectRatio);
    projectionLoc = glGetUniformLocation(shader.shaderProgram, "projection");
    // send projection matrix to shader
    glUniformMatrix4fv(projectionLoc, 1, GL_FALSE, glm::value_ptr(projection));

    //set the light direction (direction towards the light)
    lightDir = glm::vec3(0.0f, 1.0f, 1.0f);
    lightDirLoc = glGetUniformLocation(shader.shaderProgram, "lightDir");
    // send light dir to shader
    glUniform3fv(lightDirLoc, 1, glm::value_ptr(lightDir));

    //set light color
    lightColor = glm::vec3(1.0f, 1.0f, 1.0f); //white light
    lightColorLoc = glGetUniformLocation(shader.shaderProgram, "lightColor");
    // send light color to shader
    glUniform3fv(lightColorLoc, 1, glm::value_ptr(lightColor));
}

void SceneRenderer::renderObjects()
{
    for (Object& i : myObjects)
        i.render(modelLoc, normalMatrixLoc);
}

void SceneRenderer::setWindowCallbacks(
    void (*resizeCallback)(GLFWwindow*, int, int),
    void (*keyboardCallback)(GLFWwindow*, int, int, int, int),
    void (*mouseCallback)(GLFWwindow*, double, double),
    void (*scrollCallback)(GLFWwindow*, double, double))
{
    glfwSetWindowSizeCallback(myWindow.getWindow(), resizeCallback);
    glfwSetInputMode(myWindow.getWindow(), GLFW_CURSOR, GLFW_CURSOR_DISABLED);
    glfwSetKeyCallback(myWindow.getWindow(), keyboardCallback);
    glfwSetCursorPosCallback(myWindow.getWindow(), mouseCallback);
    glfwSetScrollCallback(myWindow.getWindow(), scrollCallback);
}

void SceneRenderer::insertIntoScene(const Object& object)
{
    myObjects.push_back(object);
}

void SceneRenderer::insertIntoScene(const std::vector<Object>& objects)
{
    myObjects.insert(myObjects.end(), objects.begin(), objects.end());
}
