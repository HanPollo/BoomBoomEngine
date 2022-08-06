#pragma once
#include "Model.h"
#include "../Audio/SoundSource.h"




class GameObject
{
	enum Axis {
		X,
		Y,
		Z
	};
public:
	GameObject();
	virtual ~GameObject();

	void setModel(Model& model);
	void setShader(Shader& shader);

	Shader& getShader();

	void positionObject(float x, float y, float z);
	void Draw();

	void addAudioSource(SoundSource& audio_source);
	void addSound(int sound);
	void Play(const ALuint& buffer_to_play);
	void Play();
	void SetLooping(bool loop);

	virtual void Update();

	void Rotate(float angle, Axis axis);
	void Translate(float x, float y, float z);
	void Scale(float x, float y, float z);
	void Scale(float multiplier);

	void ResetVectors();

	bool HasAudioSource();



protected:

	Model* object_model;
	Shader* object_shader;
	SoundSource* object_Asource = nullptr;

	glm::mat4 transform_model = glm::mat4(1.0f);

	glm::vec3 position = glm::vec3(0.0f, 0.0f, 0.0f);
	glm::vec3 translate_vector = glm::vec3(0.0f, 0.0f, 0.0f);
	glm::vec3 rotate_vector = glm::vec3(1.0f, 0.0f, 0.0f);
	float rotate_angle = glm::radians(0.f);
	glm::vec3 scale_vector = glm::vec3(1.0f, 1.0f, 1.0f);

	vector<int> sounds;

	float rot_speed = 1.f;
	float move_speed = 1.f;
	float scale_speed = 0.01f;


	

};