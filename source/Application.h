#include "root_directory.h"
#include "System/shaderClass.h"
#include "System/camera.h"
#include "System/Model.h"
#include "Entities/Cursor.h"
#include "Entities/Note.h"
#include "Stage/stage.h"
#include "System/Song.h"
#include "Entities/Controller.h"
#include "Audio/SoundDevice.h"
#include "Audio/SoundLibrary.h"

namespace bb = BoomBoom;
using namespace std;

class Application
{
	enum Mode {
		EDIT,
		PLAY
	};

	Application();
	~Application();

	void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);
	void framebuffer_size_callback(GLFWwindow* window, int width, int height);
	void mouse_callback(GLFWwindow* window, double xpos, double ypos);
	void scroll_callback(GLFWwindow* window, double xoffset, double yoffset);

	void init();
	void ProcessStage(float dt);
	void Update();  //ProcessInput()

	void render();

	bool isRunning();

	Mode mode;
	//Window and Shader
	GLFWwindow* window;
	Shader ourShader = Shader(bb::getPath("Resources/Shaders/default.vs").string().c_str(), bb::getPath("Resources/Shaders/default.fs").string().c_str());
	//Song
	Song song = Song("default");
	//Cursor & Controller
	Cursor cursor;
	Controller controller;
	//Stage
	Skybox stage;
	Model guitar = Model(bb::getPath("Resources/Models/guitar/scene.gltf").string());
	//Audio
	SoundDevice* sd = LISTENER->Get();
	vector<SoundSource> sound_sources;
	vector<int> sounds;
	int ID_Song;
	

	// settings
	const unsigned int SCR_WIDTH = 900;
	const unsigned int SCR_HEIGHT = 700;

	// camera
	Camera camera = Camera(glm::vec3(0.05f, 1.0f, 3.0f));
	float lastX = SCR_WIDTH / 2.0f;
	float lastY = SCR_HEIGHT / 2.0f;
	bool firstMouse = true;


	// timing
	float deltaTime = 0.0f;
	float lastFrame = 0.0f;

};