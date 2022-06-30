#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "../root_directory.h"
#include "../System/BasicMesh.h"
#include "../System/Model.h"
#include "../System/shaderClass.h"
#include "../Entities/Note.h"

#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <map>
#include <vector>

namespace bb = BoomBoom;
using namespace std;

class Song {
public:
	Song();
	~Song();

	string name;
	vector<Note*> notes;

	void DrawNotes(Shader& shader);
	void addNote(Note* new_note);
	//void Update();
};
