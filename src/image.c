/*
  +----------------------------------------------------------------------+
  | PHP Version 7                                                        |
  +----------------------------------------------------------------------+
  | Copyright (c) 1997-2018 The PHP Group                                |
  +----------------------------------------------------------------------+
  | This source file is subject to version 3.01 of the PHP license,      |
  | that is bundled with this package in the file LICENSE, and is        |
  | available through the world-wide-web at the following url:           |
  | http://www.php.net/license/3_01.txt                                  |
  | If you did not receive a copy of the PHP license and are unable to   |
  | obtain it through the world-wide-web, please send a note to          |
  | license@php.net so we can mail you a copy immediately.               |
  +----------------------------------------------------------------------+
  | Authors: Manuel Baldassarri <manuel@baldassarri.me>                  |
  +----------------------------------------------------------------------+
*/

#include "php_sdl.h"
#include "image.h"

#define SDL_RENDERER_RES_NAME "SDL Renderer"
extern int le_sdl_renderer;
extern int le_sdl_texture;

extern DECLSPEC SDL_Texture * SDLCALL IMG_LoadTexture(SDL_Renderer *renderer, const char *file);

/* {{{ proto SDL_Texture IMG_LoadTexture(string file)

	PHP note: stream are supported

 *  Load a texture from a file.
 extern DECLSPEC SDL_Texture * SDLCALL IMG_LoadTexture(SDL_Renderer *renderer, const char *file);
 */
PHP_FUNCTION(IMG_LoadTexture)
{
    zend_string *path;
	SDL_Texture *texture = NULL;

	zval *z_renderer = NULL;
	SDL_Renderer *renderer = NULL;

	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_ZVAL(z_renderer)
		Z_PARAM_STR(path)
	ZEND_PARSE_PARAMETERS_END();

    renderer = (SDL_Renderer*)zend_fetch_resource(Z_RES_P(z_renderer), SDL_RENDERER_RES_NAME, le_sdl_renderer);
	texture = IMG_LoadTexture(renderer, ZSTR_VAL(path));

	RETURN_RES(zend_register_resource(texture, le_sdl_texture));
}
/* }}} */

static const zend_function_entry php_sdl_image_methods[] = {
	PHP_FE(IMG_LoadTexture,		arginfo_IMG_LoadTexture)

    PHP_FE_END
};

/* {{{ MINIT */
PHP_MINIT_FUNCTION(sdl_image)
{
	return SUCCESS;
}
/* }}} */
