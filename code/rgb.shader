#ifdef GL_ES
precision lowp float;
#endif

uniform sampler2D texture;
uniform float redshown;
uniform float greenshown;
uniform float blueshown;

void main() {
   vec4 pixel = texture2D(texture, gl_TexCoord[0].xy);
   vec4 black = vec4(0.0,0.0,0.0,1.0);
   vec4 red = vec4(1.0,0.0,0.0,1.0);
   vec4 green = vec4(0.0,1.0,0.0,1.0);
   vec4 blue = vec4(0.0,0.0,1.0,1.0);
   gl_FragColor = vec4(redshown,greenshown,blueshown,0.1);
   gl_FragColor = pixel;

   if (redshown < 1.0) {
   } else {
      if (pixel == black) {
      } else if (pixel.r > 0.6) {
         gl_FragColor.r = 1.0;
         gl_FragColor.g = 1.0;
         gl_FragColor.b = 1.0;
         gl_FragColor.a = pixel.a;
      }
   }
   if (greenshown < 1.0) {
   } else {
      if (pixel == black) {
      } else if (pixel.g > 0.6) {
         gl_FragColor.r = 1.0;
         gl_FragColor.g = 1.0;
         gl_FragColor.b = 1.0;
         gl_FragColor.a = pixel.a;
      }
   }
   if (blueshown < 1.0) {
   } else {
      if (pixel == black) {
      } else if (pixel.b > 0.6) {
         gl_FragColor.r = 1.0;
         gl_FragColor.g = 1.0;
         gl_FragColor.b = 1.0;
         gl_FragColor.a = pixel.a;
      }
   }
}
