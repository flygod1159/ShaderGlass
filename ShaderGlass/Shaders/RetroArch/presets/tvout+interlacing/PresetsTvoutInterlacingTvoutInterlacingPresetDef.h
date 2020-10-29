/*
ShaderGlass preset presets-tvout-interlacing / tvout+interlacing imported from RetroArch:
https://github.com/libretro/slang-shaders/blob/master/presets/tvout+interlacing/tvout+interlacing.slangp
See original file for credits and usage license. 
This file is auto-generated, do not modify directly.
*/

#pragma once

namespace RetroArch
{
class PresetsTvoutInterlacingTvoutInterlacingPresetDef : public PresetDef
{
public:
	PresetsTvoutInterlacingTvoutInterlacingPresetDef() : PresetDef{}
	{
		Name = "tvout+interlacing";
		Category = "presets-tvout-interlacing";
	}

	virtual void Build() {
         	ShaderDefs.push_back(CrtShadersTvoutTweaksShaderDef()
.Param("scale_type_x", "viewport")
.Param("scale_type_y", "source")
.Param("scale_x", "1.000000")
.Param("scale_y", "1.000000"));
         	ShaderDefs.push_back(MiscImageAdjustmentShaderDef());
         	ShaderDefs.push_back(MiscInterlacingShaderDef());
	}
};
}
