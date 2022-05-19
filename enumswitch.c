/* enumswitch.c */
#include <stdio.h>

enum colors {
  red = 0xff0000,
  green = 0x00ff00,
  blue = 0x0000ff,
  yellow = 0xffff00,
  cyan = 0x00ffff,
  magenta = 0xff00ff,
  black = 0,
  white = 0xffffff,
  grey = 0x808080,
  violet = 0xee8ee
};

void col(enum colors c){
    switch(c) {
  case red :
    printf("red!\n");
    break;
  case green:
    printf("green!\n");
    break;
  case blue:
    printf("blue!\n");
    break;
  case yellow:
    printf("yellow!\n");
    break;
  case cyan:
    printf("cyan!\n");
    break;
    case magenta:
    printf("magenta!\n");
    break;
case black:
    printf("black!\n");
    break;
case white:
    printf("white!\n");
    break;
case grey:
    printf("grey!\n");
    break;
case violet:
    printf("violet!\n");
    break;
  default:
    printf("More!\n");
  }
}


int main () {
  int n;
  n = 0;
  col(n);
}
  
