<?php

$quit = false;
$x = 288;
$y = 208;

    // init SDL

    SDL_Init(SDL_INIT_VIDEO);
    $window = SDL_CreateWindow("SDL2 Keyboard/Mouse events", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 640, 480, SDL_WINDOW_ALLOW_HIGHDPI);
$renderer = SDL_CreateRenderer($window, -1, 0);

$image = SDL_LoadBMP("spaceship.bmp");
$texture = SDL_CreateTextureFromSurface($renderer, $image);
	$drect = $image->clip_rect;
    SDL_FreeSurface($image);

    SDL_SetRenderDrawColor($renderer, 255, 255, 255, 255);

$event = new SDL_Event;
    while (!$quit)
    {
        SDL_WaitEvent($event);

        switch ($event->type)
        {
        case SDL_QUIT:
            $quit = true;
            break;
	case SDL_MOUSEMOTION:
$drect->x =rand(0,300);
$drect->y = rand(0,300);;
         SDL_RenderClear($renderer);
if(SDL_RenderCopy($renderer, $texture, NULL, $drect)!=0){
	echo SDL_GetError(), PHP_EOL;
}
        SDL_RenderPresent($renderer);

		break;
        }


	SDL_Delay(10);
     }

    // cleanup SDL

    SDL_DestroyTexture($texture);
    SDL_DestroyRenderer($renderer);
    SDL_DestroyWindow($window);
    SDL_Quit();
