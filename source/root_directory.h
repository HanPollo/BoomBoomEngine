/*
	This field was automatically created with CMake please don't modify it
*/
#pragma once

#include <filesystem>

namespace BoomBoom
{
	
static const char * const source_directory = "C:/Users/pollo/OneDrive/Documentos/U/Arqui Motores de Juego/BoomBoomEngine/";

static std::filesystem::path getPath(const std::string &relative_path){
	return source_directory + relative_path;
}
	
} // BoomBoom
