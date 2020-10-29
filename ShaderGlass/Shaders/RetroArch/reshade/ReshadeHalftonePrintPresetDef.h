/*
ShaderGlass preset reshade / halftone-print imported from RetroArch:
https://github.com/libretro/slang-shaders/blob/master/reshade/halftone-print.slangp
See original file for credits and usage license. 
This file is auto-generated, do not modify directly.
*/

#pragma once

namespace RetroArch
{
class ReshadeHalftonePrintPresetDef : public PresetDef
{
public:
	ReshadeHalftonePrintPresetDef() : PresetDef{}
	{
		Name = "halftone-print";
		Category = "reshade";
	}

	virtual void Build() {
         	ShaderDefs.push_back(ReshadeShadersLUTLUTShaderDef());
         	ShaderDefs.push_back(MiscCmykHalftoneDotShaderDef()
.Param("filter_linear", "true"));
            TextureDefs.push_back(ReshadeShadersLUTCmyk16TextureDef()
.Param("linear", "true")
.Param("name", "SamplerLUT"));
	}
};
}
