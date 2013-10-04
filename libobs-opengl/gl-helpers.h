#ifndef GL_HELPERS_H
#define GL_HELPERS_H

/*
 * Okay, so GL error handling is..  unclean to work with.  I don't want
 * to have to keep typing out the same stuff over and over again do I'll just
 * make a bunch of helper functions to make it a bit easier to handle errors
 */

static inline bool gl_error_occurred(const char *funcname)
{
	GLenum errorcode = glGetError();
	if (errorcode != GL_NO_ERROR) {
		blog(LOG_ERROR, "%s failed, glGetError returned %u",
				funcname, errorcode);
		return false;
	}

	return true;
}

static inline bool gl_gen_textures(GLsizei num_texture, GLuint *textures)
{
	glGenTextures(num_texture, textures);
	return gl_error_occurred("glGenTextures");
}

static inline bool gl_bind_texture(GLenum target, GLuint texture)
{
	glBindTexture(target, texture);
	return gl_error_occurred("glBindTexture");
}

#endif