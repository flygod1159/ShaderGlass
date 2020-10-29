/*
ShaderGlass preset scalefx / scalefx-9x imported from RetroArch:
https://github.com/libretro/slang-shaders/blob/master/scalefx/scalefx-9x.slangp
See original file for credits and usage license. 
This file is auto-generated, do not modify directly.
*/

#pragma once

namespace RetroArch
{
class ScalefxScalefx9xPresetDef : public PresetDef
{
public:
	ScalefxScalefx9xPresetDef() : PresetDef{}
	{
		Name = "scalefx-9x";
		Category = "scalefx";
	}

	virtual void Build() {
         	ShaderDefs.push_back(ScalefxShadersOldScalefxPass0ShaderDef()
.Param("alias", "sfxp0")
.Param("filter_linear", "false")
.Param("scale", "1.0")
.Param("scale_type", "source"));
         	ShaderDefs.push_back(ScalefxShadersOldScalefxPass1ShaderDef()
.Param("alias", "sfxp1")
.Param("filter_linear", "false")
.Param("scale", "1.0")
.Param("scale_type", "source"));
         	ShaderDefs.push_back(ScalefxShadersOldScalefxPass2ShaderDef()
.Param("alias", "sfxp2")
.Param("filter_linear", "false")
.Param("scale", "1.0")
.Param("scale_type", "source"));
         	ShaderDefs.push_back(ScalefxShadersOldScalefxPass3ShaderDef()
.Param("alias", "sfxp3")
.Param("filter_linear", "false")
.Param("scale", "3.0")
.Param("scale_type", "source"));
         	ShaderDefs.push_back(ScalefxShadersOldScalefxPass0ShaderDef()
.Param("alias", "sfxp4")
.Param("filter_linear", "false")
.Param("scale", "1.0")
.Param("scale_type", "source"));
         	ShaderDefs.push_back(ScalefxShadersOldScalefxPass1ShaderDef()
.Param("alias", "sfxp5")
.Param("filter_linear", "false")
.Param("scale", "1.0")
.Param("scale_type", "source"));
         	ShaderDefs.push_back(ScalefxShadersOldScalefxPass2ShaderDef()
.Param("alias", "sfxp6")
.Param("filter_linear", "false")
.Param("scale", "1.0")
.Param("scale_type", "source"));
         	ShaderDefs.push_back(ScalefxShadersOldScalefxPass7ShaderDef()
.Param("alias", "sfxp7")
.Param("filter_linear", "false")
.Param("scale", "3.0")
.Param("scale_type", "source"));
	}
};
}
