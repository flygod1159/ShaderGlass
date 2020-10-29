/*
ShaderGlass preset reshade / lut imported from RetroArch:
https://github.com/libretro/slang-shaders/blob/master/reshade/lut.slangp
See original file for credits and usage license. 
This file is auto-generated, do not modify directly.
*/

#pragma once

namespace RetroArch
{
class ReshadeLutPresetDef : public PresetDef
{
public:
	ReshadeLutPresetDef() : PresetDef{}
	{
		Name = "lut";
		Category = "reshade";
	}

	virtual void Build() {
         	ShaderDefs.push_back(ReshadeShadersLUTLUTShaderDef());
            TextureDefs.push_back(ReshadeShadersLUT16TextureDef()
.Param("linear", "true")
.Param("name", "SamplerLUT"));
	}
};
}
