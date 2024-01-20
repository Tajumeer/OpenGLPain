#ifndef ERROR_TYPE_H
#define ERROR_TYPE_H

enum class ErrorType : char
{
	ET_SUCCESS = 0, // == ET_NONE
	ET_WINDOW_CREATION_FAILED,
	ET_GLAD_INITIALISATION_FAILED,
	ET_VERTEX_SHADER_COMPILATION_FAILED,
	ET_FRAG_SHADER_COMPILATION_FAILED,
	ET_SHADER_PROG_LINK_FAILED,
	ET_FILE_READ_FAILED,
	ET_STREAM_STILL_OPEN,
	ET_DATA_MANAG_NULLCHECK_FAILED,
	ET_COUNT,
	ET_FAILED_LOAD_TEXTURE
};

#endif // !ERROR_TYPE_H
