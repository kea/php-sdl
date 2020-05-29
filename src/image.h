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


#ifndef PHP_SDL_IMAGE_H
#define PHP_SDL_IMAGE_H

#ifdef  __cplusplus
extern "C" {
#endif

ZEND_BEGIN_ARG_INFO_EX(arginfo_IMG_LoadTexture, 0, 0, 2)
      ZEND_ARG_INFO(0, renderer)
      ZEND_ARG_INFO(0, path)
ZEND_END_ARG_INFO()

PHP_FUNCTION(IMG_LoadTexture);

PHP_MINIT_FUNCTION(sdl_image);

#ifdef  __cplusplus
} // extern "C" 
#endif

#endif /* PHP_SDL_IMAGE_H */

