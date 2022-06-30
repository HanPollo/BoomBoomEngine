function(MakeExample TARGETNAME FILENAME)
	add_executable(${TARGETNAME} ${FILENAME})
	set_property(TARGET ${TARGETNAME} PROPERTY CXX_STANDARD 20)
	set_property(TARGET ${TARGETNAME} PROPERTY FOLDER Examples)
	target_link_libraries(${TARGETNAME} PRIVATE BoomEngine)
	target_include_directories(${TARGETNAME} PRIVATE ${BOOM_BOOM_INCLUDE_DIRECTORY} ${THIRD_PARTY_INCLUDE_DIRECTORIES})

endfunction(MakeExample)

MakeExample(main main.cpp)