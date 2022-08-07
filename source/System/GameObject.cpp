#include "GameObject.h"

GameObject::GameObject()
{
	object_model = nullptr;
	object_shader = nullptr;

}

GameObject::~GameObject()
{
}


void GameObject::setModel(Model& model)
{
	object_model = &model;
}

void GameObject::setShader(Shader& shader)
{
	object_shader = &shader;
}
Shader& GameObject::getShader() {
	return *object_shader;
}


void GameObject::Draw()
{
	if (object_model != nullptr && object_shader != nullptr && transform_model[3][2] < 3.0f && !wasStruck) {
		object_shader->setMat4("model", transform_model);
		object_model->Draw(*object_shader);
		ResetVectors();
	}
}

void GameObject::addAudioSource(SoundSource& audio_source)
{
	object_Asource = make_shared<SoundSource>(audio_source);
	object_Asource->SetPosition(position[0], position[1], position[2]);
}

void GameObject::addSound(int sound)
{
	sounds.push_back(sound);
}

void GameObject::Play(const ALuint& buffer_to_play)
{
	//if(!object_Asource->isPlaying())
	object_Asource->Play(buffer_to_play);
}

void GameObject::Play()
{
	if (object_Asource != nullptr) {
		if (sounds.size() > 0) {
			//if (!object_Asource->isPlaying())
			object_Asource->Play(sounds.back());
		}
	}
}

void GameObject::SetLooping(bool loop)
{
	object_Asource->SetLooping(loop);
}

void GameObject::Update()
{
	transform_model = glm::rotate(transform_model, rotate_angle, rotate_vector);
	transform_model = glm::scale(transform_model, scale_vector);
	transform_model = glm::translate(transform_model, translate_vector);
	position = glm::vec3(transform_model[3][0], transform_model[3][1], transform_model[3][2]);

	if(HasAudioSource())
		object_Asource->SetPosition(position[0], position[1], position[2]);

	//object_shader->setMat4("model", transform_model);
	//Draw();
}

void GameObject::Rotate(float angle, Axis axis)
{
	if(axis == X)
		rotate_vector = glm::vec3(1.0f, 0.0f, 0.0f);
	else if(axis == Y)
		rotate_vector = glm::vec3(0.0f, 1.0f, 0.0f);
	else if (axis == Z)
		rotate_vector = glm::vec3(0.0f, 0.0f, 1.0f);
	rotate_angle = glm::radians(angle);
}

void GameObject::Translate(float x, float y, float z)
{
	translate_vector = glm::vec3(x, y, z);
}

void GameObject::Scale(float x, float y, float z)
{
	scale_vector = glm::vec3(x, y, z);
}

void GameObject::Scale(float multiplier)
{
	scale_vector = glm::vec3(1.0f, 1.0f, 1.0f) * multiplier;
}

void GameObject::ResetVectors()
{
	translate_vector = glm::vec3(0.0f, 0.0f, 0.0f);
	rotate_vector = glm::vec3(1.0f, 0.0f, 0.0f);
	rotate_angle = glm::radians(0.f);
	scale_vector = glm::vec3(1.0f, 1.0f, 1.0f);
}

bool GameObject::HasAudioSource()
{
	if (object_Asource != nullptr)
		return true;
	else return false;
}

