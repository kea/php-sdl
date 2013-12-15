--TEST--
SDL_MessageBox test
--SKIPIF--
<?php
if (!extension_loaded("sdl")) die("skip SDL extension not loaded");
?>
--FILE--
<?php
echo "= SDL_MessageBoxColor\n";
$c = new SDL_MessageBoxColor(1,2,3);
var_dump($c, "$c");
$c->r = "123";
$c->g = 345.6;
$c->b = -5;
var_dump($c); /* string, float, int */
var_dump("$c");
var_dump($c); /* 3 int */
?>
= Done
--EXPECTF--
= SDL_MessageBoxColor
object(SDL_MessageBoxColor)#1 (3) {
  ["r"]=>
  int(1)
  ["g"]=>
  int(2)
  ["b"]=>
  int(3)
}
string(26) "SDL_MessageBoxColor(1,2,3)"
object(SDL_MessageBoxColor)#1 (3) {
  ["r"]=>
  string(3) "123"
  ["g"]=>
  float(345.6)
  ["b"]=>
  int(-5)
}
string(31) "SDL_MessageBoxColor(123,89,251)"
object(SDL_MessageBoxColor)#1 (3) {
  ["r"]=>
  int(123)
  ["g"]=>
  int(89)
  ["b"]=>
  int(251)
}
= Done
