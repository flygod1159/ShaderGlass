/*
ShaderGlass preset presets-tvout / tvout-jinc-sharpen imported from RetroArch:
https://github.com/libretro/slang-shaders/blob/master/presets/tvout/tvout-jinc-sharpen.slangp
See original file for credits and usage license. 
This file is auto-generated, do not modify directly.
*/

#pragma once

namespace RetroArch
{
class PresetsTvoutTvoutJincSharpenPresetDef : public PresetDef
{
public:
	PresetsTvoutTvoutJincSharpenPresetDef() : PresetDef{}
	{
		Name = "tvout-jinc-sharpen";
		Category = "presets-tvout";
	}

	virtual void Build() {
         	ShaderDefs.push_back(CrtShadersTvoutTweaksShaderDef()
.Param("scale_type_x", "source")
.Param("scale_type_y", "source")
.Param("scale_x", "2.000000")
.Param("scale_y", "1.000000"));
         	ShaderDefs.push_back(MiscImageAdjustmentShaderDef());
         	ShaderDefs.push_back(WindowedShadersJinc2ShaderDef()
.Param("scale_type_x", "viewport")
.Param("scale_type_y", "source")
.Param("scale_x", "1.000000")
.Param("scale_y", "1.000000"));
	}
};
}
