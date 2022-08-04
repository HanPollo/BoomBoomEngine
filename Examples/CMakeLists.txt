function(MakeExample TARGETNAME FILENAME)
	add_executable(${TARGETNAME} ${FILENAME})
	set_property(TARGET ${TARGETNAME} PROPERTY CXX_STANDARD 20)
	set_property(TARGET ${TARGETNAME} PROPERTY FOLDER Examples)
	target_link_libraries(${TARGETNAME} PRIVATE BoomEngine)
	target_include_directories(${TARGETNAME} PRIVATE ${BOOM_BOOM_INCLUDE_DIRECTORY} ${THIRD_PARTY_INCLUDE_DIRECTORIES})
	add_custom_command(TARGET ${TARGETNAME} POST_BUILD        
		COMMAND ${CMAKE_COMMAND} -E copy_if_different 
        $<TARGET_FILE:OpenAL> $<TARGET_FILE_DIR:main>)



endfunction(MakeExample)

add_compile_definitions(AL_LIBTYPE_STATIC)
MakeExample(main main.cpp)
MakeExample(song loadSong.cpp)
MakeExample(playSong playSong.cpp)