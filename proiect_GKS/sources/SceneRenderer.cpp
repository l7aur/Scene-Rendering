#include "../headers/SceneRenderer.hpp"

SceneRenderer::SceneRenderer()
{
	myCamera = new gps::Camera(
        glm::vec3(0.0f, 3.0f, 0.0f),
        glm::vec3(0.0f, 3.0f, -4.0f),
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

void SceneRenderer::updateShaderMatrices(gps::Shader& shader)
{
    shader.useShaderProgram();

    glm::mat4 view = myCamera->getViewMatrix();
    glUniformMatrix4fv(shader.getViewLocUniform(), 1, GL_FALSE, glm::value_ptr(view));

    model = glm::mat4(1.0f);
    model = glm::rotate(model, glm::radians(myCamera->getModelAngle()), glm::vec3(0.0f, 1.0f, 0.0f));
    glUniformMatrix4fv(shader.getModelLocUniform(), 1, GL_FALSE, glm::value_ptr(model));

    projection = myCamera->getProjectionMatrix(static_cast<float>(myWindow.getWindowDimensions().width) / static_cast<float>(myWindow.getWindowDimensions().height));
    glUniformMatrix4fv(shader.getProjectionLocUniform(), 1, GL_FALSE, glm::value_ptr(projection));

    normalMatrix = glm::mat3(glm::inverseTranspose(view * model));
    glUniformMatrix3fv(shader.getNormalMatrixLocUniform(), 1, GL_FALSE, glm::value_ptr(normalMatrix));
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
        glfwTerminate();
        std::exit(EXIT_FAILURE);
    }
}

void SceneRenderer::initOpenGLState()
{
    glViewport(0, 0, myWindow.getWindowDimensions().width, myWindow.getWindowDimensions().height);
    glEnable(GL_FRAMEBUFFER_SRGB);
    glEnable(GL_BLEND);
    glEnable(GL_DEPTH_TEST); // enable depth-testing
    glDepthFunc(GL_LESS); // depth-testing interprets a smaller value as "closer"
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    //glEnable(GL_CULL_FACE); // cull face
    //glCullFace(GL_BACK); // cull back face
    //glFrontFace(GL_CCW); // GL_CCW for counter clock-wise
}

void SceneRenderer::renderObjects()
{
    for (Object& i : myObjects)
        i.render(myCamera->getPosition());
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
