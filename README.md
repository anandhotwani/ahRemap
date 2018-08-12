# ahRemap

These are written in HLSL and C++ to provide the same functionality Anders Langlands Remap nodes allow for in Arnold. (https://bitbucket.org/anderslanglands/alshaders/wiki/Home)

## ahFloatRemap
![remapfloat_options](https://user-images.githubusercontent.com/10408010/44002814-ebf245f4-9e40-11e8-8d58-a85af13bb2a6.jpg)

Reads in a float value or texture map. Useful for adjusting specular or roughness maps without having to leave Unreal Engine during look-development. Clamping can be useful to avoid unrealistic values being fed in to shaders. Masking option provided to mask out regions from being remapped.

![remapfloat_noremap](https://user-images.githubusercontent.com/10408010/44002847-6e1b12ea-9e41-11e8-99a2-03eaf7f47dc3.jpg)
![remapfloat_withremap](https://user-images.githubusercontent.com/10408010/44002862-aefecdb0-9e41-11e8-8948-08d119ff8428.jpg)

Able to dial in and tune the specular map to achieve more realistic responses without having to go in to Mari, Substance or Photoshop and continually re-import.

## ahColorRemap
![remapcolor_options](https://user-images.githubusercontent.com/10408010/44002891-3082ca58-9e42-11e8-86b6-28174184093b.jpg)

Reads in a color value or texture map. Useful for adjusting albedo maps without having to leave Unreal Engine during look-development. Adjusting the saturation, contrast and gamma can be useful to achieve more desirable results. Masking option provided to mask out regions from being remapped.

![remapcolor_noremap](https://user-images.githubusercontent.com/10408010/44002912-68f3403e-9e42-11e8-8df0-87ab2309a267.jpg)
![remapcolor_withremap](https://user-images.githubusercontent.com/10408010/44002913-6b46d99a-9e42-11e8-8da6-352bf723ac9f.jpg)

The albedo map has been adjusted slightly, the saturation and contrast has been dialed down to match reference images closer. All achieved without having to leave the Unreal Engine Material Graph.
